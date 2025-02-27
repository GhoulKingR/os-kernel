#include "../../include/kernel/shell.hpp"
#include "../../include/kernel/keyboard.hpp"
#include "../../include/kernel/tty.hpp"
#include "../../../libc/include/stdlib.h"
#include "../../../libc/include/string.h"

#include <stddef.h>
#include <stdbool.h>

void shell_run_command(char commandbuffer[5][20]) {
	char *command = commandbuffer[0];

	if (strcmp(command, "echo") == 0) {
		kerneltty::writeline(commandbuffer[1]);
	} else {
		kerneltty::writestring("Command not found: ");
		kerneltty::writeline(command);
	}
}

void parse_shell_input(char* input, char output[5][20]) {
	// temporary hard limit 5 command args, 20 characters long
	size_t len = strlen(input);
	size_t pos = 0, b = 0;
	char buffer[20];
	memset(buffer, '\0', 20);

	for (size_t i = 0; i < len; i++) {
		char c = input[i];
		if (c == ' ') {
			if (strlen(buffer) > 0) {
				strcpy(output[pos++], buffer);
				memset(buffer, '\0', 20);
				b = 0;
			}
		} else if (c == '"') {
			for (i++; i < len && input[i] != '"'; i++)
				buffer[b++] = input[i];
			strcpy(output[pos++], buffer);
			memset(buffer, '\0', 20);
			b = 0;
		} else {
			buffer[b++] = c;
		}
	}
	
	if (strlen(buffer) > 0) {
		strcpy(output[pos], buffer);
	}
}

void shell::init(void) {
	kerneltty::writeline("Welcome to grp9os!");
	while(true) {
		kerneltty::writestring("> ");
		char buffer[100];
		kerneltty::getline(buffer, 100);
		char commandbuffer[5][20];
		parse_shell_input(buffer, commandbuffer);
		shell_run_command(commandbuffer);
	}
}

