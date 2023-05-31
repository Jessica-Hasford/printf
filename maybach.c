#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
 * fill_short_oct_array - This sums a short octal number
 *
 * @bnr: The array where the binary is stored.
 * @oct: The array where the octal is stored.
 *@jess: The size of oct in the program
 * Return: The array of binary in the function
 */
char *fill_short_oct_array(char *bnr, char *oct)
{
int op, w, z, ioct, jess;

oct[6] = '\0';
for (w = 15, ioct = 5; w >= 0; w--, ioct--)
{
if (w > 0)
jess = 4;
else
jess = 1;
for (op = 0, z = 1; z <= limit; z *= 2, w--)
op = ((bnr[w] - '0') * j) + op;
w++;
oct[ioct] = op + '0';
}
return (oct);
}
