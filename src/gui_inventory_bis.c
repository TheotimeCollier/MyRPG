/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

static void set_inventory_bis(all_t *g)
{
    g->gui_invent.text_four = create_text
    ((float[3]) {0, 0, 12}, "ressource/number.ttf", "0", sfWhite);
    g->gui_invent.current_pos = 1;
    g->gui_invent.invent[0][0] = 0;
    g->gui_invent.invent[0][1] = 0;
    g->gui_invent.invent[1][0] = 0;
    g->gui_invent.invent[1][1] = 0;
    g->gui_invent.invent[2][0] = 0;
    g->gui_invent.invent[2][1] = 0;
    g->gui_invent.invent[3][0] = 0;
    g->gui_invent.invent[3][1] = 0;
}

void set_inventory(all_t *g)
{
    g->gui_invent.gui_inventory = create_sprite
    ((int[2]) {0, 0}, 0.13, 0.13, "ressource/inventory_gui.png");
    g->gui_invent.carre_inventory = create_sprite
    ((int[2]) {0, 0}, 0.13, 0.13, "ressource/carre_inventory.png");
    g->gui_invent.item_one = create_sprite
    ((int[2]) {0, 0}, 0.15, 0.15, "ressource/seringue.png");
    g->gui_invent.item_two = create_sprite
    ((int[2]) {0, 0}, 0.15, 0.15, "ressource/seringue.png");
    g->gui_invent.item_three = create_sprite
    ((int[2]) {0, 0}, 0.15, 0.15, "ressource/seringue.png");
    g->gui_invent.item_four = create_sprite
    ((int[2]) {0, 0}, 0.15, 0.15, "ressource/seringue.png");
    g->gui_invent.text_one = create_text
    ((float[3]) {0, 0, 12}, "ressource/number.ttf", "0", sfWhite);
    g->gui_invent.text_two = create_text
    ((float[3]) {0, 0, 12}, "ressource/number.ttf", "0", sfWhite);
    g->gui_invent.text_three = create_text
    ((float[3]) {0, 0, 12}, "ressource/number.ttf", "0", sfWhite);
    set_inventory_bis(g);
}

void draw_inventory(all_t *g)
{
    if (g->store.b_disp_store == 0) {
        sfRenderWindow_drawSprite(g->window, g->gui_invent.gui_inventory,
        NULL);
        sfRenderWindow_drawSprite(g->window, g->gui_invent.carre_inventory,
        NULL);
        sfRenderWindow_drawSprite(g->window, g->gui_invent.item_one, NULL);
        sfRenderWindow_drawSprite(g->window, g->gui_invent.item_two, NULL);
        sfRenderWindow_drawSprite(g->window, g->gui_invent.item_three, NULL);
        sfRenderWindow_drawSprite(g->window, g->gui_invent.item_four, NULL);
        sfRenderWindow_drawText(g->window, g->gui_invent.text_one, NULL);
        sfRenderWindow_drawText(g->window, g->gui_invent.text_two, NULL);
        sfRenderWindow_drawText(g->window, g->gui_invent.text_three, NULL);
        sfRenderWindow_drawText(g->window, g->gui_invent.text_four, NULL);
        }
}

int add_item(all_t *g, int item)
{
    if (g->gui_invent.invent[0][0] == item) {
        g->gui_invent.invent[0][1] += 1;
        return 1;
    }
    if (g->gui_invent.invent[1][0] == item) {
        g->gui_invent.invent[1][1] += 1;
        return 1;
    }
    if (g->gui_invent.invent[2][0] == item) {
        g->gui_invent.invent[2][1] += 1;
        return 1;
    }
    if (g->gui_invent.invent[3][0] == item) {
        g->gui_invent.invent[3][1] += 1;
        return 1;
    }
    return 0;
}
