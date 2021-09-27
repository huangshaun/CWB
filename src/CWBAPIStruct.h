#ifndef CWBAPIStruct_H
#define CWBAPIStruct_H

#include <Arduino.h>

typedef struct cwb_api_id
{
	String yilanCounty2DayForecast = "F-D0047-001";
	String yilanCountyWeekForecast = "F-D0047-003";
	String taoyuanCity2DayForecast = "F-D0047-005";
	String taoyuanCityWeekForecast = "F-D0047-007";
	String hsinchuCounty2DayForecast = "F-D0047-009";
	String hsinchuCountyWeekForecast = "F-D0047-011";
	String miaoliCounty2DayForecast = "F-D0047-013";
	String miaoliCountyWeekForecast = "F-D0047-015";
	String changhuaCounty2DayForecast = "F-D0047-017";
	String changhuaCountyWeekForecast = "F-D0047-019";
	String nantouCounty2DayForecast = "F-D0047-021";
	String nantouCountyWeekForecast = "F-D0047-023";
	String yunlinCounty2DayForecast = "F-D0047-025";
	String yunlinCountyWeekForecast = "F-D0047-027";
	String chiayiCounty2DayForecast = "F-D0047-029";
	String chiayiCountyWeekForecast = "F-D0047-031";
	String pingtungCounty2DayForecast = "F-D0047-033";
	String pingtungCountyWeekForecast = "F-D0047-035";
	String taitungCounty2DayForecast = "F-D0047-037";
	String taitungCountyWeekForecast = "F-D0047-039";
	String hualienCounty2DayForecast = "F-D0047-041";
	String hualienCountyWeekForecast = "F-D0047-043";
	String penghuCounty2DayForecast = "F-D0047-045";
	String penghuCountyWeekForecast = "F-D0047-047";
	String keelungCity2DayForecast = "F-D0047-049";
	String keelungCityWeekForecast = "F-D0047-051";
	String hsinchuCity2DayForecast = "F-D0047-053";
	String hsinchuCityWeekForecast = "F-D0047-055";
	String chiayiCity2DayForecast = "F-D0047-057";
	String chiayiCityWeekForecast = "F-D0047-059";
	String taipeiCity2DayForecast = "F-D0047-061";
	String taipeiCityWeekForecast = "F-D0047-063";
	String kaohsiungCity2DayForecast = "F-D0047-065";
	String kaohsiungCityWeekForecast = "F-D0047-067";
	String newTaipeiCity2DayForecast = "F-D0047-069";
	String newTaipeiCityWeekForecast = "F-D0047-071";
	String taichungCity2DayForecast = "F-D0047-073";
	String taichungCityWeekForecast = "F-D0047-075";
	String tainanCity2DayForecast = "F-D0047-077";
	String tainanCityWeekForecast = "F-D0047-079";
	String lienchiangCounty2DayForecast = "F-D0047-081";
	String lienchiangCountyWeekForecast = "F-D0047-083";
	String kinmenCounty2DayForecast = "F-D0047-085";
	String kinmenCountyWeekForecast = "F-D0047-087";
	String taiwan2DayForecast = "F-D0047-089";
	String taiwanWeekForecast = "F-D0047-091";
	String townshipForecast = "F-D0047-093";
}CWB_API_ID;

typedef struct weather_data
{
	String startTime;
	String endTime;
	String state;
	String value;
}WEATHER_DATA;

typedef struct weather_forecast_data
{
	bool result;
	String discription;
	String locationName;
	String apiID;
	String dataFormat;
	String elementName;
	String latitude;
	String longitude;
	WEATHER_DATA wdata[15];
}WEATHER_FORECAST_DATA;

#endif