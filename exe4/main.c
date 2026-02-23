#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int L1 = 5;
const int L2 = 8;
const int L3 = 11;
const int L4 = 15;
const int BTN_PIN = 28;


int main() {
  stdio_init_all();
  gpio_init(L1);
  gpio_init(L2);
  gpio_init(L3);
  gpio_init(L4);
  gpio_init(BTN_PIN);

  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);
  gpio_set_dir(L1, GPIO_OUT);
  gpio_set_dir(L2, GPIO_OUT);
  gpio_set_dir(L3, GPIO_OUT);
  gpio_set_dir(L4, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if (!gpio_get(BTN_PIN)) {
      gpio_put(L1, 1);
      gpio_put(L2, 0);
      gpio_put(L3, 0);
      gpio_put(L4, 0);
      sleep_ms(300);
      gpio_put(L1, 0);
      gpio_put(L2, 1);
      gpio_put(L3, 0);
      gpio_put(L4, 0);
      sleep_ms(300);
      gpio_put(L1, 0);
      gpio_put(L2, 0);
      gpio_put(L3, 1);
      gpio_put(L4, 0);
      sleep_ms(300);
      gpio_put(L1, 0);
      gpio_put(L2, 0);
      gpio_put(L3, 0);
      gpio_put(L4, 1);
      sleep_ms(300);
    } 
      gpio_put(L1, 0);
      gpio_put(L2, 0);
      gpio_put(L3, 0);
      gpio_put(L4, 0);
  }
}
