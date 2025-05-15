/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** haunted
*/

#include "../include/my.h"

void set_haunted(all_t *g)
{
    g->haunted.map = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/haunted_map.png");
    g->haunted.onmap = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/haunted_overmap.png");
    g->haunted.undermap = sfImage_createFromFile
    ("ressource/haunted_undermap.png");
}

void all_event_haunted(all_t *g, sfVector2f mouse_pos, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && g->set->disp_set == true)
        cursor_sound(g, mouse_pos);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
        pc_touch(g);
    if (event.type == sfEvtMouseButtonReleased) {
        check_clicked_esc(g, mouse_pos);
        check_clicked_set(g, mouse_pos);
    }
    event_inventory(event, g);
}

void hand_event_haunted(all_t *g)
{
    sfEvent event;
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPosition((const sfWindow *) g->window), NULL);

    if (g->esc_menu.menu == false)
        movement_mia(g, g->haunted.undermap);
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (g->boss.health <= 0)
            g->script.history = 4;
        all_event_haunted(g, mouse_pos, event);
        check_hitbox_setting(g, mouse_pos);
        check_hit_esc(g, mouse_pos);
        change_control(g, event);
        event_inventory(event, g);
    }
    if (g->script.history != 4 && g->boss_bar.life_boss > 0)
        moov_boss(g);
    hand_robot(g, event);
}

static void update_haunted_s(all_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->robot.robot, NULL);
    sfRenderWindow_drawSprite(g->window, g->haunted.onmap, NULL);
    draw_gui(g);
    printlist(g);
    update_inventory(g);
    clock_key_e(g);
    sfSprite_setTextureRect(g->gui.key_e_sprite, g->gui.key_e_rect);
    sfRenderWindow_drawSprite(g->window, g->gui.key_e_sprite, NULL);
    draw_boss_bar(g);
    verif_death(g);
}

void update_haunted(all_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (g->esc_menu.menu == false && g->esc_menu.bool_pc == 0) {
        sfRenderWindow_drawSprite(g->window, g->haunted.map, NULL);
        draw_attack(g);
        if (g->script.history != 4 && g->boss_bar.life_boss > 0)
            draw_boss(g);
        update_haunted_s(g);
    }
    draw_esc_menu(g);
    draw_setting(g);
    sfRenderWindow_display(g->window);
}

void haunted(all_t *g)
{
    hand_event_haunted(g);
    update_haunted(g);
}
