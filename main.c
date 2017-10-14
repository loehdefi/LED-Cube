#include <msp430.h>
#include "Cube-Header.h"

unsigned char bild[3][3][3];
unsigned char timerCount = 0;
unsigned char timerCount2 = 0;
unsigned char timerCount3 = 0;
unsigned int  timerCount4 = 0;
unsigned char n = 2;
unsigned int  prnr = 0;
unsigned char nextStep = 0;
unsigned char mode = 0;
unsigned int  rpt;
unsigned char wechsel = 0;
unsigned char enable = 0;
unsigned char locked = 0;

// Programm: erstes Element: Anzeigedauer der einzelnen Schritte			//
//			 zweites Element: Arrayindex nach dem wieder neu begonnen wird	//
// 			 danach: einzelne Schritte im Programm							//
const unsigned long prog[MAXPROG][nMax] = {
		{50,19,l3+l12+l21,l3+l12+l21+l2+l11+l20,l3+l12+l21+l2+l11+l20+l1+l10+l19,l3+l12+l21+l2+l11+l20+l1+l10+l19+l4+l13+l22,l3+l12+l21+l2+l11+l20+l1+l10+l19+l4+l13+l22+l7+l16+l25,l3+l12+l21+l2+l11+l20+l1+l10+l19+l4+l13+l22+l7+l16+l25+l8+l17+l26,l3+l12+l21+l2+l11+l20+l1+l10+l19+l4+l13+l22+l7+l16+l25+l8+l17+l26+l9+l18+l27,l3+l12+l21+l2+l11+l20+l1+l10+l19+l4+l13+l22+l7+l16+l25+l8+l17+l26+l9+l18+l27+l6+l15+l24,l2+l11+l20+l1+l10+l19+l4+l13+l22+l7+l16+l25+l8+l17+l26+l9+l18+l27+l6+l15+l24,l1+l10+l19+l4+l13+l22+l7+l16+l25+l8+l17+l26+l9+l18+l27+l6+l15+l24,l4+l13+l22+l7+l16+l25+l8+l17+l26+l9+l18+l27+l6+l15+l24,l7+l16+l25+l8+l17+l26+l9+l18+l27+l6+l15+l24,l8+l17+l26+l9+l18+l27+l6+l15+l24,l9+l18+l27+l6+l15+l24,l6+l15+l24,0},
		{100,8,l10+l11+l12+l13+l14+l15+l16+l17+l18,l2+l5+l8+l11+l14+l17+l20+l23+l26,l4+l5+l6+l13+l14+l15+l22+l23+l24,l1+l2+l3+l4+l5+l6+l7+l8+l9+l19+l20+l21+l22+l23+l24+l25+l26+l27,l1+l4+l7+l10+l13+l16+l19+l22+l25+l3+l6+l9+l12+l15+l18+l21+l24+l27,l1+l2+l3+l10+l11+l12+l19+l20+l21+l9+l8+l7+l18+l17+l16+l27+l26+l25},
		{100,14,l1+l3+l7+l9+l19+l21+l27+l25,l1+l3+l7+l9,l19+l21+l27+l25,l11+l13+l15+l17,l1+l7+l19+l25,l3+l9+l21+l27,l11+l5+l23+l17,l1+l3+l19+l21,l9+l7+l27+l25,l5+l13+l15+l23,l1+l3+l7+l9+l19+l21+l27+l25,0},
		{100,18,l3+l12+l21,0,l8+l17+l26,0,l1+l10+l19,0,l7+l16+l25,0,l2+l11+l20,0,l4+l13+l22,0,l9+l18+l27,0,l5+l14+l23,0},
		{40,8,l1+l2+l4+l5+l10+l11+l13+l14,l2+l3+l5+l6+l14+l11+l12+l15,l5+l6+l8+l9+l18+l17+l14+l15,l14+l15+l17+l18+l27+l26+l24+l23,l14+l13+l17+l16+l26+l25+l23+l22,l14+l13+l10+l11+l19+l20+l23+l22},
		{30,16,l14,l14+l13+l15+l11+l17+l5+l23,l14+l13+l15+l11+l17+l5+l23+l2+l4+l6+l8+l20+l22+l24+l26+l10+l12+l16+l18,l14+l13+l15+l11+l17+l5+l23+l2+l4+l6+l8+l20+l22+l24+l26+l10+l12+l16+l18+l1+l3+l7+l9+l19+l21+l27+l25,l14+l13+l15+l11+l17+l5+l23+l2+l4+l6+l8+l20+l22+l24+l26+l10+l12+l16+l18+l1+l3+l7+l9+l19+l21+l27+l25,l14+l13+l15+l11+l17+l5+l23+l2+l4+l6+l8+l20+l22+l24+l26+l10+l12+l16+l18+l1+l3+l7+l9+l19+l21+l27+l25,l14+l13+l15+l11+l17+l5+l23+l2+l4+l6+l8+l20+l22+l24+l26+l10+l12+l16+l18+l1+l3+l7+l9+l19+l21+l27+l25,l14+l13+l15+l11+l17+l5+l23+l2+l4+l6+l8+l20+l22+l24+l26+l10+l12+l16+l18+l1+l3+l7+l9+l19+l21+l27+l25,l14+l13+l15+l11+l17+l5+l23+l2+l4+l6+l8+l20+l22+l24+l26+l10+l12+l16+l18,l14+l13+l15+l11+l17+l5+l23,l14},
		{40,20,l1+l2+l3+l4+l5+l6+l7+l8+l9,l10+l11+l12+l13+l14+l15+l16+l17+l18,l19+l20+l21+l22+l23+l24+l25+l26+l27,l1+l2+l3+l10+l11+l12+l19+l20+l21,l4+l5+l6+l13+l14+l15+l22+l23+l24,l7+l8+l9+l16+l17+l18+l25+l26+l27,l1+l4+l7+l10+l13+l16+l19+l22+l25,l2+l5+l8+l11+l14+l17+l20+l23+l26,l3+l6+l9+l12+l15+l18+l21+l24+l27,l19+l20+l21+l22+l23+l24+l25+l26+l27,l10+l11+l12+l13+l14+l15+l16+l17+l18,l1+l2+l3+l4+l5+l6+l7+l8+l9,l7+l8+l9+l16+l17+l18+l25+l26+l27,l4+l5+l6+l13+l14+l15+l22+l23+l24,l1+l2+l3+l10+l11+l12+l19+l20+l21,l3+l6+l9+l12+l15+l18+l21+l24+l27,l2+l5+l8+l11+l14+l17+l20+l23+l26,l1+l4+l7+l10+l13+l16+l19+l22+l25} ,
		{30,50,l4+l1+l2+l14,l1+l2+l3+l14,l2+l3+l12+l14,l3+l12+l11+l14,l12+l11+l10+l14,l19+l10+l11+l14,l10+l19+l20+l14,l19+l20+l21+l14,l20+l21+l24+l14,l21+l24+l23+l14,l24+l23+l22+l14,l23+l22+l25+l14,l22+l25+l26+l14,l25+l26+l27+l14,l26+l27+l18+l14,l27+l18+l17+l14,l18+l17+l16+l14,l17+l16+l7+l14,l16+l7+l8+l14,l7+l8+l9+l14,l8+l9+l6+l14,l9+l6+l5+l14,l6+l5+l4+l14,l5+l4+l1+l14,l4+l1+l10+l14,l1+l10+l13+l14,l10+l13+l16+l14,l13+l16+l25+l14,l16+l25+l22+l14,l25+l22+l19+l14,l22+l19+l20+l14,l19+l20+l23+l14,l20+l23+l26+l14,l23+l26+l27+l14,l26+l27+l24+l14,l27+l24+l21+l14,l24+l21+l12+l14,l21+l12+l15+l14,l12+l15+l18+l14,l15+l18+l9+l14,l18+l9+l6+l14,l9+l6+l3+l14,l6+l3+l2+l14,l3+l2+l5+l14,l2+l5+l8+l14,l5+l8+l7+l14,l8+l7+l4+l14,l7+l4+l1+l14}
};

