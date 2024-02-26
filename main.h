#ifndef MAIN_H
#define MAIN_H

/* Standard library */
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int detect_format(char specifier, va_list args);
int handle_char_str(char specifier, va_list args);
int handle_int(int num);
int process_string(char *s);
int handle_binary(unsigned int num);
int handle_unsigned_int(unsigned int num);
int handle_octal(unsigned int num);
int handle_hex(unsigned int num, int uppercase);

#endif
