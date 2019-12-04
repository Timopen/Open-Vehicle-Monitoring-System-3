/*
;    Project:       Open Vehicle Monitor System
;    Date:          4th October 2019
;
;    (C) 2019       Timo Penttilä (timo.penttila@codetap.se)
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
*/
#include "vehicle_kianiroev.h"
#include "kia_common.h"
#include "kn_trip_Data.h"


 kn_TripData::kn_TripData(uint64_t timestring)
 {
   char ch_timestring[21]; // enough to hold all numbers up to 64-bits
   sprintf(ch_timestring, "%llu", timestring);
    this->_fileName = "/sd/Trip/TripData" + string(ch_timestring) + ".dat";
 }
  kn_TripData::~kn_TripData()
 {

 }

 void kn_TripData::SetData(uint64_t timeStamp, float Lat, float Lng, float Speed, int Odo, int Soc, float Consumption)
 {
   this->_dt = { timeStamp,  Lat,  Lng,  Speed,  Odo,  Soc,  Consumption};
 }

 void kn_TripData::SetFilename(string fileName)
 {
   this->_fileName = fileName;
 }

  void kn_TripData::saveTrips()
	{
	FILE *sf = NULL;
	sf = fopen(_fileName.c_str(), "a");
	if (sf == NULL)
		{
		return;
		}

	fprintf(sf, "{\"timeStamp\":\"%llu\",\"Lat\":\"%.7f\",\"Lng\":\"%.7f\",\"Speed\":\"%.1f\",\"Odo\":\"%6u\",\"Soc\":\"%3u\",\"Consumption\":\"%.1f\"},",this->_dt._timeStamp, this->_dt._Lat,this->_dt._Lng,this->_dt._Speed,this->_dt._Odo,this->_dt._Soc,this->_dt._Consumption);

	fclose(sf);

}
