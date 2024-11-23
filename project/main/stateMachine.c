#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char toggle_red(){ //toggle methods for the state machine, always toggle
  static char state = 0;

  switch (state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}



char toggle_green(){ //green toggle is based on the red, only if red is on
  char change = 0;
  if (red_on){
    green_on ^= 1;
    change = 1;
  }
  return change;

}


void led_state_advance(){

  char change = 0;

  static enum {R=1,G=0} color = R;
  switch (color) {
  case R:
    change = toggle_red();
    color = G;
    break;
  case G:
    change = toggle_green();
    color = R;
    break;
  }
  led_switch = change;
  led_update();
}
void switch_state_advance(){
  switch (switch_state){
  case 1:
    buzzer_set_period(1300);
    break;
  case 2:
    buzzer_set_period(200);
    break;
  case 3:
    buzzer_set_period(700);
  case 4:
    buzzer_off();
    break;
  }
  led_update();
}
