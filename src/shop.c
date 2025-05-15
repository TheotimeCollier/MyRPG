/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop
*/

#include "../include/my.h"

void set_shop(all_t *g)
{
    g->store.map = create_sprite((int[2]) {0, 0}, 1, 1,
    "ressource/shop.jpeg");
    g->store.map_col = sfImage_createFromFile("ressource/collision_shop.jpeg");
}

void draw_store_bis(all_t *g)
{
    sfRenderWindow_setView(g->window,
    sfRenderWindow_getDefaultView(g->window));
    sfRenderWindow_drawSprite(g->window, g->store.fond, NULL);
    sfRenderWindow_drawSprite(g->window, g->store.next_d_sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->store.next_g_sprite, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->store.rec_price, NULL);
    sfRenderWindow_drawSprite(g->window, g->store.current_item, NULL);
    sfRenderWindow_drawText(g->window, g->store.current_price, NULL);
    sfRenderWindow_drawSprite(g->window, g->store.dollar_sprite, NULL);
    sfRenderWindow_drawText(g->window, g->store.name_item, NULL);
    sfRenderWindow_drawSprite(g->window, g->store.shop, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.souris, NULL);
    clock_title(g);
}

void hand_event_store_bis(all_t *g, sfEvent event, sfVector2f mouse_pos)
{
    if (event.type == sfEvtKeyReleased && event.key.code == g->mia.ekey)
            check_store(g);
        if (sfMouse_isButtonPressed(sfMouseLeft) && g->set->disp_set == true)
        cursor_sound(g, mouse_pos);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
            pc_touch(g);
    if ((g->mia.x > 106 && g->mia.x < 214 && g->mia.y <
    148) && g->scene == 1) {
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {125, 83});
        return;
    } else
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {-3000, 0});
    event_inventory(event, g);
    check_hitbox_setting(g, mouse_pos);
    check_hit_esc(g, mouse_pos);
    change_control(g, event);
    update_store_stat(g, mouse_pos);
}

static void update_store_stat_bis(all_t *g, sfVector2f mouse)
{
    if (sfFloatRect_contains(&g->store.buy_hit, mouse.x, mouse.y)) {
        sfRectangleShape_setScale(g->store.rec_price,
        (sfVector2f){1.05, 1.05});
        sfRectangleShape_setPosition(g->store.rec_price,
        (sfVector2f){855, 865});
    } else {
        sfRectangleShape_setScale(g->store.rec_price, (sfVector2f){1, 1});
        sfRectangleShape_setPosition(g->store.rec_price,
        (sfVector2f){860, 870});
    }
}

void update_store_stat(all_t *g, sfVector2f mouse)
{
    if (sfFloatRect_contains(&g->store.next_d_hit, mouse.x, mouse.y)) {
        sfSprite_setScale(g->store.next_d_sprite, (sfVector2f){1.05, 1.05});
        sfSprite_setPosition(g->store.next_d_sprite, (sfVector2f){1340, 80});
    } else {
        sfSprite_setScale(g->store.next_d_sprite, (sfVector2f){1, 1});
        sfSprite_setPosition(g->store.next_d_sprite, (sfVector2f){1350, 100});
    }
    if (sfFloatRect_contains(&g->store.next_g_hit, mouse.x, mouse.y))
        sfSprite_setScale(g->store.next_g_sprite, (sfVector2f){1.05, 1.05});
    else
        sfSprite_setScale(g->store.next_g_sprite, (sfVector2f){1, 1});
    if (sfFloatRect_contains(&g->store.buy_hit, mouse.x, mouse.y))
        sfRectangleShape_setScale(g->store.rec_price,
        (sfVector2f){1.05, 1.05});
    else
        sfRectangleShape_setScale(g->store.rec_price, (sfVector2f){1, 1});
    update_store_stat_bis(g, mouse);
}

void hand_event_store(all_t *g)
{
    sfEvent event;
    sfVector2f mouse_pos;

    mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPosition((const sfWindow *) g->window), NULL);
    if (g->store.b_disp_store == 0)
        movement_mia(g, g->store.map_col);
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtMouseButtonReleased) {
            check_hit_store(g, mouse_pos);
            change_url(g);
            check_clicked_esc(g, mouse_pos);
            check_clicked_set(g, mouse_pos);
        }
        sfSprite_setPosition(g->menu.souris,
        (sfVector2f) {mouse_pos.x - 10, mouse_pos.y - 3});
        hand_event_store_bis(g, event, mouse_pos);
    }
}
