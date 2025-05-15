/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** usine
*/

#include "../../include/my.h"

/*
 * Function: my_cut_str
 * --------------------
 * a revisited version of my_str_to_word_array
 * allowing the script to be separated into
 * sentences in a char **.
 *
 * - str: script to separate
 *
 * * Returns: script separed
 */
char **my_cut_str(char *str)
{
    int line = 0;
    int len = strlen(str);
    int start = 0;
    char **result = (char **)malloc(sizeof(char *) * (len + 1));

    malloc_checker(result, "result");
    for (int loop = 0; loop <= len; loop++) {
        if (str[loop] == '\n' || str[loop] == '\0') {
            result[line] = (char *)malloc(loop - start + 1);
            malloc_checker(result[line], "result[line]");
            strncpy(result[line], &str[start], loop - start);
            result[line][loop - start] = '\0';
            start = loop + 1;
            line++;
        }
    }
    result[line] = NULL;
    return result;
}
