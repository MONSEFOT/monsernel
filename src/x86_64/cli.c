#include "cli.h"
#include "print.h"

#include <stdint.h>
#include <stddef.h>
#include <sys/io.h>


void cli_prompt() {
    print_set_color(PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);
    print_str("\nroot@monsernel >");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
}