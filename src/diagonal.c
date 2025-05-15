/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** diagonal
*/

#include "../include/my.h"

void haut_gauche(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.x -= (g->mia.vite / 2);
        g->mia.y -= (g->mia.vite / 2);
        clockmouv(g, g->mia.texture_leftup, 120, 4320);
    }
    if (g->mia.sprint == 1) {
        g->mia.x -= (g->mia.vite * g->mia.mult) / 2;
        g->mia.y -= (g->mia.vite * g->mia.mult) / 2;
        clockmouv(g, g->mia.texture_leftsprintup, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[7] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){(g->mia.x - 12), (g->mia.y - 12)});
}

void haut_droite(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.x += (g->mia.vite / 2);
        g->mia.y -= (g->mia.vite / 2);
        clockmouv(g, g->mia.texture_rightup, 120, 4320);
    }
    if (g->mia.sprint == 1) {
        g->mia.y -= (g->mia.vite * g->mia.mult) / 2;
        g->mia.x += (g->mia.vite * g->mia.mult) / 2;
        clockmouv(g, g->mia.texture_rightsprintup, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[1] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){(g->mia.x + 12), (g->mia.y - 12)});
}

void bas_gauche(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.x -= (g->mia.vite / 2);
        g->mia.y += (g->mia.vite / 2);
        clockmouv(g, g->mia.texture_leftdown, 120, 4320);
    }
    if (g->mia.sprint == 1) {
        g->mia.y += (g->mia.vite * g->mia.mult) / 2;
        g->mia.x -= (g->mia.vite * g->mia.mult) / 2;
        clockmouv(g, g->mia.texture_leftsprintdown, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[5] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){(g->mia.x - 12), (g->mia.y + 12)});
}

void bas_droite(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.x += (g->mia.vite / 2);
        g->mia.y += (g->mia.vite / 2);
        clockmouv(g, g->mia.texture_rightdown, 120, 4320);
    }
    if (g->mia.sprint == 1) {
        g->mia.x += (g->mia.vite * g->mia.mult) / 2;
        g->mia.y += (g->mia.vite * g->mia.mult) / 2;
        clockmouv(g, g->mia.texture_rightsprintdown, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[3] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){(g->mia.x + 12), (g->mia.y + 12)});
}

void idle_maker(all_t *g)
{
    if (g->mia.idle[0] == 1)
        clockmouv(g, g->mia.texture_top, 0, 0);
    if (g->mia.idle[1] == 1)
        clockmouv(g, g->mia.texture_rightup, 0, 0);
    if (g->mia.idle[2] == 1)
        clockmouv(g, g->mia.texture_right, 0, 0);
    if (g->mia.idle[3] == 1)
        clockmouv(g, g->mia.texture_rightdown, 0, 0);
    if (g->mia.idle[4] == 1)
        clockmouv(g, g->mia.texture_bottom, 0, 0);
    if (g->mia.idle[5] == 1)
        clockmouv(g, g->mia.texture_leftdown, 0, 0);
    if (g->mia.idle[6] == 1)
        clockmouv(g, g->mia.texture_left, 0, 0);
    if (g->mia.idle[7] == 1)
        clockmouv(g, g->mia.texture_leftup, 0, 0);
}
