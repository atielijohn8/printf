#include "main.h"
#include <stdint.h>

/**
 * _printf - fuction printing output according to format
 * @format: format
 * Return: value
 */

int _printf(const char *format, ...)
{
	int prints_chars;

	conver_t funct_list[] =	{
		{"s", p_string},
		{"c", p_char},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{NULL, NULL}
	};

	va_list args;


	if (format == NULL)
		return (-1);

	va_start(args, format);

	prints_chars = parser(format, funct_list, args);
	va_end(args);

	return (prints_chars);
}
