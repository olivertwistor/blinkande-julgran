/**
 * Header file for all the light pattern modes.
 *
 * @author Johan Nilsson
 * @since 0.1.0
 */

#ifndef MODES_H_
#define MODES_H_

/**
 * This mode turns all the LEDs on.
 *
 * @param ticks current timer value; unused for this function
 *
 * @since 0.1.0
 */
void all_leds_on_mode(uint32_t ticks);

/**
 * This mode makes a glittering or sparkling effect by turning off random LEDs
 * for short periods of time.
 *
 * @param ticks current timer value
 *
 * @since 0.1.0
 */
void glitter_mode(uint32_t ticks);

/**
 * This mode lights up the trunk of the Christmas tree and then lights up the
 * other LEDs in a falling motion.
 *
 * @param ticks current timer value
 *
 * @since 0.1.0
 */
void falling_lights_mode(uint32_t ticks);

/**
 * This mode turns one LED on at a time, in a predefined pattern.
 *
 * @param ticks current timer value
 *
 * @since 0.1.0
 */
void one_led_mode(uint32_t ticks);

#endif /* MODES_H_ */
