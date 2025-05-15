/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** usine
*/

#include "../include/my.h"

void set_usine(all_t *g)
{
    g->usine.map = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/usine_map.png");
    g->usine.onmap = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/usine_onmap.png");
    g->usine.undermap = sfImage_createFromFile
    ("ressource/usine_undermap.png");
    g->usine.b_draw_usine = 0;
}

void all_event_usine(all_t *g, sfVector2f mouse_pos, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && g->set->disp_set == true)
        cursor_sound(g, mouse_pos);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
        pc_touch(g);
    if ((g->mia.x > 280 && g->mia.x < 340) &&
        (g->mia.y > 525 && g->mia.y < 575)) {
        g->script.drawe_mother = 1;
        if (event.type == sfEvtKeyReleased && event.key.code == g->mia.ekey &&
        g->script.first_factory == 2) {
            script(g, 5);
            load_invent(g, 3);
            g->script.first_factory = 4;
        }
    } else
        g->script.drawe_mother = 0;
    if (event.type == sfEvtMouseButtonReleased) {
        check_clicked_esc(g, mouse_pos);
        check_clicked_set(g, mouse_pos);
    }
    event_inventory(event, g);
}

void hand_event_usine(all_t *g)
{
    sfEvent event;
    sfVector2f mouse_pos;

    mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPosition((const sfWindow *) g->window), NULL);
    movement_mia(g, g->usine.undermap);
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        all_event_usine(g, mouse_pos, event);
        check_hitbox_setting(g, mouse_pos);
        check_hit_esc(g, mouse_pos);
        change_control(g, event);
    }
    if ((g->mia.x > 280 && g->mia.x < 340 && g->mia.y
    < 573) && g->scene == 2 && g->script.first_factory == 2) {
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {310, 525});
        return;
    } else
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {-3000, 0});
}

void update_usine(all_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (g->esc_menu.menu == false && g->esc_menu.menu == false &&
    g->esc_menu.bool_pc == 0 && g->usine.b_draw_usine == 1) {
        sfRenderWindow_drawSprite(g->window, g->usine.map, NULL);
        sfRenderWindow_drawSprite(g->window, g->usine.onmap, NULL);
        draw_gui(g);
        draw_attack(g);
        printlist(g);
        update_inventory(g);
        clock_key_e(g);
        sfSprite_setTextureRect(g->gui.key_e_sprite, g->gui.key_e_rect);
        sfRenderWindow_drawSprite(g->window, g->gui.key_e_sprite, NULL);
    }
    draw_esc_menu(g);
    draw_setting(g);
    sfRenderWindow_display(g->window);
}
