#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * nab_width - This will help acquire the  width in this function
 * @format: This will format the string to display the arguments
 * @h: List of arguments to be printed.
 * @jess: list of arguments.
 *
 * Return: width.
 */
int nab_width(const char *format, int *h, va_list jess)
{
	int curr_h;
	int width = 0;

	for (curr_h = *h + 1; sym[curr_h] != '\0'; curr_h++)
	{
		if (is_digit(sym[curr_h]))
		{
			width *= 10;
			width += sym[curr_h] - '0';
		}
		else if (sym[curr_h] == '*')
		{
			curr_h++;
			width = va_arg(jess, int);
			break;
		}
		else
			break;
	}

	*h = curr_h - 1;

	return (width);
}
