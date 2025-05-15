/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

static void set_rec_bis(all_t *g)
{
    g->start_menu.seconds = 0;
    g->start_menu.seconds_mia = 0;
    g->start_menu.seconds_move = 0;
    g->start_menu.seconds_title = 0;
    g->start_menu.rect_mia.top = 0;
    g->start_menu.rect_mia.left = 0;
    g->start_menu.rect_mia.width = 175;
    g->start_menu.rect_mia.height = 175;
    g->menu.y_mia = 180;
    g->menu.rect_souris.top = 0;
    g->menu.rect_souris.left = 0;
    g->menu.rect_souris.width = 542;
    g->menu.rect_souris.height = 520;
}

static void set_rec(all_t *g)
{
    g->start_menu.rect.top = 0;
    g->start_menu.rect.left = 0;
    g->start_menu.rect.width = 1920;
    g->start_menu.rect.height = 1080;
    g->start_menu.rect_back_effect.top = 0;
    g->start_menu.rect_back_effect.left = 0;
    g->start_menu.rect_back_effect.width = 1920;
    g->start_menu.rect_back_effect.height = 1080;
    g->start_menu.rect_title.top = 0;
    g->start_menu.rect_title.left = 0;
    g->start_menu.rect_title.width = 666;
    g->start_menu.rect_title.height = 121;
    g->start_menu.bool_press_continue = 0;
    g->start_menu.x_title = 300;
    set_rec_bis(g);
}

static void create_clock(all_t *g)
{
    g->start_menu.clock = sfClock_create();
    g->start_menu.clock_title = sfClock_create();
    g->start_menu.clock_move = sfClock_create();
    g->start_menu.clock_mia = sfClock_create();
    g->menu.clock_mia_run = sfClock_create();
    g->game_one.clock_rep = sfClock_create();
}

static void set_sprite_menu(all_t *g)
{
    g->start_menu.back_start = create_sprite((int[2]) {0, 0}, 1, 1,
    "ressource/back_start.png");
    g->start_menu.back_effect = create_sprite((int[2]) {0, 0}, 1, 1,
    "ressource/back_back.png");
    g->start_menu.title = create_sprite((int[2])
    {427, g->start_menu.x_title}, 1.6, 1.6,
    "ressource/title.png");
    g->start_menu.mia = create_sprite((int[2])
    {g->menu.y_mia, 790}, 1.33, 1.33, "ressource/walk_mia.png");
    g->menu.y_mia -= 72;
    g->start_menu.mia_run = create_sprite((int[2]) {g->menu.y_mia, 730}, 2, 2,
    "ressource/mia_run.png");
    g->menu.souris = create_sprite((int[2]) {0, 0}, 0.07, 0.07,
    "ressource/souris.png");
}

static void set_sprite_rec(all_t *g)
{
    sfSprite_setTextureRect(g->start_menu.back_start, g->start_menu.rect);
    sfSprite_setTextureRect(g->start_menu.back_effect,
    g->start_menu.rect_back_effect);
    sfSprite_setTextureRect(g->start_menu.title, g->start_menu.rect_title);
    sfSprite_setTextureRect(g->start_menu.mia, g->start_menu.rect_mia);
    sfSprite_setTextureRect(g->start_menu.mia_run, g->start_menu.rect_mia);
    sfSprite_setTextureRect(g->menu.souris, g->menu.rect_souris);
    g->start_menu.text_continue = create_text((float[3]) {700, 850, 35},
    "ressource/cyber.ttf", "Press space to continue", sfWhite);
}

void set_music_text(all_t *g)
{
    char *wii =
    "ressource/music/Nintendo Wii - Shop Channel Music (Extended) HQ.wav";

    g->start_menu.music_menu =
    sfMusic_createFromFile("ressource/music/music_menu.ogg");
    sfMusic_play(g->start_menu.music_menu);
    sfMusic_setLoop(g->start_menu.music_menu, sfTrue);
    g->mia.music_ambiance =
    sfMusic_createFromFile("ressource/music/music_ambiance.ogg");
    sfMusic_setLoop(g->mia.music_ambiance, sfTrue);
    g->mia.music_maison =
    sfMusic_createFromFile("ressource/music/music_maison.wav");
    sfMusic_setLoop(g->mia.music_maison, sfTrue);
    g->mia.music_bar = sfMusic_createFromFile("ressource/music/music_bar.ogg");
    sfMusic_setLoop(g->mia.music_bar, sfTrue);
    g->mia.music_usine =
    sfMusic_createFromFile("ressource/music/music_usine.ogg");
    sfMusic_setLoop(g->mia.music_usine, sfTrue);
    g->mia.music_store = sfMusic_createFromFile(wii);
    sfMusic_setLoop(g->mia.music_store, sfTrue);
    g->mia.music_manoir =
    sfMusic_createFromFile("music_manoir.ogg");
    sfMusic_setLoop(g->mia.music_manoir, sfTrue);
}

void set_start_menu(all_t *g)
{
    set_rec(g);
    set_sprite_menu(g);
    set_sprite_rec(g);
    set_music_text(g);
    create_clock(g);
    return;
}

void move_menu(all_t *g)
{
    g->menu.y_black_back -= 3;
    g->menu.y_new_game -= 3;
    g->menu.y_conti -= 3;
    g->menu.y_setting -= 3;
    g->menu.y_exit -= 3;
    sfSprite_setPosition(g->menu.black_menu,
        (sfVector2f){0, g->menu.y_black_back});
    sfText_setPosition(g->menu.new_game,
        (sfVector2f){810, g->menu.y_new_game});
    sfText_setPosition(g->menu.conti,
        (sfVector2f){820, g->menu.y_conti});
    sfText_setPosition(g->menu.setting,
        (sfVector2f){840, g->menu.y_setting});
    sfText_setPosition(g->menu.exit,
        (sfVector2f){890, g->menu.y_exit});
}
