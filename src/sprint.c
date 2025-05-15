/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

void sprint(all_t *g)
{
    if (g->mia.endurance == 1) {
        if (sfKeyboard_isKeyPressed(g->mia.sprintkey) &&
        (sfKeyboard_isKeyPressed(g->mia.upkey) ||
        sfKeyboard_isKeyPressed(g->mia.leftkey) ||
        sfKeyboard_isKeyPressed(g->mia.downkey) ||
        sfKeyboard_isKeyPressed(g->mia.rightkey))
        && g->mia.current.r != 0 &&
        g->mia.current.g != 0 &&
        g->mia.current.b != 0) {
            g->mia.sprint = 1;
            sfSprite_setScale(g->mia.mia_sprite,
            (sfVector2f){0.4, 0.4});
        }
    }
}

void fight_anim(all_t *g)
{
    if (g->mia.attack == 1) {
        g->mia.movement = 1;
        if (g->mia.idle[0] == 1)
            clockmouvkatana(g, g->mia.katana_top, 159, 9841);
        if (g->mia.idle[1] == 1)
            clockmouvkatana(g, g->mia.katana_topright, 159, 9841);
        if (g->mia.idle[2] == 1)
            clockmouvkatana(g, g->mia.katana_right, 159, 9841);
        if (g->mia.idle[3] == 1)
            clockmouvkatana(g, g->mia.katana_botright, 159, 9841);
        if (g->mia.idle[4] == 1)
            clockmouvkatana(g, g->mia.katana_bot, 159, 9841);
        if (g->mia.idle[5] == 1)
            clockmouvkatana(g, g->mia.katana_botleft, 159, 9841);
        if (g->mia.idle[6] == 1)
            clockmouvkatana(g, g->mia.katana_left, 159, 9841);
        if (g->mia.idle[7] == 1)
            clockmouvkatana(g, g->mia.katana_topleft, 159, 9841);
    } else
        g->mia.rect_miakatana.left = 0;
}

static void check_hitbox_bindnext(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->set->hit_right, mousepos.x, mousepos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setScale(g->set->right, (sfVector2f) {1.45, 1.45});
        g->mia.right = 1;
    } else
        sfSprite_setScale(g->set->right, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_sprint, mousepos.x, mousepos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setScale(g->set->sprint, (sfVector2f) {1.45, 1.45});
        g->mia.sprint_keybool = 1;
    } else
        sfSprite_setScale(g->set->sprint, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_use, mousepos.x, mousepos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setScale(g->set->use, (sfVector2f) {1.45, 1.45});
        g->mia.e_keybool = 1;
    } else
        sfSprite_setScale(g->set->use, (sfVector2f) {0.12, 0.12});
}

static void arrow_quit_bind(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->set->hit_arrow, mousepos.x, mousepos.y))
        sfSprite_setScale(g->set->arrow_quit, (sfVector2f) {0.22, 0.22});
    else
        sfSprite_setScale(g->set->arrow_quit, (sfVector2f) {0.2, 0.2});
}

static void check_hitbox_bind(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->set->hit_up, mousepos.x, mousepos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setScale(g->set->up, (sfVector2f) {1.45, 1.45});
        g->mia.up = 1;
    } else
        sfSprite_setScale(g->set->up, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_down, mousepos.x, mousepos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setScale(g->set->down, (sfVector2f) {1.45, 1.45});
        g->mia.down = 1;
    } else
        sfSprite_setScale(g->set->down, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_left, mousepos.x, mousepos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setScale(g->set->left, (sfVector2f) {1.45, 1.45});
        g->mia.left = 1;
    } else
        sfSprite_setScale(g->set->left, (sfVector2f) {0.12, 0.12});
    check_hitbox_bindnext(g, mousepos);
    arrow_quit_bind(g, mousepos);
}

static void zoom_on_buttonparameters_next(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->set->hit_right, mousepos.x, mousepos.y)
    && !sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setScale(g->set->right, (sfVector2f) {0.116, 0.116});
    else
        sfSprite_setScale(g->set->right, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_sprint, mousepos.x, mousepos.y)
    && !sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setScale(g->set->sprint, (sfVector2f) {0.116, 0.116});
    else
        sfSprite_setScale(g->set->sprint, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_use, mousepos.x, mousepos.y)
    && !sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setScale(g->set->use, (sfVector2f) {0.116, 0.116});
    else
        sfSprite_setScale(g->set->use, (sfVector2f) {0.12, 0.12});
}

static void zoom_on_buttonparameters(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->set->hit_up, mousepos.x, mousepos.y)
    && !sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setScale(g->set->up, (sfVector2f) {0.116, 0.116});
    else
        sfSprite_setScale(g->set->up, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_down, mousepos.x, mousepos.y)
    && !sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setScale(g->set->down, (sfVector2f) {0.116, 0.116});
    else
        sfSprite_setScale(g->set->down, (sfVector2f) {0.12, 0.12});
    if (sfFloatRect_contains(&g->set->hit_left, mousepos.x, mousepos.y)
    && !sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setScale(g->set->left, (sfVector2f) {0.116, 0.116});
    else
        sfSprite_setScale(g->set->left, (sfVector2f) {0.12, 0.12});
    zoom_on_buttonparameters_next(g, mousepos);
}

void check_hitbox_setting(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->set->hit_full, mousepos.x, mousepos.y))
        sfText_setScale(g->set->full_screen, (sfVector2f) {1.05, 1.05});
    else
        sfText_setScale(g->set->full_screen, (sfVector2f) {1, 1});
    if (sfFloatRect_contains(&g->set->hit_window, mousepos.x, mousepos.y))
        sfText_setScale(g->set->window_mode, (sfVector2f) {1.05, 1.05});
    else
        sfText_setScale(g->set->window_mode, (sfVector2f) {1, 1});
    if (sfFloatRect_contains(&g->set->hit_custom, mousepos.x, mousepos.y))
        sfText_setScale(g->set->custom_text, (sfVector2f) {1.05, 1.05});
    else
        sfText_setScale(g->set->custom_text, (sfVector2f) {1, 1});
    if (sfFloatRect_contains(&g->set->hit_arrow, mousepos.x, mousepos.y))
        sfSprite_setScale(g->set->arrow_quit, (sfVector2f) {0.22, 0.22});
    else
        sfSprite_setScale(g->set->arrow_quit, (sfVector2f) {0.2, 0.2});
    if (g->set->disp_bind == true)
        check_hitbox_bind(g, mousepos);
    zoom_on_buttonparameters(g, mousepos);
}
