#include "include/stdlib.h"
#include "include/string.h"

char *itoa(int value, char *str) {
	int digits;
	for(digits = 0; str[digits] != '\0'; digits++);
	digits = digits == 0 ? 1 : digits;
	
	memset(str, '\0', digits+1);

	for (int i = digits; i >= 0; i--) {
		str[i] = value % 10;
		value /= 10;
	}
	return str;
}
