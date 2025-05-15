/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** music
*/

#include "../include/my.h"

void pause_music(all_t *g)
{
    sfMusic_pause(g->mia.music_ambiance);
    sfMusic_pause(g->mia.music_maison);
    sfMusic_pause(g->mia.music_usine);
    sfMusic_pause(g->mia.music_bar);
    sfMusic_pause(g->mia.music_store);
    sfMusic_pause(g->mia.music_manoir);
}
