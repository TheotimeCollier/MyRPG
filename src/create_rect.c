/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** event
*/

#include "../include/my.h"

sfRectangleShape *createrect(float x, float y, int s[2], sfColor color)
{
    sfRectangleShape *rectangle;

    rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(rectangle, (sfVector2f){s[0], s[1]});
    sfRectangleShape_setOutlineColor(rectangle, color);
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setPosition(rectangle, (sfVector2f){x, y});
    sfRectangleShape_setOutlineThickness(rectangle, 2.0);
    return rectangle;
}
