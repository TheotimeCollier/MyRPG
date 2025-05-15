/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

static void init(all_t *g)
{
    g->esc_menu.hit_resume = sfText_getGlobalBounds(g->esc_menu.resume_text);
    g->esc_menu.hit_save = sfText_getGlobalBounds(g->esc_menu.save_text);
    g->esc_menu.hit_load = sfText_getGlobalBounds(g->esc_menu.load_text);
    g->esc_menu.hit_setting = sfText_getGlobalBounds(g->esc_menu.settings);
    g->esc_menu.hit_back = sfText_getGlobalBounds(g->esc_menu.back_text);
    g->esc_menu.menu = false;
    g->esc_menu.clock_yolo = sfClock_create();
    g->esc_menu.clock_pc = sfClock_create();
    g->esc_menu.rect_yolo.top = 0;
    g->esc_menu.rect_yolo.left = 0;
    g->esc_menu.rect_yolo.width = 175;
    g->esc_menu.rect_yolo.height = 175;
    g->esc_menu.rect_pc.top = 0;
    g->esc_menu.rect_pc.left = 0;
    g->esc_menu.rect_pc.width = 1250;
    g->esc_menu.rect_pc.height = 704;
    g->esc_menu.yolo = create_sprite((int[2]){1340, 160}, 3.2, 3.2,
    "ressource/yolo.png");
    sfSprite_setTextureRect(g->esc_menu.yolo, g->esc_menu.rect_yolo);
}

static void init_bis(all_t *g)
{
    g->esc_menu.taille_health = 45;
    g->esc_menu.taille_speed = 25;
    g->esc_menu.taille_attack = 25;
    g->esc_menu.xp = 200;
    g->esc_menu.health_hit =
    sfSprite_getGlobalBounds(g->esc_menu.health_cross);
    g->esc_menu.attack_hit =
    sfSprite_getGlobalBounds(g->esc_menu.speed_cross);
    g->esc_menu.speed_hit =
    sfSprite_getGlobalBounds(g->esc_menu.attack_cross);
    g->esc_menu.health_rect =
    createrect(1370, 890, (int[2]){g->esc_menu.taille_health, 10}, sfRed);
    g->esc_menu.attack_rect = createrect(1370, 930,
    (int[2]){g->esc_menu.taille_attack, 10}, sfColor_fromRGB(255, 212, 0));
    g->esc_menu.speed_rect = createrect(1370, 975,
    (int[2]){g->esc_menu.taille_speed, 10}, sfColor_fromRGB(139, 0, 0));
    g->esc_menu.xp_rec = createrect(1370, 845,
    (int[2]){g->esc_menu.xp, 10}, sfColor_fromRGB(173, 255, 47));
    g->esc_menu.settingbck = create_sprite((int[2]){0, 0}, 1, 1,
    "ressource/background_setting.png");
}

void set_esc_menu(all_t *g)
{
    g->esc_menu.resume_text = create_text((float[3]){735, 375, 35},
    "ressource/cyber.ttf", "RESUME", sfWhite);
    g->esc_menu.save_text = create_text((float[3]){735, 425, 35},
    "ressource/cyber.ttf", "SAVE", sfWhite);
    g->esc_menu.load_text = create_text((float[3]){735, 475, 35},
    "ressource/cyber.ttf", "LOAD", sfWhite);
    g->esc_menu.settings = create_text((float[3]){735, 525, 35},
    "ressource/cyber.ttf", "SETTINGS", sfWhite);
    g->esc_menu.back_text = create_text((float[3]){735, 575, 35},
    "ressource/cyber.ttf", "BACK TO MENU", sfWhite);
    init(g);
    init_bis(g);
}

static void check_hit_esc_tres(all_t *g, sfVector2f mouse)
{
    if (sfFloatRect_contains(&g->esc_menu.attack_hit, mouse.x, mouse.y))
        sfSprite_setScale(g->esc_menu.speed_cross, (sfVector2f){0.067, 0.067});
    else
        sfSprite_setScale(g->esc_menu.speed_cross, (sfVector2f){0.06, 0.06});
    if (sfFloatRect_contains(&g->esc_menu.health_hit, mouse.x, mouse.y))
        sfSprite_setScale(g->esc_menu.health_cross,
        (sfVector2f){0.067, 0.067});
    else
        sfSprite_setScale(g->esc_menu.health_cross, (sfVector2f){0.06, 0.06});
    if (sfFloatRect_contains(&g->esc_menu.speed_hit, mouse.x, mouse.y))
        sfSprite_setScale(g->esc_menu.attack_cross,
        (sfVector2f){0.067, 0.067});
    else
        sfSprite_setScale(g->esc_menu.attack_cross,
        (sfVector2f){0.06, 0.06});
}

static void check_hit_esc_bis(all_t *g, sfVector2f mouse)
{
    sfSprite_setPosition(g->menu.souris, (sfVector2f)
    {mouse.x - 10, mouse.y - 3});
    if (sfFloatRect_contains(&g->esc_menu.hit_setting, mouse.x, mouse.y)) {
        sfText_setScale(g->esc_menu.settings, (sfVector2f){1.05, 1.05});
        sfSprite_setPosition(g->esc_menu.select_text, (sfVector2f){700, 475});
    } else
        sfText_setScale(g->esc_menu.settings, (sfVector2f){1, 1});
    if (sfFloatRect_contains(&g->esc_menu.hit_back, mouse.x, mouse.y)) {
        sfText_setScale(g->esc_menu.back_text, (sfVector2f){1.05, 1.05});
        sfSprite_setPosition(g->esc_menu.select_text, (sfVector2f){700, 525});
    } else
        sfText_setScale(g->esc_menu.back_text, (sfVector2f){1, 1});
    check_hit_esc_tres(g, mouse);
}

