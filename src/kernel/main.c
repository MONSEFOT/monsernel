#include "print.h"
#include "cli.h"
#include "input.h"

void kernel_main()
{
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to Manssif's 64 bits kernel <Momne>\n");
    cli_prompt();
}