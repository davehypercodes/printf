#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int handle_char_str(char specifier, va_list args);
int process_string(char *s);
int _detect_format(char format, va_list args);
int handle_int(char specifier, va_list args);
int print_number(int n);

#endif
