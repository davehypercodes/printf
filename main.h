#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int process_format_specifier(char format_specifier, va_list args);
int process_string(char *s);
#endif
