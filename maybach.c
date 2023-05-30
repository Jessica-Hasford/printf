#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * nab_precision - This will specify the precision needed in the function
 * @sym: This will format the string to display the arguments
 * @v: The list of arguments to be displayed
 * @jess: The arguments in this function
 * @format: The parameter in question
 * Return: Precision.
 */
int nab_precision(const char *format, int *v, va_list jess)
{
	int curr_v = *v + 1;
	int precision = -1;

	if (sym[curr_v] != '.')
		return (precision);

	precision = 0;

	for (curr_v += 1; sym[curr_v] != '\0'; curr_v++)
	{
		if (is_digit(sym[curr_i]))
		{
			precision *= 10;
			precision += sym[curr_v] - '0';
		}
		else if (sym[curr_v] == '*')
		{
			curr_v++;
			precision = va_arg(jess, int);
			break;
		}
		else
			break;
	}

	*v = curr_v - 1;

	return (precision);
}
