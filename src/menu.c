/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

static void set_sprite_esc_menu(all_t *g)
{
    g->esc_menu.health_cross = create_sprite(
    (int[2]) {1720, 875}, 0.06, 0.06, "ressource/cross.png");
    g->esc_menu.speed_cross = create_sprite(
    (int[2]) {1720, 925}, 0.06, 0.06, "ressource/cross.png");
    g->esc_menu.attack_cross = create_sprite(
    (int[2]) {1720, 975}, 0.06, 0.06, "ressource/cross.png");
    g->esc_menu.select_text = create_sprite(
    (int[2]) {700, 325}, 0.38, 0.3, "ressource/select_menu.png");
    g->esc_menu.init = 0;
}

static void set_sprite_menu(all_t *g)
{
    g->menu.black_menu = create_sprite(
    (int[2]) {0, g->menu.y_black_back}, 1, 1, "ressource/black_back.png");
    g->menu.pc_sripte = create_sprite(
    (int[2]) {0, 0}, 1.5, 1.5, "ressource/pc.png");
    g->esc_menu.kali = create_sprite(
    (int[2]) {0, 0}, 1, 1, "ressource/kali.png");
    set_sprite_esc_menu(g);
    return;
}

static void set_text(all_t *g)
{
    g->menu.new_game = create_text((float[3]) {810, g->menu.y_new_game, 63},
    "ressource/cyber.ttf", "New Game", sfWhite);
    g->menu.conti = create_text((float[3]) {820, g->menu.y_conti, 63},
    "ressource/cyber.ttf", "Continue", sfWhite);
    g->menu.setting = create_text((float[3]) {840, g->menu.y_setting, 63},
    "ressource/cyber.ttf", "Settings", sfWhite);
    g->menu.exit = create_text((float[3]) {890, g->menu.y_exit, 63},
    "ressource/cyber.ttf", "Exit", sfWhite);
}

void move_new_game(all_t *g)
{
    if (g->menu.y_black_back > -1200)
        move_menu(g);
    if (g->start_menu.x_title > -1200) {
        g->start_menu.x_title -= 3;
        sfSprite_setPosition(g->start_menu.title,
        (sfVector2f){427, g->start_menu.x_title});
    }
}

void draw_menu(all_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        g->start_menu.bool_press_continue = 1;
    if (g->start_menu.bool_press_continue == 0)
        sfRenderWindow_drawText(g->window, g->start_menu.text_continue, NULL);
    if (g->start_menu.bool_press_continue == 1) {
        clock_move(g);
        sfRenderWindow_drawSprite(g->window, g->menu.black_menu, NULL);
        if (g->set->disp_set == false) {
            sfRenderWindow_drawText(g->window, g->menu.new_game, NULL);
            sfRenderWindow_drawText(g->window, g->menu.conti, NULL);
            sfRenderWindow_drawText(g->window, g->menu.setting, NULL);
            sfRenderWindow_drawText(g->window, g->menu.exit, NULL);
        }
    }
}

void set_menu(all_t *g)
{
    g->menu.y_black_back = 835;
    g->menu.y_new_game = 1215;
    g->menu.y_conti = 1345;
    g->menu.y_setting = 1475;
    g->menu.y_exit = 1605;
    g->menu.bool_newgame = 0;
    g->esc_menu.bool_pc = 0;
    set_text(g);
    set_sprite_menu(g);
}

void button_newgame(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->menu.hit_new_game, mousepos.x, mousepos.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        g->script.head = (node_t *) readscriptfromfile(g, 4);
        g->menu.bool_newgame = 1;
        }
    if (sfFloatRect_contains(&g->menu.hit_exit, mousepos.x, mousepos.y) &&
    sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_close(g->window);
    if (sfFloatRect_contains(&g->menu.hit_continue, mousepos.x, mousepos.y) &&
        sfMouse_isButtonPressed(sfMouseLeft) &&
        sfText_getColor(g->menu.conti).r == 255) {
        init_save(g);
        g->menu.bool_newgame = 1;
        }
}

static void actualize_hitbox_menu(all_t *g)
{
    g->menu.hit_new_game = sfText_getGlobalBounds(g->menu.new_game);
    g->menu.hit_continue = sfText_getGlobalBounds(g->menu.conti);
    g->menu.hit_setting = sfText_getGlobalBounds(g->menu.setting);
    g->menu.hit_exit = sfText_getGlobalBounds(g->menu.exit);
}

void check_hitbox_menu(all_t *g, sfVector2f mousepos)
{
    actualize_hitbox_menu(g);
    if (sfFloatRect_contains(&g->menu.hit_new_game, mousepos.x, mousepos.y))
        sfText_setScale(g->menu.new_game, (sfVector2f) {1.05, 1.05});
    else
        sfText_setScale(g->menu.new_game, (sfVector2f) {1, 1});
    if (sfFloatRect_contains(&g->menu.hit_continue, mousepos.x, mousepos.y) &&
    error_save(g))
        sfText_setScale(g->menu.conti, (sfVector2f) {1.05, 1.05});
    else
        sfText_setScale(g->menu.conti, (sfVector2f) {1, 1});
    if (sfFloatRect_contains(&g->menu.hit_setting, mousepos.x, mousepos.y))
        sfText_setScale(g->menu.setting, (sfVector2f) {1.05, 1.05});
    else
        sfText_setScale(g->menu.setting, (sfVector2f) {1, 1});
    if (sfFloatRect_contains(&g->menu.hit_exit, mousepos.x, mousepos.y))
        sfText_setScale(g->menu.exit, (sfVector2f) {1.05, 1.05});
    else
        sfText_setScale(g->menu.exit, (sfVector2f) {1, 1});
}
