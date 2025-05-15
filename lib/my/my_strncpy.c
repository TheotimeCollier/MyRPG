/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** rf
*/

char *my_strncpy(char *dest, char const *str, int n)
{
    for (int k = 0; k != n; k++)
        dest[k] = str[k];
    return dest;
}
