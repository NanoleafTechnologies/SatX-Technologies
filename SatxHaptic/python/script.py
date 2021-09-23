from datetime import date
from datetime import datetime
from time import sleep
from tqdm import tqdm
from variables import *

with open ("data/input.csv", "r") as data:
	holder = data.read()

replaced = holder.replace(',', '.')
split = replaced.split(' ')
for element in split:
    removed = element.replace("\t", " ").strip()

splitnewline = removed.split('\n')

for element in splitnewline:
	notint = (element[:6])
	converted = float(notint)
	height.append(converted)

for element in range(len(splitnewline)):
	if(0 <= element <= 120):
		sum += (height[element+1] - height[element])
		counter += 1
height_avarage = sum/counter 

print("SATX HAPTIC V.1")
print("##########################")
today = date.today()
now = datetime.now()
current_time = now.strftime("%H:%M:%S")
print(current_time, today)
print("Current data sheet: {}".format(inputfile))
print("""

""")
user_input = input("INPUT HEIGHT: ")
print("Calculating...")

for i in tqdm(range(10)):
    sleep(1)

actual_height = float(user_input) - height[0]
pips = float(actual_height) / height_avarage
pip_round = round(pips, 1)
int_pip_round = int(pip_round)

for element in splitnewline:
	notint = (element[6:16])
	converted = float(notint)
	lat.append(converted)

for element in splitnewline:
	notint = (element[16:26])
	converted = float(notint)
	long.append(converted)

for element in splitnewline:
	notint = (element[26:31])
	converted = float(notint)
	pressure.append(converted)

for element in splitnewline:
	notint = (element[33:37])
	converted = float(notint)
	humid.append(converted)

for element in splitnewline:
	notint = (element[38:43])
	converted = float(notint)
	temp.append(converted)

for element in splitnewline:
	notint = (element[44:50])
	converted = float(notint)
	UV.append(converted)


for element in range(len(splitnewline)):
	if(0 <= element <= 120):
		sumpress += (pressure[element+1] - pressure[element])
		counterpress += 1
pressure_avarage = sumpress/counterpress 

pressurepos1 = pressure[0]
pressurepos2 = pressure[0]
pressurepos3 = pressure[0]
pressurepos4 = pressure[0]

for increment in range(int_pip_round):
	pressurepos1 += pressure_avarage

percentValue1 = pressure[39] - (pressure[0] + (40 * pressure_avarage))
percentValue2 = pressure[79] - (pressure[0] + (80 * pressure_avarage))
percentValue3 = pressure[119] - (pressure[0] + (120 * pressure_avarage))
percentValue1_= ((percentValue1 / pressure[39]) + (percentValue2 / pressure[79]) + (percentValue3 / pressure[119]) / 3)
percentValue1_rounded = round(percentValue1_, 4)

print("After {} meters the pressure is: {} mBar".format(user_input, pressurepos1))


for element in range(len(splitnewline)):
	if(0 <= element <= 120):
		sumtemp += (temp[element+1] - temp[element])
		countertemp += 1
temp_avarage = sumtemp/countertemp 
temppos1 = temp[0]
for increment in range(int_pip_round):
	temppos1 += temp_avarage

percentValue1_temp = temp[39] - (temp[0] + (40 * temp_avarage))
percentValue2_temp = temp[79] - (temp[0] + (80 * temp_avarage))
percentValue3_temp = temp[119] - (temp[0] + (120 * temp_avarage))
temp_percentValue1_= ((percentValue1_temp / temp[39]) + (percentValue2_temp / temp[79]) + (percentValue3_temp / temp[119]) / 3)
percentValue1_rounded_temp = round(temp_percentValue1_, 4)

print("After {} meters the temperature is: {} C".format(user_input, temppos1))

for element in range(len(splitnewline)):
	if(0 <= element <= 120):
		sumhumid += (humid[element+1] - humid[element])
		counterhumid += 1
humid_avarage = sumhumid/counterhumid 
humidpos1 = humid[0]

for increment in range(int_pip_round):
	humidpos1 += humid_avarage

print("After {} meters the humidity is: {} %".format(user_input, humidpos1))

for element in range(len(splitnewline)):
	if(0 <= element <= 120):
		sumUV += (UV[element+1] - UV[element])
		counterUv+= 1

UV_avarage = sumUV/counterUv 

UVpos1 = UV[0]

for increment in range(int_pip_round):
	UVpos1 += UV_avarage
print("After {} meters the UV - radiation is: {} %".format(user_input, UVpos1))

for element in range(len(splitnewline)):
	if(0 <= element <= 120):
		sumlong += (long[element+1] - long[element])
		counterLong += 1

Long_avarage = sumlong/counterLong 

Longpos1 = long[0]

for increment in range(int_pip_round):
	Longpos1 += Long_avarage
print("After {} meters the object will be at longetude {}".format(user_input, Longpos1))

for element in range(len(splitnewline)):
	if(0 <= element <= 120):
		sumlat += (lat[element+1] - lat[element])
		counterLat += 1

Lat_avarage = sumlat/counterLat

Latpos1 = lat[0]

for increment in range(int_pip_round):
	Latpos1 += Lat_avarage
print("After {} meters the object will be at latitude {}".format(user_input, Latpos1))

with open("data/output.txt", "w") as output_file:
	output_file.write("SATX HAPTIC V.1")
	output_file.write("\n")
	output_file.write("{}".format(today, current_time))
	output_file.write("\n")
	output_file.write("HEIGHT: {}".format(user_input))
	output_file.write("\n")
	output_file.write("Pressure: {} mPa".format(pressurepos1))
	output_file.write("\n")
	output_file.write("Temperature: {} C".format(temppos1))
	output_file.write("\n")
	output_file.write("Humidity: {} %".format(humidpos1))
	output_file.write("\n")
	output_file.write("UV - radiation: {} %".format(UVpos1))
	output_file.write("\n")
	output_file.write("Longitude: {}".format(Longpos1))
	output_file.write("\n")
	output_file.write("Latitude: {} ".format(Latpos1))
	output_file.write("\n")

print("\n")
print("Data is written into the file: {}".format(filename))









