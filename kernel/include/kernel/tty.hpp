#ifndef __VGA_H__
#define __VGA_H__

namespace kerneltty {
	void initialize(void);
	void writestring(const char* data);
	void putchar(char c);
	void writeline(const char* data);
};

#endif
