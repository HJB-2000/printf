#include "main.h"

/**
 * call_precision - Calculates the precision for printing.
 * @format: Formatted string in which to print the arguments.
 * @a: Parameter used in the calculation.
 * @printed_args: List of arguments to be printed.
 *
 * Return: Calculated precision for printing.
 *
 * This function determines and returns the precision for printing based on the
 * formatted string (@format), a parameter (@i),
 *  and a list of arguments (@list).
 * The result represents the calculated precision for formatting the output.
 */

int call_precision(const char *format, int *a, va_list printed_args)
{
	int x = *a + 1;
	int _precision = -1;

	if (format[x] != '.')
		return (_precision);

	_precision = 0;

	x += 1;
	while (format[x] != '\0')
	{
		if (digit(format[x]))
		{
			_precision *= 10;
			_precision += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			_precision = va_arg(printed_args, int);
			break;
		}
		else
		{
			break;
		}
		x++;
	}

	*a = x - 1;

	return (_precision);
}
