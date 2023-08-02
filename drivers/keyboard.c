#include "keyboard.h"
#include "../cpu/ports.h"
#include "../cpu/isr.h"
#include "screen.h"
#include "../libc/string.h"
#include "../libc/function.h"
#include "../kernel/kernel.h"

static bool Lshift_pressed = false;
static bool Rshift_pressed = false;
static bool caps_lock = false;

static char key_buffer[256];

char scan_code_chars[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ',
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+', 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0
};

char alternate_chars(char ch) {
    switch(ch) {
        case '`': return '~';
        case '1': return '!';
        case '2': return '@';
        case '3': return '#';
        case '4': return '$';
        case '5': return '%';
        case '6': return '^';
        case '7': return '&';
        case '8': return '*';
        case '9': return '(';
        case '0': return ')';
        case '-': return '_';
        case '=': return '+';
        case '[': return '{';
        case ']': return '}';
        case '\\': return '|';
        case ';': return ':';
        case '\'': return '\"';
        case ',': return '<';
        case '.': return '>';
        case '/': return '?';
        default: return ch;
    }
}

static void keyboard_callback(registers_t regs) {
    u8 scancode = port_byte_in(KEYBOARD_DATA_PORT);
    char letter = scan_code_chars[scancode];

    if (scancode & 0x80 && scancode != 0xB6 && scancode != 0xAA) return;

    switch(scancode) {
        case SCAN_CODE_KEY_CAPS_LOCK: 
            if (caps_lock == false) {
                caps_lock = true;
            } else {
                caps_lock = false;
            }
            break;

        case SCAN_CODE_KEY_ENTER:
            kprint("\n");
            user_input(key_buffer);
            key_buffer[0] = '\0';
            break;

        case SCAN_CODE_KEY_BACKSPACE:
            if (!strlen(key_buffer) == 0) {
                backspace(key_buffer);
                kprint_backspace();
            }
            break;

        case SCAN_CODE_KEY_TAB:
            //kprint('\t');
            break;

        case SCAN_CODE_KEY_LEFT_SHIFT:
            Lshift_pressed = true;
            break;

        case SCAN_CODE_KEY_RIGHT_SHIFT:
            Rshift_pressed = true;
            break;

        case SCAN_CODE_KEY_LEFT_SHIFT_UP:
            Lshift_pressed = false;
            break;

        case SCAN_CODE_KEY_RIGHT_SHIFT_UP:
            Rshift_pressed = false;
            break;

        default:
            letter = scan_code_chars[scancode];

            if (caps_lock) {
                if (Lshift_pressed || Rshift_pressed) {
                    letter = alternate_chars(letter);
                } else {
                    letter = upper(letter);
                }
            } else {
                if (Lshift_pressed || Rshift_pressed) {
                    if (isalpha(letter)) {
                        letter = upper(letter);
                    } else {
                        letter = alternate_chars(letter);
                    }
                }
            }

            char str[2] = {letter, '\0'};
            append(key_buffer, letter);
            kprint(str);
    }
    UNUSED(regs);
}

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback); 
}
