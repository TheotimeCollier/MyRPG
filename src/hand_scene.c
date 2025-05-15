/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** scene
*/

#include "../include/my.h"

static void hand_scene_qu(all_t *g)
{
    if (g->mia.current.r == 0 && g->mia.current.g == 255
    && g->mia.current.b == 254) {
        g->scene = 0;
        g->mia.x = 1974.0;
        g->mia.y = 2173.0;
    }
}

static void hand_scene_tr(all_t *g)
{
    if (g->mia.current.r == 255 && g->mia.current.g == 255
    && g->mia.current.b == 0) {
        g->scene = 4;
        g->mia.x = 250.0;
        g->mia.y = 605.0;
    }
    if (g->mia.current.r == 255 && g->mia.current.g == 254
    && g->mia.current.b == 0) {
        g->scene = 0;
        g->mia.x = 1238.0;
        g->mia.y = 339.0;
    }
    if (g->mia.current.r == 0 && g->mia.current.g == 255
    && g->mia.current.b == 255 && g->script.history >= 3) {
        g->scene = 6;
        g->mia.x = 218.0;
        g->mia.y = 400.0;
        g->robot.coord = (sfVector2f){218, 400};
    }
    hand_scene_qu(g);
}

static void hand_scene_bis(all_t *g)
{
    if (g->mia.current.r == 0 && g->mia.current.g == 254
    && g->mia.current.b == 0) {
        g->scene = 0;
        g->usine.b_draw_usine = 0;
        g->mia.x = 4160.0;
        g->mia.y = 2116.0;
    }
    if (g->mia.current.r == 0 && g->mia.current.g == 0
    && g->mia.current.b == 255) {
        g->scene = 3;
        g->mia.x = 447.25;
        g->mia.y = 300.0;
    }
    if ((g->mia.current.r == 0 && g->mia.current.g == 0
    && g->mia.current.b == 254) && g->script.exit_house == 1) {
        g->scene = 0;
        g->mia.x = 3665.71;
        g->mia.y = 878.22;
    }
    hand_scene_tr(g);
}

void hand_scene(all_t *g)
{
    if (g->mia.current.r == 255 && g->mia.current.g == 0
        && g->mia.current.b == 0) {
            g->scene = 1;
            g->mia.x = 160.0;
            g->mia.y = 360.0;
    }
    if (g->mia.current.r == 254 && g->mia.current.g == 0
    && g->mia.current.b == 0) {
        g->scene = 0;
        g->mia.x = 3289.0;
        g->mia.y = 380.0;
    }
    if (g->mia.current.r == 0 && g->mia.current.g == 255
    && g->mia.current.b == 0 && g->script.first_factory == 2) {
        g->scene = 2;
        g->mia.x = 90.0;
        g->mia.y = 406.0;
    }
    hand_scene_bis(g);
}
