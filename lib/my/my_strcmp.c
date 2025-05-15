/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** teb
*/

int my_strcmp(const char *first, const char *second)
{
    int indice_f = 0;
    int indice_s = 0;

    while (first[indice_f] != '\0' || second[indice_s] != '\0'){
        if (first[indice_f] != second[indice_s])
            return first[indice_f] - second[indice_s];
        indice_f++;
        indice_s++;
    }
    return 0;
}
