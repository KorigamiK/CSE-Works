/*
 * blink
 * Juan Galaz
 * seta43.duckdns.org
 * seta43.blogspot.com
 * 2021
 */

#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB = 0xff;
  PORTB = 0x03;

  while (1) {
    PORTB = 0x01;
    _delay_ms(500);
    PORTB = 0x00;
    _delay_ms(500);
  }
  return 0;
}
