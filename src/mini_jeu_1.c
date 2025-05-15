/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** game
*/

#include "../include/my.h"

static void set_game_digi_tres(all_t *g)
{
    g->game_one.b_disp_code = 0;
    g->game_one.mdp = 0;
    g->game_one.multi = 1000;
    g->game_one.bool_rep = 0;
    g->game_one.seconds_rep = 0;
}

static void set_game_digi_bis(all_t *g)
{
    g->game_one.eight = create_sprite((int[2]) {965, 645}, 1, 1,
    "ressource/eight.jpg");
    g->game_one.nine = create_sprite((int[2]) {1065, 645}, 1, 1,
    "ressource/nine.jpg");
    g->game_one.valider = create_sprite((int[2]) {1065, 745}, 1, 1,
    "ressource/v.jpg");
    g->game_one.annuler = create_sprite((int[2]) {865, 745}, 1, 1,
    "ressource/cancel.jpg");
    g->game_one.c_one = create_sprite((int[2]) {820, 220}, 1, 1,
    "ressource/mdp_a.jpg");
    g->game_one.c_two = create_sprite((int[2]) {920, 220}, 1, 1,
    "ressource/mdp_a.jpg");
    g->game_one.c_three = create_sprite((int[2]) {1020, 220}, 1, 1,
    "ressource/mdp_a.jpg");
    g->game_one.c_four = create_sprite((int[2]) {1120, 220}, 1, 1,
    "ressource/mdp_a.jpg");
    set_game_digi_tres(g);
}

void set_game_digi(all_t *g)
{
    g->game_one.zero = create_sprite((int[2]) {965, 745}, 1, 1,
    "ressource/zero.jpg");
    g->game_one.one = create_sprite((int[2]) {865, 445}, 1, 1,
    "ressource/one.jpg");
    g->game_one.two = create_sprite((int[2]) {965, 445}, 1, 1,
    "ressource/two.jpg");
    g->game_one.three = create_sprite((int[2]) {1065, 445}, 1, 1,
    "ressource/three.jpg");
    g->game_one.four = create_sprite((int[2]) {865, 545}, 1, 1,
    "ressource/four.jpg");
    g->game_one.five = create_sprite((int[2]) {965, 545}, 1, 1,
    "ressource/five.jpg");
    g->game_one.six = create_sprite((int[2]) {1065, 545}, 1, 1,
    "ressource/six.jpg");
    g->game_one.seven = create_sprite((int[2]) {865, 645}, 1, 1,
    "ressource/seven.jpg");
    g->game_one.back_digi = create_sprite((int[2]) {0, -62}, 1, 1,
    "ressource/digi_back.png");
    set_game_digi_bis(g);
}

void get_hitbox(all_t *g)
{
    g->game_one.hit_zero = sfSprite_getGlobalBounds(g->game_one.zero);
    g->game_one.hit_one = sfSprite_getGlobalBounds(g->game_one.one);
    g->game_one.hit_two = sfSprite_getGlobalBounds(g->game_one.two);
    g->game_one.hit_three = sfSprite_getGlobalBounds(g->game_one.three);
    g->game_one.hit_four = sfSprite_getGlobalBounds(g->game_one.four);
    g->game_one.hit_five = sfSprite_getGlobalBounds(g->game_one.five);
    g->game_one.hit_six = sfSprite_getGlobalBounds(g->game_one.six);
    g->game_one.hit_seven = sfSprite_getGlobalBounds(g->game_one.seven);
    g->game_one.hit_eight = sfSprite_getGlobalBounds(g->game_one.eight);
    g->game_one.hit_nine = sfSprite_getGlobalBounds(g->game_one.nine);
    g->game_one.hit_valider = sfSprite_getGlobalBounds(g->game_one.valider);
    g->game_one.hit_annuler = sfSprite_getGlobalBounds(g->game_one.annuler);
    return;
}

void add_mdp(all_t *g, int chiffre)
{
    g->game_one.mdp += chiffre * g->game_one.multi;
    g->game_one.multi /= 10;
    if (chiffre == 10) {
        if (g->game_one.mdp == 3630) {
            g->game_one.bool_rep = 2;
            g->usine.b_draw_usine = 1;
            sfClock_restart(g->game_one.clock_rep);
        } else {
            g->game_one.bool_rep = 1;
            sfClock_restart(g->game_one.clock_rep);
        }
        g->game_one.mdp = 0;
        g->game_one.multi = 1000;
    }
    if (chiffre == 11) {
        g->game_one.mdp = 0;
        g->game_one.multi = 1000;
    }
}

void verif_hit_bis(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->game_one.hit_seven, mousepos.x, mousepos.y))
        add_mdp(g, 7);
    if (sfFloatRect_contains(&g->game_one.hit_eight, mousepos.x, mousepos.y))
        add_mdp(g, 8);
    if (sfFloatRect_contains(&g->game_one.hit_nine, mousepos.x, mousepos.y))
        add_mdp(g, 9);
    if (sfFloatRect_contains(&g->game_one.hit_valider, mousepos.x, mousepos.y))
        add_mdp(g, 10);
    if (sfFloatRect_contains(&g->game_one.hit_annuler, mousepos.x, mousepos.y))
        add_mdp(g, 11);
}

void verif_hit(all_t *g, sfVector2f mousepos)
{
    if (sfFloatRect_contains(&g->game_one.hit_zero, mousepos.x, mousepos.y))
        add_mdp(g, 0);
    if (sfFloatRect_contains(&g->game_one.hit_one, mousepos.x, mousepos.y))
        add_mdp(g, 1);
    if (sfFloatRect_contains(&g->game_one.hit_two, mousepos.x, mousepos.y))
        add_mdp(g, 2);
    if (sfFloatRect_contains(&g->game_one.hit_three, mousepos.x, mousepos.y))
        add_mdp(g, 3);
    if (sfFloatRect_contains(&g->game_one.hit_four, mousepos.x, mousepos.y))
        add_mdp(g, 4);
    if (sfFloatRect_contains(&g->game_one.hit_five, mousepos.x, mousepos.y))
        add_mdp(g, 5);
    if (sfFloatRect_contains(&g->game_one.hit_six, mousepos.x, mousepos.y))
        add_mdp(g, 6);
    verif_hit_bis(g, mousepos);
    return;
}
