/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** scene
*/

#include "../include/my.h"

static void game(all_t *g)
{
    hand_event_game(g);
    update_game(g);
    if (g->esc_menu.menu == false)
        check_range(g, g->mia.image_fortnite);
}

static void mini_game(all_t *g)
{
    hand_event_mini_game(g);
    update_mini_game(g);
}

static void store(all_t *g)
{
    hand_event_store(g);
    update_store(g);
    if (g->esc_menu.menu == false)
        check_range(g, g->store.map_col);
}

static void usine(all_t *g)
{
    hand_event_usine(g);
    update_usine(g);
}

void house(all_t *g)
{
    hand_event_house(g);
    update_house(g);
    if (g->esc_menu.menu == false)
        check_range(g, g->house.undermap);
}

void hack_game(all_t *g)
{
    hand_event_hb(g);
    update_hb(g);
}

static void change_scene4(all_t *g)
{
    if (g->scene == 2 && g->usine.b_draw_usine == 0 &&
    g->script.first_factory == 2) {
        mini_game(g);
        pause_music(g);
    }
    if (g->scene == 2 && g->script.first_factory == 0) {
        script(g, 5);
        g->script.first_factory = 1;
    }
    if (g->script.first_factory == 4 && g->script.history == 0 &&
    g->gui.dollar >= 650) {
            script(g, 6);
            g->script.history = 1;
    }
}

void change_scene3(all_t *g)
{
    if (g->scene == 3) {
        house(g);
        pause_music(g);
        if (sfMusic_getStatus(g->mia.music_maison) != sfPlaying)
            sfMusic_play(g->mia.music_maison);
    }
    if (g->scene == 4) {
        saloon(g);
        pause_music(g);
        if (sfMusic_getStatus(g->mia.music_bar) != sfPlaying)
            sfMusic_play(g->mia.music_bar);
    }
    if (g->scene == 5) {
        hack_game(g);
        pause_music(g);
    }
}

void change_scene2(all_t *g)
{
    if (g->script.history == 1)
        if (g->gui_invent.invent[0][0] == 4 || g->gui_invent.invent[1][0] == 4
        || g->gui_invent.invent[2][0] == 4 ||
        g->gui_invent.invent[3][0] == 4) {
                script(g, 4);
                g->script.history = 2;
        }
    if (g->usine.b_draw_usine == 1) {
        usine(g);
        pause_music(g);
        if (sfMusic_getStatus(g->mia.music_usine) != sfPlaying)
            sfMusic_play(g->mia.music_usine);
    }
    if (g->scene == 6) {
        haunted(g);
        pause_music(g);
        if (sfMusic_getStatus(g->mia.music_manoir) != sfPlaying)
            sfMusic_play(g->mia.music_manoir);
    }
    change_scene3(g);
    change_scene4(g);
}

void change_scene(all_t *g)
{
    if (g->scene == 0) {
        game(g);
        pause_music(g);
        if (sfMusic_getStatus(g->mia.music_ambiance) != sfPlaying)
            sfMusic_play(g->mia.music_ambiance);
    }
    if (g->scene == 1) {
        store(g);
        pause_music(g);
        if (sfMusic_getStatus(g->mia.music_store) != sfPlaying)
            sfMusic_play(g->mia.music_store);
    }
    change_scene2(g);
}
