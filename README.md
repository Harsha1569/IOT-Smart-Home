IoT controlled smart home
Introduction:
This is a project utilizing the IOT (Internet of Things) Platform to send and receive data from cloud.
	Required Components:

1)	Arduino Uno with USB cable: Arduino Uno is a microcontroller board based on the ATmega328P (datasheet). It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz ceramic resonator (CSTCE16M0V53-R0), a USB connection, a power jack, an ICSP header and a reset button. Simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter or battery to get started. 
  
2)	ESP8266 (Wi-Fi module): The ESP8266 Wi-Fi Module is a self-contained SOC with integrated TCP/IP protocol stack that can give any microcontroller access to your Wi-Fi network. The ESP8266 is capable of either hosting an application or offloading all Wi-Fi networking functions from another application processor. Each ESP8266 module comes pre-programmed with an AT command set firmware, meaning, you can simply hook this up to your Arduino device and get about as much Wi-Fi-ability as a Wi-Fi Shield offers.   
               


 

3)	5v Relay (SRD-05VDC-SL-C): Relays are electric switches that use electromagnetism to convert small electrical stimuli into larger currents that occur when electrical inputs activate electromagnets to either form or break existing circuits. By leveraging weak inputs to power stronger currents, relays effectively act as either a switch or an amplifier for the electric circuit, depending on the desired application. The SRD-05VDC-SL-C relay has three high voltage terminals (NC, C, and NO), the other side has three low voltage pins (Ground, Vcc, and Signal). These are connected as follows:
•	NC: Normally closed 120-240V terminal
•	NO: Normally open 120-240V terminal
•	C: Common terminal
•	Ground: Connects to the ground pin on the Arduino
•	5V Vcc: Connects the Arduino’s 5V pin
•	Signal: Carries the trigger signal from the Arduino that activates the relay

                                                                            

4)	230v bulb along with holder
5)	Wires
6)	Jumper cables

	Soft-wares and online platforms used:

1)	Arduino I.D.E: The open-source Arduino Software (IDE) makes it easy to write code and upload it to the Arduino Uno board. It runs on Windows, Mac OS X, and Linux. The environment is written in Java and based on Processing and other open-source software.

2)	Fritzing: Fritzing is an open-source hardware initiative that makes electronics accessible as a creative material for anyone. It offers a software tool, a community website and services in the spirit of Processing and Arduino, fostering a creative ecosystem that allows users to document their prototypes, layout and manufacture professional PCBs, emulate and simulate microcontroller circuits and create schematic representations of the projects.

3)	ThingSpeak.com: ThingSpeak is an IoT analytics platform service that allows you to aggregate, visualize, and analyze live data streams in the cloud. You can send data to ThingSpeak from your devices, create instant visualization of live data, and send alerts. One can collect data sensor data privately to cloud, analyze and visualize the data with MATLAB and finally act in response to the collected data by triggering a reaction. 

4)	IFTTT.com: IFTTT (If This Then That) is a free platform that helps all your products and services (they are apps and devices that we use every day) work better together. It allows users to connect their services together to create new experiences. One can browse the thousands of connections created by the community or make their own. Each service has countless useful and creative ways to connect on IFTTT.
The objective of the project is to control a light bulb in our house using the above mentioned components along with the ThingSpeak and IFTTT platform. For instance if you say- “ok Google” Turn on the light” on our mobile phone from anywhere, this should result in the light bulb glowing. We can go about achieving the objective in a step wise manner.
	Step 1: 
•	Setup a Google assistant applet from IFTTT to trigger a web request which will update a field in ThingSpeak cloud. 
•	Here the IFTTT applet-1 sends a web request to the ThingSpeak platform that sets the field-1 value (that indicates the current status of the relay) of the “IOT smart home” channel using the read channel field URL to ‘1’. 
•	In order to turn of the bulb IFTTT applet-2 can be triggered to send a web request to the ThingSpeak platform that sets the field-1 value(that indicates the current status of the relay) of the “IOT smart home” channel using the read channel field URL to ‘0’.
•	Given below are the 2 IFTTT applets used to create this project along with the description of the services. Here “The Google Assistant” service on your phone is used to invoke a web request through the service “Webhooks” to connect to the ThingSpeak Cloud. 




	
                          

       
	Step 2: Then the data from field-1 can be read from the ThingSpeak cloud using Arduino to control the output of the relay. The ESP8266 Wi-Fi-Module connections with the Arduino are as follows:
Pins on ESP8266	Pins on Arduino Uno
Vcc	3.3V
Channel_enable	5V
Rx pin	Digital pin 3
Tx pin	Digital pin 2
GND pin	GND pin
The connections of the 5V relay with the Arduino are as follows:
Pins on 5V Relay	Pins on Arduino Uno
Vcc	5V
GND pin	GND pin
Signal pin	Digital pin 7
       Relay connections when relay status = ‘1’
NO ( Normally Open)	Shorted internally
Common pin	
NC ( Normally Closed)	None
        Relay connections when relay status = ‘0’
NC ( Normally Closed)	Shorted internally
Common pin	
NO ( Normally Open)	None
Externally the NO (normally open) pin of the relay is connected to one of the lead    from the bulb, Common pin of the relay is connected to the positive terminal of the power supply while the other lead from the bulb is connected to the negative terminal of the power supply.
  


