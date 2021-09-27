#ifndef CWB_H
#define CWB_H

#include <Arduino.h>
#include "ArduinoJson.h"
#include "CWBAPIStruct.h"

#define CWB_HOST "opendata.cwb.gov.tw"
#define CWB_API_PATH "/api/v1/rest/datastore/"
#define JSON_BUFFER_MAX_SIZE 15000

class CWB
{
	private:
		String apiID = "";
		String dataFormat = "";
		String locationName = "";
		String privateKey = "";
		String elementName = "";
		
	public:
		CWB_API_ID cwbAPIID;
		
		void Begin(char *apiKey);
		bool HttpsPost(String &resultJSON);
		bool AreaWeatherForecast(WEATHER_FORECAST_DATA *data);
		void SetPrivateKey(String apiKey);
		void SetAPIID(String id);
		void SetDataFormat(String type = "JSON");
		void SetLocationName(String location);
		void SetElementName(String element = "Wx");
};
#endif
/* END OF FILE */