#include <HTTPClient.h>
#include "ArduinoJson.h"
#include "CWB.h"
#include "CWBAPIStruct.h"

void CWB::Begin(char *apiKey)
{
	SetPrivateKey(apiKey);
	SetElementName();
}

bool CWB::AreaWeatherWeekForecast(WEATHER_FORECAST_DATA *data)
{
	bool httpResult;
	String resultJSON;
	
	//SetAPIID(cwbAPIID.newTaipeiWeekForecast);
  httpResult = HttpsPost(resultJSON);  

  if(httpResult == true)
  {
  	int jsonBufferSize = resultJSON.length() * 2;
  	if(jsonBufferSize > JSON_BUFFER_MAX_SIZE)
  	{
  		data->result = false;
  		data->discription = "Response JSON data over buffer max size!";
  		return false;
  	}
  	
  	DynamicJsonDocument doc(jsonBufferSize);
    DeserializationError error = deserializeJson(doc, resultJSON, DeserializationOption::NestingLimit(12));
    if (error)
    {
      //Serial.print(F("deserializeJson() failed: "));
      //Serial.println(error.f_str());
      
      data->result = false;
      data->discription = "deserializeJson() failed";
      return false;
    }
    
    JsonObject responseData = doc["records"]["locations"][0];
    JsonObject weatherData = responseData["location"][0]["weatherElement"][0];
    
		String apiID = responseData["dataid"];
		String locationName = responseData["location"][0]["locationName"];
		String latitude = responseData["location"][0]["lat"];
		String longitude = responseData["location"][0]["lon"];
		
		data->result = doc["success"];
		data->apiID = apiID;
		data->locationName = locationName;
		data->latitude = latitude;
		data->longitude = longitude;
		
		int i = 0;
		const char* weather_startTime;
		const char* weather_endTime;
		const char* weather_state;
		const char* weather_value;
		for(JsonObject weatherArray : weatherData["time"].as<JsonArray>())
		{
			weather_startTime = weatherArray["startTime"];
			weather_endTime = weatherArray["endTime"];
			weather_state = weatherArray["elementValue"][0]["value"];
			weather_value = weatherArray["elementValue"][1]["value"];
			
			data->wdata[i].startTime = weather_startTime;
			data->wdata[i].endTime = weather_endTime;
			data->wdata[i].state = weather_state;
			data->wdata[i].value = weather_value;
			
      i++;
		}	
		
		return true;
  }
  
  data->result = false;
  data->discription = "HTTP Get fail.";
  return false;
}

bool CWB::AreaWeather2DayForecast(WEATHER_FORECAST_DATA *data)
{
	
}

bool CWB::HttpsPost(String &resultJSON)
{
	HTTPClient http;
	
  String url = "https://";
  url += CWB_HOST;
  url += CWB_API_PATH;
  url += apiID;
  url += "?Authorization=";
  url += privateKey;
  url += "&format=";
  url += dataFormat;
  url += "&locationName=";
  url += locationName;
  url += "&elementName=";
  url += elementName;
	
	http.begin(url);
  int httpCode = http.GET();
	
	if (httpCode == 200) 
	{
		resultJSON = http.getString();
		//Serial.println(resultJSON);
		http.end();
		return true;
	}
	else 
	{
		resultJSON = "";
		
		http.end();
		return false;
	}
}



void CWB::SetPrivateKey(String apiKey)
{
	privateKey = apiKey;
}

void CWB::SetAPIID(String id)
{
	apiID = id;
}

void CWB::SetDataFormat(String type)
{
	dataFormat = type;
}

void CWB::SetLocationName(String location)
{
	locationName = location;
}

void CWB::SetElementName(String element)
{
	elementName = element;
}