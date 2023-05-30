#include "main.h"
#include <stdarg.h>
#include <unistd.h>


/**
 * nab_flags - This will round up the active flags of this function
 * @sym: This will format the string to display the arguments
 * @d: The parameter in question
 * @format: The format in question
 * Return: The flags in the function
 */
int nab_flags(const char *format, int *d)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_d;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_d = *d + 1; format[curr_d] != '\0'; curr_d++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_d] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*d = curr_d - 1;

	return (flags);
}

