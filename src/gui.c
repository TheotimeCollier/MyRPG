/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

void set_gui(all_t *g)
{
    g->gui.energie = 267;
    g->gui.malus_energie = 2;
    sprintf(g->gui.dol_text, "%d", g->gui.dollar);
    g->gui.life_sprite =
    create_sprite((int[2]){0, 0}, 0.47, 0.47, "ressource/life_sprite.png");
    g->gui.energie_sprite =
    create_sprite((int[2]){0, 0}, 0.47, 0.47, "ressource/eclair.png");
    g->gui.dollar_sprite =
    create_sprite((int[2]){0, 0}, 0.17, 0.17, "ressource/dollar.png");
    g->gui.life_rec =
    createrect(0, 0, (int[2]){g->esc_menu.taille_health, 4.8}, sfRed);
    g->gui.dollar_text = create_text((float[3]) {100, 100, 55},
    "ressource/number.ttf", g->gui.dol_text, sfWhite);
    g->gui.energie_rect = createrect(0, 0, (int[2]){g->gui.energie, 2},
    sfColor_fromRGB(255, 212, 0));
    sfText_setScale(g->gui.dollar_text, (sfVector2f){0.25, 0.25});
    g->gui.clock_regen = sfClock_create();
    g->gui.clock_energie = sfClock_create();
    g->gui.current_life = g->esc_menu.taille_health;
    g->gui.current_energie = g->gui.energie;
}

void clock_regen(all_t *g)
{
    g->gui.time_regen = sfClock_getElapsedTime(g->gui.clock_regen);
    g->gui.seconds_regen = g->gui.time_regen.microseconds / 1000000.0;
    if (g->gui.seconds_regen > 0.02 &&
    (g->gui.current_life < g->esc_menu.taille_health)) {
        g->gui.current_life += 1;
        sfRectangleShape_setSize(g->gui.life_rec,
        (sfVector2f) {g->gui.current_life / 4.37, 5.8});
        sfClock_restart(g->gui.clock_regen);
        if ((g->esc_menu.taille_health - g->gui.current_life) < 10)
            g->effect.b_effect_seringue = 0;
    }
}

void clock_energie(all_t *g)
{
    g->gui.time_energie = sfClock_getElapsedTime(g->gui.clock_energie);
    g->gui.seconds_energie = g->gui.time_energie.microseconds / 1000000.0;
    if (g->gui.seconds_energie > 0.05 &&
    (g->gui.current_energie < g->gui.energie)) {
        g->gui.current_energie += 3;
        sfRectangleShape_setSize(g->gui.energie_rect,
        (sfVector2f) {g->gui.current_energie / 3, 2});
        sfClock_restart(g->gui.clock_energie);
    }
}

static void update_pos_bis(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    sfRectangleShape_setPosition(g->gui.energie_rect,
    (sfVector2f) {viewposition.x - 275 - g->mia.v_gui1.x,
    viewposition.y - 123- g->mia.v_gui1.y});
    sfRectangleShape_setSize(g->gui.energie_rect,
    (sfVector2f) {g->gui.current_energie / 3, 4.8});
    sfText_setString(g->gui.dollar_text, g->gui.dol_text);
    sfText_setPosition(g->gui.dollar_text, (sfVector2f)
    {viewposition.x - 261 - g->mia.v_gui1.x, viewposition.y
    - 105 - g->mia.v_gui1.y});
}

static void update_pos(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    sfSprite_setPosition(g->gui.life_sprite,
    (sfVector2f) {viewposition.x - 292 - g->mia.v_gui1.x,
    viewposition.y - 170 - g->mia.v_gui1.y});
    sfSprite_setPosition(g->gui.dollar_sprite,
    (sfVector2f) {viewposition.x - 286 - g->mia.v_gui1.x,
    viewposition.y - 105 - g->mia.v_gui1.y});
    sfSprite_setPosition(g->gui.energie_sprite,
    (sfVector2f) {viewposition.x - 292 - g->mia.v_gui1.x,
    viewposition.y - 144- g->mia.v_gui1.y});
    sfRectangleShape_setPosition(g->gui.life_rec,
    (sfVector2f) {viewposition.x - 268 - g->mia.v_gui1.x,
    viewposition.y - 148- g->mia.v_gui1.y});
    sfRectangleShape_setSize(g->gui.life_rec,
    (sfVector2f) {g->gui.current_life / 4.37, 4.6});
    update_pos_bis(g);
}

void draw_gui(all_t *g)
{
    update_pos(g);
    sprintf(g->gui.dol_text, "%d", g->gui.dollar);
    sfRenderWindow_drawSprite(g->window, g->gui.dollar_sprite, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->gui.life_rec, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->gui.energie_rect, NULL);
    sfRenderWindow_drawText(g->window, g->gui.dollar_text, NULL);
    sfRenderWindow_drawSprite(g->window, g->gui.energie_sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->gui.life_sprite, NULL);
    if (g->effect.b_effect_seringue == 1)
        clock_regen(g);
    if (g->mia.sprint == 0)
        clock_energie(g);
}
