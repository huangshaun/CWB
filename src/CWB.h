#ifndef CWB_H
#define CWB_H

#include <Arduino.h>
#include "ArduinoJson.h"
#include "CWBAPIStruct.h"

#define CWB_HOST "opendata.cwb.gov.tw"
#define CWB_API_PATH "/api/v1/rest/datastore/"
#define JSON_BUFFER_MAX_SIZE 10240

class CWB
{
	private:
		//const char *cwbHost = "opendata.cwb.gov.tw";
		//const char *cwbAPIPath = "/api/v1/rest/datastore/";
		String apiID = "";
		String dataFormat = "";
		String locationName = "";
		String privateKey = "";
		String elementName = "";
		
	public:
		CWB_API_ID cwbAPIID;
		
		void Begin(char *apiKey);
		bool HttpsPost(String &resultJSON);
		bool AreaWeatherWeekForecast(WEATHER_FORECAST_DATA *data);
		bool AreaWeather2DayForecast(WEATHER_FORECAST_DATA *data);
		void SetPrivateKey(String apiKey);
		void SetAPIID(String id);
		void SetDataFormat(String type = "JSON");
		void SetLocationName(String location);
		void SetElementName(String element = "Wx");
};
#endif
/* END OF FILE */