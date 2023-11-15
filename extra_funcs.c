#include "main.h"
/*________________________________1__________________________________________*/
/**
 * convert_num - number - Casts a number to a specified size.
 * @number: Number to be casted.
 * @_size: Type indicator for the casting operation.
 *
 * This function performs typecasting on the given number
 * based on the specified size. The result is the casted value
 * of num according to the indicated type.
 *
 * Return: The casted value of num.
 */

long int convert_num(long int number, int _size)
{
	if (_size == S_LONG)
		return (number);
	else if (_size == S_SHORT)
		return ((short)number);

	return ((int)number);
}
/*__________________________________________________________________________*/
/*_________________________________2_________________________________________*/

/**
 * _buff - Prints the contents of the buffer if it exists.
 * @buff: Array of characters.
 * @buff_id: Index at which to add the next character, representing the length.
 *
 * This function prints the contents of the buffer if it exists. It takes an
 * array of characters (@buff) and an index (@buff_id) representing the length
 * of the buffer. If the buffer is non-empty, its contents are printed.
 */

void _buff(char buff[], int *buff_id)
{
	if (*buff_id > 0)
		write(1, &buff[0], *buff_id);

	*buff_id = 0;
}
/*__________________________________________________________________________*/
/*__________________________________3________________________________________*/
/**
 * digit - Verifies if a character is a digit.
 * @c: Character to be evaluated.
 *
 * This function checks if the given character (@c) is a digit. It returns 1 if
 * the character is a digit and 0 otherwise.
 *
 * Return: 1 if @c is a digit, 0 otherwise.
 */

int digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/*__________________________________________________________________________*/
/*___________________________________4_______________________________________*/
/**
 * write_num - Writes a number using a buffer.
 * @id: Index at which the number starts on the buffer.
 * @buff: Buffer.
 * @_flag: Flags.
 * @_width: Width.
 * @_precion: Precision specifier.
 * @len: Number length.
 * @p: Padding character.
 * @c: Extra character.
 *
 * This function writes a number to the buffer, starting at the specified index
 * (@ind). It considers various parameters such as flags, width, precision,
 * length, padding, and an extra character during the printing process. The
 * return value indicates the number of characters successfully printed.
 *
 * Return: Number of printed characters.
 */


int write_num(int id, char buff[],
		int _flag, int _width, int _precion,
		int len, char p, char c)
{
	int x, p_start = 1;

	if (_precion == 0 && id == BUFF_SIZE - 2 && buff[id] == '0' && _width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (_precion == 0 && id == BUFF_SIZE - 2 && buff[id] == '0')
		buff[id] = p = ' '; /* width is displayed with padding ' ' */
	if (_precion > 0 && _precion < len)
		p = ' ';
	while (_precion > len)
		buff[--id] = '0', len++;
	if (c != 0)
		len++;
	if (_width > len)
	{
		for (x = 1; x < _width - len + 1; x++)
			buff[x] = p;
		buff[x] = '\0';
		if (_flag & MINUS_FLAG && p == ' ')/* Asign extra char to left of buffer */
		{
			if (c)
				buff[--id] = c;
			return (write(1, &buff[id], len) + write(1, &buff[1], x - 1));
		}
		else if (!(_flag & MINUS_FLAG) && p == ' ')/* extra char to left of buff */
		{
			if (c)
				buff[--id] = c;
			return (write(1, &buff[1], x - 1) + write(1, &buff[id], len));
		}
		else if (!(_flag & MINUS_FLAG) && p == '0')/* extra char to left of padd */
		{
			if (c)
				buff[--p_start] = c;
			return (write(1, &buff[p_start], x - p_start) +
					write(1, &buff[id], len - (1 - p_start)));
		}
	}
	if (c)
		buff[--id] = c;
	return (write(1, &buff[id], len));
}
