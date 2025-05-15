/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** moov
*/

#include "../include/my.h"

void movement_h_b(all_t *g, sfImage *img)
{
    if (sfKeyboard_isKeyPressed(g->mia.upkey) &&
    !sfKeyboard_isKeyPressed(g->mia.rightkey)
    && !(sfKeyboard_isKeyPressed(g->mia.leftkey))
    && !sfKeyboard_isKeyPressed(g->mia.downkey)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x,
        g->mia.y - (g->mia.vite * g->mia.mult) - 15);
        if (g->mia.current.r != 0 && g->mia.current.g != 0 &&
        g->mia.current.b != 0)
            haut(g);
    }
    if (sfKeyboard_isKeyPressed(g->mia.downkey) &&
    !sfKeyboard_isKeyPressed(g->mia.rightkey)
    && !(sfKeyboard_isKeyPressed(g->mia.leftkey))
    && !sfKeyboard_isKeyPressed(g->mia.upkey)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x,
        g->mia.y + (g->mia.vite * g->mia.mult) + 15);
        if (g->mia.current.r != 0 && g->mia.current.g != 0
        && g->mia.current.b != 0)
            bas(g);
    }
}

void movement_g_d(all_t *g, sfImage *img)
{
    if (sfKeyboard_isKeyPressed(g->mia.leftkey) &&
    !sfKeyboard_isKeyPressed(g->mia.upkey)
    && !(sfKeyboard_isKeyPressed(g->mia.downkey))
    && !sfKeyboard_isKeyPressed(g->mia.rightkey)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x -
        (g->mia.vite * g->mia.mult) - 15, g->mia.y);
        if (g->mia.current.r != 0 && g->mia.current.g != 0
        && g->mia.current.b != 0)
            gauche(g);
    }
    if (sfKeyboard_isKeyPressed(g->mia.rightkey) &&
    !sfKeyboard_isKeyPressed(g->mia.upkey)
    && !(sfKeyboard_isKeyPressed(g->mia.downkey))
    && !sfKeyboard_isKeyPressed(sfKeyG)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x +
        (g->mia.vite * g->mia.mult) + 15, g->mia.y);
        if (g->mia.current.r != 0 && g->mia.current.g != 0 &&
        g->mia.current.b != 0)
            droite(g);
    }
}

void movement_h_diag(all_t *g, sfImage *img)
{
    if (sfKeyboard_isKeyPressed(g->mia.rightkey) &&
    (sfKeyboard_isKeyPressed(g->mia.upkey))
    && !sfKeyboard_isKeyPressed(g->mia.downkey)
    && !sfKeyboard_isKeyPressed(g->mia.leftkey)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x + (g->mia.vite *
        g->mia.mult) + 15, g->mia.y - (g->mia.vite * g->mia.mult) - 15);
        if (g->mia.current.r != 0 && g->mia.current.g != 0 &&
        g->mia.current.b != 0)
            haut_droite(g);
    }
    if (sfKeyboard_isKeyPressed(g->mia.leftkey) &&
    (sfKeyboard_isKeyPressed(g->mia.upkey))
    && !sfKeyboard_isKeyPressed(g->mia.downkey)
    && !sfKeyboard_isKeyPressed(g->mia.rightkey)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x + (g->mia.vite *
        g->mia.mult) + 15, g->mia.y - (g->mia.vite * g->mia.mult) - 15);
        if (g->mia.current.r != 0 && g->mia.current.g != 0 &&
        g->mia.current.b != 0)
            haut_gauche(g);
    }
}

void movement_b_diag(all_t *g, sfImage *img)
{
    if (sfKeyboard_isKeyPressed(g->mia.leftkey) &&
    (sfKeyboard_isKeyPressed(g->mia.downkey))
    && !sfKeyboard_isKeyPressed(g->mia.upkey)
    && !sfKeyboard_isKeyPressed(g->mia.rightkey)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x - (g->mia.vite *
        g->mia.mult) - 15, g->mia.y + (g->mia.vite * g->mia.mult) + 15);
        if (g->mia.current.r != 0 && g->mia.current.g != 0 &&
        g->mia.current.b != 0)
            bas_gauche(g);
        }
    if (sfKeyboard_isKeyPressed(g->mia.rightkey) &&
    (sfKeyboard_isKeyPressed(g->mia.downkey))
    && !sfKeyboard_isKeyPressed(g->mia.upkey)
    && !sfKeyboard_isKeyPressed(g->mia.leftkey)) {
        g->mia.current = sfImage_getPixel(img, g->mia.x + (g->mia.vite *
        g->mia.mult) + 15, g->mia.y + (g->mia.vite * g->mia.mult) + 15);
        if (g->mia.current.r != 0 && g->mia.current.g != 0 &&
        g->mia.current.b != 0)
            bas_droite(g);
    }
}
