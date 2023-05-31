#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * ev_print_func - returns the amount of identifiers.
 * @s: arg identifier
 * @index: index of argument identifier.
 * Return: amount of identifiers.
 */
int ev_print_func(const char *s, int index)
{
print_t pr[] = {
{"c", print_chr}, {"s", print_str}, {"i", print_int},
{"d", print_int}, {"b", print_bnr}, {"u", print_unt},
{"o", print_oct}, {"x", print_hex}, {"X", print_upx},
{"S", print_usr}, {"p", print_add}, {"li", prinlint},
{"ld", prinlint}, {"lu", prinlunt}, {"lo", prinloct},
{"lx", prinlhex}, {"lX", prinlupx}, {"hi", prinhint},
{"hd", prinhint}, {"hu", prinhunt}, {"ho", prinhoct},
{"hx", prinhhex}, {"hX", prinhupx}, {"#o", prinnoct},
{"#x", prinnhex}, {"#X", prinnupx}, {"#i", print_int},
{"#d", print_int}, {"#u", print_unt}, {"+i", prinpint},
{"+d", prinpint}, {"+u", print_unt}, {"+o", print_oct},
{"+x", print_hex}, {"+X", print_upx}, {" i", prinsint},
{" d", prinsint}, {" u", print_unt}, {" o", print_oct},
{" x", print_hex}, {" X", print_upx}, {"R", print_rot},
{"r", print_rev}, {"%", print_prg}, {"l", print_prg},
{"h", print_prg}, {" +i", prinpint}, {" +d", prinpint},
{"+ i", prinpint}, {"+ d", prinpint}, {" %", print_prg},
{NULL, NULL},
};
int l = 0, r = 0, first_index;

first_index = index;
while (pr[l].type_arg)
{
if (s[index] == pr[l].type_arg[j])
{
if (pr[i].type_arg[r + 1]
index++, r++;
else
break;
}
else
{
r = 0;
l++;
index = first_index;
}
}
return (r);
}
