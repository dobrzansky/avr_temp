/*
 * main.h
 *
 *  Created on: 02-05-2013
 *      Author: michal.dobrzanski
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#define DS	PB2
#define ANODY_DDR DDRB
#define ANODY_PORT PORTB
#define AN1 (1<<PB1)
#define AN2 (1<<PB0)
#define KATODY_DDR DDRA
#define KATODY_PORT PORTA
#define A (1<<PA1)
#define B (1<<PA2)
#define C (1<<PA3)
#define D (1<<PA4)
#define E (1<<PA5)
#define F (1<<PA6)
#define G (1<<PA7)
#define H (1<<PA0)


const uint8_t znaki [] PROGMEM = {
		A|B|C|D|E|F,//0
		B|C,		//1
		A|B|G|E|D,	//2
		A|B|C|D|G,	//3
		B|C|F|G,	//4
		A|C|D|F|G,	//5
		A|C|D|E|F|G,//6
		A|B|C,		//7
		A|B|C|D|E|F|G,//8
		A|B|C|D|F|G,//9
		A|B|C|E|F|G,//A
		C|D|E|F|G,	//B
		D|E|G,		//C
		B|C|D|E|G,	//F
		A|D|E|F|G,	//E
		A|E|F|G,	//F
		H, //PRZECINEK
		G|H, //PZECINEK i MINUS

};

void dispDigit(uint8_t);
void spij(void);

#endif /* MAIN_H_ */
