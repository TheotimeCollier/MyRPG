/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** house_mia
*/

#include "../include/my.h"

void set_house(all_t *g)
{
    g->house.map = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/house_map.png");
    g->house.onmap = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/house_onmap.png");
    g->house.undermap = sfImage_createFromFile
    ("ressource/house_undermap.png");
    g->house.s_mia_mother = create_sprite((int[2]){390, 350}, 0.3, 0.3,
    "ressource/mia_mother.png");
    g->house.clock_mother = sfClock_create();
    g->house.rect_mother.top = 0;
    g->house.rect_mother.left = 0;
    g->house.rect_mother.width = 207;
    g->house.rect_mother.height = 200;
}

void movement_mia_mother(all_t *g)
{
    g->house.time_mother = sfClock_getElapsedTime(g->house.clock_mother);
    g->house.second_mother = g->house.time_mother.microseconds / 1000000.0;
    if (g->house.second_mother > 0.1) {
        g->house.rect_mother.left += 200;
        sfSprite_setTextureRect(g->house.s_mia_mother, g->house.rect_mother);
        sfClock_restart(g->house.clock_mother);
        if (g->house.rect_mother.left > 9600)
            g->house.rect_mother.left = 0;
    }
}

void event_script_house(all_t *g, sfEvent event)
{
    if ((g->mia.x > 390 && g->mia.x < 405) &&
        (g->mia.y > 340 && g->mia.y < 400)) {
        g->script.drawe_mother = 1;
        if (event.type == sfEvtKeyReleased && event.key.code == g->mia.ekey &&
        g->script.exit_house == 0) {
            script(g, 11);
            g->script.exit_house = 1;
        }
    } else
        g->script.drawe_mother = 0;
    if ((g->mia.x > 95 && g->mia.x < 115) &&
        (g->mia.y > 330 && g->mia.y < 370)) {
            g->script.drawe_mother = 1;
        if (event.type == sfEvtKeyReleased && event.key.code == g->mia.ekey &&
        g->script.first_factory == 1) {
            script(g, 4);
            g->script.first_factory = 2;
        }
    } else
        g->script.drawe_mother = 0;
}

static void all_event_house(all_t *g, sfEvent event, sfVector2f mouse_pos)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(g->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && g->set->disp_set == true)
        cursor_sound(g, mouse_pos);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
        pc_touch(g);
    event_script_house(g, event);
    if (event.type == sfEvtMouseButtonReleased) {
        check_clicked_esc(g, mouse_pos);
        check_clicked_set(g, mouse_pos);
    }
    check_hitbox_setting(g, mouse_pos);
    check_hit_esc(g, mouse_pos);
    change_control(g, event);
}

void hand_event_house(all_t *g)
{
    sfEvent event;
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPosition((const sfWindow *) g->window), NULL);

    movement_mia(g, g->house.undermap);
    movement_mia_mother(g);
    sfSprite_setPosition(g->menu.souris, (sfVector2f)
    {mouse_pos.x - 10, mouse_pos.y - 3});
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        all_event_house(g, event, mouse_pos);
    }
}

void update_house(all_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (g->esc_menu.menu == false && g->esc_menu.bool_pc == 0) {
        sfRenderWindow_drawSprite(g->window, g->house.map, NULL);
        sfRenderWindow_drawSprite(g->window, g->mia.mia_sprite, NULL);
        draw_pnj(g);
        sfRenderWindow_drawSprite(g->window, g->house.onmap, NULL);
        sfRenderWindow_drawSprite(g->window, g->house.s_mia_mother, NULL);
        draw_gui(g);
        printlist(g);
        draw_key_e(g);
    }
        draw_esc_menu(g);
        draw_setting(g);
    sfRenderWindow_display(g->window);
}
