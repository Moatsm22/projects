import fileinput

# parameters
Batch_start = 0
Time_steps = 100
Featurs_col = ['V', 'I', 'temp']
Prediction_col = ['AH']
Useful_col = Featurs_col + Prediction_col

# export parameters into txt file
filepath = 'parameters_log.txt'
lines = ['training parameters that might be changed in each training trail']
with open(filepath, 'w') as f:
    for line in lines:
        f.write(line)
        f.write('\n')
        f.write('\n')
        f.write('Batch_start =' + str(Batch_start) + '\n')
        f.write('Time_steps =' + str(Time_steps) + '\n')
        f.write('Batch_start' + str(Batch_start) + '\n')
        f.write('Featurs_col' + str(Featurs_col) + '\n')
        f.write('Prediction_col' + str(Prediction_col) + '\n')
        f.write('UUseful_col' + str(Useful_col) + '\n')
f.close()

with open(filepath) as f:
    line = f.readline()
    cnt = 1
    while line:
        print("line {}: {}".format(cnt, line.strip()))
        cnt += 1

print("text to search for:")
textToSearch = input("> ")

print("Text to replace it with:")
textToReplace = input("> ")

print("file to perform search-replace on:")
fileToSearch = (r'D:\Univirsety\Internship\projects\Log_txt.py')
tempFile = open(fileToSearch, 'r+')

for line in fileinput.input(fileToSearch):
    if textToSearch in line:
        print('Match found')
    else:
        print('Match not found!')
    tempFile.write(line.replace( textToSearch, textToReplace))
tempFile.close()      