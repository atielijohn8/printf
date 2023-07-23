#include "main.h"
/**
 * parser - Analyze format of string and process conversion specifiersd.
 * @format: format string containing the conversion specifiers.
 * @funct_list:  array of conversion functions with, symbols.
 * @args: variable-length argument list containing data of conversion.
 *
 * Return: number characters to be printed.
 */
int parser(const char *format, conver_t funct_list[], va_list args)
{
	int i, j, r_val, prints_chars;

	prints_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; funct_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == funct_list[j].sym[0])
				{
					r_val = funct_list[j].f(args);
					if (r_val == -1)
						return (-1);
					prints_chars += r_val;
					break;
				}
			}
			if (funct_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					prints_chars = prints_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			prints_chars++;
		}
	}
	return (prints_chars);
}
