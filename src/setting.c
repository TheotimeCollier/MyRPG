/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** setting
*/

#include "../include/my.h"

static void set_cursor(all_t *g)
{
    sfColor color_barre = sfColor_fromRGB(105, 105, 105);
    sfColor color_cursor = sfColor_fromRGB(70, 70, 70);

    g->set->ms_ba = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g->set->ms_ba, color_barre);
    sfRectangleShape_setSize(g->set->ms_ba, (sfVector2f){210, 20});
    sfRectangleShape_setPosition(g->set->ms_ba, (sfVector2f){945, 367});
    g->set->ms_csr = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g->set->ms_csr, color_cursor);
    sfRectangleShape_setSize(g->set->ms_csr, (sfVector2f){10, 30});
    sfRectangleShape_setPosition(g->set->ms_csr, (sfVector2f){1145, 362});
    g->set->sound_ba = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g->set->sound_ba, color_barre);
    sfRectangleShape_setSize(g->set->sound_ba, (sfVector2f){210, 20});
    sfRectangleShape_setPosition(g->set->sound_ba, (sfVector2f){945, 467});
    g->set->sound_csr = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g->set->sound_csr, color_cursor);
    sfRectangleShape_setSize(g->set->sound_csr, (sfVector2f){10, 30});
    sfRectangleShape_setPosition(g->set->sound_csr, (sfVector2f){1145, 462});
}

static void set_text_key(all_t *g)
{
    g->set->up_key = create_text((float[3]){883, 540, 40},
    "ressource/arial_narrow_7.ttf", "Z", sfWhite);
    g->set->down_key = create_text((float[3]){883, 605, 40},
    "ressource/arial_narrow_7.ttf", "S", sfWhite);
    g->set->left_key = create_text((float[3]){818, 605, 40},
    "ressource/arial_narrow_7.ttf", "Q", sfWhite);
    g->set->right_key = create_text((float[3]){948, 605, 40},
    "ressource/arial_narrow_7.ttf", "D", sfWhite);
    g->set->shift_key = create_text((float[3]){1075, 540, 40},
    "ressource/arial_narrow_7.ttf", "Shift", sfWhite);
    g->set->e_key = create_text((float[3]){1075, 605, 40},
    "ressource/arial_narrow_7.ttf", "E", sfWhite);
}

static void set_text(all_t *g)
{
    g->set->music_text = create_text((float[3]){755, 350, 40},
    "ressource/cyber.ttf", "MUSIC", sfWhite);
    g->set->sound_text = create_text((float[3]){755, 450, 40},
    "ressource/cyber.ttf", "SOUND", sfWhite);
    g->set->reso_text = create_text((float[3]){850, 550, 40},
    "ressource/cyber.ttf", "RESOLUTION", sfWhite);
    g->set->full_screen = create_text((float[3]){750, 630, 32},
    "ressource/cyber.ttf", "fullscreen", sfWhite);
    g->set->window_mode = create_text((float[3]){1025, 630, 32},
    "ressource/cyber.ttf", "window", sfWhite);
    g->set->custom_text = create_text((float[3]){750, 730, 40},
    "ressource/cyber.ttf", "customize Controls", sfWhite);
    g->set->arrow_quit = create_sprite((int[2]){920, 820}, 0.2, 0.2,
    "ressource/arrow.png");
    set_text_key(g);
}

static void set_key_bind(all_t *g)
{
    g->set->up = create_sprite((int[2]){860, 535}, 0.12, 0.12,
    "ressource/key_touch.png");
    g->set->down = create_sprite((int[2]){860, 600}, 0.12, 0.12,
    "ressource/key_touch.png");
    g->set->left = create_sprite((int[2]){925, 600}, 0.12, 0.12,
    "ressource/key_touch.png");
    g->set->right = create_sprite((int[2]){795, 600}, 0.12, 0.12,
    "ressource/key_touch.png");
    g->set->sprint = create_sprite((int[2]){1050, 535}, 0.12, 0.12,
    "ressource/key_touch.png");
    g->set->use = create_sprite((int[2]){1050, 600}, 0.12, 0.12,
    "ressource/key_touch.png");
    g->set->hit_up = sfSprite_getGlobalBounds(g->set->up);
    g->set->hit_down = sfSprite_getGlobalBounds(g->set->down);
    g->set->hit_left = sfSprite_getGlobalBounds(g->set->left);
    g->set->hit_right = sfSprite_getGlobalBounds(g->set->right);
    g->set->hit_sprint = sfSprite_getGlobalBounds(g->set->sprint);
    g->set->hit_use = sfSprite_getGlobalBounds(g->set->use);
}

