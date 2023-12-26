#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int process_character(char format_specifier, va_list args);
int process_string(char *s);
int process_integer(char format_specifier, va_list args);
int process_unsigned_integer(unsigned int num, int base);
#endif
