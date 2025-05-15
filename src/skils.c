/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** esc_menu
*/

#include "../include/my.h"

void maj_rec_bis(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->esc_menu.speed_hit, mousepos.x, mousepos.y)
    && g->esc_menu.taille_speed < 325 && g->esc_menu.xp > 25) {
        g->esc_menu.taille_speed += 25;
        g->esc_menu.xp -= 25;
        sfRectangleShape_setSize(g->esc_menu.speed_rect,
        (sfVector2f) {g->esc_menu.taille_speed, 10});
    }
}

void maj_rec(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->esc_menu.health_hit, mousepos.x, mousepos.y)
    && g->esc_menu.taille_health < 325 && g->esc_menu.xp > 25) {
        g->esc_menu.taille_health += 25;
        g->esc_menu.xp -= 25;
        sfRectangleShape_setSize(g->esc_menu.health_rect,
        (sfVector2f) {g->esc_menu.taille_health, 10});
    }
    if (sfFloatRect_contains(&g->esc_menu.attack_hit, mousepos.x, mousepos.y)
    && g->esc_menu.taille_attack < 325 && g->esc_menu.xp > 25) {
        g->esc_menu.taille_attack += 25;
        g->esc_menu.xp -= 25;
        g->gui.malus_energie -= 0.12;
        sfRectangleShape_setSize(g->esc_menu.attack_rect,
        (sfVector2f) {g->esc_menu.taille_attack, 10});
    }
    maj_rec_bis(g, mousepos);
}
