# SetMux

> ## [Muxing Around With The CD74HC4067 + Arduino](http://bildr.org/2011/02/cd74hc4067-arduino/)
>
> Have you ever found yourself running out of pins to read an array of analog sensors? Don’t worry, you’re not alone, it happens to the best of us, and there is something you can do about it. An [analog](http://wiki.bildr.org/index.php/analog) / [digital](http://wiki.bildr.org/index.php/digital) [multiplexer](http://wiki.bildr.org/index.php/multiplexer) like the [CD74HC4067](http://wiki.bildr.org/index.php/CD74HC4067) ([mux](http://wiki.bildr.org/index.php/mux) for short) can help multiply the amount of pins you have, and it is insanely easy to connect to your arduino or other [microcontroller](http://wiki.bildr.org/index.php/microcontroller)

The schematic may seem complicated, but it is not. Not at all. And to prove it, look at the version on the left with out the pots; Much easier, right? The potentiometers are just connected with to [ground](http://wiki.bildr.org/index.php/ground) and 5v, and the middle pin connected to one of the 16 channels on the CD74HC4067. 16 pots is just enough to make anything look scary little scary. Also of note is the EN, or enable, pin. The EN pin is a kill switch: pull it up to 5v to disable all channels, and ground it to enable them. Im just going to leave it at ground so we can use it and simplify things, but feel free to connect it to a digital pin, and control when the mux is enabled or disabled.

![](http://ww3.sinaimg.cn/large/006tNc79ly1g35nkrsvasj30qe08c750.jpg)

Connect the four control pins to any unused digital or analog pins.

Connect the common pin to any other available pin. This is the pin that will be shared between the 16 channels of the CD74HC4067. The 16 channels will inherit the capabilties of the common pin. For example, if it's connected to an anolog pin, you will be able to use analogRead on each of the 16 channels.

![](http://ww4.sinaimg.cn/large/006tNc79ly1g35nklvlswj30sg0d83zn.jpg)

![](http://ww1.sinaimg.cn/large/006tNc79ly1g35nlswskqj30sg0f4dhb.jpg)



use the library by adding

```c
#include <SetMux.h>
```

to the top of your program.

Create a new CD74HC4067 object, specifying the control pins, s0 s1, s2, s3.

```c
SetMux my_mux(4, 5, 6, 7); 
```

or

```c
SetMux my_mux(4, 5, 6, 7, 5, 8);
```



Set the channel using the .channel() function

```c
my_mux.channel(8);
```



### Example

```c
#include <SetMux.h>

               // s0 s1 s2 s3 #size en
SetMux my_mux(4, 5, 6, 7, 5, 8);  // create a new CD74HC4067 object with its four control pins

const int g_common_pin = A0; // select a pin to share with the 16 channels of the CD74HC4067

void setup()
{
    pinMode(g_common_pin, OUTPUT); // set the initial mode of the common pin.
	                               // This can be changed in loop() for for each channel.
    my_mux.disable();
    my_mux.printDebug();
}

void loop()
{
    digitalWrite(g_common_pin, HIGH);
    my_mux.begin();
    while(true){
    	my_mux.next();
    	my_mux.printDebug();
    	delay(500);
    }
}
```

