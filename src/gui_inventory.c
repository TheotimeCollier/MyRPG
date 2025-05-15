/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

static void set_pos_bis(all_t *g)
{
    sprintf(g->gui_invent.char_one, "%d", g->gui_invent.invent[0][1]);
    sprintf(g->gui_invent.char_two, "%d", g->gui_invent.invent[1][1]);
    sprintf(g->gui_invent.char_three, "%d", g->gui_invent.invent[2][1]);
    sprintf(g->gui_invent.char_four, "%d", g->gui_invent.invent[3][1]);
    sfText_setString(g->gui_invent.text_one, g->gui_invent.char_one);
    sfText_setString(g->gui_invent.text_two, g->gui_invent.char_two);
    sfText_setString(g->gui_invent.text_three, g->gui_invent.char_three);
    sfText_setString(g->gui_invent.text_four, g->gui_invent.char_four);
}

static void set_pos(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    sfSprite_setPosition(g->gui_invent.gui_inventory,
    (sfVector2f) {viewposition.x + 140 + g->mia.v_gui1.x,
    viewposition.y + 105 + g->mia.v_gui1.y});
    sfText_setPosition(g->gui_invent.text_one,
    (sfVector2f) {viewposition.x + 165 + g->mia.v_gui1.x,
    viewposition.y + 138 + g->mia.v_gui1.y});
    sfText_setPosition(g->gui_invent.text_two,
    (sfVector2f) {viewposition.x + 200 + g->mia.v_gui1.x,
    viewposition.y + 138 + g->mia.v_gui1.y});
    sfText_setPosition(g->gui_invent.text_three,
    (sfVector2f) {viewposition.x + 235 + g->mia.v_gui1.x,
    viewposition.y + 138 + g->mia.v_gui1.y});
    sfText_setPosition(g->gui_invent.text_four,
    (sfVector2f) {viewposition.x + 270 + g->mia.v_gui1.x,
    viewposition.y + 138 + g->mia.v_gui1.y});
    set_pos_bis(g);
}

static void set_item(all_t *g, sfSprite *sprite, int coord[2], int number)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    if (g->gui_invent.invent[number][0] == 0)
        sfSprite_setPosition(sprite,
        (sfVector2f) {viewposition.x + 10082 + g->mia.v_gui1.x,
        viewposition.y + 105 - g->mia.v_gui1.y});
    else
        sfSprite_setPosition(sprite,
        (sfVector2f) {viewposition.x + coord[0] + g->mia.v_gui1.x,
        viewposition.y + coord[1] + g->mia.v_gui1.y});
    if (g->gui_invent.invent[number][0] == 1)
        sfSprite_setTexture(sprite, g->store.seringue_texture, sfTrue);
    if (g->gui_invent.invent[number][0] == 2)
        sfSprite_setTexture(sprite, g->store.sugar, sfTrue);
    if (g->gui_invent.invent[number][0] == 3)
        sfSprite_setTexture(sprite, g->store.katana, sfTrue);
    if (g->gui_invent.invent[number][0] == 4)
        sfSprite_setTexture(sprite, g->store.pc_texture, sfTrue);
}

static void update_carre(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    if (g->gui_invent.current_pos == 1)
        sfSprite_setPosition(g->gui_invent.carre_inventory,
        (sfVector2f) {viewposition.x + 82 + g->mia.v_gui1.x,
        viewposition.y + 105 + g->mia.v_gui1.y});
    if (g->gui_invent.current_pos == 2)
        sfSprite_setPosition(g->gui_invent.carre_inventory,
        (sfVector2f) {viewposition.x + 116 + g->mia.v_gui1.x,
        viewposition.y + 105 + g->mia.v_gui1.y});
    if (g->gui_invent.current_pos == 3)
        sfSprite_setPosition(g->gui_invent.carre_inventory,
        (sfVector2f) {viewposition.x + 151 + g->mia.v_gui1.x,
        viewposition.y + 105 + g->mia.v_gui1.y});
    if (g->gui_invent.current_pos == 4)
        sfSprite_setPosition(g->gui_invent.carre_inventory,
        (sfVector2f) {viewposition.x + 186 + g->mia.v_gui1.x,
        viewposition.y + 105 + g->mia.v_gui1.y});
}

void event_inventory(sfEvent event, all_t *g)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyLeft && g->gui_invent.current_pos > 1)
            g->gui_invent.current_pos -= 1;
        if (event.key.code == sfKeyRight && g->gui_invent.current_pos < 4)
            g->gui_invent.current_pos += 1;
    }
}

static void load_invent_tres(all_t *g, int item)
{
    if (g->gui_invent.invent[2][0] == 0) {
        g->gui_invent.invent[2][0] = item;
        g->gui_invent.invent[2][1] += 1;
    } else if (g->gui_invent.invent[3][0] == 0) {
        g->gui_invent.invent[3][0] = item;
        g->gui_invent.invent[3][1] += 1;
    }
}

static void load_invent_bis(all_t *g, int item)
{
    if (g->gui_invent.invent[0][0] == 0) {
        g->gui_invent.invent[0][0] = item;
        g->gui_invent.invent[0][1] += 1;
    } else if (g->gui_invent.invent[1][0] == 0) {
        g->gui_invent.invent[1][0] = item;
        g->gui_invent.invent[1][1] += 1;
    } else
        load_invent_tres(g, item);
}

void load_invent(all_t *g, int item)
{
    if (item == 0)
        item = 4;
    if (add_item(g, item) == 0)
        load_invent_bis(g, item);
}

void update_inventory(all_t *g)
{
    set_pos(g);
    update_carre(g);
    set_item(g, g->gui_invent.item_one, (int[2]) {143, 121}, 0);
    set_item(g, g->gui_invent.item_two, (int[2]) {177, 121}, 1);
    set_item(g, g->gui_invent.item_three, (int[2]) {212, 121}, 2);
    set_item(g, g->gui_invent.item_four, (int[2]) {247, 121}, 3);
    draw_inventory(g);
}
