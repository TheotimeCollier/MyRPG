/*
** EPITECH PROJECT, 2024
** lib
** File description:
** read_file and return char *
*/

#include "../../include/my.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

char *read_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *tab;
    struct stat sb;

    if (fd == -1)
        return NULL;
    if (fstat(fd, &sb) == -1) {
        close(fd);
        return NULL;
    }
    if (!S_ISREG(sb.st_mode)) {
        close(fd);
        return NULL;
    }
    tab = malloc(sizeof(char) * (sb.st_size + 1) + 1);
    read(fd, tab, sb.st_size);
    close(fd);
    tab[sb.st_size] = '\0';
    return tab;
}
