#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>


/**
 * print_buffer- prints buffer
 * @buffer: buffer pointer
 * @nbuffer: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buffer(char *buffer, unsigned int nbuffer)
{
	return (write(1, buffer, nbuffer));
}

