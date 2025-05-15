/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** moov
*/

#include "../include/my.h"

static void clock_forendurancesprint(all_t *g)
{
    g->gui.time_energie = sfClock_getElapsedTime(g->gui.clock_energie);
    g->gui.seconds_energie = g->gui.time_energie.microseconds / 984100.0;
    if (g->gui.seconds_energie > 0.05 &&
    (g->gui.current_energie <= g->gui.energie + 5) &&
    (g->gui.current_energie > 4)) {
        g->gui.current_energie -= g->gui.malus_energie;
        sfRectangleShape_setSize(g->gui.energie_rect,
        (sfVector2f) {g->gui.current_energie / 3, 2});
        sfClock_restart(g->gui.clock_energie);
    }
}

static void condition_endurance(all_t *g)
{
    if (!sfKeyboard_isKeyPressed(g->mia.sprintkey) &&
    g->mia.current.r != 0 && g->mia.current.g != 0 && g->mia.current.b != 0) {
        g->mia.sprint = 0;
        sfSprite_setScale(g->mia.mia_sprite, (sfVector2f){0.35, 0.35});
    }
    if (g->gui.current_energie <= 4) {
        g->mia.endurance = 0;
        g->mia.sprint = 0;
    }
    if (g->mia.sprint == 1 && (sfKeyboard_isKeyPressed(g->mia.upkey)
        || sfKeyboard_isKeyPressed(g->mia.leftkey) ||
        sfKeyboard_isKeyPressed(g->mia.downkey) ||
        sfKeyboard_isKeyPressed(g->mia.rightkey))) {
        if (g->effect.b_effect_sugar == 0)
            clock_forendurancesprint(g);
        }
    if (g->gui.current_energie > 70)
        g->mia.endurance = 1;
    if (g->mia.endurance == 0)
        sfSprite_setScale(g->mia.mia_sprite, (sfVector2f){0.35, 0.35});
}

void clockmouvkatana(all_t *g, sfTexture *texture, float left, int limit)
{
    sfSprite_setTexture(g->mia.mia_katana, texture, sfTrue);
    g->mia.time_mia = sfClock_getElapsedTime(g->mia.clock_mia);
    g->mia.seconds_mia =
    g->mia.time_mia . microseconds / 984100.0;
    if (g->mia.seconds_mia > 0.02){
        g->mia.rect_miakatana.left += left;
        sfClock_restart(g->mia.clock_mia);
        check_rangewithmia(g);
        if (g->mia.rect_miakatana.left > limit) {
            g->mia.attack = 0;
            g->mia.movement = 0;
        }
    }
}

static void minimap(all_t *g)
{
    sfVector2f viewposition = sfView_getCenter(g->view);
    sfVector2f minimap = {
        viewposition.x + 288 + g->mia.v_minimap.x,
        viewposition.y - 162 - g->mia.v_minimap.y
    };

    if (g->gui_invent.invent[g->gui_invent.current_pos - 1][0] == 3) {
        fight_anim(g);
        mouse_fight(g);
    }
    sfSprite_setPosition(g->mia.spritemia_minimap,
    (sfVector2f) {(g->mia.x * 1.040 + 76 + g->mia.v_minimap.x),
    (g->mia.y * 1.040) - 170 - g->mia.v_minimap.y});
    sfSprite_setPosition(g->mia.view_minimap, minimap);
    sfSprite_setPosition(g->mia.mia_katana, (sfVector2f){g->mia.x, g->mia.y});
    sfSprite_setTextureRect(g->mia.mia_sprite, g->mia.rect_mia);
    sfSprite_setTextureRect(g->mia.mia_katana, g->mia.rect_miakatana);
    sfSprite_setOrigin(g->mia.mia_sprite, (sfVector2f){60, 60});
}

void affichage_map(all_t *g)
{
    static int previous = 0;
    int key_m = sfKeyboard_isKeyPressed(sfKeyM);

    if (key_m && !previous) {
        if (g->mia.map == 1)
            g->mia.map = 0;
        else
            g->mia.map = 1;
    }
    previous = key_m;
}

static void sound_run(all_t *g)
{
    if (sfSound_getBuffer(g->mia.footstepsound) != g->mia.footsteprun)
            sfSound_setBuffer(g->mia.footstepsound, g->mia.footsteprun);
        if (g->mia.endurance == 0) {
            if (sfSound_getBuffer(g->mia.footstepsound) != g->mia.footstep)
                sfSound_setBuffer(g->mia.footstepsound, g->mia.footstep);
            if (sfSound_getStatus(g->mia.footstepsound) != sfPlaying)
                sfSound_play(g->mia.footstepsound);
            return;
        }
        if (sfSound_getStatus(g->mia.footstepsound) != sfPlaying)
            sfSound_play(g->mia.footstepsound);
}

static void condition_sound_next(all_t *g, int was_sprinting, int was_moving)
{
    if (is_sprinting(g) && !was_sprinting)
        sound_run(g);
    if (!is_sprinting(g) && is_moving(g) && (was_sprinting || !was_moving)) {
        if (sfSound_getBuffer(g->mia.footstepsound) != g->mia.footstep)
            sfSound_setBuffer(g->mia.footstepsound, g->mia.footstep);
        if (sfSound_getStatus(g->mia.footstepsound) != sfPlaying)
            sfSound_play(g->mia.footstepsound);
    }
    if (is_sprinting(g) && g->mia.endurance == 0) {
        if (sfSound_getBuffer(g->mia.footstepsound) != g->mia.footstep)
            sfSound_setBuffer(g->mia.footstepsound, g->mia.footstep);
        if (sfSound_getStatus(g->mia.footstepsound) != sfPlaying)
            sfSound_play(g->mia.footstepsound);
    }
    if (!is_moving(g) && !is_sprinting(g)) {
        if (sfSound_getStatus(g->mia.footstepsound) == sfPlaying) {
            sfSound_stop(g->mia.footstepsound);
        }
    }
}

static void condition_sound(all_t *g)
{
    static int was_sprinting = 0;
    static int was_moving = 0;
    static int was_hitting = 0;
    int mouse_left = sfMouse_isButtonPressed(sfMouseLeft);

    if (mouse_left && !was_hitting) {
        if (sfSound_getBuffer(g->mia.footstepsound) != g->mia.hit &&
        g->gui_invent.invent[g->gui_invent.current_pos - 1][0] == 3)
            sfSound_setBuffer(g->mia.footstepsound, g->mia.hit);
        if (sfSound_getStatus(g->mia.footstepsound) != sfPlaying)
            sfSound_play(g->mia.footstepsound);
    }
    condition_sound_next(g, was_sprinting, was_moving);
    was_hitting = mouse_left;
    was_sprinting = is_sprinting(g);
    was_moving = is_moving(g);
}

void moov_sprite(all_t *g, sfImage *img)
{
    if (idle_bind(g))
        idle_maker(g);
    sprint(g);
    if (is_moving(g) || sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfSound_getStatus(g->mia.footstepsound) != sfPlaying)
            sfSound_play(g->mia.footstepsound);
    } else
        sfSound_stop(g->mia.footstepsound);
    condition_endurance(g);
    if (g->mia.movement == 0) {
        movement_b_diag(g, img);
        movement_g_d(g, img);
        movement_h_b(g, img);
        movement_h_diag(g, img);
    }
    affichage_map(g);
    condition_sound(g);
    config_view(g);
    minimap(g);
}
