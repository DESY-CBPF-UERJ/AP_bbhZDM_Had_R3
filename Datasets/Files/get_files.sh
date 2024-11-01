#Don't use get_signal,  we are working with private signal
#python3 get_signal.py -p 0_22 -v 12 #Don't use get_signal
#python3 get_signal.py -p 1_22 -v 12 #Don't use get_signal
#python3 get_signal.py -p 0_23 -v 12 #Don't use get_signal
#python3 get_signal.py -p 1_23 -v 12 #Don't use get_signal
#Don't use get_signal,  we are working with private signal

python3 get_bkg.py -p 0_22 -v 12
python3 get_bkg.py -p 1_22 -v 12
python3 get_bkg.py -p 0_23 -v 12
python3 get_bkg.py -p 1_23 -v 12

python3 get_data_22.py -v 12
python3 get_data_23.py -v 12
