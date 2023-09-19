#include "shell.h"

/**
 * print_error - Prints an error message to stderr
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * @msg: The error message to print
 *
 * Return: Nothing
 */
void print_error(info_t *info, char *msg)
{
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(msg);
	info->status = 2;
}

/**
 * print_error_code - Prints an error message with a custom exit code to stderr
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * @msg: The error message to print
 * @exit_code: The exit code to set
 *
 * Return: Nothing
 */
void print_error_code(info_t *info, char *msg, int exit_code)
{
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(msg);
	info->status = exit_code;
}

/**
 * _erratoi - Converts a string to an integer with error handling
 * @s: The string to be converted
 *
 * Return: The converted integer if successful, or -1 on failure
 */
int _erratoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * _puterror - Writes an error message to stderr
 * @str: The string to be printed
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puterror(char *str)
{
	int i = 0;

	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
	return (1);
}

