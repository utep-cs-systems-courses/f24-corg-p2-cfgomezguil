#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "stateMachine.h"



int main(void){
  P1DIR |= LEDS;
  P1OUT |= LED_GREEN;
  P1OUT |= LED_RED;
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();
  or_sr(0x18);
}
