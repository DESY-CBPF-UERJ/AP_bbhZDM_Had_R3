#ifndef BTAGEFFANALYZER_H
#define BTAGEFFANALYZER_H

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

class BTagEffAnalyzer {
    struct Entry {
        float etaMin;
        float etaMax;
        float ptMin;
        float ptMax;
        double efficiency;
    };

    struct Bounds {
        float etaMin;
        float etaMax;
        float ptMin;
        float ptMax;
    };

    std::map<std::string, std::map<std::string, std::vector<Entry>>> dataMap;
    std::map<std::string, std::map<std::string, Bounds>> boundsMap;
    std::string datasetName;

    double evaluate(const std::string& flavour, float eta, float pt) const {
        const auto& entries = dataMap.at(datasetName).at(flavour);
        for (const auto& entry : entries) {
            if (eta >= entry.etaMin && eta <= entry.etaMax &&
                pt >= entry.ptMin && pt < entry.ptMax) {
                return entry.efficiency;
            }
        }
        return 0.;
    }

public:
    void readFile(const std::string& path) {
        FILE* file = fopen(path.c_str(), "r");
        if (!file) throw std::runtime_error("Cannot open b-tag efficiency file: " + path);

        char buffer[0xFFFF];
        rapidjson::FileReadStream stream(file, buffer, sizeof(buffer));
        rapidjson::Document document;
        document.ParseStream(stream);
        fclose(file);

        if (document.HasParseError() || !document.IsObject()) {
            throw std::runtime_error("Invalid b-tag efficiency JSON: " + path);
        }

        dataMap.clear();
        boundsMap.clear();
        for (auto dataset = document.MemberBegin(); dataset != document.MemberEnd(); ++dataset) {
            const std::string datasetKey = dataset->name.GetString();
            for (auto flavour = dataset->value.MemberBegin(); flavour != dataset->value.MemberEnd(); ++flavour) {
                const std::string flavourKey = flavour->name.GetString();
                float minEta = 1.e9;
                float maxEta = -1.e9;
                float minPt = 1.e9;
                float maxPt = -1.e9;

                for (const auto& value : flavour->value.GetArray()) {
                    Entry entry{
                        value["eta_min"].GetFloat(), value["eta_max"].GetFloat(),
                        value["pt_min"].GetFloat(), value["pt_max"].GetFloat(),
                        value["eff"].GetDouble()
                    };
                    dataMap[datasetKey][flavourKey].push_back(entry);
                    minEta = std::min(minEta, entry.etaMin);
                    maxEta = std::max(maxEta, entry.etaMax);
                    minPt = std::min(minPt, entry.ptMin);
                    maxPt = std::max(maxPt, entry.ptMax);
                }
                boundsMap[datasetKey][flavourKey] = {minEta, maxEta, minPt, maxPt};
            }
        }
    }

    void calib(std::string requestedDataset, const std::string& fallbackDataset) {
        if (dataMap.count(requestedDataset) == 0) {
            std::cout << "WARNING: Missing dataset " << requestedDataset
                      << " in b-tag efficiency file. Using " << fallbackDataset << "." << std::endl;
            requestedDataset = fallbackDataset;
        }
        if (dataMap.count(requestedDataset) == 0) {
            throw std::runtime_error("Missing b-tag fallback dataset: " + requestedDataset);
        }
        datasetName = requestedDataset;
    }

    double getEfficiency(const std::string& flavour, float eta, float pt) const {
        eta = std::fabs(eta);
        const auto& bounds = boundsMap.at(datasetName).at(flavour);
        if (eta < bounds.etaMin || eta > bounds.etaMax || pt < bounds.ptMin) return 0.;
        if (pt >= bounds.ptMax) pt = bounds.ptMax - 0.0001f;
        return evaluate(flavour, eta, pt);
    }
};

#endif
