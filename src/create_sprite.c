/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

sfSprite *create_sprite(int s[2], float sizex, float sizey, char *url)
{
    sfSprite *sprite;
    sfTexture *texture;

    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(url, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){sizex, sizey});
    sfSprite_setPosition(sprite, (sfVector2f){s[0], s[1]});
    return sprite;
}
