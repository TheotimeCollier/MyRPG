/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

void clock_title(all_t *g)
{
    g->start_menu.time_title = sfClock_getElapsedTime
    (g->start_menu.clock_title);
    g->start_menu.seconds_title =
    g->start_menu.time_title . microseconds / 1000000.0;
    if (g->start_menu.seconds_title > 0.1){
        g->start_menu.rect_title.left += 666;
        g->menu.rect_souris.left += 542;
        sfSprite_setTextureRect(g->start_menu.title, g->start_menu.rect_title);
        sfSprite_setTextureRect(g->menu.souris, g->menu.rect_souris);
        sfClock_restart(g->start_menu.clock_title);
        if (g->start_menu.rect_title.left > 8668)
            g->start_menu.rect_title.left = 0;
        if (g->menu.rect_souris.left > 2000)
            g->menu.rect_souris.left = 0;
    }
}

static void clock_mia_bis(all_t *g)
{
    if (g->menu.bool_newgame == 0)
        if (g->start_menu.rect_mia.left > 6300)
            g->start_menu.rect_mia.left = 0;
    if (g->menu.bool_newgame == 1)
        if (g->start_menu.rect_mia.left > 3800)
            g->start_menu.rect_mia.left = 0;
}

void clock_mia(all_t *g)
{
    g->start_menu.time_mia = sfClock_getElapsedTime(g->start_menu.clock_mia);
    g->start_menu.seconds_mia =
    g->start_menu.time_mia . microseconds / 1000000.0;
    if (g->start_menu.seconds_mia > 0.04){
        g->start_menu.rect_mia.left += 175;
        sfSprite_setTextureRect(g->start_menu.mia, g->start_menu.rect_mia);
        sfSprite_setTextureRect(g->start_menu.mia_run, g->start_menu.rect_mia);
        sfClock_restart(g->start_menu.clock_mia);
        clock_mia_bis(g);
    }
}

void clock_menu(all_t *g)
{
    g->start_menu.time = sfClock_getElapsedTime(g->start_menu.clock);
    g->start_menu.seconds = g->start_menu.time . microseconds / 1000000.0;
    if (g->start_menu.seconds > 0.02){
        g->start_menu.rect.left += 2;
        g->start_menu.rect_back_effect.left += 1;
        sfClock_restart(g->start_menu.clock);
        sfSprite_setTextureRect(g->start_menu.back_start, g->start_menu.rect);
        sfSprite_setTextureRect(g->start_menu.back_effect,
        g->start_menu.rect_back_effect);
        if (g->start_menu.rect.left > 4011)
            g->start_menu.rect.left = 0;
        if (g->start_menu.rect_back_effect.left > 4011)
            g->start_menu.rect_back_effect.left = 0;
        }
}

void move_mia_end(all_t *g)
{
    g->menu.time_mia_run = sfClock_getElapsedTime(g->menu.clock_mia_run);
    g->menu.seconds_mia_run =
    g->menu.time_mia_run . microseconds / 1000000.0;
    if (g->menu.seconds_mia_run > 0.001){
        g->menu.y_mia += 2.5;
        sfSprite_setPosition(g->start_menu.mia_run,
        (sfVector2f){g->menu.y_mia, 730});
    }
    sfClock_restart(g->menu.clock_mia_run);
}

void clock_move(all_t *g)
{
    g->start_menu.time_move = sfClock_getElapsedTime(g->start_menu.clock_move);
    g->start_menu.seconds_move =
    g->start_menu.time_move . microseconds / 1000000.0;
    if (g->start_menu.seconds_move > 0.005){
        if (g->start_menu.x_title > 20) {
        g->start_menu.x_title -= 1;
        sfSprite_setPosition(g->start_menu.title,
        (sfVector2f){427, g->start_menu.x_title});
        }
        if (g->menu.y_black_back > 0) {
            move_menu(g);
        }
        if (g->menu.bool_newgame == 1){
            move_new_game(g);
            move_mia_end(g);
        }
        sfClock_restart(g->start_menu.clock_move);
    }
}
