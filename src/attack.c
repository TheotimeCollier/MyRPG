/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** attack
*/

#include "../include/my.h"

void check_rangewithmia(all_t *g)
{
    sfFloatRect hitbox_pnj;
    sfFloatRect hitbox_mia = sfRectangleShape_getGlobalBounds
    (g->mia.hitbox_tape);
    sfFloatRect hitbox_boss;

    for (pnj_t *tmp = g->all_pnj.pnj; tmp != NULL; tmp = tmp->next) {
        hitbox_pnj = sfRectangleShape_getGlobalBounds(tmp->hitbox);
        if (sfFloatRect_intersects(&hitbox_mia, &hitbox_pnj, NULL) == 1)
            tmp->health -= 1;
        if (tmp->death == false && tmp->health <= 0) {
            g->gui.dollar += 75;
            g->esc_menu.xp += 20;
            tmp->death = true;
        }
    }
    hitbox_boss = sfRectangleShape_getGlobalBounds(g->boss.hitbox);
    if (sfFloatRect_intersects(&hitbox_mia, &hitbox_boss, NULL) == 1)
        g->boss_bar.life_boss -= 1;
}

void draw_attack(all_t *g)
{
    if (g->mia.attack == 0)
        sfRenderWindow_drawSprite(g->window, g->mia.mia_sprite,
        NULL);
    if (g->mia.attack == 1)
        sfRenderWindow_drawSprite(g->window, g->mia.mia_katana,
        NULL);
}
