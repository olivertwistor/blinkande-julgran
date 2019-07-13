/**
 * Implementations of the utility functions for use throughout this program.
 *
 * @author Johan Nilsson
 *
 * @since 0.1.0
 */

#include <avr/io.h>
#include "utils.h"

/*
 * Switches off all LEDs.
 *
 * @since 0.1.0
 */
void switch_off_all_leds()
{
	PORTC &= ~(0b00111111);
	PORTD &= ~(0b00011111);
}

/*
 * Switches on all LEDs.
 *
 * @since 0.1.0
 */
void switch_on_all_leds()
{
	PORTC |= 0b00111111;
	PORTD |= 0b00011111;
}
