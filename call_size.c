#include "main.h"

/**
 * call_size - Calculates the size to cast the argument.
 * @format: Formatted string in which to print the arguments.
 * @a: List of arguments to be printed.
 *
 * This function determines and returns the size for casting the argument based
 * on the formatted string (@format) and a list of arguments (@i). The result
 * represents the calculated size for casting the argument during printing.
 *
 * Return: Calculated size for casting the argument.
 */

int call_size(const char *format, int *a)
{
	int x = *a + 1;
	int _size = 0;

	if (format[x] == 'l')
		_size = S_LONG;
	else if (format[x] == 'h')
		_size = S_SHORT;

	if (_size == 0)
		*a = x - 1;
	else
		*a = x;

	return (_size);
}
