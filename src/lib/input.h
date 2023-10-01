#pragma once

#include <stdint.h>

#define KEYBOARD_PORT 0x60
#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2E
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1F
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2F
#define KEY_W 0x11
#define KEY_X 0x2D
#define KEY_Y 0x15
#define KEY_Z 0x2C
#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0A
#define KEY_0 0x0B
#define KEY_MINUS 0x0C
#define KEY_EQUAL 0x0D
#define KEY_SQUARE_OPEN_BRACKET 0x1A
#define KEY_SQUARE_CLOSE_BRACKET 0x1B
#define KEY_SEMICOLON 0x27
#define KEY_BACKSLASH 0x2B
#define KEY_COMMA 0x33
#define KEY_DOT 0x34
#define KEY_FORESLHASH 0x35
#define KEY_F1 0x3B
#define KEY_F2 0x3C
#define KEY_F3 0x3D
#define KEY_F4 0x3E
#define KEY_F5 0x3F
#define KEY_F6 0x40
#define KEY_F7 0x41
#define KEY_F8 0x42
#define KEY_F9 0x43
#define KEY_F10 0x44
#define KEY_F11 0x85
#define KEY_F12 0x86
#define KEY_BACKSPACE 0x0E
#define KEY_DELETE 0x53
#define KEY_DOWN 0x50
#define KEY_END 0x4F
#define KEY_ENTER 0x1C
#define KEY_ESC 0x01
#define KEY_HOME 0x47
#define KEY_INSERT 0x52
#define KEY_KEYPAD_5 0x4C
#define KEY_KEYPAD_MUL 0x37
#define KEY_KEYPAD_Minus 0x4A
#define KEY_KEYPAD_PLUS 0x4E
#define KEY_KEYPAD_DIV 0x35
#define KEY_LEFT 0x4B
#define KEY_PAGE_DOWN 0x51
#define KEY_PAGE_UP 0x49
#define KEY_PRINT_SCREEN 0x37
#define KEY_RIGHT 0x4D
#define KEY_SPACE 0x39
#define KEY_TAB 0x0F
#define KEY_UP 0x48

const static char keycode_to_ascii[256] = {
    0,  // 0x00
    0,  // 0x01
    '1', // 0x02
    '2', // 0x03
    '3', // 0x04
    '4', // 0x05
    '5', // 0x06
    '6', // 0x07
    '7', // 0x08
    '8', // 0x09
    '9', // 0x0A
    '0', // 0x0B
    '-', // 0x0C
    '=', // 0x0D
    '\b', // 0x0E (Backspace)
    '\t', // 0x0F (Tab)
    'q', // 0x10
    'w', // 0x11
    'e', // 0x12
    'r', // 0x13
    't', // 0x14
    'y', // 0x15
    'u', // 0x16
    'i', // 0x17
    'o', // 0x18
    'p', // 0x19
    '[', // 0x1A
    ']', // 0x1B
    '\n', // 0x1C (Enter)
    0,  // 0x1D (Left Control)
    'a', // 0x1E
    's', // 0x1F
    'd', // 0x20
    'f', // 0x21
    'g', // 0x22
    'h', // 0x23
    'j', // 0x24
    'k', // 0x25
    'l', // 0x26
    ';', // 0x27
    '\'', // 0x28
    '`', // 0x29
    0,  // 0x2A (Left Shift)
    '\\', // 0x2B
    'z', // 0x2C
    'x', // 0x2D
    'c', // 0x2E
    'v', // 0x2F
    'b', // 0x30
    'n', // 0x31
    'm', // 0x32
    ',', // 0x33
    '.', // 0x34
    '/', // 0x35
    0,  // 0x36 (Right Shift)
    '*', // 0x37 (Keypad *)
    0,  // 0x38 (Left Alt)
    ' ', // 0x39 (Space)
    0,  // 0x3A (Caps Lock)
    0,  // 0x3B (F1)
    0,  // 0x3C (F2)
    0,  // 0x3D (F3)
    0,  // 0x3E (F4)
    0,  // 0x3F (F5)
    // ... (continue with the rest of the table)
};
char get_input_keycode();
void wait_for_io(uint32_t timer_count);
void sleep(uint32_t timer_count);
void read(char *buffer, int length);