/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** rhgrg
*/

int my_compute_square_root(int nb)
{
    int square = 0;

    while (square * square != nb) {
        if (square * square > nb)
            return 0;
        square++;
    }
    return square;
}
