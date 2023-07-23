#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * struct convert - Conversion of  structure fort the format specifiers.
 * @sym: at format specifier symbols
 * @f:corresponding conversion function of  format specifier.
 */

struct convert
{
	char *sym;
	int (*f)(va_list);
};

typedef struct convert conver_t;
int _putchar(char c);
int _printf(const char *format, ...);
int print_unsgined_number(unsigned int n);
int print_number(va_list);
int p_integer(va_list);
void _vprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[], va_list args);
int p_char(va_list);
int p_string(va_list args);
int p_percent(va_list);

#endif
