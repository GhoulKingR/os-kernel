#include <stddef.h>
#include <stdint.h>

#include "../include/kernel/tty.h"
#include "../include/kernel/shell.h"

void kernel_main(void) {
	terminal_initialize();
	shell_init();
}
