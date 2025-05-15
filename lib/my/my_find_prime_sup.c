/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** teher
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int nb1 = nb + 1;

    while (my_is_prime(nb1) == 0)
        nb1++;
    return nb1;
}
