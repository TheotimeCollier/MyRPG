/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** zrg
*/

int my_get_nbr(char const *str)
{
    int j = 0;
    int i = 0;
    int nb = 0;

    for (int y = 0; str[y] != '\0'; y++) {
        nb += str[y] - 48;
        nb *= 10;
    }
    nb /= 10;
    return nb;
}
