#include "print.h"
#include "cli.h"

struct Char
{
    uint8_t character;
    uint8_t color;
};

struct Char *buffer = (struct Char *)0xb8000;

size_t col = 0, row = 0;
size_t cursor_row = 0, cursor_col = 0;

uint8_t color = PRINT_COLOR_YELLOW | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row)
{
    struct Char empty = (struct Char){
        character : ' ',
        color : color,
    };

    for (size_t col = 0; col < NUM_COLS; col++)
    {
        buffer[col + NUM_COLS * row] = empty;
    }
}
void print_clear()
{
    for (size_t i = 0; i < NUM_ROWS; i++)
    {
        clear_row(i);
    }
}
void print_newline()
{
    col = 0;
    if (row < NUM_ROWS - 1)
    {
        row++;
    }
    else
    {

        for (size_t row = 1; row < NUM_ROWS; row++)
        {
            for (size_t col = 0; col < NUM_COLS; col++)
            {
                struct Char character = buffer[col + NUM_COLS * row];
                buffer[col + NUM_COLS * (row - 1)] = character;
            }
        }
        clear_row(NUM_COLS - 1);
    }
}
void print_char(char character)
{
    if (character == '\n')
    {
        print_newline();
        return;
    }

    if (col > NUM_COLS)
    {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char){
        character : (uint8_t)character,
        color : color,
    };
    col++;
}
void print_str(char *string)
{
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        char character = (uint8_t)string[i];
        print_char(character);
    }
    set_cursor_position(row, col);
}
void set_cursor_position(size_t row, size_t col)
{
    buffer[cursor_col + NUM_COLS * cursor_row].color &= 0x0F; // Reset lower 4 bits for background color.
    
    cursor_col = col;
    cursor_row = row;

    buffer[col + NUM_COLS * row].color |= (PRINT_COLOR_RED << 4); // Set the lowest bit for background color
}
void print_set_color(uint8_t foreground, uint8_t background)
{
    color = foreground + (background << 4);
}