void set_setting(all_t *g)
{
    g->set = malloc(sizeof(setting_t));
    set_cursor(g);
    set_text(g);
    set_key_bind(g);
    g->set->hit_full = sfText_getGlobalBounds(g->set->full_screen);
    g->set->hit_window = sfText_getGlobalBounds(g->set->window_mode);
    g->set->hit_custom = sfText_getGlobalBounds(g->set->custom_text);
    g->set->hit_arrow = sfSprite_getGlobalBounds(g->set->arrow_quit);
    g->set->disp_set = false;
    g->set->disp_bind = false;
}

static void draw_settingbind(all_t *g)
{
    if (g->set->disp_bind == true) {
        if (g->menu.y_mia > 1920)
            sfRenderWindow_drawSprite(g->window, g->esc_menu.settingbck, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->up, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->down, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->left, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->right, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->sprint, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->use, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->arrow_quit, NULL);
        sfRenderWindow_drawText(g->window, g->set->up_key, NULL);
        sfRenderWindow_drawText(g->window, g->set->down_key, NULL);
        sfRenderWindow_drawText(g->window, g->set->left_key, NULL);
        sfRenderWindow_drawText(g->window, g->set->e_key, NULL);
        sfRenderWindow_drawText(g->window, g->set->right_key, NULL);
        sfRenderWindow_drawText(g->window, g->set->shift_key, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.souris, NULL);
    }
}

void draw_setting(all_t *g)
{
    if (g->set->disp_set == true && g->set->disp_bind == false) {
        if (g->menu.y_mia > 1920)
            sfRenderWindow_drawSprite(g->window, g->esc_menu.settingbck, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->set->ms_ba, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->set->ms_csr, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->set->sound_ba, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->set->sound_csr, NULL);
        sfRenderWindow_drawText(g->window, g->set->music_text, NULL);
        sfRenderWindow_drawText(g->window, g->set->sound_text, NULL);
        sfRenderWindow_drawText(g->window, g->set->reso_text, NULL);
        sfRenderWindow_drawText(g->window, g->set->full_screen, NULL);
        sfRenderWindow_drawText(g->window, g->set->window_mode, NULL);
        sfRenderWindow_drawText(g->window, g->set->custom_text, NULL);
        sfRenderWindow_drawSprite(g->window, g->set->arrow_quit, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.souris, NULL);
    }
    draw_settingbind(g);
}

void check_clicked_setnext(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->set->hit_full, mousepos.x, mousepos.y)
    && g->set->disp_set == true && g->set->disp_bind == false) {
        sfRenderWindow_close(g->window);
        g->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Hacktivist", sfFullscreen, NULL);
    }
    if (sfFloatRect_contains(&g->set->hit_window, mousepos.x, mousepos.y)
    && g->set->disp_set == true && g->set->disp_bind == false) {
        sfRenderWindow_close(g->window);
        g->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Hacktivist", sfDefaultStyle, NULL);
    }
}

void check_clicked_set(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->menu.hit_setting, mousepos.x, mousepos.y)
    && g->set->disp_set == false)
        g->set->disp_set = true;
    if (sfFloatRect_contains(&g->set->hit_arrow, mousepos.x, mousepos.y)
    && g->set->disp_set == true && g->set->disp_bind == false)
        g->set->disp_set = false;
    if (sfFloatRect_contains(&g->set->hit_custom, mousepos.x, mousepos.y)
    && g->set->disp_set == true)
        g->set->disp_bind = true;
    if (sfFloatRect_contains(&g->set->hit_arrow, mousepos.x, mousepos.y)
    && g->set->disp_bind == true)
        g->set->disp_bind = false;
    check_clicked_setnext(g, mousepos);
}
