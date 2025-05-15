/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

static void menu(all_t *g)
{
    if (sfMusic_getStatus(g->start_menu.music_menu) != sfPlaying)
                sfMusic_play(g->start_menu.music_menu);
    hand_event_menu(g);
    update_menu(g);
}

void loop_game(all_t *g)
{
    g->scene = 3;
    while (sfRenderWindow_isOpen(g->window)) {
        if (g->menu.y_mia < 1920)
            menu(g);
        else {
            sfMusic_pause(g->start_menu.music_menu);
            change_scene(g);
            }
        hand_scene(g);
    }
    return;
}
