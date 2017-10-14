/*
 * Cube-Header.h
 *
 *  Created on: 09.08.2013
 *      Author: Jonas Löhdefink
 */

#define MAXPROG 		8				// Anzahl der Programme
#define nMax			60
#define ProgZeit		4000			// Programmwechsel alle 4000 * 5 ms = 20 s

void init(void);
void abbilden(unsigned long x);

/*unsigned char get_key_press( unsigned char key_mask );
unsigned char get_key_rpt( unsigned char key_mask );
unsigned char get_key_state( unsigned char key_mask );
unsigned char get_key_short( unsigned char key_mask );*/

extern unsigned char bild[3][3][3];

extern volatile unsigned char key_state;                               // debounced and inverted key state: // bit = 1: key pressed
extern volatile unsigned char key_press;                               // key press detect
extern volatile unsigned char key_rpt;                                 // key long press and repeat

#define S1		BIT0		//Port 1
#define S2		BIT1		//Port 1
#define S3		BIT2		//Port 1
#define S4		BIT4		//Port 1
#define S5		BIT5		//Port 1
#define S6		BIT0		//Port 2
#define S7		BIT1		//Port 2
#define S8		BIT2		//Port 2
#define S9		BIT3		//Port 2
#define E1		BIT4		//Port 2
#define E2		BIT6		//Port 1
#define E3		BIT5		//Port 2
#define BUTTON	BIT3		//Port 1

#define l1		BIT0		//LED 1
#define l2		BIT1		//LED 2
#define l3		BIT2		//LED 3
#define l4		BIT3		//LED 4
#define l5		BIT4		//LED 5
#define l6		BIT5		//LED 6
#define l7		BIT6		//LED 7
#define l8		BIT7		//LED 8
#define l9		BIT8		//LED 9
#define l10		BIT9		//LED 10
#define l11		BITA		//LED 11
#define l12		BITB		//LED 12
#define l13		BITC		//LED 13
#define l14		BITD		//LED 14
#define l15		BITE		//LED 15
#define l16		BITF		//LED 16
#define l17		(0x10000)		//LED 17
#define l18		(0x20000)		//LED 18
#define l19		(0x40000)		//LED 19
#define l20		(0x80000)		//LED 20
#define l21 	(0x100000)		//LED 21
#define l22		(0x200000)		//LED 22
#define l23 	(0x400000)		//LED 23
#define l24		(0x800000)		//LED 24
#define l25		(0x1000000)		//LED 25
#define l26		(0x2000000)	//LED 26
#define l27		(0x4000000)	//LED 27
#define lall	l1+l2+l3+l4+l5+l6+l7+l8+l9+l10+l11+l12+l13+l14+l15+l16+l17+l18+l19+l20+l21+l22+l23+l24+l25+l26+l27	// alle LEDs

#define REPEAT_START    100                        // after 500ms
#define REPEAT_NEXT     20                        // every 200ms

/* CUBE_HEADER_H_ */
