/**
 * This file defines macros for setting and clearing register bits, as well as
 * determining whether a particular register bit is set or cleared.
 *
 * @author Johan Nilsson
 * @since 0.1.0
 */

#ifndef MACROS_H_
#define MACROS_H_

/* Global variables */
extern volatile uint32_t timer_count;
extern volatile uint8_t selected_mode;

// Sets bit in register.
#define SETBIT(ADDR, BIT)   (ADDR |= (1 << BIT))

// Clears bit in register.
#define CLRBIT(ADDR, BIT)   (ADDR &= ~(1 << BIT))

// Checks to see whether bit in register are set.
#define CHKBITP(ADDR, BIT)   (ADDR & (1 << BIT))

// Checks to see whether bit in register are cleared.
#define CHKBITN(ADDR, BIT)  (~ADDR & (1 << BIT))

#endif /* MACROS_H_ */
