#include "main.h"
/**
 * write_p - Writes a memory address.
 * @buff: Array of characters.
 * @id: Index at which the number starts in the buffer.
 * @len: Length of the number.
 * @_width: Width specifier.
 * @_flag: Flags specifier.
 * @p: Character representing the padding.
 * @c: Character representing an extra character.
 * @p_start: Index at which padding should start.
 *
 * This function writes a memory address to the buffer,
 * starting at the specified index (@id). It considers
 * various parameters such as length, width, flags,padding,
 * and an extra character during the writing process. The return value
 * indicates the number of characters successfully written.
 *
 * Return: Number of written characters.
 */

int write_p(char buff[], int id, int len, int _width,
		int _flag, char p, char c, int p_start)
{
	int a = 3;

	if (_width > len)
	{
		while (a < _width - len + 3)
			buff[a++] = p;

		buff[a] = '\0';

		if ((_flag & MINUS_FLAG) && p == ' ')
			return (write(1, &buff[--id], len) + write(1, &buff[3], a - 3));

		if (!(_flag & MINUS_FLAG) && p == ' ')
			return (write(1, &buff[3], a - 3) + write(1, &buff[--id], len));

		if (!(_flag & MINUS_FLAG) && p == '0')
			return (write(1, &buff[p_start], a - p_start) +
					write(1, &buff[id], len - (1 - p_start) - 2));
	}

	buff[--id] = 'x';
	buff[--id] = '0';

	if (c)
		buff[--id] = c;

	return (write(1, &buff[id], BUFF_SIZE - id - 1));
}
