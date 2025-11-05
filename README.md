# Home-Automation-ESP8266-Blynk
IoT-based home automation using NodeMCU (ESP8266), 2-channel relay, and Blynk app to control lights and fans via smartphone.
This project demonstrates how to control two electrical appliances (like a fan and light) using the NodeMCU ESP8266, 2-channel relay module, and Blynk IoT App.
It allows remote ON/OFF control from anywhere via the Internet.


Components Used :-

1.NodeMCU ESP8266

2.2-Channel Relay Module

3.12V Light / Fan

4.Power Supply (5V)

5.Jumper Wires

6.Blynk IoT Mobile App.




Circuit Diagram:-

1.D1 → Relay 1 (Light)

2.D2 → Relay 2 (Fan)

3.VCC → 5V

4.GND → GND

5.NO & COM → connected to the light/fan as per relay switching.




Code Explanation:-

The code connects the NodeMCU to your Wi-Fi and controls the two relays using Blynk virtual pins.

Function	Virtual Pin	Description
BLYNK_WRITE(V0)	V0	Controls Relay 1 (Light)
BLYNK_WRITE(V1)	V1	Controls Relay 2 (Fan).




Blynk App Setup:-

Open Blynk IoT App and create a new project.

Add-

Two Buttons

Button 1 → Virtual Pin V0

Button 2 → Virtual Pin V1

Set Button Mode: Switch

Paste your Blynk Auth Token into the code.





How to Use:-
Upload the code to NodeMCU using Arduino IDE.

Open Serial Monitor (115200 baud) to check Wi-Fi connection.

Open Blynk app → press button → relay toggles the light/fan.




