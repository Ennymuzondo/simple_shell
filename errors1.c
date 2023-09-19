#include "shell.h"

/**
 * _str_to_int - converts a string to an integer
 * @str: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
int _str_to_int(char *str)
{
	int i = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @error_type: string containing the specified error type
 */
void print_error(info_t *info, char *error_type)
{
	_eputs(info->fname);
	_eputs(": ");
	print_integer(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(error_type);
}

/**
 * print_integer - function prints an integer to the given file descriptor
 * @num: the integer to print
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_integer(int num, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int absolute, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (num < 0)
	{
		absolute = -num;
		__putchar('-');
		count++;
	}
	else
		absolute = num;
	current = absolute;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absolute / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *hex_digits;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	hex_digits = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = hex_digits[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces the first instance of '#' with '\0'
 * @buf: address of the string to modify
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

