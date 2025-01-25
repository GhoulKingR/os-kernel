#ifndef __KEYBOARD_H__

#include <stddef.h>

char terminal_getchar(void);
void terminal_getline(char *resultbuffer, size_t size);

#endif
