#include "input.h"
#include "print.h"

#include <stdint.h>
#include <stddef.h>
#include <sys/io.h>

char get_input_keycode()
{
  char code = 0;
  do {
    code = inb(KEYBOARD_PORT);
  } while (code <= 0);
  return code;
}

/*
keep the cpu busy for doing nothing(nop)
so that io port will not be processed by cpu
here timer can also be used, but lets do this in looping counter
*/
void wait_for_io(uint32_t timer_count)
{
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}

void sleep(uint32_t timer_count)
{
  wait_for_io(timer_count);
}

void read(char *buffer, int length) {
    size_t index = 0;
    char keycode = 0;
    do
    {
        keycode = get_input_keycode();
        char character = keycode_to_ascii[keycode];
        buffer[index] = character;
        print_char(character);
        index++;
        sleep(0x02FFFFFF);
    } while (index < length && keycode != KEY_ENTER);
}