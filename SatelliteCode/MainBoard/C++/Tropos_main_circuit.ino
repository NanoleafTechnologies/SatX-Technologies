//SatX Tropos v.04 BASECODE
//Horten High School
//2020

//UV sensor I2C
#include <Wire.h>
#include <Adafruit_VEML6070.h>

Adafruit_VEML6070 uv = Adafruit_VEML6070();

//DHT sensor
#include <DHT.h>
#include <DHT_U.h>

#define dhtPin 7

DHT dht(dhtPin, DHT11);

//GPS libraries
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
///////////////////////////////////////////////////////////////////////////
// The GY91 reads the data from the GY91 module
#include <GY91.h>
#include <SD.h>
#include <SD_t3.h>

#include <Cansat_RFM96.h>
#define USE_SD 1

// Declare all variables
double temp, ax, ay, az, gx, gy, gz, mx, my, mz, VIN, pressure, read_temp_direct();
unsigned int counter=0;

// We need to make an instance of the two objects
GY91 gy91;
Cansat_RFM96 rfm96(433500, USE_SD);
///////////////////////////////////////////////////////////////////////////
static const int RXPin = 0, TXPin = 1;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

//CO2
SoftwareSerial mySerial(10, 11); // RX, TX
unsigned char hexdata[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
///////////////////////////////////////////////////////////////////////////// 

const int piezo = 29;

unsigned long time;
///////////////////////////////////////////////////////////////////////////
const int tempSen = A10;
float voltageTemp = 0;
float tempSenValue = 0;
float TemperatureOne = 0;


 void setup() {
Serial.begin(9600);
ss.begin(9600);
dht.begin();
uv.begin(VEML6070_1_T); 
tone(piezo, 2000, 50);

 if (!rfm96.init()) {
 rfm96.printlnToBuffer("Init of radio failed, stopping");
while(1);
}
if (!gy91.init()) {
 rfm96.printlnToBuffer("Could not initiate");
while(1);
}
rfm96.printlnToBuffer();
rfm96.printlnToBuffer("SatX Tropos GPS - ver.1.08");
rfm96.printlnToBuffer();
rfm96.printlnToBuffer("Date: 17.11.2020");
//rfm96.printlnToBuffer("___________________________________________________________________");
tone(piezo, 2500, 50);
delay(100);
rfm96.printlnToBuffer("GPS Status: OK "); 
//rfm96.printlnToBuffer("___________________________________________________________________");
tone(piezo, 2500, 50);
delay(100);
rfm96.printlnToBuffer("GY91 Status: OK ");
//rfm96.printlnToBuffer("___________________________________________________________________");
tone(piezo, 2500, 50);
delay(100);
rfm96.printlnToBuffer("RFM91 Status: OK ");
//rfm96.printlnToBuffer("___________________________________________________________________");
tone(piezo, 2500, 50);
delay(100);
rfm96.printlnToBuffer("All rights reserved (R)");
//rfm96.printlnToBuffer("___________________________________________________________________");
tone(piezo, 2500, 50);
delay(100);
rfm96.printlnToBuffer("SatX Tropos ready for takeoff...");
tone(piezo, 2500, 50);
delay(5000);

rfm96.sendAndWriteToFile();

}

 

void loop() {
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      // Latitude in degrees (double)
      //rfm96.printToBuffer("Latitude= "); 
      rfm96.printToBuffer(gps.location.lat(), 6);
      rfm96.printToBuffer(" ");    
      // Longitude in degrees (double)
      //rfm96.printToBuffer(" Longitude= "); 
      rfm96.printToBuffer(gps.location.lng(), 6);
      rfm96.printToBuffer(" "); 

      //rfm96.printToBuffer("Speed in m/s = ");
      rfm96.printToBuffer(gps.speed.mps());
      rfm96.printToBuffer(" ");

      //rfm96.printToBuffer("Altitude in meters = "); 
      rfm96.printToBuffer(gps.altitude.meters());
      rfm96.printToBuffer(" ");
      tone(piezo, 1000, 100);
      
      // Update the new pressure data
       pressure = gy91.readPressure();
       //rfm96.printToBuffer("Pressure: ");
       rfm96.printToBuffer(pressure / 1000);
       rfm96.printToBuffer(" ");

       //DHT 11 Humidity & temperature
       rfm96.printToBuffer(dht.readHumidity());
       //rfm96.printToBuffer(dht.readHumidity()/100);
       //rfm96.printToBuffer(" %");
       rfm96.printToBuffer(" ");
       rfm96.printToBuffer(dht.readTemperature());
       //rfm96.printToBuffer("C");
       rfm96.printToBuffer(" ");

       rfm96.printToBuffer(uv.readUV());
       rfm96.printToBuffer(" ");

       //CO2
       mySerial.write(hexdata,9);
       for(int i=0,j=0;i<9;i++)
       {
        if (mySerial.available()>0)
        {
           long hi,lo,CO2;
           int ch=mySerial.read();
          if(i==2){     hi=ch;   }   //High concentration
          if(i==3){     lo=ch;   }   //Low concentration
          if(i==8) {
            CO2=hi*256+lo;  //CO2 concentration
            //rfm96.printToBuffer("CO2 concentration: ");
            rfm96.printToBuffer(CO2);
            //rfm96.printToBuffer("ppm");
         }
        }
       }


       //Temperature
      
      tempSenValue = analogRead(tempSen);
      voltageTemp = (tempSenValue / 1024.0) * 5.0;
      rfm96.printToBuffer("Voltage: ");
      rfm96.printToBuffer(voltageTemp);
      rfm96.printToBuffer(" ");

      TemperatureOne = (voltageTemp - .5) * 10;
      rfm96.printToBuffer("Temperature: ");
      rfm96.printToBuffer(TemperatureOne);
      rfm96.printToBuffer(" ");
      rfm96.printlnToBuffer();
     
       
       //Update the new Gyro data
        gy91.read_gyro();
        
        gx = gy91.gx;
        gy = gy91.gy;
        gz = gy91.gz;

       //rfm96.printToBuffer("(G) - x: ");
      rfm96.printToBuffer(gx);
      rfm96.printToBuffer(" ");
      //rfm96.printToBuffer("G) - y: ");
      rfm96.printToBuffer(gy);
      rfm96.printToBuffer(" ");
      //rfm96.printToBuffer("G) - z: ");
      rfm96.printToBuffer(gz);
      rfm96.printToBuffer(" ");
      
      gy91.read_acc();
      
      ax = gy91.ax;
      ay = gy91.ay;
      az = gy91.az;
      
      //rfm96.printToBuffer("(A) - x: ");
      rfm96.printToBuffer(ax - 0.98 );
      rfm96.printToBuffer(" ");
      //rfm96.printToBuffer("(A) - y: ");
      rfm96.printToBuffer(ay - 0.04);
      rfm96.printToBuffer(" ");
      //rfm96.printToBuffer("(A) - z: ");
      rfm96.printToBuffer(az + 0.20);
      rfm96.printToBuffer(" ");
      

      gy91.read_mag();
      
      mx = gy91.mx;
      my = gy91.my;
      mz = gy91.mz;
      
      //Add data from mag to the buffer
      //rfm96.printToBuffer("(M) - x: ");
      rfm96.printToBuffer(mx);
      rfm96.printToBuffer(" ");
      //rfm96.printToBuffer("(M) - y: ");
      rfm96.printToBuffer(my);
      rfm96.printToBuffer(" ");
      //rfm96.printToBuffer("(M) - z: ");
      rfm96.printToBuffer(mz);
      rfm96.printToBuffer(" ");

      time = millis();
      rfm96.printToBuffer(time);
      rfm96.printlnToBuffer();

      rfm96.sendAndWriteToFile();
    }
  }    
}
