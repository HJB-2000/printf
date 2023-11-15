#include "main.h"


/**
 * _char - Outputs a single character.
 * @forme: Input argument representing the character to be printed.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the character.
 *
 * This function is responsible for printing a single character based on the
 * provided arguments. It utilizes a buffer array for efficient printing and
 * considers formatting parameters such as width, precision, and size during
 * the printing process. The return value indicates the number of characters
 * successfully printed.
 *
 * Return: Number of characters successfully printed.
 */

int _char(va_list forme, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	char c = va_arg(forme, int);

	return (write_char(c, buff, _flag, _width, _precision, _size));
}
/*_________________________________________________________________________*/
/**
 * _string - Outputs a string.
 * @forme: Argument list containing the string to be printed.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the string.
 *
 * This function is responsible for printing a string based on the provided
 * arguments. It utilizes a buffer array for efficient printing and considers
 * formatting parameters such as width, precision, and size during the printing
 * process. The return value indicates the number of characters successfully
 * printed.
 *
 * Return: Number of characters successfully printed.
 */
int _string(va_list forme, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	int len = 0, a;
	char *string = va_arg(forme, char *);

	UNUSED(buff);
	UNUSED(_flag);
	UNUSED(_size);
	if (string == NULL)
	{
		string = "(null)";
		if (_precision >= 6)
			string = "      ";
	}

	for (; string[len] != '\0'; len++)
		;

	if (_precision >= 0 && _precision < len)
		len = _precision;

	if (_width > len)
	{
		if (_flag & MINUS_FLAG)
		{
			write(1, string, len);
			for (a = _width - len; a > 0; a--)
				write(1, " ", 1);
			return (_width);
		}
		else
		{
			for (a = _width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, string, len);
			return (_width);
		}
	}

	return (write(1, string, len));
}
/*_______________________________________________________________*/
/**
 * _percent - Outputs a percent sign.
 * @forme: Argument list (unused).
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the percent sign.
 *
 * This function prints a percent sign. While the argument list (forme) is not
 * used, the function utilizes a buffer array for efficient printing.
 * Formatting parameters such as width, precision, and size are considered
 * during the printing process. The return value indicates the number
 * of characters successfully printed.
 *
 * Return: Number of characters successfully printed.
 */
int _percent(va_list forme, char buff[],
	int _flag, int _width, int _precision, int _size)
{
	UNUSED(forme);
	UNUSED(buff);
	UNUSED(_flag);
	UNUSED(_width);
	UNUSED(_precision);
	UNUSED(_size);
	return (write(1, "%%", 1));
}
