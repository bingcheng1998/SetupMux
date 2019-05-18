#include <SetMux.h>

               // s0 s1 s2 s3
SetMux my_mux(4, 5, 6, 7);  // create a new CD74HC4067 object with its four control pins

const int g_common_pin = A0; // select a pin to share with the 16 channels of the CD74HC4067

void setup()
{
    pinMode(g_common_pin, OUTPUT); // set the initial mode of the common pin.
	                               // This can be changed in loop() for for each channel.
}

void loop()
{
    digitalWrite(g_common_pin, HIGH);
    while(true){
    	my_mux.next();
    	delay(500);
    }
}
