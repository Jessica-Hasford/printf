#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * prinlunt - prints a long unsigned integer
 * @arg: number to print
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int prinlunt(va_list arg, char *buffer, unsigned int ibuffer)
{
unsigned long int int_in, int_temp, j, div;

int_in = va_arg(arg, unsigned long int);
int_temp = int_in;
div = 1;
while (int_temp > 9)
{
div *= 10;
int_temp /= 10;
}
for (j = 0; div > 0; div /= 10, j++)
{
ibuffer = handl_buffer(buffer, ((int_in / div) % 10) + '0', ibuffer);
}
return (j);
}

