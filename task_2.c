#include "main.h"

/**
 * _binary - Prints an unsigned number in binary format.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the number.
 *
 * This function prints an unsigned number in binary format
 * based on the provided arguments. It utilizes a buffer array
 * for efficient printing and considers formatting parameters
 * such as width, precision, and size during the printing process.
 * The return value indicates the number of characters successfully
 * printed.
 *
 * Return: Number of characters printed.
 */


int _binary(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size)
{
	unsigned int a, b, l, s;
	unsigned int w[32];
	int co;

	UNUSED(buff);
	UNUSED(_flag);
	UNUSED(_width);
	UNUSED(_precision);
	UNUSED(_size);

	a = va_arg(args, unsigned int);
	b = 2147483648U; /* (2 ^ 31) */
	w[0] = a / b;

	l = 1;
	while (l < 32)
	{
		b /= 2;
		w[l] = (a / b) % 2;
		l++;
	}

	l = 0;
	s = 0;
	co = 0;

	while (l < 32)
	{
		s += w[l];
		if (s || l == 31)
		{
			char z = '0' + w[l];

			write(1, &z, 1);
			co++;
		}
		l++;
	}

	return (co);
}
