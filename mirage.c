#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
* is_printable -  This will access the printability of a character
* @c: The character in question
*
* Return: 1 if c is true, 0 otherwise
*/
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
* fix_hex_code - This will include ascii values in hexadecimal code to buffer
* @buffer: The array of characters in question
* @m: The appending index
* @ascii_code: ASCII CODE.
* Return: Always 3
*/
int fix_hex_code(char ascii_code, char buffer[], int m)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hex format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[m++] = '\\';
	buffer[m++] = 'x';

	buffer[m++] = map_to[ascii_code / 16];
	buffer[m] = map_to[ascii_code % 16];

	return (3);
}

/**
* is_digit - This will verify if a character is a numeral
* @c: The character in question
 *
 * Return: 1 if c is numerical, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - This changes a number to the specified size
 * @num: The number in question
 * @size: The number of type to be set aside
 *
 * Return: The value of num set aside
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - This will set a number to the specified size
 * @num: The number in question
 * @size: The size in question
 *
 * Return: The value of num set aside
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
