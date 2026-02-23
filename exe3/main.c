#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PINR = 28;
const int BTN_PING = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
int main() {

  stdio_init_all();
  gpio_init(BTN_PINR);
  gpio_init(BTN_PING);
  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);
  
  gpio_set_dir(BTN_PINR, GPIO_IN);
  gpio_pull_up(BTN_PINR);
  gpio_set_dir(BTN_PING, GPIO_IN);
  gpio_pull_up(BTN_PING);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  int var_vermelho = 0;
  int var_verde = 0;

  while (true) {
    if (gpio_get(BTN_PINR) == 0) {
      var_vermelho = !var_vermelho;
      gpio_put(LED_PIN_R, var_vermelho);
      sleep_ms(200);
    }
    if (gpio_get(BTN_PING) == 0) {
      var_verde = !var_verde;
      gpio_put(LED_PIN_G, var_verde);
      sleep_ms(200);
    }
  }
}
