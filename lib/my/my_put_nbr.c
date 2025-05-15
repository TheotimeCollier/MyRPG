/*
** EPITECH PROJECT, 2023
** zjdaidj
** File description:
** yanis
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0){
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9){
        my_put_nbr(nb / 10);
        my_putchar((nb % 10)+'0');
    } else
        my_putchar(nb + '0');
    return 0;
}
