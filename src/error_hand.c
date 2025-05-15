/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** error_hand
*/

#include "../include/my.h"

bool error_s(all_t *g, char **save)
{
    for (int i = 0; save[i] != NULL; i++)
        if (my_str_isnum(save[i]) == 0) {
            sfText_setColor(g->menu.conti, sfColor_fromRGB(120, 120, 120));
            sfText_setColor(g->esc_menu.load_text,
            sfColor_fromRGB(120, 120, 120));
            return false;
        }
    return true;
}

bool error_save(all_t *g)
{
    char *file = read_file("save/save.txt");
    char **save;

    if (file == NULL) {
        sfText_setColor(g->menu.conti, sfColor_fromRGB(120, 120, 120));
        sfText_setColor(g->esc_menu.load_text, sfColor_fromRGB(120, 120, 120));
        return false;
    }
    save = my_str_to_word_array(file, ';');
    if (count_word(file, ';') != 27) {
        sfText_setColor(g->menu.conti, sfColor_fromRGB(120, 120, 120));
        sfText_setColor(g->esc_menu.load_text, sfColor_fromRGB(120, 120, 120));
        return false;
    }
    if (error_s(g, save) == false)
        return false;
    sfText_setColor(g->menu.conti, sfWhite);
    sfText_setColor(g->esc_menu.load_text, sfWhite);
    return true;
}
