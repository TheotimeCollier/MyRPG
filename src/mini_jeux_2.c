/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

void digi_game(all_t *g)
{
    get_hitbox(g);
}

void hand_event_mini_game(all_t *g)
{
    sfEvent event;
    sfVector2i mousepos;
    sfVector2f mouse_pos;

    mousepos = sfMouse_getPosition((const sfWindow *) g->window);
    mouse_pos = sfRenderWindow_mapPixelToCoords(g->window, mousepos,
    NULL);
    sfSprite_setPosition(g->menu.souris,
        (sfVector2f) {mouse_pos.x - 10, mouse_pos.y - 3});
    digi_game(g);
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtMouseButtonReleased)
            verif_hit(g, mouse_pos);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
            g->game_one.b_disp_code = 0;
    }
}

static void update_mini_game_bis(all_t *g)
{
    if (g->game_one.bool_rep == 1 || g->game_one.bool_rep == 2)
        clock_rep(g);
    if (g->game_one.multi == 100 && g->game_one.bool_rep == 0)
        sfRenderWindow_drawSprite(g->window, g->game_one.c_one, NULL);
    if (g->game_one.multi == 10 && g->game_one.bool_rep == 0) {
        sfRenderWindow_drawSprite(g->window, g->game_one.c_one, NULL);
        sfRenderWindow_drawSprite(g->window, g->game_one.c_two, NULL);
    }
    if (g->game_one.multi == 1 && g->game_one.bool_rep == 0) {
        sfRenderWindow_drawSprite(g->window, g->game_one.c_one, NULL);
        sfRenderWindow_drawSprite(g->window, g->game_one.c_two, NULL);
        sfRenderWindow_drawSprite(g->window, g->game_one.c_three, NULL);
    }
    if (g->game_one.multi == 0 && g->game_one.bool_rep == 0) {
        sfRenderWindow_drawSprite(g->window, g->game_one.c_one, NULL);
        sfRenderWindow_drawSprite(g->window, g->game_one.c_two, NULL);
        sfRenderWindow_drawSprite(g->window, g->game_one.c_three, NULL);
        sfRenderWindow_drawSprite(g->window, g->game_one.c_four, NULL);
    }
}

void update_mini_game(all_t *g)
{
    sfRenderWindow_setView(g->window,
    sfRenderWindow_getDefaultView(g->window));
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->game_one.back_digi, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.zero, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.one, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.two, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.three, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.four, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.five, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.six, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.seven, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.eight, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.nine, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.valider, NULL);
    sfRenderWindow_drawSprite(g->window, g->game_one.annuler, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.souris, NULL);
    clock_title(g);
    update_mini_game_bis(g);
    sfRenderWindow_display(g->window);
}

void check_difi_disp(all_t *g)
{
    if (g->game_one.b_disp_code == 0 && (g->mia.x > 3850
    && g->mia.x < 3950) && (g->mia.y > 2040
    && g->mia.y < 2200)) {
        g->game_one.b_disp_code = 1;
        return;
    }
    if (g->game_one.b_disp_code == 1)
        g->game_one.b_disp_code = 0;
}
