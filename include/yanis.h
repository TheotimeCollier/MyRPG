/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** yanis
*/

#ifndef YANIS_H_
    #define YANIS_H_

typedef struct playermouv_s {
    sfSprite *fortnite;
    sfSprite *sur_map;
    sfSprite *mia_sprite;
    sfTexture *texture_left;
    sfTexture *texture_right;
    sfTexture *texture_top;
    sfTexture *texture_bottom;
    sfTexture *texture_leftup;
    sfTexture *texture_rightup;
    sfTexture *texture_leftdown;
    sfTexture *texture_rightdown;
    sfTexture *texture_topsprint;
    sfTexture *texture_downsprint;
    sfTexture *texture_rightsprint;
    sfTexture *texture_leftsprint;
    sfTexture *texture_leftsprintup;
    sfTexture *texture_rightsprintup;
    sfTexture *texture_rightsprintdown;
    sfTexture *texture_leftsprintdown;
    sfTexture *katana_top;
    sfTexture *katana_topright;
    sfTexture *katana_right;
    sfTexture *katana_botright;
    sfTexture *katana_bot;
    sfTexture *katana_botleft;
    sfTexture *katana_left;
    sfTexture *katana_topleft;
    sfColor current;
    sfImage *image_fortnite;
    sfFloatRect hitbox_mia;
    sfIntRect rect_mia;
    sfIntRect rect_miakatana;
    sfClock *clock_mia;
    sfClock *clock_mvt;
    sfTime time_mia;
    sfTime time_mvt;
    sfBool endurance;
    sfRectangleShape *hitbox_tape;
    sfSprite *view_minimap;
    sfSprite *spritemia_minimap;
    sfSprite *mia_katana;
    float x;
    float seconds_mia;
    float y;
    float vite;
    float seconds_mvt;
    float mult;
    float screensize;
    int sprint;
    int idle[8];
    int attack;
    int movement;
    int map;
    int up;
    int right;
    int down;
    int left;
    int e_keybool;
    int sprint_keybool;
    sfVector2f v_gui1;
    sfVector2f v_gui2;
    sfVector2f v_minimap;
    sfSoundBuffer* footstep;
    sfSoundBuffer* footsteprun;
    sfSoundBuffer* hit;
    sfSound* footstepsound;
    sfKeyCode upkey;
    sfKeyCode downkey;
    sfKeyCode leftkey;
    sfKeyCode rightkey;
    sfKeyCode ekey;
    sfKeyCode sprintkey;
    sfMusic *music_ambiance;
    sfMusic *music_maison;
    sfMusic *music_bar;
    sfMusic *music_usine;
    sfMusic *music_store;
    sfMusic *music_manoir;
} playermouv_t;

typedef struct keybinds_s {
    sfText *key;
} keybinds_t;

#endif
