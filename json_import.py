import json

# insert the terain number
filepath = ('train_1_parameters.json')

# reading from json file
with open(filepath, 'r') as openfile:
    json_object = json.load(openfile)
    
Batch_start = (json_object['Batch_start'])
Time_steps = (json_object['Time_steps'])
Featurs_col = (json_object['Featurs_col'])
Prediction_col = (json_object['Prediction_col']) 
Useful_col = (json_object['Useful_col'])

print(json_object['Useful_col'])
print(type(json_object['Batch_start']))