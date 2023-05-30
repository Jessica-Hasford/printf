#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct conversion specifier - This will define a structure for symbols and functions in this project
* @sym : The operator in this function
* @f: The function associated in this program
*/
 typedef struct conversion specifier
{
	char sym;
	int (*f)(va_list, char[], int);
};


/**
 * conversion specifier_t -  This is the struct operator  in this function
 *
 * @sym: The format in question
 * @f: The function being referenced
 */
conversion specifier_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *e,
va_list jess, char buffer[], int flags, int width, int precision, int size);


int print_char(va_list est, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list est, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list est, char buffer[],
	int flags, int width, int precision, int size);


int print_int(va_list est, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list est, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list est, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list est, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list est, char buffer[],
	int flags, int width, int precision, int size);
int print_HEXA(va_list est, char buffer[],
	int flags, int width, int precision, int size);

int print_hex(va_list est, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list est, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list est, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int nab_flags(const char *format, int *j);
int nab_width(const char *format, int *h, va_list jess);
int nab_precision(const char *format, int *i, va_list jess);
int nab_size(const char *format, int *b);

int print_rev(va_list est, char buffer[],
	int flags, int width, int precision, int size);

/
int print_rot13string(va_list est, char buffer[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int draft_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int draft_num(int ind, char buffer[], int flags, int width, int precision,
	int length, char pad, char extra_c);
int draft_pointer(char buffer[], int ind, int length,
	int width, int flags, char pad, char extra_ch, int pad_start);

int draft_unsigned(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);


int is_printable(char);
Int fix_hex_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */
