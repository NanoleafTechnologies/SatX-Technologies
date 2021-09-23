//SatX (2020)
//Modified code for reciverer @ ground station. 

#include <Cansat_RFM96.h>
#define USE_SD 0

const int freq = 433500;

Cansat_RFM96 rfm96(433500, USE_SD);

unsigned long time_counter=0;

const int piezo = 3;
const int greenled = 24;

int last_RSSI_value_in_dBm = rfm96.last_RSSI();

void setup() {
 Serial.begin(9600);
 while(!Serial);
 pinMode(greenled, OUTPUT);
 Serial.print("SatX Tropos Reciever...");
 Serial.println("Starting setup");
 Serial.println();

 if (!rfm96.init()) {
 Serial.println("Init of radio failed, stopping");
 while(1);
 }
 Serial.println("Found RFM96 radio, and it is working as expected");
 Serial.println();
 Serial.print("Frequency: ");
 Serial.print(freq);
 Serial.print(" Hz");
 Serial.println();
 Serial.print("Signal strenght: ");
 Serial.print(last_RSSI_value_in_dBm);
 Serial.println();
 tone(piezo, 2000, 50);
 delay(70);
 tone(piezo, 2000, 50);
 rfm96.setTxPower(5); // 
 Serial.println("End of setup");
 Serial.println();
 delay(2000);
}


void loop() {
 uint8_t read_value;
 while (rfm96.available()) {
 time_counter = millis();
 read_value = rfm96.read();
 Serial.write(read_value);
 tone(piezo, 2000, 50);
 }
 if (millis()-time_counter > 5000) {
 time_counter = millis();
 Serial.println("We have not received anything in 5 seconds");
 Serial.println();
 Serial.println(last_RSSI_value_in_dBm);
 tone(piezo, 500, 1000);
 //digitalWrite(greenled, LOW);
 }
}
