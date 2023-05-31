#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
 * fill_hex_array - This writes the character c to stdout
 *
 * @bnr: The array where the binary is stored.
 * @hex: The array where the hexadecimal is stored.
 * @isupp: The integer that indicates whether hexadecimal array is
 * in uppercase or lowercase letters.
 * @jess: The size of the hexadecimal in the program
 * @limit: The limit in question
 * Return: The array of binary
 */
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit)
{
	int op, c, p, toletter;

	hex[jess] = '\0';
	if (isupp)
		toletter = 55;
	else
		toletter = 87;
	for (c = (jess * 4) - 1; c >= 0; p--)
	{
	for (op = 0, p = 1; p <= 8; p *= 2, c--)
		op = ((bnr[c] - '0') * p) + op;
		c++;
	if (op < 10)
		hex[c / 4] = op + 48;
	else
		Hex[c / 4] = op + toletter;
	}
	return (hex);
}

