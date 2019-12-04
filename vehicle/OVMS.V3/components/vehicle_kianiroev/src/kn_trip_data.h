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
#ifndef __VEHICLE_KIA_TRIP_DATA_H__
#define __VEHICLE_KIA_TRIP_DATA_H__

class kn_TripData
{



public:
        kn_TripData(uint64_t timestring);
       ~kn_TripData();

private:
       typedef struct {
             uint64_t _timeStamp;
             float _Lat;
             float _Lng;
             float _Speed;
             int _Odo;
             int _Soc;
             float _Consumption;
       }Data;
       Data _dt;
       string _fileName;
public:
        void saveTrips();
        void SetData(uint64_t timeStamp, float Lat, float Lng, float Speed, int Odo, int Soc, float Consumption);
        void SetFilename(string fileName);


};
#endif
