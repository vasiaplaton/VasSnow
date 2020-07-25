#include <avr/eeprom.h>
#define    RANDOM_SEED_ADDRESS    0x00
static uint16_t random_number = 0;

static uint16_t lfsr16_next(uint16_t n)
{

  return (n >> 0x01U) ^ (-(n & 0x01U) & 0xB400U);
}

void random_init(uint16_t seed)
{
  random_number = lfsr16_next(eeprom_read_word((uint16_t *)RANDOM_SEED_ADDRESS) ^ seed);
  eeprom_write_word((uint16_t *)0, random_number);
}

uint16_t random_f(void)
{

  return (random_number = lfsr16_next(random_number));
}
