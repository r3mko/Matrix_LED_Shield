#ifndef Matrix_LED_H
#define Matrix_LED_H

#include <Arduino.h>

#define MLED_MOSI 13
#define MLED_SCLK 14

class MLED {
public:
	MLED(uint8_t mled_intensity, uint8_t mled_mosi = MLED_MOSI, uint8_t mled_sclk = MLED_SCLK);
	void display();
	void clear();
	void dot(uint8_t x, uint8_t y, bool draw = 1);
	volatile uint8_t disBuffer[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

private:
	void sendCommand(byte led);
	void sendData(byte add, byte data);
	void send(byte data);
	uint8_t _mosi;
	uint8_t _sclk;
	uint8_t _intensity;
};

#endif