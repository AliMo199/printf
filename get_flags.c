#include "main.h"

/**
 * get_flags - Calculate active flags
 * @format: Formatted string in which to print args
 * @i: a parameter.
 * 
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flag = 0;
	const char FLACS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLACS_CHAR[j] != '\0'; j++)
			if (format[curr_i] == FLACS_CHAR[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}

		if (FLACS_CHAR[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flag);
}
