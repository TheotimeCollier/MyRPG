/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** event
*/

#include "../include/my.h"

static void music_menupause(all_t *g)
{
    if (g->menu.bool_newgame == 0) {
        sfMusic_pause(g->mia.music_ambiance);
        sfMusic_pause(g->mia.music_maison);
        sfMusic_pause(g->mia.music_usine);
        sfMusic_pause(g->mia.music_bar);
        sfMusic_pause(g->mia.music_store);
        sfMusic_pause(g->mia.music_manoir);
    }
}

void hand_event_menu(all_t *g)
{
    sfEvent event;
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPosition((const sfWindow *) g->window), NULL);

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        check_hitbox_menu(g, mouse_pos);
        if (sfMouse_isButtonPressed(sfMouseLeft) && g->set->disp_set == true)
            cursor_sound(g, mouse_pos);
        if (event.type == sfEvtMouseButtonReleased)
            check_clicked_set(g, mouse_pos);
        if (g->set->disp_set == false)
            button_newgame(g, mouse_pos);
        sfSprite_setPosition(g->menu.souris,
        (sfVector2f) {mouse_pos.x - 10, mouse_pos.y - 3});
        check_hitbox_setting(g, mouse_pos);
        music_menupause(g);
        change_control(g, event);
    }
}

static void all_event(sfEvent event, all_t *g, sfVector2f mouse_pos)
{
    sfSprite_setPosition(g->menu.souris,
        (sfVector2f) {mouse_pos.x - 10, mouse_pos.y - 3});
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
    if (event.type == sfEvtKeyReleased &&
    event.key.code == g->mia.ekey) {
        check_store(g);
        check_difi_disp(g);
    }
    event_effect(g, event);
}

void size_map(all_t *g, sfEvent event)
{
    if (event.mouseWheelScroll.delta == 1 && g->mia.screensize >= 0.4) {
        g->mia.screensize -= 0.1;
        g->mia.v_gui1.x -= 95;
        g->mia.v_gui1.y -= 55;
        g->mia.v_minimap.x -= 98;
        g->mia.v_minimap.y -= 55;
    }
    if (event.mouseWheelScroll.delta == -1 && g->mia.screensize < 0.5){
        g->mia.screensize += 0.1;
        g->mia.v_gui1.x += 95;
        g->mia.v_gui1.y += 55;
        g->mia.v_minimap.x += 98;
        g->mia.v_minimap.y += 55;
    }
}

static void event_script_game(all_t *g, sfEvent event)
{
    if ((g->mia.x > 4150 && g->mia.x < 41250) &&
        (g->mia.y > 2040 && g->mia.y < 2200)) {
            g->script.drawe_mother = 1;
        if (event.type == sfEvtKeyReleased &&
        event.key.code == g->mia.ekey && g->script.first_factory == 0) {
            script(g, 5);
            g->script.first_factory = 1;
        }
    }
}

void hand_event_game(all_t *g)
{
    sfEvent event;
    sfVector2f mouse_pos;

    mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPosition((const sfWindow *) g->window), NULL);
    if (g->esc_menu.menu == false)
        movement_mia(g, g->mia.image_fortnite);
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        size_map(g, event);
        check_hit_esc(g, mouse_pos);
        check_hitbox_setting(g, mouse_pos);
        all_event(event, g, mouse_pos);
        event_inventory(event, g);
        event_script_game(g, event);
        hack_drone(g, event);
        change_control(g, event);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyY) {
            g->script.first_factory = 2;
            script(g, 4);
        }
    }
    hand_robot(g, event);
}
