#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../include/kernel/keyboard.h"
#include "../include/kernel/tty.h"

void kernel_main(void) {
	terminal_initialize();
	terminal_writestring("Welcome to grp9os!\n");

	while(true) {
		terminal_writestring("> ");

		char buffer[100];
		terminal_getline(buffer, 100);

		terminal_writestring("You inputed: ");
		terminal_writestring(buffer);
		terminal_writestring("\n");
	}
}
