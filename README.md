# SatX Technologies 

### _Full Project_

![Vertical SatX Technologies Logo with Flag](/Images/SatX-Technologies-logo.png)

SatX Technologies is a research project consisting of five high school students enrolled in a STEM specific honours program in Horten, Norway. We develop mini - satellites to retrieve data from the atmosphere and software to analyze the data afterwards. This repo consists of all of the files used in our project and the files submitted to [The European Space Agency](https://www.esa.int/) for the 2021 European CanSat Finals. 

1.  Project overview
2.  Satellite design
3. Satellite & Receiver code
4.  Data analyzation tools
    * SatX Fire
    * SatX Haptic
    * SatX Plot
5.  SatX Cloud
6.  Datasets
    * Borrehaugene
    * Slottsfjell
7. Additional Info

## Project overview

The main goal of the project is to reduce climate change and human environmental impact with the use of modern technology. We have developed an advanced mini - satellite, software for data analyzing, in addition to a website and a data-sharing application. When launched, the mini satellite retrieves data such as temperature, pressure, humidity and more, in addition to GPS - signal and camera footage, writes the data onto an two separate sd-cards and sends the data towards a self-developed ground station using radio transmission, where the data can be displayed live through a computer terminal. 

The data retrieved during flight can be further analyzed. Using SatX Fire, the risk of wildfire can be calculated and mapped using GPS - coordinates and camera footage in order to determine the chances of a significant wildefire in the area and where the risk is the greatest. Further the data can be visually displayed using SatX Plot, which automatically detects .csv and .txt files and draws graphs using one single user command. The graphs can be downloaded into .jpg format. 

Our latest inventions are SatX Haptic and SatX Cloud. Haptic is a model which uses regression to calculate data at a higher elevation based on already retrieved data, meaning the user of the program can calculate retrieved parameters such as temperature and pressure at the height of 80 meters, while the satellite was launched at only 40 meters. Further the data retrieved, the data analyzed using Fire and Plot, in addition to the data calculated using Haptic can be published over the SatX Cloud application. The application is currently available over Google Play. 

For more information about the satellite, prerequisite softwares or about the team, please visit our website and read our final report! [/SatX_Technologies_Final_Report.pdf] 
[Our Website](http://satxnorway.com/)
[Contact Us!](mailto:satxnorway@gmail.com)
![Horisontal SatX Technologies Logo](/Images/SatX-Technologies-horisontal-logo.png)

## Tropos Design
The .stl, .obj, .glb and .svg files for the satellite design can be found in the design folder of this repository. These files are needed in order to 3D - print the satellite's inner and outer shell. These shells are used to mount and protect the components within the satellite. For more information about the components used in the satellite, please refer to our final report. [/SatX_Technologies_Final_Report.pdf] 


## Satellite Code
The code for the satellite itself can be found in the folder /SatelliteCode in this repo. There are three files, each for the three main modules of the satellite. 
1.Satellite on-board unit
2.Ground station unit
3.On-board Camera Unit

The code must be compiled using a .ino compiler such as the Arduino IDE before uploading.

## Data Analyzation Tools
The data analyzation tools are used for analyzing the data retrieved from the satellite while in-air or after a lanuch. 
| Tool | Folder |
| ------ | ------ |
| SatX Fire | [SatxFire/C++/main.cpp] |
| SatX Haptic | [SatxHaptic/python/script.py]|
| SatX Plot | [SatxPlot/python/script.py] |

### SatX Fire
SatX Fire is used to determine the risk of wildfire in the area in which the satellite has flown over. Fire takes the amount of rain from the last 7 days as input, the current temperature and humidity data. The program outputs a scale between 1 and 4, indicating the risk of wildfire in the specific area. 


### SatX Haptic
SatX Haptic uses regression to calculate data at a higher altitude using already retrieved data. The program automatically detects files in the project folder when run and asks for a user specified height as input. It further writes the calculated data onto a .txt file. /output.txt

```sh
python script.py
```

```sh
INPUT: <user input>
```
```sh
Data is written into the file: output.txt
```

### SatX Plot
SatX Plot is a data visualization tool in which detects .csv or .txt files in its repo and asks for a user input based on what type of data the user wants to display. Further the software generates a graph which can be downloaded into an .jpg for further analysis.

```sh
python script.py
```

```sh
What do you want to display? 
1. Temperature (A) 
2. Humiditiy (B) 
3. Pressure (C) 
4. UV radiation (D)
5. Latitude coordinates (E) 
6. Longitude coordinates (F)

INPUT:
```

## SatX Cloud
SatX Cloud is our latest platform for data sharing. Users can view and download retrieved data from the application and use the data for personal or commercial use. As of now, we are working on further developments for data sharing for the users and implementing the application into app store.  

You can download the application on Google Play by following the link below
[SatX Cloud](https://play.google.com/store/apps/details?id=com.gmail.satxnorway.satx10&gl=NO)

## Datasets
The datasets included in this repo is available both for private and commercial use

##### Borrehaugene, Horten
First official launch done at Borrehaugene, Horten in Norway the 24.11.2020

##### Slottsfjell, Tonsberg
The second official launch done at Slottsfjell, Tonsberg in Norway the 03.01.2021


## Additional Information

- We encourage you to read our final report to learn more about the project! [/SatX_Technologies_Final_Report.pdf]
- Feel free to contact us over mail or by using our contact section on our [website](http://satxnorway.com/)
- Follow us on [Instagram](https://www.instagram.com/satx_norway/) in order to get updates about the project and the European CanSat Competition 2021.






