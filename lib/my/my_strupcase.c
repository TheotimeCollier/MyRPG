/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** egtb
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return str;
}
