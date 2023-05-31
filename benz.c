#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
 * fill_oct_array - This displays the character c to stdout
 *
 * @bnr: array where the binary is stored.
 * @oct: array where the octal is stored.
 *@jess: size of oct
 * Return: binary array.
 */
char *fill_oct_array(char *bnr, char *oct)
{
	int op, f, u, ioct, jess;

	oct[11] = '\0';
	for (f = 31, ioct = 10; f >= 0; f--, ioct--)
	{
	if (f > 1)
		jess = 4;
	else
		jess = 2;
	for (op = 0, u = 1; u <= jess; u *= 2, f--)
		op = ((bnr[f] - '0') * u) + op;
	f++;
	oct[ioct] = op + '0';
	}
	return (oct);
}

