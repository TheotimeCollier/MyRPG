/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** moov
*/

#include "../include/my.h"

void haut(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.y -= g->mia.vite;
        clockmouv(g, g->mia.texture_top, 120, 4080);
    }
    if (g->mia.sprint == 1) {
        g->mia.y -= (g->mia.vite *
        g->mia.mult);
        clockmouv(g, g->mia.texture_topsprint, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[0] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){g->mia.x, (g->mia.y - 12)});
}

void bas(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.y += g->mia.vite;
        clockmouv(g, g->mia.texture_bottom, 120, 4320);
    }
    if (g->mia.sprint == 1) {
        g->mia.y += (g->mia.vite *
        g->mia.mult);
        clockmouv(g, g->mia.texture_downsprint, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[4] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){g->mia.x, (g->mia.y + 12)});
}

void gauche(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.x -= g->mia.vite;
        clockmouv(g, g->mia.texture_left, 120, 4320);
    }
    if (g->mia.sprint == 1) {
        g->mia.x -= (g->mia.vite * g->mia.mult);
        clockmouv(g, g->mia.texture_leftsprint, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[6] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){(g->mia.x - 12), g->mia.y});
}

void droite(all_t *g)
{
    if (g->mia.sprint == 0) {
        g->mia.x += g->mia.vite;
        clockmouv(g, g->mia.texture_right, 120, 4320);
    }
    if (g->mia.sprint == 1) {
        g->mia.x += (g->mia.vite * g->mia.mult);
        clockmouv(g, g->mia.texture_rightsprint, 120, 2520);
    }
    reset_texture_mia_idle(g);
    g->mia.idle[2] = 1;
    sfRectangleShape_setPosition(g->mia.hitbox_tape,
    (sfVector2f){(g->mia.x + 12), g->mia.y});
}

void mouse_fight(all_t *g)
{
    static int previous = 0;
    int mouse_left = sfMouse_isButtonPressed(sfMouseLeft);

    if (mouse_left && !previous) {
        if (g->mia.attack == 1) {
            g->mia.attack = 0;
            g->mia.movement = 0;
        } else
            g->mia.attack = 1;
    }
    previous = mouse_left;
}
