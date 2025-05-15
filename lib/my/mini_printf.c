/*
** EPITECH PROJECT, 2023
** my_print
** File description:
** rg
*/

#include "../../include/my.h"

int suite(const char *format, va_list list)
{
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == 'c')
            my_putchar(va_arg(list, int));
        if (format[i] == '%' && format[i + 1] == 's')
            my_putstr(va_arg(list, char *));
        if (format[i] == '%' && format[i + 1] == 'i')
            my_put_nbr(va_arg(list, int));
        if (format[i] == '%' && format[i + 1] == '%')
            my_putchar('%');
        if (format[i] == '%' && format[i + 1] == 'd')
            my_put_nbr(va_arg(list, int));
        if (format[i] != '%')
            my_putchar(format[i]);
        if (format[i] == '%')
            i += 1;
    }
}

void mini_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    suite(format, list);
    va_end(list);
    return;
}
