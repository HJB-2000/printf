#include "main.h"

/**
 * call_flag - Calculates active flags based on a formatted string.
 * @format: Formatted string in which to print the arguments.
 * @position: Parameter used in the calculation.
 *
 *
 * This function calculates and returns active flags based on the formatted
 * string (@format) and an additional parameter (@i). The result represents the
 * flags that influence printing behavior.
 *
 * Return: Active flags determined from the provided format.
 */

int call_flag(const char *format, int *position)
{
	int x;
	int y;
	int _flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS_FLAG, PLUS_FLAG, ZERO_FLAG,
		HASH_FLAG, SPACE_FLAG, 0};

	y = *position + 1;

	while (format[y] != '\0')
	{
		x = 0;
		while (FLAGS_CH[x] != '\0')
		{
			if (format[y] == FLAGS_CH[x])
			{
				_flag |= FLAGS_ARR[x];
				break;
			}
			x++;
		}

		if (FLAGS_CH[x] == 0)
			break;

		y++;
	}

	*position = y - 1;

	return (_flag);
}
