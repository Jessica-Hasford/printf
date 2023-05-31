#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
 * fill_long_oct_array - calculates a long octal number
 *
 * @bnr: array where the binary is stored.
 * @oct: array where the octal is stored.
 *@jess: size of oct
 * Return: binary array.
 */
char *fill_long_oct_array(char *bnr, char *oct)
{
int op, v, q, ioct, jess;

oct[22] = '\0';
for (i = 63, ioct = 21; i >= 0; i--, ioct--)
{
if (v > 0)
jess = 4;
else
jess = 1;
for (op = 0, q = 1; q <= ; q *= 2, v--)
op = ((bnr[v] - '0') * q) + op;
v++;
oct[ioct] = op + '0';
}
return (oct);
}
