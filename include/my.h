/*
** EPITECH PROJECT, 2023
** my
** File description:
** ergb
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lucas.h"
#include "theotime.h"
#include "yanis.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#ifndef MY_H_
    #define MY_H_

typedef struct boss_s {
    sfSprite *boss_walk;
    sfSprite *boss_att;
    sfVector2f coord;
    sfIntRect rect_boss_walk;
    sfIntRect rect_boss_att;
    sfClock *clock;
    sfTime time;
    float seconds;
    int direction;
    int wait_att;
    int health;
    sfTexture *walk_up;
    sfTexture *walk_down;
    sfTexture *walk_left;
    sfTexture *walk_right;
    sfTexture *attack_up;
    sfTexture *attack_down;
    sfTexture *attack_left;
    sfTexture *attack_right;
    bool walk;
    sfRectangleShape *hitbox;
    sfClock *clock_att;
} boss_t;

typedef struct robot_s {
    sfSprite *robot;
    sfVector2f coord;
    sfIntRect rect_robot;
    sfClock *clock;
    sfClock *clock_effect;
    sfTime time;
    float seconds;
    bool on;
} robot_t;

typedef struct node_s {
    sfText *text;
    sfVector2f position;
    struct node_s *next;
} node_t;

typedef struct script_s {
    node_t *head;
    int line;
    float gap;
    int drawe_mother;
    int exit_house;
    int first_factory;
    int history;
} script_t;

typedef struct haunted_s {
    sfSprite *map;
    sfSprite *onmap;
    sfImage *undermap;
} haunted_t;

typedef struct usine_s {
    sfSprite *map;
    sfSprite *onmap;
    sfImage *undermap;
    int b_draw_usine;
} usine_t;

typedef struct hackbot_s {
    sfSprite *background_hb;
    sfText *text_one;
    sfText *text_two;
    char *script_one;
    char *script_two;
    int one;
    int two;
    char *draw_one;
    char *draw_two;
    int key;
    int pause;
    int last_scene;
} hackbot_t;

typedef struct house_s {
    sfSprite *map;
    sfSprite *onmap;
    sfImage *undermap;
    sfTexture *t_mia_mother;
    sfSprite *s_mia_mother;
    sfClock *clock_mother;
    sfTime time_mother;
    float second_mother;
    sfIntRect rect_mother;
} house_t;

typedef struct saloon_s {
    sfSprite *map;
    sfSprite *onmap;
    sfImage *undermap;
} saloon_t;

typedef struct pnj_s {
    sfVector2f coord;
    sfSprite *sprite;
    sfText *diag;
    int scene;
    double distance;
    bool track;
    sfClock *clock;
    sfTime time;
    float seconds;
    float travel;
    int direction;
    int dist;
    struct pnj_s *next;
    int wait;
    int wait_att;
    bool display;
    sfIntRect rect_spr;
    sfRectangleShape *hitbox;
    int health;
    int attack;
    bool death;
    int when;
    sfClock *clock_attack;
    int agro;
} pnj_t;

typedef struct all_pnj_s {
    pnj_t *pnj;
    sfTexture *walk_up_en;
    sfTexture *walk_down_en;
    sfTexture *walk_left_en;
    sfTexture *walk_right_en;
    sfTexture *sprint_up_en;
    sfTexture *sprint_down_en;
    sfTexture *sprint_left_en;
    sfTexture *sprint_right_en;
    sfTexture *punch_up_en;
    sfTexture *punch_down_en;
    sfTexture *punch_left_en;
    sfTexture *punch_right_en;
} all_pnj_t;

typedef struct setting_s {
    sfRectangleShape *ms_csr;
    sfRectangleShape *ms_ba;
    sfText *music_text;
    sfRectangleShape *sound_csr;
    sfRectangleShape *sound_ba;
    sfText *sound_text;
    sfText *reso_text;
    sfText *window_mode;
    sfText *full_screen;
    sfFloatRect hit_window;
    sfFloatRect hit_full;
    bool disp_set;
    sfText *custom_text;
    sfFloatRect hit_custom;
    sfSprite *arrow_quit;
    sfFloatRect hit_arrow;
    sfSprite *up;
    sfSprite *down;
    sfSprite *left;
    sfSprite *right;
    sfSprite *sprint;
    sfSprite *use;
    sfFloatRect hit_up;
    sfFloatRect hit_down;
    sfFloatRect hit_left;
    sfFloatRect hit_right;
    sfFloatRect hit_sprint;
    sfFloatRect hit_use;
    bool disp_bind;
    sfText *up_key;
    sfText *down_key;
    sfText *left_key;
    sfText *right_key;
    sfText *e_key;
    sfText *shift_key;
} setting_t;

typedef struct escape_menu_s {
    sfText *resume_text;
    sfText *save_text;
    sfText *load_text;
    sfText *settings;
    sfText *back_text;
    sfFloatRect hit_resume;
    sfFloatRect hit_save;
    sfFloatRect hit_load;
    sfFloatRect hit_setting;
    sfFloatRect hit_back;
    bool menu;
    sfClock *clock_yolo;
    sfTime time_yolo;
    float second_yolo;
    sfIntRect rect_yolo;
    sfSprite *yolo;
    sfClock *clock_pc;
    sfTime time_pc;
    float second_pc;
    sfIntRect rect_pc;
    int bool_pc;
    sfSprite *kali;
    sfSprite *attack_cross;
    sfSprite *speed_cross;
    sfSprite *health_cross;
    sfSprite *select_text;
    sfFloatRect health_hit;
    sfFloatRect speed_hit;
    sfFloatRect attack_hit;
    sfRectangleShape *health_rect;
    sfRectangleShape *attack_rect;
    sfRectangleShape *speed_rect;
    sfRectangleShape *xp_rec;
    int taille_health;
    int taille_attack;
    int taille_speed;
    int xp;
    int init;
    sfSprite *settingbck;
} escape_menu_t;

typedef struct all_s {
    sfRenderWindow *window;
    start_t start_menu;
    menu_t menu;
    game_one_t game_one;
    gui_t gui;
    playermouv_t mia;
    sfView *view;
    store_t store;
    inven_gui_t gui_invent;
    setting_t *set;
    escape_menu_t esc_menu;
    all_pnj_t all_pnj;
    keybinds_t keybind;
    sfSprite *sprite_diag;
    usine_t usine;
    house_t house;
    saloon_t saloon;
    script_t script;
    effect_t effect;
    hackbot_t hackbot;
    int scene;
    death_t death;
    robot_t robot;
    haunted_t haunted;
    char **save;
    boss_bar_t boss_bar;
    boss_t boss;
} all_t;

//lib
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_str_islower(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strstr(char *str, char *pat);
int my_strcmp(char const *s1, char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void mini_printf(const char *format, ...);
char **my_str_to_word_array(const char *file, char deli);
int count_word(char const *file, char deli);
//rpg
void hand_event_menu(all_t *g);
void loop_game(all_t *g);
void update_menu(all_t *g);
void set_start_menu(all_t *g);
void cursor_sound(all_t *g, sfVector2f mousepos);
void set_setting(all_t *g);
void draw_setting(all_t *g);
void check_hitbox_setting(all_t *g, sfVector2f mousepos);
void clock_move(all_t *g);
void clock_title(all_t *g);
void clock_mia(all_t *g);
void clock_menu(all_t *g);
void set_menu(all_t *g);
void check_hitbox_menu(all_t *g, sfVector2f mousepos);
void move_menu(all_t *g);
void check_clicked_set(all_t *g, sfVector2f mousepos);
void draw_menu(all_t *g);
void button_newgame(all_t *g, sfVector2f mousepos);
void move_new_game(all_t *g);
void config_view(all_t *g);
void hand_event_game(all_t *g);
void set_game_digi(all_t *g);
void hand_event_mini_game(all_t *g);
void update_mini_game(all_t *g);
void clock_rep(all_t *g);
void clock_rep(all_t *g);
void draw_esc_menu(all_t *g);
void check_hit_esc(all_t *g, sfVector2f mousepos);
void set_esc_menu(all_t *g);
void set_text_digi(all_t *g);
void check_clicked_esc(all_t *g, sfVector2f mousepos);
void clock_yolo(all_t *g);
void open_file(all_t *g);
void draw_pnj(all_t *g);
void check_range(all_t *g, sfImage *img);
void draw_diag(all_t *g);
void clock_pc(all_t *g);
void pc_touch(all_t *g);
void maj_rec_bis(all_t *g, sfVector2f mousepos);
void maj_rec(all_t *g, sfVector2f mousepos);
void movement_mia(all_t *g, sfImage *img);
void draw_gui(all_t *g);
void set_gui(all_t *g);
void idle_maker(all_t *g);
int idle_bind(all_t *g);
void change_url(all_t *g);
void check_store(all_t *g);
void set_boutique(all_t *g);
void hand_event_store(all_t *g);
void update_store(all_t *g);
void verif_hit(all_t *g, sfVector2f mousepos);
void get_hitbox(all_t *g);
void clock_key_e(all_t *g);
void set_key_e(all_t *g);
void draw_key_e(all_t *g);
void displacement_pnj(all_t *g, pnj_t *tmp, sfImage *img);
void set_shop(all_t *g);
void update_usine(all_t *g);
void hand_event_usine(all_t *g);
void set_usine(all_t *g);
void update_house(all_t *g);
void hand_event_house(all_t *g);
void update_inventory(all_t *g);
void event_inventory(sfEvent event, all_t *g);
void load_invent(all_t *g, int item);
void set_inventory(all_t *g);
void draw_inventory(all_t *g);
int add_item(all_t *g, int item);
void set_house(all_t *g);
void draw_store_bis(all_t *g);
void check_hit_store(all_t *g, sfVector2f mousepos);
void set_effect(all_t *g);
void event_effect(all_t *g, sfEvent event);
void draw_effect(all_t *g);
void clock_effect_sugar(all_t *g);
void update_effect(all_t *g);
void hand_scene(all_t *g);
void draw_attack(all_t *g);
void clock_robot(all_t *g);
void set_robot(all_t *g);
void hand_robot(all_t *g, sfEvent event);
void update_haunted(all_t *g);
void hand_event_haunted(all_t *g);
void set_haunted(all_t *g);
void haunted(all_t *g);
void write_save(all_t *g);
void *readscriptfromfile(all_t *g, int inewline);
void change_scene(all_t *g);
void update_store_stat(all_t *g, sfVector2f mouse);
void set_boss(all_t *g);
void moov_boss(all_t *g);
void draw_boss(all_t *g);
bool error_save(all_t *g);
void save(all_t *g, sfVector2f mousepos);
void change_scene2(all_t *g);
void pause_music(all_t *g);
void saloon(all_t *g);
//yanis
void set_sprite(all_t *g);
void update_game(all_t *g);
void movement_b_diag(all_t *g, sfImage *img);
void movement_h_diag(all_t *g, sfImage *img);
void movement_g_d(all_t *g, sfImage *img);
void movement_h_b(all_t *g, sfImage *img);
void bas_droite(all_t *g);
void bas_gauche(all_t *g);
void haut_droite(all_t *g);
void haut_gauche(all_t *g);
void droite(all_t *g);
void gauche(all_t *g);
void bas(all_t *g);
void haut(all_t *g);
void clockmouv(all_t *g, sfTexture *texture, int left, int limit);
void print_keybinds(all_t *g);
void reset_texture_mia_idle(all_t *g);
void moov_sprite(all_t *g, sfImage *img);
void check_difi_disp(all_t *g);
void check_rangewithmia(all_t *g);
void change_control(all_t *g, sfEvent event);
void verif_death(all_t *g);
void set_death(all_t *g);
void verif_death(all_t *g);
void clock_death(all_t *g);
//lucas rpg
void set_boss_bar(all_t *g);
void draw_boss_bar(all_t *g);
void set_script(all_t *g);
void script(all_t *g, int newline);
void printlist(all_t *g);
void hand_event_saloon(all_t *g);
void update_saloon(all_t *g);
void set_saloon(all_t *g);
void freelist(node_t *head);
void add(node_t **headref, char *text);
void clockmouvkatana(all_t *g, sfTexture *texture, float left, int limit);
void hack_game(all_t *g);
void saloon(all_t *g);
void set_hb(all_t *g);
void hand_event_hb(all_t *g);
void update_hb(all_t *g);
void mouse_fight(all_t *g);
int init_save(all_t *g);
char *read_file(const char *filepath);
char *get_key(sfKeyCode key);
void hack_drone(all_t *g, sfEvent event);
void sprint(all_t *g);
void fight_anim(all_t *g);
int is_moving(all_t *g);
int is_sprinting(all_t *g);
#endif
