/*
** EPITECH PROJECT, 2024
** lib
** File description:
** main
*/

#include "../include/my.h"

sfText *create_text(float s[3], char *fonte, char *text_char, sfColor color)
{
    sfFont *font;
    sfText *text;

    font = sfFont_createFromFile(fonte);
    text = sfText_create();
    sfText_setString(text, text_char);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, s[2]);
    sfText_setPosition(text, (sfVector2f){s[0], s[1]});
    return text;
}
