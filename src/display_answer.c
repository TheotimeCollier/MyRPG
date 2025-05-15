/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

void set_text_digi(all_t *g)
{
    g->game_one.t_false = create_text((float[3]) {820, 170, 120},
    "ressource/cyber.ttf", "Error", sfBlack);
    g->game_one.t_passed = create_text((float[3]) {775, 170, 120},
    "ressource/cyber.ttf", "Passed", sfBlack);
}

void clock_rep(all_t *g)
{
    g->game_one.time_rep = sfClock_getElapsedTime(g->game_one.clock_rep);
    g->game_one.seconds_rep =
    g->game_one.time_rep . microseconds / 1000000.0;
    if (g->game_one.seconds_rep < 1.5) {
        if (g->game_one.bool_rep == 1)
        sfRenderWindow_drawText(g->window, g->game_one.t_false, NULL);
        if (g->game_one.bool_rep == 2)
            sfRenderWindow_drawText(g->window, g->game_one.t_passed, NULL);
    }
    if (g->game_one.seconds_rep > 1.5) {
        g->game_one.bool_rep = 0;
    }
}
