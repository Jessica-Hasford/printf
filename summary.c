#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * prinlint - prints a long integer
 * @arg: input string
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int prinlint(va_list arg, char *buffer, unsigned int ibuffer)
{
long int int_input;
unsigned long int int_in, int_temp, u, div, isneg;

int_input = va_arg(arg, long int);
isneg = 0;
if (int_input < 0)
{
int_in = int_input * -1;
ibuffer = handl_buffer(buffer, '-', ibuffer);
isneg = 1;
}
else
{
int_in = int_input;
}

int_temp = int_in;
div = 1;
while (int_temp > 9)
{
div *= 10;
int_temp /= 10;
}
for (u = 0; div > 0; div /= 10, u++)
{
ibuffer = handl_buffer(buffer, ((int_in / div) % 10) + '0', ibuffer);
}
return (u + isneg);
}
