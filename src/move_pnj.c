/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** move_pnj
*/

#include "../include/my.h"

static bool collision_pnj_s(sfColor color, pnj_t *tmp, sfImage *img)
{
    if (tmp->direction == 2) {
        color = sfImage_getPixel(img, tmp->coord.x, tmp->coord.y + 20);
        if (color.r == 0 && color.g == 0 && color.b == 0)
            return false;
    }
    if (tmp->direction == 3) {
        color = sfImage_getPixel(img, tmp->coord.x, tmp->coord.y - 20);
        if (color.r == 0 && color.g == 0 && color.b == 0)
            return false;
    }
    return true;
}

bool check_collision_pnj(pnj_t *tmp, sfImage *img)
{
    sfColor color;

    if (tmp->direction == 0) {
        color = sfImage_getPixel(img, tmp->coord.x + 20, tmp->coord.y);
        if (color.r == 0 && color.g == 0 && color.b == 0)
            return false;
    }
    if (tmp->direction == 1) {
        color = sfImage_getPixel(img, tmp->coord.x - 20, tmp->coord.y);
        if (color.r == 0 && color.g == 0 && color.b == 0)
            return false;
    }
    if (collision_pnj_s(color, tmp, img) == false)
        return false;
    return true;
}

static void displacement_anim_pnj(pnj_t *tmp, sfImage *img)
{
    if (tmp->direction == 0 && check_collision_pnj(tmp, img) == true) {
        tmp->coord.x += tmp->dist * 0.01;
        tmp->rect_spr.left += 140;
    }
    if (tmp->direction == 1 && check_collision_pnj(tmp, img) == true) {
        tmp->coord.x -= tmp->dist * 0.01;
        tmp->rect_spr.left += 140;
    }
    if (tmp->direction == 2 && check_collision_pnj(tmp, img) == true) {
        tmp->coord.y += tmp->dist * 0.01;
        tmp->rect_spr.left += 140;
    }
    if (tmp->direction == 3 && check_collision_pnj(tmp, img) == true) {
        tmp->coord.y -= tmp->dist * 0.01;
        tmp->rect_spr.left += 140;
    }
    if (tmp->rect_spr.left > 4340)
        tmp->rect_spr.left = 0;
    tmp->travel += tmp->dist * 0.01;
    sfSprite_setPosition(tmp->sprite, tmp->coord);
}

static void displacement_pnj_s(pnj_t *tmp, all_t *g, sfImage *img)
{
    if (tmp->travel >= tmp->dist) {
        tmp->direction = rand() % 4;
        tmp->travel = 0;
        tmp->dist = rand() % 100;
        tmp->wait = 0;
        tmp->rect_spr.left = 0;
        if (tmp->direction == 0)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.walk_right_en, sfTrue);
        if (tmp->direction == 1)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.walk_left_en, sfTrue);
        if (tmp->direction == 2)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.walk_down_en, sfTrue);
        if (tmp->direction == 3)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.walk_up_en, sfTrue);
    }
    if (tmp->wait > tmp->dist)
        displacement_anim_pnj(tmp, img);
    sfSprite_setTextureRect(tmp->sprite, tmp->rect_spr);
    tmp->wait++;
    sfClock_restart(tmp->clock);
}

static void change_texture(int x, int y, all_t *g, pnj_t *tmp)
{
    if (x > 0 && abs((int)x) > abs((int)y)) {
        tmp->direction = 0;
        sfSprite_setTexture(tmp->sprite, g->all_pnj.sprint_right_en,
        sfTrue);
    }
    if (x < 0 && abs((int)x) > abs((int)y)) {
        tmp->direction = 1;
        sfSprite_setTexture(tmp->sprite, g->all_pnj.sprint_left_en,
        sfTrue);
    }
    if (y > 0 && abs((int)x) < abs((int)y)) {
        tmp->direction = 2;
        sfSprite_setTexture(tmp->sprite, g->all_pnj.sprint_down_en,
        sfTrue);
    }
    if (y < 0 && abs((int)x) < abs((int)y)) {
        tmp->direction = 3;
        sfSprite_setTexture(tmp->sprite, g->all_pnj.sprint_up_en,
        sfTrue);
    }
}

void cond_moov(pnj_t *tmp, sfImage *img, int x, int y)
{
    if (check_collision_pnj(tmp, img) == true) {
        tmp->coord.x += x;
        tmp->coord.y += y;
        tmp->rect_spr.left += 140;
            if (tmp->rect_spr.left > 5460)
                tmp->rect_spr.left = 0;
    }
}

void bave(all_t *g, pnj_t *tmp, sfImage *img)
{
    int x = 0;
    int y = 0;

    if (tmp->seconds > 0.03 && tmp->distance > 30) {
        x = ((g->mia.x - tmp->coord.x) / tmp->distance) * 3;
        y = ((g->mia.y - tmp->coord.y) / tmp->distance) * 3;
        x *= 100;
        y *= 100;
        change_texture(x, y, g, tmp);
        x /= 100;
        y /= 100;
        cond_moov(tmp, img, x, y);
        sfSprite_setTextureRect(tmp->sprite, tmp->rect_spr);
        sfSprite_setPosition(tmp->sprite, tmp->coord);
        sfClock_restart(tmp->clock);
    }
}

static void anim_punch(pnj_t *tmp, all_t *g)
{
    if (tmp->seconds > 0.03 && tmp->distance < 30) {
        if (tmp->direction == 0)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.punch_right_en,
            sfTrue);
        if (tmp->direction == 1)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.punch_left_en, sfTrue);
        if (tmp->direction == 2)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.punch_down_en, sfTrue);
        if (tmp->direction == 3)
            sfSprite_setTexture(tmp->sprite, g->all_pnj.punch_up_en, sfTrue);
        tmp->rect_spr.left += 140;
        if (tmp->rect_spr.left > 9240)
            tmp->rect_spr.left = 0;
        sfSprite_setTextureRect(tmp->sprite, tmp->rect_spr);
        sfClock_restart(tmp->clock);
    }
}

void displacement_pnj(all_t *g, pnj_t *tmp, sfImage *img)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (tmp->track == true) {
        bave(g, tmp, img);
        anim_punch(tmp, g);
    } else
        if (tmp->seconds > 0.03)
            displacement_pnj_s(tmp, g, img);
    sfSprite_setTextureRect(tmp->sprite, tmp->rect_spr);
    sfRectangleShape_setPosition(tmp->hitbox,
    (sfVector2f){tmp->coord.x, tmp->coord.y});
}
