#include "main.h"
#include <stdarg.h>
#include <unistd.h>

size_t _strlen(const char *str);
/**
 * _printf - Printf function.
 * @format: Format string.
 *
 * This function emulates the behavior of the standard printf function. It
 * takes a format string (@format) and prints the specified characters to the
 * standard output. The return value indicates the number of characters
 * successfully printed.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char ch = (char)va_arg(args, int);

						count += write(1, &ch, 1);
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);

					if (str == NULL)
					{
						str = "(null)";
					}
					count += write(1, str, _strlen(str));
					break;
					}
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					break;
			}
		} else
		{
			count += write(1, format, 1);
		}

		format++;
	}

	va_end(args);
	return (count);
}
/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * This function calculates and returns the length of the given string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

