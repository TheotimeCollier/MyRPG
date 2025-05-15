/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** begt
*/

int bis(int i, char *str, char *pat)
{
    for (int j = 0; pat[j]; j++) {
        if (str[i + j] != pat[j])
            return 1;
    }
    return 0;
}

int my_strstr(char *str, char *pat)
{
    for (int i = 0; str[i]; i++) {
        if (bis(i, str, pat) == 0)
            return 0;
    }
    return 1;
}
