/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** view
*/

#include "../include/my.h"

void config_view(all_t *g)
{
    sfVector2f vecteur_cam = sfSprite_getPosition(g->mia.mia_sprite);

    vecteur_cam.x -= 15;
    sfView_setCenter(g->view, (sfVector2f){vecteur_cam.x, vecteur_cam.y});
    sfView_setSize(g->view, (sfVector2f){1920, 1080});
    sfView_move(g->view,
    (sfVector2f){g->mia.vite, g->mia.vite});
    sfView_zoom(g->view, g->mia.screensize);
    sfRenderWindow_setView(g->window, g->view);
    sfSprite_setPosition(g->mia.mia_sprite,
    (sfVector2f){g->mia.x, g->mia.y});
}

void reset_texture_mia_idle(all_t *g)
{
    g->mia.idle[0] = 0;
    g->mia.idle[1] = 0;
    g->mia.idle[2] = 0;
    g->mia.idle[3] = 0;
    g->mia.idle[4] = 0;
    g->mia.idle[5] = 0;
    g->mia.idle[6] = 0;
    g->mia.idle[7] = 0;
}
