/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** robot
*/

#include "../include/my.h"

void set_robot(all_t *g)
{
    g->robot.coord = (sfVector2f){1522, 2966};
    g->robot.robot = create_sprite((int[2]){g->robot.coord.x, g->robot.coord.y}
    , 0.1, 0.1, "ressource/robot.png");
    g->robot.rect_robot.top = 0;
    g->robot.rect_robot.left = 0;
    g->robot.rect_robot.width = 200;
    g->robot.rect_robot.height = 150;
    g->robot.clock = sfClock_create();
    g->robot.clock_effect = sfClock_create();
    g->robot.seconds = 0.0;
    g->robot.on = false;
    sfSprite_setOrigin(g->robot.robot, (sfVector2f){100, 75});
}

void clock_robot(all_t *g)
{
    g->robot.time = sfClock_getElapsedTime(g->robot.clock);
    g->robot.seconds = g->robot.time.microseconds / 1000000.0;
    if (g->robot.seconds > 0.1) {
        g->robot.rect_robot.left += 200;
        sfSprite_setTextureRect(g->robot.robot, g->robot.rect_robot);
        sfClock_restart(g->robot.clock);
        if (g->robot.rect_robot.left > 9400)
            g->robot.on = true;
    }
}

void moov_robot(all_t *g)
{
    double distance = sqrt(pow(g->mia.x - g->robot.coord.x, 2) +
    pow(g->mia.y - g->robot.coord.y, 2));
    double angle = atan2((g->robot.coord.y - g->mia.y),
    (g->robot.coord.x - g->mia.x)) * 180 / 3.14;

    sfSprite_setRotation(g->robot.robot, angle);
    g->robot.time = sfClock_getElapsedTime(g->robot.clock);
    g->robot.seconds = g->robot.time.microseconds / 1000000.0;
    if (g->robot.seconds > 0.03 && distance > 25) {
        g->robot.coord.x += ((g->mia.x - g->robot.coord.x) / distance);
        g->robot.coord.y += ((g->mia.y - g->robot.coord.y) / distance);
        sfSprite_setPosition(g->robot.robot, g->robot.coord);
        sfClock_restart(g->robot.clock);
    }
}

void hand_robot(all_t *g, sfEvent event)
{
    sfSprite_setTextureRect(g->robot.robot, g->robot.rect_robot);
    if (g->script.history < 3)
        return;
    if (g->robot.on == false)
        clock_robot(g);
    else
        moov_robot(g);
    if (event.type == sfEvtKeyReleased && event.key.code == g->mia.ekey) {
        g->robot.time = sfClock_getElapsedTime(g->robot.clock_effect);
        g->robot.seconds = g->robot.time.microseconds / 1000000.0;
        if (g->robot.seconds > 30) {
            g->gui.current_energie = g->gui.energie;
            g->gui.current_life = g->esc_menu.taille_health;
            sfClock_restart(g->robot.clock_effect);
        }
    }
}
