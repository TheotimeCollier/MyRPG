/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** draw
*/

#include "../include/my.h"

void update_menu(all_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->start_menu.back_effect, NULL);
    sfRenderWindow_drawSprite(g->window, g->start_menu.back_start, NULL);
    sfRenderWindow_drawSprite(g->window, g->start_menu.title, NULL);
    if (g->menu.bool_newgame == 0)
    sfRenderWindow_drawSprite(g->window, g->start_menu.mia, NULL);
    if (g->menu.bool_newgame == 1)
    sfRenderWindow_drawSprite(g->window, g->start_menu.mia_run, NULL);
    draw_menu(g);
    draw_setting(g);
    clock_title(g);
    clock_mia(g);
    clock_menu(g);
    sfRenderWindow_drawSprite(g->window, g->menu.souris, NULL);
    sfRenderWindow_display(g->window);
}

static void draw_map(all_t *g)
{
    if (g->mia.map == 1) {
        sfRenderWindow_drawSprite(g->window, g->mia.view_minimap,
        NULL);
        sfRenderWindow_drawSprite(g->window,
        g->mia.spritemia_minimap, NULL);
    }
}

void update_game(all_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (g->esc_menu.menu == false && g->esc_menu.bool_pc == 0) {
        sfRenderWindow_drawSprite(g->window, g->mia.fortnite, NULL);
        draw_attack(g);
        draw_pnj(g);
        sfRenderWindow_drawSprite(g->window, g->mia.sur_map, NULL);
        sfRenderWindow_drawSprite(g->window, g->robot.robot, NULL);
        draw_map(g);
        draw_gui(g);
        draw_key_e(g);
        update_inventory(g);
        update_effect(g);
        printlist(g);
        verif_death(g);
    }
    draw_esc_menu(g);
    draw_setting(g);
    sfRenderWindow_display(g->window);
}
