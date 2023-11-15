#include "main.h"

/*____________________reversed string : r__________*/
/**
 * _reverse - Prints a reversed string.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier.
 *
 * This function prints a reversed string based on the provided arguments. It
 * utilizes a buffer array for efficient printing and considers formatting
 * parameters such as width, precision, and size during the printing process.
 * The return value indicates the number of characters successfully printed.
 *
 * Return: Number of characters printed.
 */


int _reverse(va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(_flag);
	UNUSED(_width);
	UNUSED(_size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(_precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/*_______________ROT13 : R____________________________________*/
/**
 * print_rot13string - Print a string in ROT13.
 * @args: Argument list.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier for the string.
 *
 * This function prints a string in ROT13 encoding based on the provided
 * arguments. It utilizes a buffer array for efficient printing and considers
 * formatting parameters such as width, precision, and size during the printing
 * process. The return value indicates the number of characters successfully
 * printed.
 *
 * Return: Number of characters printed.
 */

int _rot13string(va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	char w;
	char *string;
	unsigned int a, b;
	int co = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(args, char *);
	UNUSED(buff);
	UNUSED(_flag);
	UNUSED(_width);
	UNUSED(_precision);
	UNUSED(_size);

	if (string == NULL)
		string = "(AHYY)";
	for (a = 0; string[a]; a++)
	{
		for (b = 0; input[b]; b++)
		{
			if (input[b] == string[b])
			{
				w = output[b];
				write(1, &b, 1);
				co++;
				break;
			}
		}
		if (!input[b])
		{
			w = string[a];
			write(1, &w, 1);
			co++;
		}
	}
	return (co);
}
