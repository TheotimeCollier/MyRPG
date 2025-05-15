/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** usine
*/

#include "../include/my.h"

void set_boss_bar(all_t *g)
{
    g->boss_bar.life_boss = 525;
    g->boss_bar.life_rect = createrect(0, 0,
    (int[2]) {g->boss_bar.life_boss / 3, 4}, sfColor_fromRGB(128, 0, 128));
    g->boss_bar.sprite_boss_bar = create_sprite((int[2]) {1, 1}, 1, 1,
    "ressource/bos_bar2.png");
}

void draw_boss_bar(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    sfRectangleShape_setPosition(g->boss_bar.life_rect,
    (sfVector2f) {viewposition.x - 85 - g->mia.v_gui1.x,
    viewposition.y - 138 - g->mia.v_gui1.y});
    sfSprite_setPosition(g->boss_bar.sprite_boss_bar,
    (sfVector2f) {viewposition.x - 100 - g->mia.v_gui1.x,
    viewposition.y - 167 - g->mia.v_gui1.y});
    if (g->boss_bar.life_boss > 0)
        sfRectangleShape_setSize(g->boss_bar.life_rect, (sfVector2f)
        {g->boss_bar.life_boss / 3, 3});
    else
    sfRectangleShape_setSize(g->boss_bar.life_rect, (sfVector2f){0, 3});
    sfRenderWindow_drawRectangleShape(g->window, g->boss_bar.life_rect, NULL);
    sfRenderWindow_drawSprite(g->window, g->boss_bar.sprite_boss_bar, NULL);
    printf("%d\n", g->script.history);
    if (g->boss_bar.life_boss <= 0 && g->script.history == 3) {
        g->script.history++;
        script(g, 7);
    }
}
