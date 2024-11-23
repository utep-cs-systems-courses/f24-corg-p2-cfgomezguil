#MSP430 Config
COMMON_OBJECTS	=

CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as



all: project.elf



project.elf: ${COMMON_OBJECTS} main.c stateMachine.o led.o interupt_handler.o wdInterruptHandler.o switches.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^



load: project.elf

	msp430loader.sh project.elf



clean:

	rm -f *.o *.elf



led.o: led.c led.h

stateMachine.o: stateMachine.c stateMachine.h

# buzzer.o: buzzer.c buzzer.h

switches.o: switches.c switches.h

wdInterruptHandler.o: wdInterruptHandler.c

interupt_handler.o: interupt_handler.c
