/*
 Name:		mega_cap_I2Cslave.ino
 Created:	4/15/2018 8:43:27 PM
 Author:	jcats
*/

/*
Name:		mega_modi2c.ino
Created:	4/14/2018 2:20:30 PM
Author:	jcats
*/
#include <Wire\src\Wire.h>

char position_char[6];

// the setup function runs once when you press reset or power the board
void setup() {
	Wire.begin(2);
	Wire.onRequest(farewellTransmission);
}


// the loop function runs over and over again until power down or reset
void loop() {



}

void farewellTransmission()
{
	for (int i = 0; i < 6; i++)
	{
		Wire.write(position_char[i]);
	}
}





#include <CapacitiveSensor.h>
#include "capslide.h"

int outputPins[6] = { 2,3,4,5,6,7 };


int recvpins1[5] = { 22,24,26,28,30 };
int recvpins2[5] = { 23,25,27,29,31 };
int recvpins3[5] = { 32,34,36,38,40 };
int recvpins4[5] = { 33,35,37,39,41 };
int recvpins5[5] = { 42,44,46,48,50 };
int recvpins6[5] = { 43,45,47,49,51 };

int sendpin[6] = { 8,9,10,11,12,13 };



double position[6] = { 300, 300, 300, 300, 300, 300 };
double position_mem = 2.5;
double *position_ptr = &position_mem;
int range = 9000;
double curentposition = 1;

CapacitiveSensor Slide1[5] = {
	CapacitiveSensor(sendpin[0], recvpins1[0]),
	CapacitiveSensor(sendpin[0], recvpins1[1]),
	CapacitiveSensor(sendpin[0], recvpins1[2]),
	CapacitiveSensor(sendpin[0], recvpins1[3]),
	CapacitiveSensor(sendpin[0], recvpins1[4]),
};

CapacitiveSensor Slide2[5] = {
	CapacitiveSensor(sendpin[1], recvpins2[0]),
	CapacitiveSensor(sendpin[1], recvpins2[1]),
	CapacitiveSensor(sendpin[1], recvpins2[2]),
	CapacitiveSensor(sendpin[1], recvpins2[3]),
	CapacitiveSensor(sendpin[1], recvpins2[4]),
};

CapacitiveSensor Slide3[5] = {
	CapacitiveSensor(sendpin[2], recvpins3[0]),
	CapacitiveSensor(sendpin[2], recvpins3[1]),
	CapacitiveSensor(sendpin[2], recvpins3[2]),
	CapacitiveSensor(sendpin[2], recvpins3[3]),
	CapacitiveSensor(sendpin[2], recvpins3[4]),
};

CapacitiveSensor Slide4[5] = {
	CapacitiveSensor(sendpin[3], recvpins4[0]),
	CapacitiveSensor(sendpin[3], recvpins4[1]),
	CapacitiveSensor(sendpin[3], recvpins4[2]),
	CapacitiveSensor(sendpin[3], recvpins4[3]),
	CapacitiveSensor(sendpin[3], recvpins4[4]),
};

CapacitiveSensor Slide5[5] = {
	CapacitiveSensor(sendpin[4], recvpins5[0]),
	CapacitiveSensor(sendpin[4], recvpins5[1]),
	CapacitiveSensor(sendpin[4], recvpins5[2]),
	CapacitiveSensor(sendpin[4], recvpins5[3]),
	CapacitiveSensor(sendpin[4], recvpins5[4]),
};

CapacitiveSensor Slide6[5] = {
	CapacitiveSensor(sendpin[5], recvpins6[0]),
	CapacitiveSensor(sendpin[5], recvpins6[1]),
	CapacitiveSensor(sendpin[5], recvpins6[2]),
	CapacitiveSensor(sendpin[5], recvpins6[3]),
	CapacitiveSensor(sendpin[5], recvpins6[4]),
};

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(57600);

	Serial.println("hello");

	for (int i = 0; i <6; i++)	pinMode(outputPins[i], OUTPUT);
	;

}

// the loop function runs over and over again until power down or reset
void loop() {
	readSlider_debug(Slide1, outputPins[0], position[0], 800, 250, 15);// sending on one pin to 5 pads
																	   //long oldmilis = micros();
	delay(10);
	//delay(1);
	readSlider(Slide2, outputPins[1], position[1], 800, 250, 15);
	delay(10);
	readSlider(Slide3, outputPins[2], position[2], 1000, 250, 15);

	readSlider(Slide4, outputPins[3], position[3], 1000, 250);

	readSlider(Slide5, outputPins[4], position[4], 1000, 250);

	readSlider(Slide6, outputPins[5], position[5], 1000, 250);

	for (int i = 0; i < 3; i++)
	{
		Serial.println(position[i]);
	}
	Serial.println("next");
	delay(40);
}

