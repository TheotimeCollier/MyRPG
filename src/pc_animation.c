/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

void clock_pc_bis(all_t *g)
{
    if (g->esc_menu.bool_pc == 1) {
            g->esc_menu.init = 0;
            if (g->esc_menu.rect_pc.left > 8600) {
                g->esc_menu.rect_pc.top += 704;
                g->esc_menu.rect_pc.left = 0;
            }
            g->esc_menu.rect_pc.left += 1250;
        }
        if (g->esc_menu.bool_pc == 2) {
            if (g->esc_menu.init == 0) {
                g->esc_menu.init = 1;
                g->esc_menu.rect_pc.top = 1406;
                g->esc_menu.rect_pc.left = 8749;
            }
            if (g->esc_menu.rect_pc.left < 1350) {
                g->esc_menu.rect_pc.top -= 704;
                g->esc_menu.rect_pc.left = 8749;
            }
            g->esc_menu.rect_pc.left -= 1250;
        }
}

void clock_pc(all_t *g)
{
    sfRenderWindow_setView(g->window,
    sfRenderWindow_getDefaultView(g->window));
    g->esc_menu.time_pc = sfClock_getElapsedTime(g->esc_menu.clock_pc);
    g->esc_menu.second_pc = g->esc_menu.time_pc.microseconds / 1000000.0;
    sfRenderWindow_drawSprite(g->window, g->menu.pc_sripte, NULL);
    if (g->esc_menu.second_pc > 0.05) {
        clock_pc_bis(g);
        sfSprite_setTextureRect(g->menu.pc_sripte, g->esc_menu.rect_pc);
        sfClock_restart(g->esc_menu.clock_pc);
        if (g->esc_menu.rect_pc.left > 4600 &&
        g->esc_menu.bool_pc == 1 && g->esc_menu.rect_pc.top > 2000)
            g->esc_menu.menu = true;
        if (g->esc_menu.bool_pc == 2)
            g->esc_menu.menu = false;
        if (g->esc_menu.rect_pc.left < 1300 &&
        g->esc_menu.bool_pc == 2 && g->esc_menu.rect_pc.top < 0) {
            g->esc_menu.bool_pc = 0;
        }
    }
}

void pc_touch(all_t *g)
{
    if (g->esc_menu.menu == false) {
                g->esc_menu.bool_pc = 1;
                return;
            }
    if (g->esc_menu.menu == true) {
        if (g->esc_menu.bool_pc == 1) {
            g->esc_menu.bool_pc = 2;
            g->esc_menu.rect_pc.left = 9645;
            g->set->disp_bind = false;
            g->set->disp_set = false;
            return;
        }
        if (g->esc_menu.bool_pc == 2) {
            g->esc_menu.menu = false;
            g->esc_menu.rect_pc.left = 0;
            g->esc_menu.bool_pc = 0;
            }
        return;
    }
}
