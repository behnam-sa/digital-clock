﻿#include <avr/io.h>
#include <util/delay.h>

#include "text.hpp"
#include "keypad.hpp"
#include "timer0.hpp"
#include "timer2.hpp"

int main(void)
{
	i2c.Initialize();
	keypad.Initialize();
	seven_segment.Initialize();
	seven_segment.SetData(1, 2, 3, 4, true);
	timer0.Initialize();
	timer2.Initialize();
	
	uint8_t img[3][3] = {{0xaa, 0x55, 0xaa}, {8, 0, 8}, {0xaa, 0x55, 0xaa}};
	
	display.Initialize(true);
	display.Draw((uint8_t*)img, 3, 3);
	display.Draw((uint8_t*)img, 3, 3);
	
	text.PrintProgMem(PSTR("Hello!\nTesting\t\a1\a234\b\bab"), true);
	
	text.GoToXY(3, 5);
	text.Print("Hello!\nTesting\t1234\b\aab\a");
	
	text.GoToXY(6, 0);
	
	sei();
	
	while (1)
	{
		timer2.TurnOn();
		_delay_ms(80);
		timer2.TurnOff();
		_delay_ms(80);
		timer2.TurnOn();
		_delay_ms(80);
		timer2.TurnOff();
		_delay_ms(80);
		timer2.TurnOn();
		_delay_ms(80);
		timer2.TurnOff();
		_delay_ms(80);
		timer2.TurnOn();
		_delay_ms(80);
		timer2.TurnOff();
		_delay_ms(440);
	}
	
	/* Replace with your application code */
	while (1)
	{
		_delay_ms(200);
		Key key = keypad.GetKeyPress();
		if (key != Key::None)
		text.Print('0' + (uint8_t)key);
	}
}

