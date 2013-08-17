/*
 * main.c
 *
 *  Created on: 02-05-2013
 *      Author: michal.dobrzanski
 */

#include "main.h"
#include "1Wire/ds18x20.h"
#include <avr/sleep.h>

uint8_t czujniki_cnt;		/* iloœæ czujników na magistrali */
uint8_t subzero;		//wyniki pomiaru
volatile uint8_t _temp = 0;
uint8_t _tempDecimal = 0;

int main (void) {
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_enable();
	TCCR0A |= (1<<WGM01); //CTC
	TCCR0B |= (1<<CS01)|(1<<CS00); // preskaler 64
	TIMSK0 |= (1<<OCIE0A);  //enable Interupt
	OCR0A = 80;
	KATODY_DDR=0xFF;
	sei();
	ANODY_DDR |= AN1 | AN2;
	while (1){
		czujniki_cnt = search_sensors();
		_delay_ms(50);
		DS18X20_start_meas( DS18X20_POWER_PARASITE, 0 );
		_delay_ms(750);
		if( DS18X20_OK == DS18X20_read_meas(gSensorIDs[0], &subzero, &_temp, &_tempDecimal) )
		{
			_delay_ms(3000);
			if (!subzero) _temp = _tempDecimal+160;
			else _temp = _tempDecimal+170;
			_delay_ms(3000);
			spij();
		}
		else dispDigit(14);
	}

}

ISR(TIM0_COMPA_vect){   //przerzuca anody
	static uint8_t _digit_num = 1;
	ANODY_PORT |= AN1 | AN2;
	if (_digit_num == 1) {
		ANODY_PORT &= ~AN2;
		_delay_us(40);
		if (_temp < 10) {
			dispDigit(_temp);
		}
		else {
			dispDigit(_temp - (_temp/10)*10);
		}
		_digit_num++;
	}
	else {
		ANODY_PORT |= AN1 | AN2;
		ANODY_PORT &= ~AN1;
		dispDigit(_temp/10);
		_digit_num=1;
	}
}

void dispDigit(uint8_t cyfra) { //wyswietla cyfre 0::F
	KATODY_PORT = ~pgm_read_byte(&znaki[cyfra]);
}

void spij(){
	ANODY_PORT |= AN1 |AN2;
	KATODY_PORT = 0xFF;
	sleep_mode();
}


