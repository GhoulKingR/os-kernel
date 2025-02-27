#include <stddef.h>
#include <stdint.h>

#include "../include/kernel/tty.hpp"
#include "../include/kernel/shell.hpp"

extern "C"
void kernel_main(void) {
	kerneltty::initialize();
	shell::init();
}
