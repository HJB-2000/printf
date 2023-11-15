#include "main.h"

/*______________"u" : print an unsigned___________________*/
/**
 * _unsigned - Prints an unsigned number.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the number.
 *
 * This function prints an unsigned number based on the provided arguments.
 * It utilizes a buffer array for efficient printing and considers formatting
 * parameters such as width, precision, and size during the printing process.
 * The return value indicates the number of characters successfully printed.
 *
 * Return: Number of characters printed.
 */
int _unsigned(va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

	number = convert_unsgnd(number, _size);

	if (number == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	for (; number > 0;)
	{
		buff[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buff, _flag, _width, _precision, _size));
}
/*__________________________________________________________________________*/
/*_________________"o": print an unsigned octal integer_____________________*/
/**
 * _octal - Prints an unsigned number in octal notation.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the number.
 *
 * This function prints an unsigned number in octal notation
 * based on the provided arguments. It utilizes a buffer array
 * for efficient printing and considers formatting parameters
 * such as width, precision, and size during the printing process.
 * The return value indicates the number of characters successfully
 * printed.
 *
 * Return: Number of characters printed.
 */
int _octal(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size)
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
		buff[a--] = (number % 8) + '0';
		number /= 8;
	}

	if (_flag & HASH_FLAG && init_number != 0)
		buff[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buff, _flag, _width, _precision, _size));
}

/*_________________________________________________________________________*/
/*__________"x": prints the hexadecimal digits in lowercase________________*/
/**
 * _hexadecimal_low - Prints an unsigned number in hexadecimal notation.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the number.
 *
 * This function prints an unsigned number in hexadecimal notation (lowercase)
 * based on the provided arguments. It utilizes a buffer array for efficient
 * printing and considers formatting parameters such as width, precision, and
 * size during the printing process. The return value indicates the number of
 * characters successfully printed.
 *
 * Return: Number of characters printed.
 */
int _hexadecimal_low(va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
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
		buff[a--] = "0123456789abcdef"[number % 16];
		number /= 16;
	}

	if (_flag & HASH_FLAG && init_number != 0)
	{
		buff[a--] = 'x';
		buff[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buff, _flag, _width, _precision, _size));
}
/*___________________________________________________________________________*/
/*__________________"X": prints the hexadecimal digits in uppercase__________*/
/**
 * _hexa_upper - Prints an unsigned number in upper hexadecimal notation.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the number.
 *
 * This function prints an unsigned number in upper hexadecimal notation based
 * on the provided arguments. It utilizes a buffer array for efficient printing
 * and considers formatting parameters such as width, precision, and size
 * during the printing process. The return value indicates the number
 * of characters successfully printed.
 *
 * Return: Number of characters printed.
 */
int _hexa_upper(va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	return (write_hexa_up(args, "0123456789ABCDEF", buff,
				_flag, 'X', _width, _precision, _size));
}
