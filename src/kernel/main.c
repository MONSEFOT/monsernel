#include "print.h"
#include "cli.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to Manssif's 64 bits kernel\n");
    cli_prompt();
}