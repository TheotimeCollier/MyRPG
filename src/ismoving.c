/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** moov
*/

#include "../include/my.h"

int is_moving(all_t *g)
{
    return sfKeyboard_isKeyPressed(g->mia.upkey) ||
        sfKeyboard_isKeyPressed(g->mia.leftkey) ||
        sfKeyboard_isKeyPressed(g->mia.downkey) ||
        sfKeyboard_isKeyPressed(g->mia.rightkey);
}

int is_sprinting(all_t *g)
{
    return sfKeyboard_isKeyPressed(g->mia.sprintkey) &&
        (sfKeyboard_isKeyPressed(g->mia.upkey) ||
        sfKeyboard_isKeyPressed(g->mia.leftkey) ||
        sfKeyboard_isKeyPressed(g->mia.downkey) ||
        sfKeyboard_isKeyPressed(g->mia.rightkey));
}

int idle_bind(all_t *g)
{
    return !sfKeyboard_isKeyPressed(g->mia.upkey) &&
        !sfKeyboard_isKeyPressed(g->mia.rightkey) &&
        !sfKeyboard_isKeyPressed(g->mia.leftkey) &&
        !sfKeyboard_isKeyPressed(g->mia.downkey) &&
        !sfKeyboard_isKeyPressed(g->mia.sprintkey);
}
