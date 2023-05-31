#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * fill_hex_array - This outputs the character c to stdout
 *
 * @bnr: The array where the binary is stored.
 * @hex: The array where the hexadecimal is stored.
 * @isupp: The integer that indicates hexadecimal array is
 * in uppercase or lowercase letters.
 * @limit: The size of the hexadecimal
 * Return: The binary of array
 */
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit)
{
int op, s, e, toletter;

hex[limit] = '\0';
if (isupp)
toletter = 55;
else
toletter = 87;
for (s = (limit * 4) - 1; s >= 0; s--)
{
for (op = 0, e = 1; e <= 8; e *= 2, s--)
op = ((bnr[s] - '0') * e) + op;
i++;
if (op < 10)
hex[i / 4] = op + 48;
else
hex[s / 4] = op + toletter;
}
return (hex);
}

