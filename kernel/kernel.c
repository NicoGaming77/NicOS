#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "functions.h"

static char command_buffer[256];

void kernel_main() {
    isr_install();
    irq_install();

    clear_screen();
    print_welcome();
    kprint("> ");
    asm volatile("hlt");
}

void user_input(char *input) {
    int i;
    for (i = 0; input[i] != ' ' && input[i] != '\0'; i++) {
        command_buffer[i] = upper(input[i]);
    }
    command_buffer[i] = '\0';
    run_command(input, command_buffer);
    command_buffer[0] = '\0';
    input[0] = '\0';
}

void run_command(char *input, char *command) {
    if (command[0] == '\0') return kprint("> ");
    if (strcmp(command, "END") == 0) {
        kprint("Stopping the CPU...\n");
        print_poweroff();
        asm volatile("hlt");
    } else if (strcmp(command, "CLEAR") == 0) {
        clear_screen();
        kprint("> ");
        return;
    } else if (strcmp(command, "COLOR") == 0) {
        if (strlen(input) < 8) return syntax_error();
        input[6] = upper(input[6]);
        input[7] = upper(input[7]);
        if (((input[6] >= '0' && input[6] <= '9') || (input[6] >= 'A' && input[6] <= 'F')) && ((input[7] >= '0' && input[7] <= '9') || (input[7] >= 'A' && input[7] <= 'F'))) {
            if (input[8] != '\0' && input[8] != ' ') return syntax_error();
            if (input[6] >= 'A' && input[6] <= 'F') input[6] -= 55;
            if (input[7] >= 'A' && input[7] <= 'F') input[7] -= 55;
            char color;
            color = (input[6] << 4) | (input[7] & 0x0F);
            change_color(color);
        } else {
            return syntax_error();
        }
    } else if (strcmp(command, "ECHO") == 0) {
        if (input[4] != '\0' && input[5] != '\0') {
            char print_buffer[256];
            int i;
            for (i = 5; input[i] != '\0'; i++) {
                print_buffer[i-5] = input[i];
            }
            print_buffer[i-5] = '\0';
            kprint(print_buffer);
            print_buffer[0] = '\0';
        }
    } else if (strcmp(command, "HELP") == 0) {
        print_help();
    }
    else {
        kprint("ERROR: Unknown Command\n");
    }
    kprint("\n> ");
}
