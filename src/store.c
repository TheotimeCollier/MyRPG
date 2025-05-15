/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

static void set_boutique_bis(all_t *g)
{
    g->store.seringue_texture =
    sfTexture_createFromFile("ressource/seringue.png", NULL);
    g->store.pc_texture =
    sfTexture_createFromFile("ressource/pc_store.png", NULL);
    g->store.sugar =
    sfTexture_createFromFile("ressource/sugar.png", NULL);
    g->store.katana =
    sfTexture_createFromFile("ressource/katana.png", NULL);
    g->store.fond = create_sprite((int[2]){0, 0}, 4, 4,
    "ressource/fond_boutique.jpeg");
    g->store.dollar_sprite = create_sprite((int[2])
    {990, 890}, 0.58, 0.58, "ressource/dollar.png");
    g->store.rec_price = createrect(860, 870, (int[2])
    {200, 100}, sfColor_fromRGBA(0, 0, 0, 180));
}

void set_boutique(all_t *g)
{
    g->store.b_disp_store = 0;
    g->store.b_current_item = 0;
    g->store.next_d_sprite =
    create_sprite((int[2]){1350, 100}, 1, 1, "ressource/next_d.png");
    g->store.next_g_sprite =
    create_sprite((int[2]){100, 100}, 1, 1, "ressource/next_g.png");
    g->store.current_item =
    create_sprite((int[2]){845, 420}, 1.2, 1.2, "ressource/pc_store.png");
    g->store.shop = create_sprite((int[2]){555, 0}, 1, 1,
    "ressource/title_shop.png");
    set_boutique_bis(g);
    g->store.name_item = create_text((float[3]) {853, 690, 45},
    "ressource/cyber.ttf", "test", sfWhite);
    g->store.current_price = create_text((float[3]) {890, 890, 45},
    "ressource/number.ttf", "test", sfWhite);
    change_url(g);
}

void check_store(all_t *g)
{
    if (g->store.b_disp_store == 0 && (g->mia.x > 105 &&
    g->mia.x < 211) && g->mia.y < 140) {
        g->store.b_disp_store = 1;
        return;
    }
    if (g->store.b_disp_store == 1)
        g->store.b_disp_store = 0;
}

static void change_url_bis(all_t *g)
{
    if (g->store.b_current_item == 2) {
        sfSprite_setTexture(g->store.current_item,
        g->store.sugar, sfTrue);
        sfText_setString(g->store.name_item, "sugar");
        sfText_setString(g->store.current_price, "50");
        g->store.price_item = 50;
        sfText_setPosition(g->store.name_item, (sfVector2f) {853, 690});
        sfSprite_setColor(g->store.next_d_sprite, sfWhite);
        sfSprite_setColor(g->store.next_g_sprite, sfWhite);
    }
    if (g->store.b_current_item == 3) {
        sfSprite_setTexture(g->store.current_item,
        g->store.katana, sfTrue);
        sfText_setPosition(g->store.name_item, (sfVector2f) {853, 690});
        sfText_setString(g->store.name_item, "katana");
        sfText_setString(g->store.current_price, "800");
        g->store.price_item = 800;
        sfSprite_setColor(g->store.next_d_sprite,
        sfColor_fromRGB(120, 120, 120));
    }
}

static void change_url_tres(all_t *g)
{
    if (g->store.b_current_item == 1) {
        sfSprite_setTexture(g->store.current_item,
        g->store.seringue_texture, sfTrue);
        sfText_setString(g->store.name_item, "Seringue");
        sfText_setString(g->store.current_price, "35");
        g->store.price_item = 35;
        sfText_setPosition(g->store.name_item, (sfVector2f) {853, 690});
        sfSprite_setColor(g->store.next_d_sprite, sfWhite);
        sfSprite_setColor(g->store.next_g_sprite, sfWhite);
    }
}

void change_url(all_t *g)
{
    if (g->store.b_current_item == 0) {
        sfSprite_setTexture(g->store.current_item,
        g->store.pc_texture, sfTrue);
        sfText_setString(g->store.name_item, "Portable Computer");
        sfText_setString(g->store.current_price, "650");
        g->store.price_item = 650;
        sfText_setPosition(g->store.name_item, (sfVector2f) {745, 690});
        sfSprite_setColor(g->store.next_g_sprite,
        sfColor_fromRGB(120, 120, 120));
    }
    change_url_tres(g);
    change_url_bis(g);
}

void check_hit_store(all_t *g, sfVector2f mousepos)
{
    if (g->store.b_disp_store == 1) {
        if (sfFloatRect_contains(&g->store.next_d_hit, mousepos.x, mousepos.y)
        && g->store.b_current_item < 3) {
            g->store.b_current_item++;
            return;
        }
        if (sfFloatRect_contains(&g->store.next_g_hit, mousepos.x, mousepos.y)
        && g->store.b_current_item > 0)
            g->store.b_current_item--;
        }
        if (sfFloatRect_contains(&g->store.buy_hit, mousepos.x, mousepos.y)) {
            if (g->store.price_item <= g->gui.dollar &&
            (g->gui_invent.invent[1][0] == 0 ||
            g->gui_invent.invent[2][0] == 0 || g->gui_invent.invent[3][0] == 0
            || g->gui_invent.invent[0][0] == 0)) {
                g->gui.dollar -= g->store.price_item;
                load_invent(g, g->store.b_current_item);
            }
        }
}

static void init_hit_store(all_t *g)
{
    g->store.next_g_hit =
    sfSprite_getGlobalBounds(g->store.next_g_sprite);
    g->store.next_d_hit =
    sfSprite_getGlobalBounds(g->store.next_d_sprite);
    g->store.buy_hit =
    sfRectangleShape_getGlobalBounds(g->store.rec_price);
}

static void draw_store(all_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (g->store.b_disp_store == 1 && g->esc_menu.menu == false &&
    g->esc_menu.bool_pc == 0)
        draw_store_bis(g);
    else if (g->esc_menu.menu == false && g->esc_menu.bool_pc == 0) {
        sfRenderWindow_drawSprite(g->window, g->store.map, NULL);
        sfRenderWindow_drawSprite(g->window, g->mia.mia_sprite, NULL);
        draw_pnj(g);
        clock_key_e(g);
        sfSprite_setTextureRect(g->gui.key_e_sprite, g->gui.key_e_rect);
        sfRenderWindow_drawSprite(g->window, g->gui.key_e_sprite, NULL);
        draw_gui(g);
    }
    draw_esc_menu(g);
    draw_setting(g);
}

void update_store(all_t *g)
{
    init_hit_store(g);
    draw_store(g);
    printlist(g);
    update_inventory(g);
    sfRenderWindow_display(g->window);
}