void check_hit_esc(all_t *g, sfVector2f mouse)
{
    if (sfFloatRect_contains(&g->esc_menu.hit_resume, mouse.x, mouse.y)) {
        sfText_setScale(g->esc_menu.resume_text, (sfVector2f){1.05, 1.05});
        sfSprite_setPosition(g->esc_menu.select_text, (sfVector2f){700, 325});
    } else
        sfText_setScale(g->esc_menu.resume_text, (sfVector2f){1, 1});
    if (sfFloatRect_contains(&g->esc_menu.hit_save, mouse.x, mouse.y)) {
        sfText_setScale(g->esc_menu.save_text, (sfVector2f){1.05, 1.05});
        sfSprite_setPosition(g->esc_menu.select_text, (sfVector2f){700, 375});
    } else
        sfText_setScale(g->esc_menu.save_text, (sfVector2f){1, 1});
    if (sfFloatRect_contains(&g->esc_menu.hit_load, mouse.x, mouse.y) &&
    error_save(g)) {
        sfText_setScale(g->esc_menu.load_text, (sfVector2f){1.05, 1.05});
        sfSprite_setPosition(g->esc_menu.select_text, (sfVector2f){700, 425});
    } else
        sfText_setScale(g->esc_menu.load_text, (sfVector2f){1, 1});
    check_hit_esc_bis(g, mouse);
}

static void draw_esc_true(all_t *g)
{
    sfRenderWindow_setView(g->window,
    sfRenderWindow_getDefaultView(g->window));
    sfRenderWindow_drawSprite(g->window, g->esc_menu.kali, NULL);
    sfRenderWindow_drawSprite(g->window, g->esc_menu.yolo, NULL);
    sfRenderWindow_drawSprite(g->window, g->esc_menu.speed_cross, NULL);
    sfRenderWindow_drawSprite(g->window, g->esc_menu.health_cross, NULL);
    sfRenderWindow_drawSprite(g->window, g->esc_menu.attack_cross, NULL);
    sfRenderWindow_drawRectangleShape
    (g->window, g->esc_menu.health_rect, NULL);
    sfRenderWindow_drawRectangleShape
    (g->window, g->esc_menu.attack_rect, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->esc_menu.speed_rect, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->esc_menu.xp_rec, NULL);
}

void draw_esc_menu(all_t *g)
{
    if (g->esc_menu.bool_pc == 1 || g->esc_menu.bool_pc == 2)
        clock_pc(g);
    if (g->esc_menu.menu == true) {
        draw_esc_true(g);
        clock_yolo(g);
        if (g->set->disp_set != true) {
        sfRenderWindow_drawText(g->window, g->esc_menu.resume_text, NULL);
        sfRenderWindow_drawText(g->window, g->esc_menu.save_text, NULL);
        sfRenderWindow_drawText(g->window, g->esc_menu.load_text, NULL);
        sfRenderWindow_drawText(g->window, g->esc_menu.settings, NULL);
        sfRenderWindow_drawText(g->window, g->esc_menu.back_text, NULL);
        sfRenderWindow_drawSprite(g->window, g->esc_menu.select_text, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.souris, NULL);
        clock_title(g);
        }
    }
    if (g->esc_menu.xp < 325)
            sfRectangleShape_setSize(g->esc_menu.xp_rec,
            (sfVector2f) {g->esc_menu.xp, 10});
}

void check_clicked_esc(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->esc_menu.hit_resume, mousepos.x, mousepos.y))
        pc_touch(g);
    if (sfFloatRect_contains(&g->esc_menu.hit_back, mousepos.x, mousepos.y)) {
        g->menu.y_mia = 180;
        g->menu.bool_newgame = 0;
        g->start_menu.bool_press_continue = 1;
        g->menu.y_black_back = 835;
        g->menu.y_new_game = 1215;
        g->menu.y_conti = 1345;
        g->menu.y_setting = 1475;
        g->menu.y_exit = 1605;
        g->start_menu.x_title = 300;
    }
    if (sfFloatRect_contains(&g->esc_menu.hit_setting, mousepos.x, mousepos.y))
        g->set->disp_set = true;
    save(g, mousepos);
    if (sfFloatRect_contains(&g->esc_menu.hit_load, mousepos.x, mousepos.y)
    && sfText_getColor(g->menu.conti).r == 255)
        init_save(g);
    maj_rec(g, mousepos);
}

void clock_yolo(all_t *g)
{
    g->esc_menu.time_yolo = sfClock_getElapsedTime(g->esc_menu.clock_yolo);
    g->esc_menu.second_yolo = g->esc_menu.time_yolo.microseconds / 1000000.0;
    if (g->esc_menu.second_yolo > 0.1) {
        g->esc_menu.rect_yolo.left += 175;
        sfSprite_setTextureRect(g->esc_menu.yolo, g->esc_menu.rect_yolo);
        sfClock_restart(g->esc_menu.clock_yolo);
        if (g->esc_menu.rect_yolo.left > 5400)
            g->esc_menu.rect_yolo.left = 0;
    }
}
