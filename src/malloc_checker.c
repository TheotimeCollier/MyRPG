/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** usine
*/

#include "../include/my.h"

/*
 * Function: malloc_checker
 * --------------------
 * check if a malloc was successful,
 * otherwise it stops the program.
 *
 * - checked: malloc subject parameter
 * - context: error return precision message
 */
void malloc_checker(void *checked, char *context)
{
    if (checked == NULL) {
        fprintf(stderr,
            "Error: Memory allocation failed for \"%s\".\n", context);
        exit(EXIT_FAILURE);
    }
}

/*
 * Function: line_counter
 * --------------------
 * function counting the number of lines in the script.
 *
 * - str: raw script
 *
 * returns: number of lines in the script.
 */
int line_counter(char *str)
{
    int result = 0;

    for (int loop = 0; str[loop] != '\0'; loop++) {
        if (str[loop] == '\n')
            result++;
    }
    return (result + 1);
}
