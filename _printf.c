#include "main.h"

int _putchar(char c) {
    return write(1, &c, 1);
}

int print_char(va_list arguments, int *length) {
    int i = va_arg(arguments, int);
    *length += _putchar(i);
    return 1;
}

int print_string(va_list arguments, int *length) {
    char *string_to_print = va_arg(arguments, char *);
    int string_length = 0;

    while (string_to_print[string_length] != '\0') {
        string_length++;
    }

    *length += write(1, string_to_print, string_length);
    return string_length;
}

int process_format(const char *format, va_list arguments) {
    int length = 0;

    while (*format != '\0') {
        if (*format != '%') {
            _putchar(*format);
            length++;
        } else {
            format++;
            if (*format == '\0') {
                break;
            }

            switch (*format) {
                case '%':
                    _putchar(*format);
                    length++;
                    break;
                case 'c':
                    length += print_char(arguments, &length);
                    break;
                case 's':
                    length += print_string(arguments, &length);
                    break;
            }
        }
        format++;
    }

    return length;
}

int _printf(const char *format, ...) {
    if (format == NULL) {
        return -1;
    }

    va_list arguments;
    va_start(arguments, format);
    int length = process_format(format, arguments);
    va_end(arguments);

    return length;
}

