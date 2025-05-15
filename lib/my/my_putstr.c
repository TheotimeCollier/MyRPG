/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** agagag
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
