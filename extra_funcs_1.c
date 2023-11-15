#include "main.h"
/**
 * convert_unsgnd - Casts a number to a specified size.
 * @number: Number to be casted.
 * @_size: Type indicator for the casting operation.
 *
 * This function casts the given number (@number) to
 * a specified size based on theprovided type indicator
 * (@_size). The result represents the casted value of
 * the number.
 *
 * Return: The casted value of num.
 */

long int convert_unsgnd(unsigned long int number, int _size)
{
	if (_size == S_LONG)
		return (number);
	else if (_size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
/*________________________________________________________________________*/
/**
 * write_unsgnd - Writes an unsigned number
 * @negative: Number indicating if the num is negative
 * @id: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @_flag: Flags specifiers
 * @_width: Width specifier
 * @_precision: Precision specifier
 * @_size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int negative, int id, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	int len = BUFF_SIZE - id - 1, x = 0;
	char p = ' ';

	UNUSED(negative);
	UNUSED(_size);

	if (_precision == 0 && id == BUFF_SIZE - 2 && buff[id] == '0')
		return (0);

	if (_precision > 0 && _precision < len)
		p = ' ';

	for (; _precision > len;)
	{
		buff[--id] = '0';
		len++;
	}

	if ((_flag & ZERO_FLAG) && !(_flag & MINUS_FLAG))
		p = '0';

	if (_width > len)
	{
		for (x = 0; x < _width - len; x++)
			buff[x] = p;

		buff[x] = '\0';

		if (_flag & MINUS_FLAG)
		{
			return (write(1, &buff[id], len) + write(1, &buff[0], x));
		}
		else
		{
			return (write(1, &buff[0], x) + write(1, &buff[id], len));
		}
	}

	return (write(1, &buff[id], len));
}

/*________________________________________________________________________*/
/**
 * write_hexa_up - Prints a hexadecimal number in lower or upper case.
 * @args: Argument list.
 * @map_to: Array of values to map the number to.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_flag2: Calculation of active flags (character).
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the number.
 * @_size: Size specification.
 *
 * This function prints a hexadecimal number in either lower
 * or upper case based on the provided arguments. It utilizes
 * a buffer array for efficient printing and considers formatting
 * parameters such as flags, width, precision, and size during the
 * printing process. The return value indicates the number of
 * characters successfully printed.
 *
 * Return: Number of characters printed.
 */
int write_hexa_up(va_list args, char map_to[], char buff[],
		int _flag, char _flag2, int _width, int _precision, int _size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(_width);

	number = convert_unsgnd(number, _size);

	if (number == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	for (; number > 0;)
	{
		buff[a--] = map_to[number % 16];
		number /= 16;
	}

	if (_flag & HASH_FLAG && init_number != 0)
	{
		buff[a--] = _flag2;
		buff[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buff, _flag, _width, _precision, _size));
}

