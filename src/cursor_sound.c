/*
** EPITECH PROJECT, 2024
** lib
** File description:
** main
*/

#include "../include/my.h"

static void music_volume(all_t *g, float mouseX, sfVector2f size_rec)
{
        sfMusic_setVolume(g->start_menu.music_menu,
        (float)(mouseX - size_rec.x) / 2);
        sfMusic_setVolume(g->mia.music_ambiance,
        (float)(mouseX - size_rec.x) / 2);
        sfMusic_setVolume(g->mia.music_bar,
        (float)(mouseX - size_rec.x) / 2);
        sfMusic_setVolume(g->mia.music_maison,
        (float)(mouseX - size_rec.x) / 2);
        sfMusic_setVolume(g->mia.music_store,
        (float)(mouseX - size_rec.x) / 2);
        sfMusic_setVolume(g->mia.music_usine,
        (float)(mouseX - size_rec.x) / 2);
}

static void cursor_music(all_t *g, sfVector2f mousepos)
{
    sfVector2f size_rec = sfRectangleShape_getPosition(g->set->ms_ba);
    float mouseX = 0.0;

    if (size_rec.x <= mousepos.x && mousepos.x <= size_rec.x
    + sfRectangleShape_getSize(g->set->ms_ba).x &&
    size_rec.y <= mousepos.y && mousepos.y <= size_rec.y
    + sfRectangleShape_getSize(g->set->ms_ba).y) {
        mouseX = mousepos.x;
        if (mouseX < size_rec.x)
            mouseX = size_rec.x;
        if (mouseX > size_rec.x + 200)
            mouseX = size_rec.x + 200;
        sfRectangleShape_setPosition(g->set->ms_csr,
        (sfVector2f){mouseX, size_rec.y - 5});
        music_volume(g, mouseX, size_rec);
    }
}

void cursor_sound(all_t *g, sfVector2f mousepos)
{
    sfVector2f size_rec = sfRectangleShape_getPosition(g->set->sound_ba);
    float mouseX = 0.0;

    if (size_rec.x <= mousepos.x && mousepos.x <= size_rec.x
    + sfRectangleShape_getSize(g->set->sound_ba).x &&
    size_rec.y <= mousepos.y && mousepos.y <= size_rec.y
    + sfRectangleShape_getSize(g->set->sound_ba).y) {
        mouseX = mousepos.x;
        if (mouseX < size_rec.x)
            mouseX = size_rec.x;
        if (mouseX > size_rec.x + 200)
            mouseX = size_rec.x + 200;
        sfRectangleShape_setPosition(g->set->sound_csr,
        (sfVector2f){mouseX, size_rec.y - 5});
        sfSound_setVolume(g->mia.footstepsound,
        (float)(mouseX - size_rec.x) / 2);
    }
    cursor_music(g, mousepos);
}
