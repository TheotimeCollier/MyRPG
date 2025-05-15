/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

void set_key_e(all_t *g)
{
    g->gui.key_e_sprite = create_sprite((int[2])
    {-3000, 0}, 0.3, 0.3, "ressource/ekey.png");
    g->gui.key_e_rect.top = 0;
    g->gui.key_e_rect.left = 0;
    g->gui.key_e_rect.height = 51;
    g->gui.key_e_rect.width = 49;
    g->gui.clock_key_e = sfClock_create();
}

static void update_key_e_bis(all_t *g)
{
    if ((g->mia.x >= 385 && g->mia.x <= 430) &&
    (g->mia.y >= 330) &&
    g->scene == 3 && g->script.exit_house == 0)
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {400, 380});
    else if (g->scene != 1)
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {-3000, 0});
}

static void update_key_e(all_t *g)
{
    if ((g->mia.x > 4150 && g->mia.x < 4250) &&
    (g->mia.y > 2040 && g->mia.y < 2200) &&
    g->script.first_factory == 0) {
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {4213, 2106});
        return;
    } else if ((g->mia.x >= 1467 && g->mia.x <= 1575) &&
    (g->mia.y >= 2954 && g->mia.y <= 2988) &&
    g->script.history == 2)
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {1520, 2980});
    else
        update_key_e_bis(g);
}

void draw_key_e(all_t *g)
{
    update_key_e(g);
    clock_key_e(g);
    sfSprite_setTextureRect(g->gui.key_e_sprite, g->gui.key_e_rect);
    sfRenderWindow_drawSprite(g->window, g->gui.key_e_sprite, NULL);
}

void clock_key_e(all_t *g)
{
    g->gui.time_key_e = sfClock_getElapsedTime(g->gui.clock_key_e);
    g->gui.seconds_key_e = g->gui.time_key_e.microseconds / 1000000.0;
    if (g->gui.seconds_key_e > 0.5) {
        g->gui.key_e_rect.left += 49;
        sfSprite_setTextureRect(g->gui.key_e_sprite, g->gui.key_e_rect);
        sfClock_restart(g->gui.clock_key_e);
        if (g->gui.key_e_rect.left > 49)
            g->gui.key_e_rect.left = 0;
    }
}
