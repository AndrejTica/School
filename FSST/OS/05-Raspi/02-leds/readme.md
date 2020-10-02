# Raspi - leds

> wiringPI has to be installed.


## which Pins? 

```bash
gpio readall
```

<pre>
 +-----+-----+---------+------+---+-Model B1-+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   0 |   8 |   SDA.1 |   IN | 1 |  3 || 4  |   |      | 5V      |     |     |
 |   1 |   9 |   SCL.1 |   IN | 1 |  5 || 6  |   |      | 0v      |     |     |
 |   4 |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | ALT0 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT0 | RxD     | 16  | 15  |
 |  17 |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | IN   | GPIO. 1 | 1   | 18  |
 |  21 |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |  22 |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | IN   | GPIO. 5 | 5   | 24  |
 |  10 |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   9 |  13 |    MISO |   IN | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |  11 |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | IN   | CE1     | 11  | 7   |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+-Model B1-+---+------+---------+-----+-----+
</pre>

Some example:
* Pin 1 3.3V
* Pin 2 5V
* Pin 4 5V
* Pin 6 0V GND
* Pin22 GPIO25
* Pin13 GPIO21


## blinking leds

Pin 4(5V) -> 220 Ohm -> Led -> Pin6(GND)

### use GPIO25 (Pin22) - wiringPI
```
gpio -g mode 25 out
gpio -g write 25 1
gpio -g write 25 0
```


### use GPIO25 (Pin22) - shell
```
cd /sys/class/gpio
echo 25 >export 
cd gpio25
echo out >direction 
echo 1 >value 
echo 0 >value 
```


### use GPIO25 (Pin22) - C
```c
// gpio25.c
// gcc gpio25.c -o gpio25.exe
// sudo ./gpio25.exe


#define GPIO_EXPORT "/sys/class/gpio/export"
#define GPIO_UNEXPORT "/sys/class/gpio/unexport"

#define GPIO25 "25"
#define GPIO25_VALUE "/sys/class/gpio/gpio25/value"
#define GPIO25_DIRECTION "/sys/class/gpio/gpio25/direction"


#include <stdio.h>

int main() {
    FILE *fp;

    //Configure GPIO25
    fp = fopen(GPIO_EXPORT, "w");
    fprintf(fp, GPIO25);
    fclose(fp);

    fp = fopen(GPIO25_DIRECTION, "w");
    fprintf(fp, "out");
    fclose(fp);


    while (1) {
            fp = fopen(GPIO25_VALUE, "w");
            fprintf(fp, "1");
            fclose(fp);

            sleep(1);

            fp = fopen(GPIO25_VALUE, "w");
            fprintf(fp, "0");
            fclose(fp);

            sleep(1);
    }

    //Clean up
    fp = fopen(GPIO_UNEXPORT, "w");
    fprintf(fp, GPIO25);
    fclose(fp);

    return 0;
}
```

### lab: A gpio module (gpio.c, gpio.h)
given is **gpio.h**
```c
int gpio_export(int gpioNumber, char* direction);
int gpio_unexport(int gpioNumber);
int gpio_set(int gpioNumber, int value);
```

write **gpio.c** and test with *blink25.c*
> hint: 
>	char filename[128+1];
>	sprintf(filename, "/sys/class/gpio/gpio%i/value", gpioNumber);



```c
// blink25.c
// gcc -c gpio.c
// gcc blink25.c gpio.o -o blink25.exe
// sudo ./blink25.exe
#include <stdio.h>
#include "gpio.h"

int main() {

    //Configure GPIO25
	gpio_export(25,"out");


    while (1) {
			gpio_set(25, 1);
            sleep(1);

			gpio_set(25, 0);
            sleep(1);
    }

    //Clean up
    gpio_unexport(25);

    return 0;
}
```

links:
* [blink] (http://www.it-adviser.net/raspberry-pi-gpio-pins-schalten/)
* [Pins] (http://www.elektronik-kompendium.de/sites/raspberry-pi/1907101.htm)




## gpio-traffic-lights

1. green (3 sec)
2. yellow (1.2 sec)
3. red (3. sec)
4. red+yellow (1.2 sec)
5. goto 1.


see below a simple C-programm which additionally checks user 
interrupts with control-c. In this case all GPIOs are
unexported correctly.
 
```
// traffic-light.c
// gcc traffic-light.c gpio.o -o traffic-light.exe
// sudo ./traffic-light.exe

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h> // usleep (microseconds)

#include <signal.h>	// check for ctrl+c

#include "gpio.h"

#define DURATION_LONG	3*1000*1000			// 3 sec
#define DURATION_SHORT	1.2*1000*1000		// 1.2 sec

#define RED		4		// Pin 7
#define YELLOW 18		// Pin 12
#define GREEN	25		// Pin 22


// if ctrl-C interrupts 
void cleanup(int signo){
	gpio_set(RED, 0);
	gpio_set(YELLOW, 0);
	gpio_set(GREEN, 0);

	gpio_unexport(RED);
	gpio_unexport(YELLOW);
	gpio_unexport(GREEN);
	exit(0);
}


int main() {

    //Configure
	signal(SIGINT, cleanup);	// Ctrl-C

	gpio_export(RED,"out");
	gpio_export(YELLOW,"out");
	gpio_export(GREEN,"out");

/*
green (2s)->yellow(0.5s)->red(2s)
red+yellow(0.5s) -> green(2s)
*/

    while (1) {
			//GREEN			
			gpio_set(RED, 0);
			gpio_set(YELLOW, 0);
			gpio_set(GREEN, 1);

			usleep(DURATION_LONG);


			//YELLOW			
			gpio_set(RED, 0);
			gpio_set(YELLOW, 1);
			gpio_set(GREEN, 0);

			usleep(DURATION_SHORT);	

			//RED			
			gpio_set(RED, 1);
			gpio_set(YELLOW, 0);
			gpio_set(GREEN, 0);
			
			usleep(DURATION_LONG);

			//RED+YELLOW			
			gpio_set(RED, 1);
			gpio_set(YELLOW, 1);
			gpio_set(GREEN, 0);
			
			usleep(DURATION_SHORT);	
    }

    //Clean up
	cleanup(SIGINT);

    return 0;
}
```


## lab: running-lights
**todo**

## lab: morse-code
[morse code] (https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/robot/morse_code/)

## lab: system-load
**todo**

