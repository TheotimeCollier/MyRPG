/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** theotime
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef THEOTIME_H_
    #define THEOTIME_H_

struct all_t;

typedef struct start_s {
    sfSprite *back_start;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float seconds_title;
    sfClock *clock_title;
    sfTime time_title;
    sfSprite *title;
    sfSprite *mia;
    sfIntRect rect_title;
    sfIntRect rect_mia;
    sfMusic *music_menu;
    sfText *text_continue;
    int bool_press_continue;
    sfClock *clock_move;
    sfTime time_move;
    float seconds_move;
    int x_title;
    sfClock *clock_mia;
    sfTime time_mia;
    float seconds_mia;
    sfSprite *back_effect;
    sfIntRect rect_back_effect;
    sfSprite *mia_run;
} start_t;

typedef struct menu_s {
    sfSprite *black_menu;
    int y_black_back;
    sfText *new_game;
    sfText *conti;
    sfText *setting;
    sfText *exit;
    int y_new_game;
    int y_conti;
    int y_setting;
    int y_exit;
    sfFloatRect hit_new_game;
    sfFloatRect hit_continue;
    sfFloatRect hit_setting;
    sfFloatRect hit_exit;
    int bool_newgame;
    sfClock *clock_mia_run;
    sfTime time_mia_run;
    float seconds_mia_run;
    float y_mia;
    sfSprite *souris;
    sfIntRect rect_souris;
    sfSprite *pc_sripte;
} menu_t;

typedef struct effect_s {
    sfText *effect_sugar;
    int b_effect_sugar;
    sfClock *clock_dure;
    sfTime time_dure;
    float seconds_dure;
    int sec;
    char sec_char[3];
    sfSprite *sugar;
    int b_effect_seringue;
} effect_t;

typedef struct gui_s {
    sfSprite *life_sprite;
    sfRectangleShape *life_rec;
    sfClock *clock_regen;
    sfTime time_regen;
    float seconds_regen;
    int current_life;
    sfSprite *energie_sprite;
    int energie;
    float current_energie;
    sfRectangleShape *energie_rect;
    sfTime time_energie;
    float seconds_energie;
    sfClock *clock_energie;
    sfSprite *dollar_sprite;
    int dollar;
    sfText *dollar_text;
    char dol_text[10];
    sfSprite *key_e_sprite;
    sfVector2f pos_key_e;
    sfTime time_key_e;
    float seconds_key_e;
    sfClock *clock_key_e;
    sfIntRect key_e_rect;
    float malus_energie;
} gui_t;

typedef struct inven_gui_s {
    sfSprite *gui_inventory;
    sfSprite *carre_inventory;
    int current_pos;
    int invent[4][2];
    sfSprite *item_one;
    sfSprite *item_two;
    sfSprite *item_three;
    sfSprite *item_four;
    sfText *text_one;
    sfText *text_two;
    sfText *text_three;
    sfText *text_four;
    char char_one[10];
    char char_two[10];
    char char_three[10];
    char char_four[10];
} inven_gui_t;

typedef struct game_one_s {
    sfSprite *digi;
    sfSprite *zero;
    sfSprite *one;
    sfSprite *two;
    sfSprite *three;
    sfSprite *four;
    sfSprite *five;
    sfSprite *six;
    sfSprite *seven;
    sfSprite *eight;
    sfSprite *nine;
    sfSprite *valider;
    sfSprite *annuler;
    sfFloatRect hit_zero;
    sfFloatRect hit_one;
    sfFloatRect hit_two;
    sfFloatRect hit_three;
    sfFloatRect hit_four;
    sfFloatRect hit_five;
    sfFloatRect hit_six;
    sfFloatRect hit_seven;
    sfFloatRect hit_eight;
    sfFloatRect hit_nine;
    sfFloatRect hit_valider;
    sfFloatRect hit_annuler;
    int mdp;
    int multi;
    sfSprite *c_one;
    sfSprite *c_two;
    sfSprite *c_three;
    sfSprite *c_four;
    sfSprite *back_digi;
    sfText *t_false;
    sfText *t_passed;
    sfClock *clock_rep;
    sfTime time_rep;
    float seconds_rep;
    int bool_rep;
    int b_disp_code;
} game_one_t;

typedef struct store_s {
    sfSprite *next_d_sprite;
    sfSprite *next_g_sprite;
    sfSprite *name_sprite;
    int b_disp_store;
    sfFloatRect buy_hit;
    sfFloatRect next_d_hit;
    sfFloatRect next_g_hit;
    sfSprite *current_item;
    sfTexture *seringue_texture;
    sfTexture *pc_texture;
    sfTexture *sugar;
    sfTexture *katana;
    sfText *name_item;
    int b_current_item;
    sfText *current_price;
    int price_item;
    sfSprite *map;
    sfImage *map_col;
    sfSprite *fond;
    sfSprite *shop;
    sfSprite *dollar_sprite;
    sfRectangleShape *rec_price;
} store_t;

typedef struct death_s {
    sfText *text_death;
    int is_death;
    sfClock *clock_death;
    sfTime time_death;
    float seconds_death;
    sfRectangleShape *death_rect;
    int bool_clock;
} death_t;

typedef struct boss_bar_s {
    sfRectangleShape *life_rect;
    int life_boss;
    sfSprite *sprite_boss_bar;
} boss_bar_t;

sfSprite *create_sprite(int s[2], float sizex, float sizey, char *url);
sfText *create_text(float s[3], char *fonte, char *text_char, sfColor color);
sfRectangleShape *createrect(float x, float y, int s[2], sfColor color);

#endif
