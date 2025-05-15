/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

void set_effect(all_t *g)
{
    g->effect.effect_sugar = create_text((float[3]) {0, 0, 12},
    "ressource/number.ttf", "0", sfWhite);
    g->effect.sec = 30;
    g->effect.clock_dure = sfClock_create();
    g->effect.b_effect_sugar = 0;
    g->effect.b_effect_seringue = 0;
    g->effect.sugar = create_sprite
    ((int[2]) {0, 0}, 0.12, 0.12, "ressource/sugar.png");
}

static void verif_clear_item(all_t *g)
{
    if (g->gui_invent.invent[0][1] == 0)
        g->gui_invent.invent[0][0] = 0;
    if (g->gui_invent.invent[1][1] == 0)
        g->gui_invent.invent[1][0] = 0;
    if (g->gui_invent.invent[2][1] == 0)
        g->gui_invent.invent[2][0] = 0;
    if (g->gui_invent.invent[3][1] == 0)
        g->gui_invent.invent[3][0] = 0;
}

static void verif_item(all_t *g)
{
    if (g->gui_invent.invent[g->gui_invent.current_pos - 1][0] == 2)
        if (g->gui_invent.invent[g->gui_invent.current_pos - 1][1] >= 1 &&
        g->effect.b_effect_sugar == 0) {
            g->gui_invent.invent[g->gui_invent.current_pos - 1][1] -= 1;
            g->effect.b_effect_sugar = 1;
        }
    if (g->gui_invent.invent[g->gui_invent.current_pos - 1][0] == 1)
        if (g->gui_invent.invent[g->gui_invent.current_pos - 1][1] >= 1 &&
        g->effect.b_effect_seringue == 0) {
            g->gui_invent.invent[g->gui_invent.current_pos - 1][1] -= 1;
            g->effect.b_effect_seringue = 1;
        }
}

static void all_clock(all_t *g)
{
    if (g->effect.b_effect_sugar == 1)
        clock_effect_sugar(g);
}

void clock_effect_sugar(all_t *g)
{
    g->effect.time_dure = sfClock_getElapsedTime(g->effect.clock_dure);
    g->effect.seconds_dure = g->effect.time_dure.microseconds / 1000000.0;
    if (g->effect.seconds_dure > 1.0) {
        g->effect.sec -= 1;
        sprintf(g->effect.sec_char, "%d", g->effect.sec);
        sfText_setString(g->effect.effect_sugar, g->effect.sec_char);
        sfClock_restart(g->effect.clock_dure);
        if (g->effect.sec == 0) {
            g->effect.b_effect_sugar = 0;
            g->effect.sec = 30;
        }
    }
}

static void set_pos_effect(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    sfText_setPosition(g->effect.effect_sugar,
    (sfVector2f) {viewposition.x - 260 - g->mia.v_gui1.x,
    viewposition.y - 76 - g->mia.v_gui1.y});
    sfSprite_setPosition(g->effect.sugar,
    (sfVector2f) {viewposition.x - 286 - g->mia.v_gui1.x,
    viewposition.y - 80 - g->mia.v_gui1.y});
}

void event_effect(all_t *g, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        if (event.key.code == sfKeyEnter) {
            verif_item(g);
            verif_clear_item(g);
        }
}

void update_effect(all_t *g)
{
    set_pos_effect(g);
    draw_effect(g);
    all_clock(g);
}

void draw_effect(all_t *g)
{
    if (g->effect.b_effect_sugar == 1) {
        sfRenderWindow_drawText(g->window, g->effect.effect_sugar, NULL);
        sfRenderWindow_drawSprite(g->window, g->effect.sugar, NULL);
    }
}
