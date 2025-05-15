/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** rfgb
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    int maxsize = len_dest + len_src;
    int j = 0;

    while (j != len_src) {
        dest[len_dest + j] = src[j];
        j++;
    }
    dest[maxsize] = '\0';
    return dest;
}
