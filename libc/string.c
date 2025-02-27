#include "include/string.h"

#include <stddef.h>
#include <stdint.h>

size_t strlen(const char *str) {
	size_t len = 0;
	while(str[len])
		len++;
	return len;
}

void *memset(void *s, int c, size_t n) {
	char *str = (char*) s;
	for (size_t i = 0; i < n; i++) {
		str[i] = c;
	}
	return s;
}

char *strcpy(char *dst, const char *src) {
	size_t len = strlen(src);
	for (size_t i = 0; i <= len; i++) {
		dst[i] = src[i];
	}
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	size_t l1 = strlen(s1);
	size_t l2 = strlen(s2);

	if (l1 < l2) return -1;
	else if (l1 > l2) return 1;
	else for (size_t i = 0; i < l1; i++) {
		char c1 = s1[i];
		char c2 = s2[i];
		if (c1 < c2) return -1;
		else if (c1 > c2) return 1;
	}

	return 0;
}
