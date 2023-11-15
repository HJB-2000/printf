#include "main.h"
/**
 * _printf - Printf function.
 * @format: Format string.
 *
 * This function emulates the behavior of the standard printf function. It
 * takes a format string (@format) and prints the specified characters to the
 * standard output. The return value indicates the number of characters
 * successfully printed.
 *
 * Return: Number of characters printed.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_c = 0;
	int _flag, _width, _precision, _size, buff_id = 0;
	va_list args;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_id++] = format[i];
			if (buff_id == BUFF_SIZE)
				_buff(buff, &buff_id);
			printed_c++;
		}
		else
		{
			_buff(buff, &buff_id);
			_flag = call_flag(format, &i);
			_width = call_width(format, &i, args);
			_precision = call_precision(format, &i, args);
			_size = call_size(format, &i);
			++i;
			printed = _specifier(format, &i, args, buff,
					_flag, _width, _precision, _size);
			if (printed == -1)
				return (-1);
			printed_c += printed;
		}
	}

	_buff(buff, &buff_id);
	va_end(args);
	return (printed_c);
}
