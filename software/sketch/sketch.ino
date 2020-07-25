#include <util/delay.h>
#define ANODES_Q 4
#define CATHODES_Q 6
#define EFFECTS_Q 3
#define MAX_BR 254
#define MIN_BR 1
#define EFFECT_DELAY 5000 // in ms
#define AUTOCHANGE false
int std_br = 195;
int cathodes[CATHODES_Q] = { 10, 9, 1, 8, 7, 6};
int anodes[ANODES_Q] = {5, 2, 3, 4};
bool center = true;
byte leds[CATHODES_Q][ANODES_Q] = { { 0, 0, 1, 0}, { 0, 1, 0, 0}, { 1, 0, 0, 0}, { 0, 1, 1, 0},  { 0, 0, 0, 1}, { 1, 0, 0, 0}};
byte cathod_num = 0;
int effect_num = 2;
unsigned long int millis = 0;
unsigned long int prev_millis = 0;
ISR(TIM0_COMPA_vect)
{
  for (int i = 0; i < ANODES_Q; i++) {
    if (leds[cathod_num][i] == 1)  digitalWrite(anodes[i], HIGH);
    else digitalWrite(anodes[i], LOW);
  }
  digitalWrite(cathodes[cathod_num], LOW);
  cathod_num++;
  if (cathod_num >= CATHODES_Q) {
    cathod_num = 0;
    if (center == true) digitalWrite(0, HIGH);
  }

}
ISR(TIM0_OVF_vect)
{
  PORTA |= 0b00011111;
  PORTB |= 0b00000010;
  PORTB &= 0b11111110;
  millis += 2;
}
void set_br(byte br) {
  OCR0A = 0xFF - br;
}
void set_rays(byte *ray) {
  for (int i = 0; i < CATHODES_Q; i++) {
    for (int j = 0; j < ANODES_Q; j++) {
      leds[i][j] = ray[j];
    }
  }
}
void clear() {
  for (int i = 0; i < CATHODES_Q; i++) {
    for (int j = 0; j < ANODES_Q; j++) {
      leds[i][j] = 0;
    }
  }
}
void ligth_all() {
  for (int i = 0; i < CATHODES_Q; i++) {
    for (int j = 0; j < ANODES_Q; j++) {
      leds[i][j] = 1;
    }
  }
}
void mange_effects() {
  if(((millis - prev_millis) > 5000) && AUTOCHANGE){
    prev_millis = millis;
    effect_num++;
    if (effect_num>= EFFECTS_Q){
      effect_num = 0;
    }
  }
}
void setup() {
  DDRA = 0b11111111; // all output
  DDRB = 0b00000111;// all output
  PORTA = 0b11111111;// all high
  PORTB = 0b00000111;// all high
  TCCR0A |= 0b00000011;
  TCCR0B = 0b00000011;
  set_br(std_br);
  TIMSK0 |= _BV(OCIE0A);
  TIMSK0 |= _BV(TOIE0);
  interrupts();
}

void loop() {
  mange_effects();
  switch (effect_num) {
    case 0:
      breath(400);
      break;
    case 1:
      roundd(70 , 6);
      break;
    case 2:
      breath2(8);
      break;
  }
  

  /* digitalWrite(0, HIGH);
    _delay_ms(500);
       digitalWrite(0, LOW);
    _delay_ms(500);*/
}
