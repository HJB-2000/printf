#include "main.h"
/**
 * write_char - Outputs a character.
 * @c: Char type to be printed.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specifier for printing.
 * @_size: Size specifier for the character.
 *
 * This function prints a single character specified by
 * the 'c' parameter. It utilizes a buffer array for
 * efficient printing and considers formatting parameters
 * such as width, precision, and size during the printing process.
 * The return value indicates the number of characters
 * successfully printed.
 *
 * Return: Number of characters successfully printed
 *  (1 if successful, 0 otherwise).
 */

int write_char(char c, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	int a = 0;
	char p = ' ';

	UNUSED(_precision);
	UNUSED(_size);

	if (_flag & ZERO_FLAG)
		p = '0';

	buff[a++] = c;
	buff[a] = '\0';

	if (_width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < _width - 1; a++)
			buff[BUFF_SIZE - a - 2] = p;

		if (_flag & MINUS_FLAG)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - a - 1], _width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - a - 1], _width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}
/**
 * write_number - Outputs a numerical value.
 * @negative: Indicates if the number is negative.
 * @a: Character type to be printed.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specifier for printing.
 * @_size: Size specifier for the numerical value.
 *
 * This function is responsible for formatting and printing
 * numerical values.It considers various parameters such as width,
 * precision, and flags during the printing process.
 * The return value indicates the number of characters
 * successfully printed.
 *
 * Return: Number of characters successfully printed.
 */
int write_number(int negative, int a, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	int len = BUFF_SIZE - a - 1;
	char p = ' ', ch = 0;

	UNUSED(_size);

	if ((_flag & ZERO_FLAG) && !(_flag & MINUS_FLAG))
		p = '0';
	if (negative)
		ch = '-';
	else if (_flag & PLUS_FLAG)
		ch = '+';
	else if (_flag & SPACE_FLAG)
		ch = ' ';

	return (write_num(a, buff, _flag, _width, _precision,
				len, p, ch));
}
