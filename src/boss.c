/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** boss
*/

#include "../include/my.h"

static void set_texture(all_t *g)
{
    g->boss.attack_up = sfTexture_createFromFile(
    "ressource/boss_attack_up.png", NULL);
    g->boss.attack_down = sfTexture_createFromFile(
    "ressource/boss_attack_down.png", NULL);
    g->boss.attack_left = sfTexture_createFromFile(
    "ressource/boss_attack_left.png", NULL);
    g->boss.attack_right = sfTexture_createFromFile(
    "ressource/boss_attack_right.png", NULL);
    g->boss.walk_up = sfTexture_createFromFile(
    "ressource/boss_walk_up.png", NULL);
    g->boss.walk_down = sfTexture_createFromFile(
    "ressource/boss_walk_down.png", NULL);
    g->boss.walk_left = sfTexture_createFromFile(
    "ressource/boss_walk_left.png", NULL);
    g->boss.walk_right = sfTexture_createFromFile(
    "ressource/boss_walk_right.png", NULL);
    g->boss.hitbox = createrect(g->boss.coord.x, g->boss.coord.y,
    (int[2]){50, 50}, sfWhite);
    sfRectangleShape_setOrigin(g->boss.hitbox, (sfVector2f){25, 25});
}

void set_boss(all_t *g)
{
    g->boss.coord = (sfVector2f){300, 300};
    g->boss.boss_walk = create_sprite((int[2]){g->boss.coord.x,
    g->boss.coord.y},
    0.5, 0.5, "ressource/boss_walk_left.png");
    g->boss.boss_att = create_sprite((int[2]){g->boss.coord.x,
    g->boss.coord.y},
    0.35, 0.35, "ressource/boss_attack_left.png");
    g->boss.rect_boss_walk = (sfIntRect){0, 0, 143, 143};
    g->boss.rect_boss_att = (sfIntRect){0, 0, 200, 200};
    g->boss.clock = sfClock_create();
    g->boss.clock_att = sfClock_create();
    g->boss.seconds = 0.0;
    g->boss.direction = 0;
    set_texture(g);
    g->boss.walk = true;
    g->boss.health = 1000;
    sfSprite_setOrigin(g->boss.boss_walk, (sfVector2f){71.5, 71.5});
    sfSprite_setOrigin(g->boss.boss_att, (sfVector2f){100, 100});
}

static void change_texture_boss(float x, float y, all_t *g)
{
    x *= 100;
    y *= 100;
    if (x > 0 && abs((int)x) > abs((int)y)) {
        g->boss.direction = 0;
        sfSprite_setTexture(g->boss.boss_walk, g->boss.walk_right, sfTrue);
    }
    if (x < 0 && abs((int)x) > abs((int)y)) {
        g->boss.direction = 1;
        sfSprite_setTexture(g->boss.boss_walk, g->boss.walk_left, sfTrue);
    }
    if (y > 0 && abs((int)x) < abs((int)y)) {
        g->boss.direction = 2;
        sfSprite_setTexture(g->boss.boss_walk, g->boss.walk_down, sfTrue);
    }
    if (y < 0 && abs((int)x) < abs((int)y)) {
        g->boss.direction = 3;
        sfSprite_setTexture(g->boss.boss_walk, g->boss.walk_up, sfTrue);
    }
}

static void anim_att_boss(all_t *g, double distance)
{
    if (g->boss.seconds > 0.03 && distance < 35) {
        g->boss.walk = false;
        if (g->boss.direction == 0)
            sfSprite_setTexture(g->boss.boss_att, g->boss.attack_right,
            sfTrue);
        if (g->boss.direction == 1)
            sfSprite_setTexture(g->boss.boss_att, g->boss.attack_left, sfTrue);
        if (g->boss.direction == 2)
            sfSprite_setTexture(g->boss.boss_att, g->boss.attack_down, sfTrue);
        if (g->boss.direction == 3)
            sfSprite_setTexture(g->boss.boss_att, g->boss.attack_up, sfTrue);
        g->boss.rect_boss_att.left += 200;
        if (g->boss.rect_boss_att.left > 9000)
            g->boss.rect_boss_att.left = 0;
        sfClock_restart(g->boss.clock);
        sfSprite_setTextureRect(g->boss.boss_att, g->boss.rect_boss_att);
        sfRenderWindow_drawSprite(g->window, g->boss.boss_att, NULL);
    }
}

static void anim_moov_boss(all_t *g, double distance)
{
    float x = 0;
    float y = 0;

    if (g->boss.seconds > 0.03 && distance > 35) {
        g->boss.walk = true;
        x = ((g->mia.x - g->boss.coord.x) / distance);
        y = ((g->mia.y - g->boss.coord.y) / distance);
        change_texture_boss(x, y, g);
        g->boss.coord.x += x;
        g->boss.coord.y += y;
        if (g->boss.rect_boss_walk.left > 9857)
            g->boss.rect_boss_walk.left = 0;
        g->boss.rect_boss_walk.left += 143;
        sfSprite_setPosition(g->boss.boss_walk, g->boss.coord);
        sfSprite_setPosition(g->boss.boss_att, g->boss.coord);
        sfRectangleShape_setPosition(g->boss.hitbox, g->boss.coord);
        sfClock_restart(g->boss.clock);
        sfSprite_setTextureRect(g->boss.boss_walk, g->boss.rect_boss_walk);
        sfRenderWindow_drawSprite(g->window, g->boss.boss_walk, NULL);
    }
}

void moov_boss(all_t *g)
{
    double distance = sqrt(pow(g->mia.x - g->boss.coord.x, 2) +
    pow(g->mia.y - g->boss.coord.y, 2));

    g->boss.time = sfClock_getElapsedTime(g->boss.clock);
    g->boss.seconds = g->boss.time.microseconds / 1000000.0;
    anim_moov_boss(g, distance);
    anim_att_boss(g, distance);
    g->boss.time = sfClock_getElapsedTime(g->boss.clock_att);
    g->boss.seconds = g->boss.time.microseconds / 1000000.0;
    if (g->boss.seconds > 1 && g->boss.health > 0 && distance < 35) {
        g->gui.current_life -= 5;
        sfClock_restart(g->boss.clock_att);
    }
}

void draw_boss(all_t *g)
{
    if (g->boss.walk == false)
        sfRenderWindow_drawSprite(g->window, g->boss.boss_att, NULL);
    else
        sfRenderWindow_drawSprite(g->window, g->boss.boss_walk, NULL);
}
