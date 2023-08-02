#include "functions.h"
#include "../drivers/screen.h"
#include "../libc/mem.h"

void print_welcome() {
    //kprint_color("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xBA                                                                              \xBA\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC", WHITE_ON_BLUE);

    kprint_color("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\xBA                                                                              \xBA\xBA                           _   _ _       ___  ____                            \xBA\xBA                          | \\ | (_) ___ / _ \\/ ___|                           \xBA\xBA                          |  \\| | |/ __| | | \\___ \\                           \xBA\xBA                          | |\\  | | (__| |_| |___) |                          \xBA\xBA                          |_| \\_|_|\\___|\\___/|____/                           \xBA\xBA                                                                              \xBA\xBA                                 Version 0.02                                 \xBA\xBA                                  Kernel Dev                                  \xBA\xBA                                                                              \xBA\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC", WHITE_ON_BLUE);
}

void print_poweroff() {
    clear_screen();
    change_color(WHITE_ON_BLACK);
    kprint("It is safe to turn off your PC.");
}

void print_help() {
    kprint("List of available commands\n- CLEAR - Clears the screen\n- COLOR - Change the screen color\n- ECHO  - Print something out to the screen\n- END   - Stop the CPU\n");
}

void syntax_error() {
    kprint("ERROR: Invalid Syntax For This Command\n\n> ");
}
