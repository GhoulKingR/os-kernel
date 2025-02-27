#include "../../include/kernel/keyboard.hpp"
#include "../../include/kernel/tty.hpp"

#include <stdint.h>
#include <stdbool.h>

extern "C" uint16_t _getkeyboardinput(void);

const char regular[58] = {
	'\0', '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
	'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
	'\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', '\0', '\\',
	'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', '\0', '\0', ' ',
};
const char shifted[58] = {
	'\0', '\0', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
	'\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
	'\0', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~', '\0', '\\',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', '\0', '\0', '\0', ' ',
};

char kerneltty::getchar() {
	bool shiftpressed = false;
	while(true) {
		uint8_t keyboard_input = _getkeyboardinput();

		if(keyboard_input == 0x2a || keyboard_input == 0x36) {
			shiftpressed = true;
			continue;
		} else if (keyboard_input == (0x2a + 0x80) || keyboard_input == (0x36 + 0x80)) {
			shiftpressed = false;
			continue;
		}

		if (keyboard_input >= 0x80 || keyboard_input <= 0x00) {
			return '\0';
		} else {
			char result = (shiftpressed ? shifted : regular)[keyboard_input];
			
			if (result != '\b')
				kerneltty::putchar(result);

			return result;
		}
	}
}

void kerneltty::getline(char *resultbuffer, size_t size) {
	uint8_t i = 0;
	while(i < size - 2) {
		char input = kerneltty::getchar();

		if (input == '\0')
			continue;
		if (input == '\n')
			break;

		if (input == '\b') {
			if (i > 0) {
				kerneltty::putchar(input);
				resultbuffer[i-1] = ' ';
				--i;
			}
			continue;
		}

		resultbuffer[i] = input;
		i++;
	}
	resultbuffer[i] = '\0';
}

