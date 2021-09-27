#include "CWB.h"
#include <WiFi.h>

// ===== Wifi setup =====
const char *ssid     = "your wifi ssid";
const char *password = "your wifi password";

CWB cwb;
void setup()
{
  Serial.begin(115200);
  delay(10);
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200); 
    Serial.print(".");
  }
  
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  cwb.Begin("your CWB API key");

  //you want run API ID like "F-D0047-059" 
  //or used CWBAPIStruct.h list like cwb.cwbAPIID.newTaipeiWeekForecast
  cwb.SetAPIID(cwb.cwbAPIID.newTaipeiWeekForecast);

  //like "中正區"
  cwb.SetLocationName("your location name");

  WEATHER_FORECAST_DATA week;
  bool result;
  result = cwb.AreaWeatherWeekForecast(&week);

  if(result)
  {
    Serial.println("========================");
    Serial.println(week.result);
    Serial.println(week.apiID);
    Serial.println(week.locationName);
    Serial.println(week.latitude);
    Serial.println(week.longitude);
    
    for(int i=0; i<15; i++)
    {
      Serial.println("------------------------");
      Serial.println(week.wdata[i].startTime);
      Serial.println(week.wdata[i].endTime);
      Serial.println(week.wdata[i].state);
      Serial.println(week.wdata[i].value);
    }
  }

  delay(5000);
}
