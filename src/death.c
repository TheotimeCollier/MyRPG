/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** usine
*/

#include "../include/my.h"

void set_death(all_t *g)
{
    g->death.seconds_death = 0;
    g->death.is_death = 0;
    g->death.bool_clock = 0;
    g->death.clock_death = sfClock_create();
    g->death.death_rect = createrect(0, 0, (int[2]) {10000, 10000},
    sfColor_fromRGBA(0, 0, 0, 220));
    g->death.text_death = create_text((float[3]) {100, 100, 90},
    "ressource/cyber.ttf", "You are dead", sfRed);
    sfText_setScale(g->death.text_death, (sfVector2f){0.25, 0.25});
}

void verif_death(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);

    if (g->gui.current_life <= 0) {
        if (g->death.bool_clock == 0) {
            sfClock_restart(g->death.clock_death);
            g->death.bool_clock = 1;
        }
    sfText_setPosition(g->death.text_death,
    (sfVector2f) {viewposition.x - 75 - g->mia.v_gui1.x,
    viewposition.y - 23- g->mia.v_gui1.y});
        clock_death(g);
        sfRenderWindow_drawRectangleShape(g->window, g->death.death_rect,
        NULL);
        sfRenderWindow_drawText(g->window, g->death.text_death, NULL);
    }
}

void clock_death(all_t *g)
{
    g->death.time_death = sfClock_getElapsedTime(g->death.clock_death);
    g->death.seconds_death = g->death.time_death.microseconds / 1000000.0;
    if (g->death.seconds_death > 3) {
        g->scene = 3;
        g->gui.current_life = g->esc_menu.taille_health;
        g->mia.x = 95.0;
        g->mia.y = 45.0;
        g->death.bool_clock = 0;
        sfClock_restart(g->death.clock_death);
    }
}
