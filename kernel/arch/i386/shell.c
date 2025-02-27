#include "../../include/kernel/shell.h"
#include "../../include/kernel/keyboard.h"
#include "../../include/kernel/tty.h"
#include "../../../libc/include/stdlib.h"
#include "../../../libc/include/string.h"

#include <stddef.h>
#include <stdbool.h>

// shell commands start
void shell_run_command(char commandbuffer[5][20]) {
	char *command = commandbuffer[0];

	if (strcmp(command, "echo") == 0) {
		terminal_writeline(commandbuffer[1]);
	} else {
		terminal_writestring("Command not found: ");
		terminal_writeline(command);
	}
}

// shell commands end

void parse_shell_input(char* input, char output[5][20]) {
	// temporary hard limit 5 command args, 20 characters long
	size_t len = strlen(input);
	size_t pos = 0;

	char buffer[20];
	int b = 0;
	memset(buffer, '\0', 20);

	for (size_t i = 0; i < len; i++) {
		char c = input[i];

		if (c == ' ') {
			if (strlen(buffer) > 0) {
				strcpy(output[pos], buffer);
				memset(buffer, '\0', 20);
				b = 0;
				pos++;
			}
		} else if (c == '"') {
			for (i++; i < len && input[i] != '"'; i++) {
				buffer[b] = input[i];
				b++;
			}

			strcpy(output[pos], buffer);
			memset(buffer, '\0', 20);
			b = 0;
			pos++;
		}else {
			buffer[b] = c;
			b++;
		}
	}
	
	if (strlen(buffer) > 0) {
		strcpy(output[pos], buffer);
	}
}

void shell_init() {
	terminal_writeline("Welcome to grp9os!");
	while(true) {
		terminal_writestring("> ");
		char buffer[100];
		terminal_getline(buffer, 100);
		char commandbuffer[5][20];
		parse_shell_input(buffer, commandbuffer);
		shell_run_command(commandbuffer);
	}
}

