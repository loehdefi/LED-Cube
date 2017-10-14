#include <msp430.h>
#include "Cube-Header.h"

// check if a key has been pressed. Each pressed key is reported
// only once
//
/*unsigned char get_key_press( unsigned char key_mask )
{
	TA1CCTL0 &= ~CCIE;                                          // read and clear atomic !
	key_mask &= key_press;                          // read key(s)
	key_press ^= key_mask;                          // clear key(s)
	TA1CCTL0 = CCIE;
	return key_mask;
}*/

// check if a key has been pressed long enough such that the
// key repeat functionality kicks in. After a small setup delay
// the key is reported being pressed in subsequent calls
// to this function. This simulates the user repeatedly
// pressing and releasing the key.
//
/*unsigned char get_key_rpt( unsigned char key_mask )
{
	TA1CCTL0 &= ~CCIE;                                          // read and clear atomic !
	key_mask &= key_rpt;                            // read key(s)
	key_rpt ^= key_mask;                            // clear key(s)
	TA1CCTL0 = CCIE;
	return key_mask;
}*/

// check if a key is pressed right now
//
/*unsigned char get_key_state( unsigned char key_mask )
{
	key_mask &= key_state;
	return key_mask;
}*/

/*unsigned char get_key_short( unsigned char key_mask )
{
	TA1CCTL0 &= ~CCIE;                                          // read key state and key press atomic !
	return get_key_press( ~key_state & key_mask );
}*/
