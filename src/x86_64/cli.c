#include "cli.h"
#include "print.h"
#include "input.h"
#include "bool.h"

#include <stdint.h>
#include <stddef.h>
#include <sys/io.h>

void process_user_input()
{

    char input_buffer[MAX_COMMAND_LENGTH];
    read(input_buffer, MAX_COMMAND_LENGTH);
}
void cli_prompt()
{
    __wait_and_process:
        print_set_color(PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);
        print_str("\nroot@monsernel/>");
        print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
        process_user_input();
    goto __wait_and_process;
}