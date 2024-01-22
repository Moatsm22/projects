import json
import glob

Batch_start = 0
Time_steps = 100
Featurs_col = ['V', 'I', 'temp']
Prediction_col = ['AH']
Useful_col = Featurs_col + Prediction_col

# export parameters to json list file
parameters = {
    
    "Batch_start" : (Batch_start),
    "Time_steps" : (Time_steps),
    "Featurs_col" : (Featurs_col),
    "Prediction_col" : (Prediction_col),
    "Useful_col" : (Useful_col),    
}    

data = json.dumps(parameters, indent=4)
# filepath to folder of json files
my_files_path = glob.glob(r'D:\Univirsety\Internship\projects\*.json')
i = len(my_files_path) + 1
filepath = ('train_' + str(i) + '_parameters.json')
with open(filepath, 'w') as file:
    file.write(data)
file.close()