#include "main.h"
/**
 * print_number - Prints a signed integer.
 * @args: variable length arg list containing  integer to printed.
 *
 * Return: number characters printed.
 */
int print_number(va_list args)
{
	int n;
	int check;
	int len;
	unsigned int numb;

	n  = va_arg(args, int);
	check = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		numb = n * -1;
	}
	else
		numb = n;

	for (; numb / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		len += _putchar('0' + numb / check);
		numb %= check;
		check /= 10;
	}

	return (len);
}
/**
 * print_unsgined_number - Print an unsigned num.
 * @n: unsigned integer to print.
 *
 * Return: character to print.
 */
int print_unsgined_number(unsigned int n)
{
	int check;
	int len;
	unsigned int numb;

	check = 1;
	len = 0;

	numb = n;

	for (; numb / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		len += _putchar('0' + numb / check);
		numb %= check;
		check /= 10;
	}

	return (len);
}
/**
 * p_char - Print  character.
 * @args:  variable-len arg  containing  character to  print
 *
 * Return: 0 (succsess)
 */

int p_char(va_list args)
{
	char value;

	value = va_arg(args, int);
	_putchar(value);
	return (1);
}
/**
 * p_string - Print  string.
 * @args: variable-len arg list containing  string to be printed.
 *
 * Return: number of characters to print
 */

int p_string(va_list args)
{
	int i;
	const char *s;

	s = va_arg(args, const char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}
/**
 * p_percent - Print the percentage character '%'.
 * @args: The variable-len arg list
 *
 * Return: returns 1.
 */

int p_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
/**
 * p_integer - Print integer.
 * @args: variable-len arg list containing the integer to print.
 *
 * Return: character number to be printed
 */

int p_integer(va_list args)
{
	int n;

	n = print_number(args);
	return (n);

}
