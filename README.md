# MQTTforIOT-Internet-of-Things-
Tutorial MQTT using as communication protocol for IoT (Internet of Things)

# Device & Tools:
1. ESP8266/ESP32
2. Micro USB Cable
3. PC or Laptop/Notebook
4. Arduino IDE
5. Internet

# Instuction:
1. Start Arduino (Device and IDE)
   - when prot COM not detect, download and install driver CP210x_USB: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers
2. Add board ESP8266/ESP32:
   - add URL on Aditional Board Manager
     for ESP8266:http://arduino.esp8266.com/stable/package_esp8266com_index.json
	 ESP32	:https://dl.espressif.com/dl/package_esp32_index.json
4. Download & install library EspMQTTClient for Arduino
5. Download mosquitto broker
   - url: https://mosquitto.org/download/
6. Install mosquitto as service broker on spesific folder (Ex: C:\Program Files\mosquitto)
7. Running mosquitto: 
   - Type search windows-> Command Prompt-> Run as administration>
   - C:/> cd spesific folder> mosquitto> enter

   - Another command:
   	mosquitto    		= running mosquitto broker
   	mosquitto -v (-verbose) = see console messages
   	mosquitto -h 		= mosquitto command help
8. Download MQTT client (mqtt lens, mqtt fx, etc)
   - MQTT FX  : https://www.jensd.de/wordpress/?p=2746
   - MQTT Lens: https://chrome.google.com/webstore/detail/mqttlens/hemojaaeigabkbcookmlgmdigohjobjm?hl=id
   - MQTT X   : https://mqttx.app/
9. Install MQTT Client
10. Open, Configuration, and Connect to broker
   - OpenSource Broker: test.mosquitto.org, broker.emqx.io
   - LocalBroker: your IP Address (192.168.xxx.xxx)

If appear problem MQTT Client can't connected to LocalBroker:
- Check aditional file: libcrypto-1_1_x64.dll, & libssl-1_1_x64.dll
  	If not avalilable in folder Mosquitto, copy this file to spesific folder
  	Note 1: You can obtain these files by installing openssl using the files from URL: https://slproweb.com/products/Win32OpenSSL.html
  	Note 2: They are now included in the 1.5.8 install package
- Configure mosquitto.config: 
  	per_listener_settings [false]
  	allow_anonymous [true]
- Check windows service> find mosquitto broker> test start automatic or manual
- Port cascade: https://stackoverflow.com/questions/39632667/how-do-i-kill-the-process-currently-using-a-port-on-localhost-in-windows

11. Programming on Arduino IDE

   - Test Wifi Connection
   - Test MQTT Connection
   - Test Publish & Subscribe
   All program download in here:

12. Chek dummy data show on MQTT client

