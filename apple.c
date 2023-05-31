#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * print_add - prints the address of an input variable
 * @arg: input address.
 * @buffer: buffer pointer.
 * @ibuffer: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int print_add(va_list arg, char *buffer, unsigned int ibuffer)
{
	void *add;
	long int int_input;
	int i, count, first_digit, isnegative;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(arg, void *));
	if (add == NULL)
	{
	for (e = 0; nill[e]; e++)
		ibuffer = handl_buffer(buffer, nill[e], ibuffer);
	return (5);
	}
	int_input = (intptr_t)add;
	isnegative = 0;
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	ibuffer = handl_buffer(buffer, '0', ibuffer);
	ibuffer = handl_buffer(buffer, 'x', ibuffer);
	for (first_digit = e = count = 0; hexadecimal[e]; i++)
	{
		if (hexadecimal[e] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuffer = handl_buffer(buffer, hexadecimal[e], ibuffer);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}

