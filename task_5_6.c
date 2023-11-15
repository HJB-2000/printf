#include "main.h"
/*______________________task: 5______________________*/

/*___________________non_printable : S___________________*/
/**
 * _non_printable - Prints ASCII codes in hexadecimal
 *   of non-printable characters.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier.
 *
 * This function prints the ASCII codes in hexadecimal
 * of non-printable characters based on the provided arguments.
 * It utilizes a buffer array for efficient printing and
 * considers formatting parameters such as width, precision, and
 * size during the printing process. The return value indicates
 * the number of characters successfully printed.
 *
 * Return: Number of characters printed.
 */


int _non_printable(va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	int a = 0, b = 0;
	char *string = va_arg(args, char *);

	UNUSED(_flag);
	UNUSED(_width);
	UNUSED(_precision);
	UNUSED(_size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[a] != '\0')
	{
		if (string[a] >= 32 && string[a] < 127)
		{
			buff[a + b] = string[a];
		}
		else
		{
			char map_to[] = "0123456789ABCDEF";

			int ascii = string[a];

			if (ascii < 0)
				ascii *= -1;

			buff[a + b++] = '\\';
			buff[a + b++] = 'x';

			buff[a + b++] = map_to[ascii / 16];
			buff[a + b] = map_to[ascii % 16];
		}

		a++;
	}

	buff[a + b] = '\0';

	return (write(1, buff, a + b));
}


/*_______________________________________________________*/
/*_____________________task : 6______________________________*/
/*_______________________________________________________*/
/**
 * _pointer - Prints the value of a pointer variable.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the pointer.
 *
 * This function prints the value of a pointer variable
 * based on the provided arguments. It utilizes a buffer
 * array for efficient printing and considers formatting
 * parameters such as width, precision, and size during the printing
 * process. The return value indicates the number of characters
 * successfully printed.
 *
 * Return: Number of characters printed.
 */

int _pointer(va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	char c = 0, p = ' ';
	int id = BUFF_SIZE - 2, len = 2, p_start = 1; /* length=2, for '0x' */
	unsigned long number_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(_width);
	UNUSED(_size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(_precision);

	number_addrs = (unsigned long)addrs;

	for (; number_addrs > 0;)
	{
		buff[id--] = map_to[number_addrs % 16];
		number_addrs /= 16;
		len++;
	}

	if ((_flag & ZERO_FLAG) && !(_flag & MINUS_FLAG))
		p = '0';
	if (_flag & PLUS_FLAG)
		c = '+', len++;
	else if (_flag & SPACE_FLAG)
		c = ' ', len++;

	id++;

	return (write_p(buff, id, len, _width, _flag, p, c, p_start));
}

/*_____________________________________________________________*/
