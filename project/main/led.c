#include <msp430.h>
#include "led.h"
#include "stateMachine.h"

unsigned char red_on = 0;
unsigned char green_on = 0;
unsigned char led_switch = 0;
char ledFlags = 0;
char switch2_state, switch3_state;
char switch_state_switched;

static char Red[] = {0,LED_RED}, Green[] = {0,LED_GREEN};

void led_init(){
  P1DIR |= LEDS;
  led_switch = 1;
  switch_state_switched = 1;
  led_update();
}

void led_update(){
  if (led_switch && switch_state == 1){
    ledFlags = Green[green_on] | Red[red_on]; //first state for led state machine
    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
    led_switch = 0;
  }
  if (switch_state_switched && switch_state == 2){
    ledFlags |= switch2_state ? LED_GREEN : 0; //green then when pressed switch to red
    ledFlags |= switch2_state ? 0 : LED_RED;
    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  if (switch_state_switched && switch_state == 3){
    ledFlags |= switch3_state ? 0 : LED_GREEN; //red and when pressed goes off
    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_switched = 0;
}
