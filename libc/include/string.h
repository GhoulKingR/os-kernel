#ifndef __STRING_H__
#define __STRING_H__

#include <stddef.h>

size_t strlen(const char *str);
void *memset(void *s, int c, size_t n);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);

#endif
