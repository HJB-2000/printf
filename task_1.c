#include "main.h"


/**
 * _int - Outputs an integer.
 * @forme: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the integer.
 *
 * This function prints an integer based on the provided
 * arguments. It utilizes a buffer array for efficient printing
 * and considers formatting parameters such as width, precision,
 * and size during the printing process. The return value
 * indicates the number of characters successfully printed.
 *
 * Return: Number of characters successfully printed.
 */

int _int(va_list forme, char buff[],
	int _flag, int _width, int _precision, int _size)
{
	int a = BUFF_SIZE - 2;
	int negative = 0;
	long int n = va_arg(forme, long int);
	unsigned long int number;

	n = convert_num(n, _size);

	if (n == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		negative = 1;
	}

	for (; number > 0;)
	{
		buff[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (write_number(negative, a, buff, _flag, _width, _precision, _size));
}
