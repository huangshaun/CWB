# CWB Library For ESP32

CWB (Central Weather Bureau) API library for ESP32.

This is first version for test.
Only weather week forecast for city each area.
CWB response data to more information, it will over default buffer size.
You need modify ESP32 library "HTTPClient.h" #define HTTP_TCP_BUFFER_SIZE xxxx.
Modify xxxx value to add buffer size

此為使用ESP32透過HTTP GET從中央氣象局API取得各縣市天氣預報
因為CWB回傳的資料非常多，其中包含中文
因此原先預設HTTP buffer size會不夠用
需要自行到ESP32 library "HTTPClient.h"內修改#define HTTP_TCP_BUFFER_SIZE xxxx
把xxxx位置數字改大一點

目前僅有各縣市天氣預報(一週或兩天)
會陸續增加功能，有興趣的人可以一起維護

## Install

[Download the latest library release.](https://github.com/huangshaun/CWB/releases/latest) Or [Use the Library Manager.](https://www.arduino.cc/en/Guide/Libraries#toc3)


## Examples

[Please see example code.](./examples)

