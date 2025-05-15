/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** egr
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 48 || str[i] > 57) && str[i] != 46)
            return 0;
    return 1;
}
