#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * print_bnr - prints decimal in binary
 * @arg: input string
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of characters  printed.
 */
int print_bnr(va_list arg, char *buffer, unsigned int ibuffer)
{
int int_input, count, i, first_one, isnegative;
char *binary;

int_input = va_arg(arguments, int);
isnegative = 0;
if (int_input == 0)
{
ibuffer = handl_buffer(buffer, '0', ibuffer);
return (1);
}
if (int_input < 0)
{
int_input = (int_input * -1) - 1;
isnegative = 1;
}
binary = malloc(sizeof(char) * (32 + 1));
binary = fill_binary_array(binary, int_input, isnegative, 32);
first_one = 0;
for (count = h = 0; binary[h]; h++)
{
if (first_one == 0 && binary[h] == '1')
first_one = 1;
if (first_one == 1)
{
ibuffer = handl_buffer(buffer, binary[h], ibuffer)
count++;
}
}
free(binary);
return (count);
}

