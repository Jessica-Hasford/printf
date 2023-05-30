#include "main.h"
#include <stdarg.h>
#include <unistd.h>


/**
 * print_unsigned -  This will display an unsigned number to the terminal
 * @est:  The arguments being used in the function
 * @buffer: The array of buffer to display output
 * @flags:  This rounds up the active flags of this function
 * @width: This reference width in the function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_unsigned(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{
	int u = BUFF_SIZE - 2;
	unsigned long int num = va_arg(est, unsigned long int);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
		buffer[u--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[u--] = (num % 10) + '0';
		num /= 10;
	}

	l++;

	return (draft_unsigned int(0, u, buffer, flags, width, precision, size));
}

/**
 *print_oct -This displays an unsigned number in octal notation to the
 *terminal
 *@est: The arguments in this function
 *@buffer: The array of buffer to display the output
 *@flags:  This will round up the active flags of this function
 *@width: This will help acquire the  width in this function
 *@precision: This will specify the precision needed in the function
 *@size: This will specify the size needed in this function
 *Return: The total number of characters to be displayed
 */
int print_oct(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{

	int o = BUFF_SIZE - 2;
	unsigned long int num = va_arg(est, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
		buffer[o--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[o--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[o--] = '0';

	o++;

	return (draft_unsigned int(0, o, buffer, flags, width, precision, size));
}

/**
 * print_hex - This will display an unsigned number in hexadecimal notation
 * @est: The arguments in this function
 * @buffer: The array of buffer to display the output
 * @flags:  This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_hex(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(est, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 *print_HEXA- This will display an unsigned number in upper
 *hexadecimal notation
 *@est: The arguments in this function
 *@buffer: The array of buffer to display the output
 *@flags: This will round up the active flags of this function
 *@width: This will help acquire the  width in this function
 *@precision: This will specify the precision needed in the function
 *@size: This will specify the size needed in this function
 *Return: The total number of characters to be displayed
 */
int print_HEXA(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_HEXA(est, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hex - This will display a hexadecimal number in lower or upper
 * @est: The arguments in this function
 * @map_to: The array of values to map the number to
 * @buffer: The array of buffer to display the output
 * @flags: This will round up the active flags of this function
 * @flag_ch: This will round up the active flags in the function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_hex(va_list est, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int s = BUFF_SIZE - 2;
	unsigned long int num = va_arg(est, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[s--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[s--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[s--] = flag_ch;
		buffer[s--] = '0';
	}

	s++;

	return (draft_unsigned int(0, s, buffer, flags, width, precision, size));
}

