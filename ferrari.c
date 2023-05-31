#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
* handl_buffer - concatenates the buffer characters
* @buffer: buffer pointer
* @c: character to concatenate
* @ibuffer: index of buffer pointer
* Return: index of buffer pointer.
*/
unsigned int handl_buffer(char *buffer, char c, unsigned int ibuffer)
{
if (ibuffer == 1024)
{
print_buf(bufer, ibuffer);
ibuffer = 0;
}
buffer[ibuffer] = c;
ibuffer++;
return (ibuffer);
}
