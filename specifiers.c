#include "main.h"
/**
 * handle_print - Prints an argument based on its type.
 * @specifier: Formatted string indicating how to print the arguments.
 * @args: List of arguments to be printed.
 * @id: Index.
 * @buff: Buffer array used for printing.
 * @_flag: Calculation of active flags during printing.
 * @_width: Width parameter for formatting.
 * @_precision: Precision specification for printing.
 * @_size: Size specifier.
 *
 * This function handles the printing of an argument based on its type, as
 * specified by the formatted string (@specifier). It uses a buffer array
 * (@buff) for efficient printing and considers various formatting parameters
 * such as flags, width, precision, and size. The return value indicates
 * the success of the printing operation.
 *
 * Return: 1 or 2; indication of success.
 **/
int _specifier(const char *specifier, int *id, va_list args, char buff[],
		int _flag, int _width, int _precision, int _size)
{
	int i, len = 0, printed = -1;

	specifier_type specifier_types[] = {
		{'c', _char}, {'s', _string}, {'%', _percent},
		{'i', _int}, {'d', _int}, {'b', _binary}, {'u', _unsigned},
		{'o', _octal}, {'x', _hexadecimal_low}, {'X', _hexa_upper},
		{'S', _non_printable}, {'p', _pointer}, {'r', _reverse},
		{'R', _rot13string}, {'\0', NULL}
	};
	for (i = 0; specifier_types[i].specifier != '\0'; i++)
		if (specifier[*id] == specifier_types[i].specifier)
			return (specifier_types[i].fun_associated(args, buff,
					_flag, _width, _precision, _size));

	if (specifier_types[i].specifier == '\0')
	{
		if (specifier[*id] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (specifier[*id - 1] == ' ')
			len += write(1, " ", 1);
		else if (_width)
		{
			--(*id);
			while (specifier[*id] != ' ' && specifier[*id] != '%')
				--(*id);
			if (specifier[*id] == ' ')
				--(*id);
			return (1);
		}
		len += write(1, &specifier[*id], 1);
		return (len);
	}
	return (printed);
}
