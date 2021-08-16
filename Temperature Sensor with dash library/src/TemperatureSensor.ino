#include<ESP8266WiFi.h>

#include<ESP8266HTTPClient.h>

#include<ArduinoJson.h>

#include<ESPAsyncTCP.h>

#include<ESPAsyncWebServer.h>

#include<ESPDash.h>

 

AsyncWebServer server(80);

ESPDash dashboard(&server);

 

#define LM35pin A0

#define BAUDRATE 115200

 

Card temperature_card(&dashboard, TEMPERATURE_CARD, "Temprature", " °C");

Card humidity_card(&dashboard, HUMIDITY_CARD, "Humidity", " %");

Card my_card(&dashboard, GENERIC_CARD, "Temprature", " °Genric");

Card my_button(&dashboard, BUTTON_CARD, "Temprature", " Fire");

 

const char* ssid = "WSG-Mobilna pracownia";

const char* pass = "M0b1lnaPracown1a";

 

const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=";

const String my_location = "Bydgoszcz, PL";

const String key = "&APPID=668092ae28f7ca6aa922f9ecb11fbe7a";

 

char status;

String inputBuffer = "";

bool stringComplete = false;

 

const int capacity = JSON_OBJECT_SIZE(2);

StaticJsonDocument<1000> jsonDoc;

 

String weather_message;

long p_millis=0;

 

void setup() {

  // put your setup code here, to run once:

  Serial.begin(BAUDRATE);

  WiFi.begin(ssid, pass);

  //WiFi.mode(WIFI_AP);

  //WiFi.softAP(ssid, pass);

  //delay(1000);

  Serial.print("Connecting to WiFi ");

  while (WiFi.status() != WL_CONNECTED){

    delay(500);

    Serial.print(".");

  }

  Serial.println("\nConnected to the WiFi network ");

  Serial.print("IP");

  Serial.println(WiFi.localIP());

  //Serial.println(WiFi.softAPIP());

  server.begin();

  delay(500);

  String s = "DASH library";

  my_card.update(s);

  my_button.attachCallback([&](bool value){

    Serial.println("Button: " + String((value)?"true":"false"));

    my_button.update(value);

    dashboard.sendUpdates();

  });

  //Serial.println(WiFi.localIP());

  //serializeJson(jsonDoc, Serial);

}

 

HTTPClient http;

#define DELAY 5000

 

void loop() {

  // put your main code here, to run repeatedly:

  if(millis() - p_millis > DELAY){

    http.useHTTP10(true);

    http.begin((endpoint + my_location + key).c_str());

    int httpResponseCode = http.GET();

    Serial.print("Code:");

    Serial.println(httpResponseCode);

    if(httpResponseCode > 0){

      weather_message = http.getString();

      Serial.println(weather_message);

      DeserializationError error = deserializeJson(jsonDoc, weather_message);

      // Test if parsing succeeds.

      if (error) {

        Serial.print(F("deserializeJson() failed: "));

        Serial.println(error.f_str());

        return;

      }

      double temp = jsonDoc["main"]["temp"];

      double tempc = temp- 273.15;

      double feel_temp = jsonDoc["main"]["feels_like"];

      double feel_tempc =feel_temp- 273.15;

      double pressure = jsonDoc["main"]["pressure"];

      double humidity = jsonDoc["main"]["humidity"];

      double longitude = jsonDoc["coord"]["lon"];

      double  latitude = jsonDoc["coord"]["lat"];

      // Print values.

      Serial.print("Coordinate at Bydgoszcz, PL (long, lat): ");

      Serial.print(longitude);

      Serial.print(" , ");

      Serial.println(latitude);

      Serial.print("Temp in this location location: ");

      Serial.print(tempc);

      Serial.println(" ° Celcius");

      Serial.print("But the temperatue feels like: ");

      Serial.print(feel_tempc);

      Serial.println(" ° Celcius");

      Serial.print("Pressure at this location: ");

      Serial.print(pressure);

      Serial.println(" Pascal");

      Serial.print("Humudity at this location: ");

      Serial.print(humidity);

      Serial.println(" %");


      Serial.println();

      temperature_card.update((int)tempc);

      humidity_card.update((int)humidity);

      dashboard.sendUpdates();

    }

    http.end();

    p_millis = millis();

  }}
