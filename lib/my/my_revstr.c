/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** etfb
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int x = my_strlen(str);
    int y = 0;
    char temp[x];

    while (i < x) {
        temp[i] = str[i];
        i++;
    }
    while (y < x) {
        str[y] = temp[i - 1];
        i--;
        y++;
    }
    return str;
}
