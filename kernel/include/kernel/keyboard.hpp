#ifndef __KEYBOARD_HPP__
#define __KEYBOARD_HPP__

#include <stddef.h>

namespace kerneltty {
	char getchar(void);
	void getline(char *resultbuffer, size_t size);
};

#endif
