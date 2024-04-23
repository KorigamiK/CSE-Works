CC      = avr-gcc
OBJCOPY = avr-objcopy
MCU     = attiny84
FREQ    = 16000000
APP     = first_attempt
CFLAGS  = -O2 -I. -mmcu=${MCU} -DF_CPU=${FREQ}UL

${APP}.hex: ${APP}.elf
	${OBJCOPY} -j .text -j .data -O ihex $< $@

${APP}.elf: ${APP}.o
	${CC} -o $@ $^

clean:
	rm -f ${APP}.elf ${APP}.hex ${APP}.o
