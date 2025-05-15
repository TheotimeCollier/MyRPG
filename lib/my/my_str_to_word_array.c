/*
** EPITECH PROJECT, 2023
** load map
** File description:
** gf
*/

#include "../../include/my.h"

int count_word(char const *file, char deli)
{
    int count = 1;
    int l = 0;

    for (; file[l] == deli; l++);
    for (; file[l] != '\0'; l++)
        if ((file[l] == deli && file[l + 1] != deli))
            count++;
    return count;
}

char **mem_alloc_2d_array(char const *file, char deli)
{
    int count = count_word(file, deli);
    char **array = malloc(sizeof(char *) * (count + 1));
    int i = 0;
    int j = 0;

    for (; file[i] == deli; i++);
    j = i;
    for (int c = 0; c < count; c++) {
        for (; file[j] != deli && file[j] != '\0'; j++);
        array[c] = malloc(sizeof(char) * j - i + 2);
        for (; file[j] == deli || file[j] == '\n'; j++);
        i = j;
    }
    return array;
}

char **my_str_to_word_array(const char *file, char deli)
{
    char **array;
    int k = 0;
    int j = 0;
    int i = 0;

    array = mem_alloc_2d_array(file, deli);
    for (; k < my_strlen(file); i++) {
        for (; file[k] == deli; k++);
        for (j = 0; file[k] != deli && file[k] != '\n' &&
        file[k] != '\0'; j++) {
            array[i][j] = file[k];
            k++;
        }
        array[i][j] = '\0';
        k++;
    }
    array[i] = NULL;
    return array;
}
