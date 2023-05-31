#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * print_chr - writes the character c to stdout
 * @arg: input characters
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: On success 1.
 */
int print_chr(va_list arg, char *buffer, unsigned int ibuffer)
{
char c;

c = va_arg(arg, int);
handl_buffer(buffer, c, ibuffer);

return (1);
}
