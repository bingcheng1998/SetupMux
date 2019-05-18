/*
  Multiplexer.cpp - Library for using the CD74HC4067 multiplexer.
  April 18, 2016.
  LGPL 3.0
*/

#include "Arduino.h"
#include "SetMux.h"

int _g_channel_truth_table[16][4] = {
  // s0, s1, s2, s3     channel
    {0,  0,  0,  0}, // 0
    {1,  0,  0,  0}, // 1
    {0,  1,  0,  0}, // 2
    {1,  1,  0,  0}, // 3
    {0,  0,  1,  0}, // 4
    {1,  0,  1,  0}, // 5
    {0,  1,  1,  0}, // 6
    {1,  1,  1,  0}, // 7
    {0,  0,  0,  1}, // 8
    {1,  0,  0,  1}, // 9
    {0,  1,  0,  1}, // 10
    {1,  1,  0,  1}, // 11
    {0,  0,  1,  1}, // 12
    {1,  0,  1,  1}, // 13
    {0,  1,  1,  1}, // 14
    {1,  1,  1,  1}  // 15
};

SetMux::SetMux(int s0, int s1, int s2, int s3, int size, int en)
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  if (en != -1)
  {
  	pinMode(en, OUTPUT);
  }
  _en = en;
  _size = size;
  _s0 = s0;
  _s1 = s1;
  _s2 = s2;
  _s3 = s3;
}

void SetMux::begin()
{
	if (en != -1){
		digitalWrite(_en, LOW);
	}
}
void SetMux::printDebug()
{
	Serial.print('s0 = ');
	Serial.print(_s0);
	Serial.print(', s1 = ');
	Serial.print(_s1);
	Serial.print(', s2 = ');
	Serial.print(_s2);
	Serial.print(', s3 = ');
	Serial.print(_s3);
	Serial.print(', en = ');
	Serial.print(_en);
	Serial.print(', size = ');
	Serial.print(_size);
	Serial.print(', current channel = ');
	Serial.println(_channel);
}
void SetMux::disable()
{
	if (en != -1){
		digitalWrite(_en, HIGH);
	}
}
void SetMux::next(){
	_channel++;
	if (_channel > _size -1)
	{
		_channel = 0;
	}
	channel(_channel);
}
void SetMux::last(){
	_channel--;
	if (_channel < 1)
	{
		_channel = _size - 1;
	}
	channel(_channel);
}
int  SetMux::current(){
	return _channel;
}

void SetMux::channel(int channel)
{
  digitalWrite(_s0, _g_channel_truth_table[channel][0]);
  digitalWrite(_s1, _g_channel_truth_table[channel][1]);
  digitalWrite(_s2, _g_channel_truth_table[channel][2]);
  digitalWrite(_s3, _g_channel_truth_table[channel][3]);
}
