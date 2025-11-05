/*************************************************************
   ESP8266 + 2-Channel Relay Control via Blynk
   ---------------------------------------------
   - Control two relays (like fan & light)
   - Relay 1 → Virtual Pin V0
   - Relay 2 → Virtual Pin V1
   - Shows device uptime on V2 (optional)
 *************************************************************/

#define BLYNK_TEMPLATE_ID "TMPL3Avf2qAVq"
#define BLYNK_TEMPLATE_NAME "Quickstart Device"
#define BLYNK_AUTH_TOKEN   "daB6hsfY2pIeCxn3iPIRI1WBItJNkYRl"
 // Paste your actual token here

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "motorola edge 40";       // Your Wi-Fi SSID
char pass[] = "09871234";   // Your Wi-Fi Password

BlynkTimer timer;

// ✅ Define your relay pins (change if you used different ones)
#define RELAY1 D1
#define RELAY2 D2

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set relay pins as output
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  // Default OFF (HIGH means off for most relay modules)
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);

  // Optional: Send uptime to Blynk every second
  timer.setInterval(1000L, []() {
    Blynk.virtualWrite(V2, millis() / 1000);
  });
}

// 🔹 Relay 1 Control - from Button Widget on V0
BLYNK_WRITE(V0)
{
  int state = param.asInt();
  digitalWrite(RELAY1, state ? LOW : HIGH);  // LOW = ON, HIGH = OFF
  Serial.print("Relay 1 is ");
  Serial.println(state ? "ON" : "OFF");
}

// 🔹 Relay 2 Control - from Button Widget on V1
BLYNK_WRITE(V1)
{
  int state = param.asInt();
  digitalWrite(RELAY2, state ? LOW : HIGH);
  Serial.print("Relay 2 is ");
  Serial.println(state ? "ON" : "OFF");
}

void loop()
{
  Blynk.run();
  timer.run();
}
