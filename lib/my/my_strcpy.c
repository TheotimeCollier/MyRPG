/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** qetrhh
*/

char *my_strcpy(char *dest, char const *str)
{
    for (int i = 0; dest[i] != '\0'; i++)
        dest[i] = '\0';
    for (int k = 0; dest[k] != '\0'; k++)
        dest[k] = str[k];
    return dest;
}
