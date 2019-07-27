/**
 * This file contains implementations of all light pattern modes.
 *
 * @author Johan Nilsson
 * @since 0.1.0
 */

#include <avr/io.h>
#include <stdlib.h>
#include "macros.h"
#include "utils.h"

/* Global variables for Glitter mode. */
uint8_t random_led;
uint32_t random_ticks;
uint32_t random_duration;

/**
 * Switches on all LEDs.
 *
 * @param ticks current timer value; unused for this function
 *
 * @since 0.1.0
 */
void all_leds_on_mode(uint32_t ticks)
{
    switch_on_all_leds();
}

/**
 * Randomly chooses an output register bit and clears it for a small period of
 * time before all register bits are set again, creating a glittering or
 * sparkling effect.
 *
 * @param ticks current timer value
 *
 * @since 0.1.0
 */
void glitter_mode(uint32_t ticks)
{
    // If the timer is between 0 ms and 33 ms, randomize the first round.
    if (ticks == 0 || ticks == 1)
    {
        random_led = (uint8_t) rand() % 11;
        random_ticks = (uint32_t) rand() % 30 + 2;
        switch_on_all_leds();
    }

    if (ticks == random_ticks)
    {
        if (random_led == 0)
        {
            CLRBIT(PORTC, 0);
        }
        else if (random_led == 1)
        {
            CLRBIT(PORTC, 1);
        }
        else if (random_led == 2)
        {
            CLRBIT(PORTC, 2);
        }
        else if (random_led == 3)
        {
            CLRBIT(PORTC, 3);
        }
        else if (random_led == 4)
        {
            CLRBIT(PORTC, 4);
        }
        else if (random_led == 5)
        {
            CLRBIT(PORTC, 5);
        }
        else if (random_led == 6)
        {
            CLRBIT(PORTD, 0);
        }
        else if (random_led == 7)
        {
            CLRBIT(PORTD, 1);
        }
        else if (random_led == 8)
        {
            CLRBIT(PORTD, 2);
        }
        else if (random_led == 9)
        {
            CLRBIT(PORTD, 3);
        }
        else if (random_led == 10)
        {
            CLRBIT(PORTD, 4);
        }
    }

    if (ticks == random_ticks + 5)
    {
        if (random_led == 0)
        {
            SETBIT(PORTC, 0);
        }
        else if (random_led == 1)
        {
            SETBIT(PORTC, 1);
        }
        else if (random_led == 2)
        {
            SETBIT(PORTC, 2);
        }
        else if (random_led == 3)
        {
            SETBIT(PORTC, 3);
        }
        else if (random_led == 4)
        {
            SETBIT(PORTC, 4);
        }
        else if (random_led == 5)
        {
            SETBIT(PORTC, 5);
        }
        else if (random_led == 6)
        {
            SETBIT(PORTD, 0);
        }
        else if (random_led == 7)
        {
            SETBIT(PORTD, 1);
        }
        else if (random_led == 8)
        {
            SETBIT(PORTD, 2);
        }
        else if (random_led == 9)
        {
            SETBIT(PORTD, 3);
        }
        else if (random_led == 10)
        {
            SETBIT(PORTD, 4);
        }

        random_led = (uint8_t) rand() % 11;
        random_ticks += (uint32_t) rand() % 30 + 2;
    }
}

/**
 * LEDs on the tree trunk will light up in a fast pace, from the bottom and
 * up. Then, the LEDs on the branches will light up in a slower pace, from the
 * top to the bottom.
 *
 * @param ticks current timer value
 *
 * @since 0.1.0
 */
void falling_lights_mode(uint32_t ticks)
{
    switch (ticks)
    {
        // 0-33 ms.
        case 0:
        case 1:
            switch_off_all_leds();
            break;

        // 250 ms.
        case 8:
            SETBIT(PORTC, 2);
            break;

        // 500 ms.
        case 15:
            SETBIT(PORTC, 3);
            break;

        // 750 ms.
        case 23:
            SETBIT(PORTD, 0);
            break;

        // 1000 ms.
        case 30:
            SETBIT(PORTD, 1);
            break;

        // 1250 ms.
        case 38:
            SETBIT(PORTD, 4);
            break;

        // 1750 ms.
        case 53:
            SETBIT(PORTD, 2);
            SETBIT(PORTD, 3);
            break;

        // 2250 ms.
        case 68:
            SETBIT(PORTC, 4);
            SETBIT(PORTC, 5);
            break;

        // 2750 ms.
        case 83:
            SETBIT(PORTC, 0);
            SETBIT(PORTC, 1);
            break;

        // 4000 ms.
        case 121:
            timer_count = 0;
            break;
    }
}

/**
 * Turns on a new LED and turns off the previous LED in a predefined pattern.
 *
 * @param ticks current timer value
 *
 * @since 0.1.0
 */
void one_led_mode(uint32_t ticks)
{
    switch (ticks)
    {
        // 0-33 ms.
        case 0:
        case 1:
            switch_off_all_leds();
            break;

        // 250 ms.
        case 8:
            SETBIT(PORTC, 0);
            break;

        // 500 ms.
        case 15:
            SETBIT(PORTC, 1);
            CLRBIT(PORTC, 0);
            break;

        // 750 ms.
        case 23:
            SETBIT(PORTC, 2);
            CLRBIT(PORTC, 1);
            break;

        // 1000 ms.
        case 30:
            SETBIT(PORTC, 3);
            CLRBIT(PORTC, 2);
            break;

        // 1250 ms.
        case 38:
            SETBIT(PORTC, 4);
            CLRBIT(PORTC, 3);
            break;

        // 1500 ms.
        case 45:
            SETBIT(PORTC, 5);
            CLRBIT(PORTC, 4);
            break;

        // 1750 ms.
        case 53:
            SETBIT(PORTD, 0);
            CLRBIT(PORTC, 5);
            break;

        // 2000 ms.
        case 61:
            SETBIT(PORTD, 1);
            CLRBIT(PORTD, 0);
            break;

        // 2250 ms.
        case 68:
            SETBIT(PORTD, 2);
            CLRBIT(PORTD, 1);
            break;

        // 2500 ms.
        case 76:
            SETBIT(PORTD, 3);
            CLRBIT(PORTD, 2);
            break;

        // 2750 ms.
        case 83:
            SETBIT(PORTD, 4);
            CLRBIT(PORTD, 3);
            break;

        // 3000 ms.
        case 91:
            SETBIT(PORTD, 3);
            CLRBIT(PORTD, 4);
            break;

        // 3250 ms.
        case 98:
            SETBIT(PORTD, 2);
            CLRBIT(PORTD, 3);
            break;

        // 3500 ms.
        case 106:
            SETBIT(PORTD, 1);
            CLRBIT(PORTD, 2);
            break;

        // 3750 ms.
        case 114:
            SETBIT(PORTD, 0);
            CLRBIT(PORTD, 1);
            break;

        // 4000 ms.
        case 121:
            SETBIT(PORTC, 5);
            CLRBIT(PORTD, 0);
            break;

        // 4250 ms.
        case 129:
            SETBIT(PORTC, 4);
            CLRBIT(PORTC, 5);
            break;

        // 4500 ms.
        case 136:
            SETBIT(PORTC, 3);
            CLRBIT(PORTC, 4);
            break;

        // 4750 ms.
        case 144:
            SETBIT(PORTC, 2);
            CLRBIT(PORTC, 3);
            break;

        // 5000 ms.
        case 152:
            SETBIT(PORTC, 1);
            CLRBIT(PORTC, 2);
            break;

        // 5250 ms.
        case 159:
            timer_count = 0;
            break;
    }
}
