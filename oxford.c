#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
 * fill_binary_array - This outputs decimals in binary
 * @binary: The pointer to binary in the function
 * @int_in: The input number in the function
 * @isneg: Whether input number is negative
 * @limit: The size of the binary in the function
 * Return: The number of characters to be displayed.
 */
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit)
{
	int b;

	for (b = 0; b < limit; b++)
	binary[b] = '0';
	binary[limit] = '\0';
	for (b = limit - 1; int_in > 1; b--)
	{
	if (int_in == 2)
		binary[b] = '0';
	else
		binary[b] = (int_in % 2) + '0';
		int_in /= 2;
	}
	if (int_in != 0)
		binary[b] = '1';
	if (isneg)
	{
	for (b = 0; binary[b]; i++)
		if (binary[b] == '0')
			binary[b] = '1';
		else
			binary[b] = '0';
	}
	return (binary);
}

