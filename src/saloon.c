/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** house_mia
*/

#include "../include/my.h"

void set_saloon(all_t *g)
{
    g->saloon.map = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/saloon.png");
    g->saloon.onmap = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/saloon_onmap.png");
    g->saloon.undermap = sfImage_createFromFile
    ("ressource/saloon_undermap.png");
}

static void all_event_saloon(all_t *g, sfVector2f mouse_pos, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(g->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && g->set->disp_set == true)
        cursor_sound(g, mouse_pos);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
        pc_touch(g);
    if (event.type == sfEvtMouseButtonReleased) {
        check_clicked_esc(g, mouse_pos);
        check_clicked_set(g, mouse_pos);
    }
    check_hitbox_setting(g, mouse_pos);
    check_hit_esc(g, mouse_pos);
    change_control(g, event);
    event_inventory(event, g);
}

void hand_event_saloon(all_t *g)
{
    sfEvent event;
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPosition((const sfWindow *) g->window), NULL);

    sfSprite_setPosition(g->menu.souris, (sfVector2f)
    {mouse_pos.x - 10, mouse_pos.y - 3});
    movement_mia(g, g->saloon.undermap);
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        all_event_saloon(g, mouse_pos, event);
    }
}

void update_saloon(all_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (g->esc_menu.menu == false && g->esc_menu.bool_pc == 0) {
        sfRenderWindow_drawSprite(g->window, g->saloon.map, NULL);
        draw_pnj(g);
        sfRenderWindow_drawSprite(g->window, g->saloon.onmap, NULL);
        draw_gui(g);
        draw_attack(g);
        printlist(g);
        update_inventory(g);
        verif_death(g);
    }
    draw_esc_menu(g);
    draw_setting(g);
    sfRenderWindow_display(g->window);
}

void saloon(all_t *g)
{
    hand_event_saloon(g);
    update_saloon(g);
    if (g->esc_menu.menu == false)
        check_range(g, g->saloon.undermap);
}
