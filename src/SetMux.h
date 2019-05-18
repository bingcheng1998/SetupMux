#ifndef SETMUX_h
#define SETMUX_h

#include "Arduino.h"
//boot with CD74HC4067

extern int _g_channel_truth_table[16][4];

class SetMux
{
public:
	SetMux(int s0, int s1, int s2, int s3, int size = 16; int en = -1); 
	//初始化，设置引脚
	void begin(); //启动
	void printDebug(); //打印所有信息
	void disable(); //关闭mux
	void next(); //下一个端口
	void last(); //上一个端口
	void channel(int channel);
	int current(); //现在端口是多少查询
protected:
	int _size;
  	int _s0;
  	int _s1;
  	int _s2;
  	int _s3;
	int _en;
	int _channel;
};


#endif