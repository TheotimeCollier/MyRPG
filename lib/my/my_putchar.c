/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_putchar
*/

#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
