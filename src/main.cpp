#include <avr/io.h>

void setup() {
  DDRC = 0xFF;
  PORTC = 0x00;
    
  // TCC/8
  TCCR1B |= (1<<1);
  TCCR1B &= ~((1<<0) | (1<<2));
  TCNT1 = 0;
}

void loop() {
  if (TCNT1 == 32257) {
    PORTC ^= (1<<0);
  }
}

int main(void) {
  setup();
    
  while (1) {
    loop();
  }
}