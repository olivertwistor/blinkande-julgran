/**
 * This file is the main controller: it initialize ports, interrupts and timers
 * and controls the active light pattern.
 *
 * @author Johan Nilsson
 * @since 0.1.0
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "macros.h"
#include "modes.h"
#include "utils.h"

/* Set the frequency. */
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz
#endif

/* Global variables */
volatile uint32_t timer_count = 0;
volatile uint8_t selected_mode = 0;

/**
 * Initializes the ports, choosing which will be inputs and which will be
 * outputs.
 *
 * @since 0.1.0
 */
void initialize_ports()
{
	// Set PB0-2,6 to inputs; PC0-5, PD0-4 to outputs.
	DDRB &= ~(0b01000111);
	DDRC |= 0b00111111;
	DDRD |= 0b00011111;

	// Switch off all the LEDs initially (PC0-5, PD0-4).
	switch_off_all_leds();

	// Activate the pull-up resistors for the variator (PB0-2,6).
	PORTB = 0b01000111;
}

/**
 * Initializes the interrupt pertaining to the timer.
 *
 * @since 0.1.0
 */
void initialize_timer_interrupt()
{
	// Set the pre-scaler to 1024.
	SETBIT(TCCR0B, CS02);
	SETBIT(TCCR0B, CS00);

	// Activate the timer's overflow.
	SETBIT(TIMSK0, TOIE0);

	// Reset the timer.
	TCNT0 = 0;

	// Activate the interrupt routine.
	sei();
}

/**
 * Initializes the interrupt pertaining to the mode selector.
 *
 * @since 0.1.0
 */
void initialize_mode_interrupt()
{
	// Set the interrupt to listen to PCINT0, PCINT1, PCINT2 and PCINT6.
	SETBIT(PCICR, PCIE0);
	PCMSK0 |= 0b01000111;

	// Activate the interrupt routine.
	sei();
}

/**
 * Whenever the variator is manipulated, the selected mode is changed and that
 * mode is activated. At the start of the program, the "all leds on" mode is
 * activated.
 *
 * @since 0.1.0
 */
void set_mode()
{
	if (CHKBITN(PINB, PCINT0))
	{
		selected_mode = 1;
	}
	else if (CHKBITN(PINB, PCINT1))
	{
		selected_mode = 2;
	}
	else if (CHKBITN(PINB, PCINT2))
	{
		selected_mode = 3;
	}
	else if (CHKBITN(PINB, PCINT6))
	{
		selected_mode = 4;
	}
	else
	{
		selected_mode = 1;
	}
}

/**
 * The timer interrupt routine.
 *
 * @since 0.1.0
 */
ISR(TIMER0_OVF_vect)
{
	switch (selected_mode)
	{
		// Mode: All LEDs on
		case 1:
		    all_leds_on_mode(timer_count);
			break;

		// Mode: Glitter
		case 2:
		    glitter_mode(timer_count);
		    break;

		// Mode: Falling lights
		case 3:
		    falling_lights_mode(timer_count);
		    break;

		// Mode: One LED on at a time
		case 4:
		    one_led_mode(timer_count);
		    break;
	}

	// Increase the timer count by 1. Every tick is 33 ms.
	timer_count++;
}

/*
 * The interrupt routine for the variator. Whenever it is manipulated, the
 * timer is reset and the selected mode is activated.
 *
 * @since 0.1.0
 */
ISR(PCINT0_vect)
{
	timer_count = 0;
	set_mode();
}

/*
 * Initializes the ports and the interrupt routines. Then the program is run in
 * a continuous while loop until the system is powered down.
 *
 * @since 0.1.0
 */
int main(void)
{
	initialize_ports();
	initialize_mode_interrupt();
	initialize_timer_interrupt();
	set_mode();

    while (1);

	return 0;
}
