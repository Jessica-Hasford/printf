#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limit.h>

/**
 * struct print -  The struct to print functions in this program
 * @type_arg: The identifier in the program
 * @f: The pointer to a printer functions
 *
 * Description: The struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
char *type_arg;
int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list arg, char *buffer, unsigned int ibuffer);
int print_str(va_list arg, char *buffer, unsigned int ibuffer);
int print_int(va_list arg, char *buffer, unsigned int ibuffer);
int print_bnr(va_list arg, char *buffer, unsigned int ibuffer);
int print_unt((va_list arg, char *buffer, unsigned int ibuffer);
int print_oct(va_list arg, char *buffer, unsigned int ibuffer);
int print_hex(va_list arg, char *buffer, unsigned int ibuffer);
int print_upx(va_list arg, char *buffer, unsigned int ibuffer);
int print_usr(va_list arg, char *buffer, unsigned int ibuffer);
int print_add(va_list arg, char *buffer, unsigned int ibuffer);
int print_rev(va_list arg, char *buffer, unsigned int ibuffer);
int print_rot(va_list arg, char *buffer, unsigned int ibuffer);
int prinlint(va_list arg, char *buffer, unsigned int ibuffer);
int prinlunt(va_list arg, char *buffer, unsigned int ibuffer);
int prinloct(va_list arg, char *buffer, unsigned int ibuffer);
int prinlhex(va_list arg, char *buffer, unsigned int ibuffer);
int prinlupx(va_list arg, char *buffer, unsigned int ibuffer);
int prinhint(va_list arg, char *buffer, unsigned int ibuffer);
int prinhunt(va_list arg, char *buffer, unsigned int ibuffer);
int prinhoct(va_list arg, char *buffer, unsigned int ibuffer);
int prinhhex(va_list arg, char *buffer, unsigned int ibuffer);
int prinhupx(va_list arg, char *buffer, unsigned int ibuffer);
int prinpint(va_list arg, char *buffer, unsigned int ibuffer);
int prinnoct(va_list arg, char *buffer, unsigned int ibuffer);
int prinnhex(va_list arg, char *buffer, unsigned int ibuffer);
int prinnupx(va_list arg, char *buffer, unsigned int ibuffer);
int prinsint(va_list arg, char *buffer, unsigned int ibuffer);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int handl_buffer(char *buffer, char c, unsigned int ibuffer);
int print_buffer(char *buffer, unsigned int nbuffer);
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit);
char *fill_oct_array(char *bnr, char *oct);
char *fill_long_oct_array(char *bnr, char *oct);
char *fill_short_oct_array(char *bnr, char *oct);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
