/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** save
*/

#include "../include/my.h"

void write_save(all_t *g)
{
    FILE *fd = fopen("save/save.txt", "w+");

    fprintf(fd,
    "%f;%f;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;"
    "%d;%d;%d;%d;%d\n",
    g->mia.x, g->mia.y, g->scene, g->gui.dollar, g->esc_menu.xp,
    g->esc_menu.taille_attack, g->esc_menu.taille_health,
    g->esc_menu.taille_speed, g->gui_invent.invent[0][0],
    g->gui_invent.invent[0][1], g->gui_invent.invent[1][0],
    g->gui_invent.invent[1][1], g->gui_invent.invent[2][0],
    g->gui_invent.invent[2][1], g->gui_invent.invent[3][0],
    g->gui_invent.invent[3][1], g->mia.upkey, g->mia.downkey, g->mia.leftkey,
    g->mia.rightkey, g->mia.sprintkey, g->mia.ekey, g->script.exit_house,
    g->script.first_factory, g->script.history, g->script.line,
    g->usine.b_draw_usine);
    fclose(fd);
}

void save(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->esc_menu.hit_save, mousepos.x, mousepos.y))
        write_save(g);
}

static void init_save_s(all_t *g)
{
    g->gui_invent.invent[2][1] = atoi(g->save[13]);
    g->gui_invent.invent[3][0] = atoi(g->save[14]);
    g->gui_invent.invent[3][1] = atoi(g->save[15]);
    g->mia.upkey = atoi(g->save[16]);
    g->mia.downkey = atoi(g->save[17]);
    g->mia.leftkey = atoi(g->save[18]);
    g->mia.rightkey = atoi(g->save[19]);
    g->mia.sprintkey = atoi(g->save[20]);
    g->mia.ekey = atoi(g->save[21]);
    g->script.exit_house = atoi(g->save[22]);
    g->script.first_factory = atoi(g->save[23]);
    g->script.history = atoi(g->save[24]);
    g->script.line = atoi(g->save[25]);
    g->usine.b_draw_usine = atoi(g->save[26]);
    sfText_setString(g->set->left_key, get_key(g->mia.leftkey));
    sfText_setString(g->set->e_key, get_key(g->mia.ekey));
    sfText_setString(g->set->shift_key, get_key(g->mia.sprintkey));
    sfText_setString(g->set->up_key, get_key(g->mia.upkey));
    sfText_setString(g->set->down_key, get_key(g->mia.downkey));
    sfText_setString(g->set->right_key, get_key(g->mia.rightkey));
}

int init_save(all_t *g)
{
    char *file = read_file("save/save.txt");

    if (file == NULL)
        return (84);
    g->save = my_str_to_word_array(file, ';');
    g->mia.x = atof(g->save[0]);
    g->mia.y = atof(g->save[1]);
    g->scene = atoi(g->save[2]);
    g->gui.dollar = atoi(g->save[3]);
    g->esc_menu.xp = atoi(g->save[4]);
    g->esc_menu.taille_attack = atoi(g->save[5]);
    g->esc_menu.taille_health = atoi(g->save[6]);
    g->esc_menu.taille_speed = atoi(g->save[7]);
    g->gui_invent.invent[0][0] = atoi(g->save[8]);
    g->gui_invent.invent[0][1] = atoi(g->save[9]);
    g->gui_invent.invent[1][0] = atoi(g->save[10]);
    g->gui_invent.invent[1][1] = atoi(g->save[11]);
    g->gui_invent.invent[2][0] = atoi(g->save[12]);
    init_save_s(g);
    return (0);
}
