#include "main.h"
#include <stdarg.h>
#include <unistd.h>


/**
 * nab_size - This will sum up the size to use in this the argument
 * @format: This will format the string to display the arguments
 * @b: The arguments being used in this function
 *
 * Return: The precision of this function
 */
int nab_size(const char *format, int *b)
{
	int curr_b = *b + 1;
	int size = 0;

	if (format[curr_b] == 'l')
		size = S_LONG;
	else if (format[curr_b] == 'h')
		size = S_SHORT;

	if (size == 0)
		*b = curr_b - 1;
	else
		*b = curr_b;

	return (size);
}

