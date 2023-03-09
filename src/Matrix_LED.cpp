#include "Matrix_LED.h"

MLED::MLED(uint8_t mled_intensity, uint8_t mled_mosi, uint8_t mled_sclk) {
	_mosi = mled_mosi;
	_sclk = mled_sclk;

	if (mled_intensity > 7) {
		_intensity = 7;
	} else {
		_intensity = mled_intensity;
	}

	pinMode(_mosi, OUTPUT);
	pinMode(_sclk, OUTPUT);
	
	digitalWrite(_mosi, HIGH);
	digitalWrite(_sclk, HIGH);
}

/* High level commands, for the user! */

void MLED::display() {
	for (uint8_t i = 0; i < 8; i++) {
		sendData(i, disBuffer[i]);

		digitalWrite(_mosi, LOW);
		digitalWrite(_sclk, LOW);
		digitalWrite(_sclk, HIGH);
		digitalWrite(_mosi, HIGH);
	}

	sendCommand(0x88 | _intensity);
}

void MLED::clear() {
	for (uint8_t i = 0; i < 8; i++) {
		disBuffer[i] = 0x00;
	}
}

void MLED::dot(uint8_t x, uint8_t y, bool draw) {
	x &= 0x07;
	y &= 0x07;

	if (draw) {
		disBuffer[y] |= (1 << x);
	} else {
		disBuffer[y] &= ~(1 << x);
	}
}

/* Low level data pushing commands */

void MLED::sendCommand(byte cmd) {
  digitalWrite(_mosi, LOW);
  send(cmd);
  digitalWrite(_mosi, HIGH);
}

void MLED::sendData(byte address, byte data) {
  sendCommand(0x44);
  digitalWrite(_mosi, LOW);
  send(0xC0 | address);
  send(data);
  digitalWrite(_mosi, HIGH);
}

void MLED::send(byte data) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(_sclk, LOW);
    digitalWrite(_mosi, data & 1 ? HIGH : LOW);
    data >>= 1;
    digitalWrite(_sclk, HIGH);
  }
}