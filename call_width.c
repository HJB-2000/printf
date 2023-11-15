#include "main.h"

/**
 * call_width - Calculates the width for printing.
 * @format: Formatted string in which to print the arguments.
 * @a: Parameter used in the calculation.
 * @printed_args: List of arguments to be printed.
 *
 * This function determines and returns the width for printing based on the
 * formatted string (@format), a parameter (@a),
 *   and a list of arguments (@printed_args).
 * The result represents the calculated width for formatting the output.
 *
 * Return: Calculated width for printing.
 */
int call_width(const char *format, int *a, va_list printed_args)
{
	int x = *a + 1;
	int _width = 0;

	while (format[x] != '\0')
	{
		if (digit(format[x]))
		{
			_width *= 10;
			_width += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			_width = va_arg(printed_args, int);
			break;
		}
		else
		{
			break;
		}
		x++;
	}

	*a = x - 1;

	return (_width);
}
