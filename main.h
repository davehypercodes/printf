#ifndef MAIN_H
#define MAIN_H

/* Standard library */
#include <stddef.h>
#include <stdarg.h>

/* Function prtotypes */
int _printf(const char *format, ...);
int _putchar(char c);
int detect_format(char specifier, va_list args);
int handle_char_str(char specifier, va_list args);
int handle_int(int num);
int process_string(char *s);

#endif
