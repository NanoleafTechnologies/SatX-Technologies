import matplotlib.pyplot as plt

lat = []
long = []
pressure = []
humid = []
temp = []
UV = []
time = []

with open("./Dataset/data.csv") as datafile:
    holder = datafile.read()

replaced = holder.replace(',', '.')
split = replaced.split(' ')
for element in split:
    removed = element.replace("\t", " ").strip()

splitnewline = removed.split('\n')

#adds lattirude coordiantes to lat list after converted to float
for element in range(len(splitnewline)):
    integer = splitnewline[element][:9]
    converted = float(integer)
    lat.append(converted)

#long coordiantes to long list after converted to float
for element in range(len(splitnewline)):
    integer = splitnewline[element][10:19]
    converted = float(integer)
    long.append(converted)

#pressure
for element in range(len(splitnewline)):
    integer = splitnewline[element][19:28]
    integer.strip()
    converted = float(integer)
    pressure.append(converted)

#humidity
for element in range(len(splitnewline)):
    integer = splitnewline[element][28:34]
    integer.strip()
    converted = float(integer)
    humid.append(converted)

#temperature
for element in range(len(splitnewline)):
    integer = splitnewline[element][34:40]
    integer.strip()
    converted = float(integer)
    temp.append(converted)

#UV
for element in range(len(splitnewline)):
    integer = splitnewline[element][40:46]
    integer.strip()
    converted = float(integer)
    UV.append(converted)


#time
for element in range(len(splitnewline)):
    integer = splitnewline[element][-5:]
    integer.strip()
    converted = float(integer)
    time.append(converted)

user_input = input("""What do you want to display? 
1. Temperature (A) 
2. Humiditiy (B) 
3. Pressure (C) 
4. UV radiation (D)
5. Latitude coordinates (E) 
6. Longitude coordinates (F)

INPUT: """)

if (user_input == "A"):
    x = time
    y = temp
    plt.plot(x, y)
    plt.xlabel('Time in seconds')
    plt.ylabel('Temperature in Celsius')
    plt.title('TEMPERATURE')
    plt.show()

elif (user_input == "B"):
    x = time
    y = humid
    plt.plot(x, y)
    plt.xlabel('Time in seconds')
    plt.ylabel('Humidity in %')
    plt.title('HUMIDITY')
    plt.show()

elif (user_input == "C"):
    x = time
    y = pressure
    plt.plot(x, y)
    plt.xlabel('Time in seconds')
    plt.ylabel('Pressure (cBar)')
    plt.title('PRESSURE')
    plt.show()

elif (user_input == "D"):
    x = time
    y = UV
    plt.plot(x, y)
    plt.xlabel('Time in seconds')
    plt.ylabel('UV - radiation')
    plt.title('UV - radiation')
    plt.show()

elif (user_input == "E"):
    x = time
    y = lat
    plt.plot(x, y)
    plt.xlabel('Time in seconds')
    plt.ylabel('Lattitude coordinates')
    plt.title('LATTITUDE COORDINATES')
    plt.show()

elif (user_input == "F"):
    x = time
    y = long
    plt.plot(x, y)
    plt.xlabel('Time in seconds')
    plt.ylabel('Longitude coordinates')
    plt.title('LONGITUDE COORDINATES')
    plt.show()

else:
    print("Input not eligible")









