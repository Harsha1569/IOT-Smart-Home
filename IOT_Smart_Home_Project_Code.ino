#include "ThingSpeak.h"
#include "WiFiEsp.h"

char ssid[] = "HARSHA";   //  network SSID (name) 
char pass[] = "harsha@2001";   // network password
WiFiEspClient  client;

// Emulating Serial1/ESP8266 on pins 2/3 as hardware serial not present
#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial ESP8266(2, 3); // RX, TX
#define ESP_BAUDRATE  19200
#else
#define ESP_BAUDRATE  115200
#endif

// Smart Home channel details
unsigned long smartHomeChannelNumber = 1080943;
const char * channelReadAPIKey = "PR2AL6TNFMEWMQYM";
unsigned int relayStatusFieldNumber = 1; 

int relaypin = 7;

void setup() {
 //Initialize serial and wait for port to open
  Serial.begin(9600);  
  
  // initialize serial for ESP module  
  setEspBaudRate(ESP_BAUDRATE);

  while (!Serial) {
    ; // wait for serial port to connect. 
  }

  Serial.print("Searching for ESP8266..."); 
  // initialize ESP module
  WiFi.init(&ESP8266);
    
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  pinMode(relaypin,OUTPUT);  //connected to S terminal of relay
}

void loop() {

  int statusCode = 0;
  
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network.
      Serial.print(".");
      delay(2000);     
    } 
    Serial.println("\nConnected");
  }
  // Reading field 1(relaystatus) of the channel 
  int relaystatus = ThingSpeak.readLongField(smartHomeChannelNumber, relayStatusFieldNumber, channelReadAPIKey);  

   // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    Serial.println("Relaystatus: " + String(relaystatus));
    if(relaystatus==1){
      digitalWrite(relaypin,HIGH);  //turn relay on
    }
    else{
      digitalWrite(relaypin,LOW);  //turn relay off
    }
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }
  
  delay(2000); 
  
}

// This function attempts to set the ESP8266 baudrate.
void setEspBaudRate(unsigned long baudrate){
  long rates[6] = {115200,74880,57600,38400,19200,9600};

  Serial.print("Setting ESP8266 baudrate to ");
  Serial.print(baudrate);
  Serial.println("...");

  for(int i = 0; i < 6; i++){
    ESP8266.begin(rates[i]);
    delay(100);
    ESP8266.print("AT+UART_DEF=");
    ESP8266.print(baudrate);
    ESP8266.print(",8,1,0,0\r\n");
    delay(100);  
  }
    
  ESP8266.begin(baudrate);
}