volatile unsigned char key_state;                               // debounced and inverted key state: // bit = 1: key pressed
volatile unsigned char key_press;                               // key press detect
volatile unsigned char key_rpt;                                 // key long press and repeat

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;			// Stop watchdog timer
    init();

   	TACTL = TASSEL_2 + ID_0 + MC_1;		// Timer A configuration
   	TACCTL0 = CCIE;						// Timer A 0 capture/compare enable
   	TACCR0 = 5000;						// 200 Hz // alle 5 ms
   	// Clear the timer and enable timer interrupt
   	__enable_interrupt();
   	__bis_SR_register(GIE); 			// interrupts enabled

   	while(1)
   	{

   		if(mode == 0) abbilden(0);
   		else if(mode == 1)
   		{
   			wechsel = 1;
   			if(nextStep)
   			{
   				abbilden(prog[prnr][n]);
   				n++;
   				if(n == prog[prnr][1]) n = 2;
   				nextStep = 0;
   			}
   		}
   		else if(mode == 2)
   		{
   			wechsel = 0;
			if(nextStep)
			{
				abbilden(prog[prnr][n]);
				n++;
				if(n == prog[prnr][1]) n = 2;
				nextStep = 0;
			}
   		}
   	}
}

// Timer 0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0 (void)
{
	static const char maxprog = MAXPROG;
	timerCount2 = (timerCount2 + 1) % 2;		// alle 10 ms
	if(timerCount2 == 0)
	{
		static int in;
		static unsigned char ct0, ct1;//, rpt;
		unsigned char i;

		in = P1IN;
		i = key_state ^ ~((unsigned char)BUTTON & (unsigned char)in);                       // key changed ?
		ct0 = ~( ct0 & i );                             // reset or count ct0
		ct1 = ct0 ^ (ct1 & i);                          // reset or count ct1
		i &= ct0 & ct1;                                 // count until roll over ?
		key_state ^= i;                                 // then toggle debounced state
		key_press |= key_state & i;                     // 0->1: key press detect

		if( (key_state & BUTTON) == 0)// check repeat function
		{
			rpt = REPEAT_START;                         // start delay
			locked = 0;
		}
		if( --rpt == 0){
			locked = 1;
			mode++;
			if(mode >= 3) mode = 0;
			abbilden(lall);
		}

		if(key_press & BUTTON && mode == 2)
	   	{
			key_press &= ~BUTTON;
			prnr++;
			n = 2;
			if(prnr == maxprog) prnr = 0;
	   	}
	}

	timerCount3 = (timerCount3 + 1) % prog[prnr][0];
	if(timerCount3 == 0)
	{
		nextStep = 1;
	}

	if(wechsel)
	{
		timerCount4 = (timerCount4 + 1) % ProgZeit;
		if(timerCount4 == 0)
		{
			prnr++;
			n = 2;
			if(prnr == maxprog) prnr = 0;
		}
	}

	timerCount = (timerCount + 1) % 3;
	switch(timerCount)
	{
		case 0:	P1OUT &= ~(S1 | S2 | S3 | S4 | S5 | E2);
				P2OUT = E1; break;
		case 1:	P2OUT &= ~(S6 | S7 | S8 | S9 | E1 | E3);
				P1OUT &= ~(S1 | S2 | S3 | S4 | S5 | E2);
				P1OUT |= E2; break;
		case 2:	P1OUT &= ~(S1 | S2 | S3 | S4 | S5 | E2);
				P2OUT = E3; break;
	}
	P1OUT |= S1 & bild[timerCount][0][0] | S2 & bild[timerCount][0][1]<<1 | S3 & bild[timerCount][0][2]<<2 | S4 & bild[timerCount][1][0]<<4 | S5 & bild[timerCount][1][1]<<5;
	P2OUT |= S6 & bild[timerCount][1][2] | S7 & bild[timerCount][2][0]<<1 | S8 & bild[timerCount][2][1]<<2 | S9 & bild[timerCount][2][2]<<3;
}

void init(void)
{
	/*unsigned int i, j, k;
	for(i = 3; i>0; i--)
	{
		for(j = 3; j>0; j--)
		{
			for(k = 3; k>0; k--)
			{
				bild[i][j][k] = 0;
			}
		}
	}*/
    P1OUT = BUTTON;
    P2OUT = 0;
	P1DIR = S1 | S2 | S3 | S4 | S5 | E2;
    P2DIR = S6 | S7 | S8 | S9 | E1 | E3;
    P1REN = BUTTON;
}

void abbilden(unsigned long x)
{
	int j, k, l, shift;
	for(j = 2; j>=0; j--)
	{
		for(k = 2; k>=0; k--)
		{
			for(l = 2; l>=0; l--)
			{
				shift = (j+j+j+j+j+j+j+j+j + k+k+k + l);
				bild[j][k][l] = 1 & x>>shift;
			}
		}
	}
}
