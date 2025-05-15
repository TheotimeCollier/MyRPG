/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** moov
*/

#include "../include/my.h"

static void set_texture_mia_idle(all_t *g)
{
    g->mia.hitbox_tape = createrect(g->mia.x,
    g->mia.y, (int[2]) {6, 6}, sfWhite);
    sfRectangleShape_setOrigin(g->mia.hitbox_tape,
    (sfVector2f){4.0, 4.0});
}

static void set_texture_mia_sprint(all_t *g)
{
    g->mia.texture_topsprint =
    sfTexture_createFromFile("ressource/top_sprint.png", NULL);
    g->mia.texture_downsprint =
    sfTexture_createFromFile("ressource/downsprint.png", NULL);
    g->mia.texture_leftsprint =
    sfTexture_createFromFile("ressource/leftsprint.png", NULL);
    g->mia.texture_rightsprint =
    sfTexture_createFromFile("ressource/rightsprint.png", NULL);
    g->mia.texture_leftsprintup =
    sfTexture_createFromFile("ressource/leftsprintup.png", NULL);
    g->mia.texture_leftsprintdown =
    sfTexture_createFromFile("ressource/leftsprintdown.png", NULL);
    g->mia.texture_rightsprintup =
    sfTexture_createFromFile("ressource/rightsprintup.png", NULL);
    g->mia.texture_rightsprintdown =
    sfTexture_createFromFile("ressource/rightsprintdown.png", NULL);
    g->mia.clock_mvt = sfClock_create();
    g->mia.seconds_mvt = 0;
    g->mia.sur_map =
    create_sprite((int[2]) {0.0, 0.0}, 1, 1, "ressource/surmap.png");
}

static void set_texture_mia(all_t *g)
{
    g->mia.mia_sprite = create_sprite((int[2]) {95, 45},
    0.35, 0.35, "ressource/m_devant.png");
    g->mia.texture_left =
    sfTexture_createFromFile("ressource/m_gauche.png", NULL);
    g->mia.texture_right =
    sfTexture_createFromFile("ressource/m_droite.png", NULL);
    g->mia.texture_top =
    sfTexture_createFromFile("ressource/m_devant.png", NULL);
    g->mia.texture_bottom =
    sfTexture_createFromFile("ressource/m_bas.png", NULL);
    g->mia.texture_leftup =
    sfTexture_createFromFile("ressource/m_leftup.png", NULL);
    g->mia.texture_rightup =
    sfTexture_createFromFile("ressource/m_rightup.png", NULL);
    g->mia.texture_leftdown =
    sfTexture_createFromFile("ressource/m_leftdown.png", NULL);
    g->mia.texture_rightdown =
    sfTexture_createFromFile("ressource/m_rightdown.png", NULL);
    g->mia.texture_topsprint =
    sfTexture_createFromFile("ressource/top_sprint.png", NULL);
}

static void set_katanasprite(all_t *g)
{
    g->mia.fortnite = create_sprite((int[2]) {0.0, 0.0},
    1, 1, "ressource/map.png");
    g->mia.katana_top =
    sfTexture_createFromFile("ressource/katana_top.png", NULL);
    g->mia.katana_topright =
    sfTexture_createFromFile("ressource/katana_topright.png", NULL);
    g->mia.katana_right =
    sfTexture_createFromFile("ressource/katana_right.png", NULL);
    g->mia.katana_botright =
    sfTexture_createFromFile("ressource/katana_botright.png", NULL);
    g->mia.katana_bot =
    sfTexture_createFromFile("ressource/katana_bot.png", NULL);
    g->mia.katana_botleft =
    sfTexture_createFromFile("ressource/katana_botleft.png", NULL);
    g->mia.katana_left =
    sfTexture_createFromFile("ressource/katana_left.png", NULL);
    g->mia.katana_topleft =
    sfTexture_createFromFile("ressource/katana_topleft.png", NULL);
    g->mia.attack = 0;
}

static void set_key(all_t *g)
{
    g->mia.v_gui1 = (sfVector2f){0, 0};
    g->mia.v_gui2 = (sfVector2f){0, 0};
    g->mia.v_minimap = (sfVector2f){0, 0};
    g->mia.upkey = sfKeyZ;
    g->mia.downkey = sfKeyS;
    g->mia.rightkey = sfKeyD;
    g->mia.leftkey = sfKeyQ;
    g->mia.sprintkey = sfKeyLShift;
    g->mia.ekey = sfKeyE;
    g->mia.map = 0;
    sfSprite_setOrigin(g->mia.mia_katana, (sfVector2f){79.5, 79.5});
}

static void set_mia(all_t *g)
{
    g->mia.sprint = 0;
    g->mia.mult = 5.3;
    g->mia.current = sfTransparent;
    g->mia.endurance = 0;
    g->mia.x = 95.0;
    g->mia.y = 45.0;
    g->mia.hitbox_mia =
    sfSprite_getGlobalBounds(g->mia.mia_sprite);
    set_katanasprite(g);
    reset_texture_mia_idle(g);
    set_texture_mia_idle(g);
    g->mia.idle[0] = 1;
    g->mia.screensize = 0.3;
    g->mia.mia_katana = create_sprite((int[2]) {0, 0},
    0.4, 0.4, "ressource/katana_top.png");
    g->mia.rect_miakatana.top = 0;
    g->mia.rect_miakatana.left = 0;
    g->mia.rect_miakatana.width = 120;
    g->mia.rect_miakatana.height = 159;
    set_key(g);
}

void set_sound(all_t *g)
{
    g->mia.footstep = sfSoundBuffer_createFromFile("ressource/music/step.wav");
    g->mia.footsteprun =
    sfSoundBuffer_createFromFile("ressource/music/run.wav");
    g->mia.hit = sfSoundBuffer_createFromFile("ressource/music/hit.wav");
    g->mia.footstepsound = sfSound_create();
    sfSound_setBuffer(g->mia.footstepsound, g->mia.footstep);
    g->mia.movement = 0;
}

void set_sprite(all_t *g)
{
    set_texture_mia(g);
    set_texture_mia_sprint(g);
    set_mia(g);
    set_sound(g);
    g->view = sfView_create();
    g->mia.view_minimap = create_sprite((int[2]) {0.0, 0.0},
    0.04, 0.04, "ressource/minimap.png");
    g->mia.spritemia_minimap = create_sprite((int[2]) {0.0, 0.0},
    0.04, 0.04, "ressource/mia_icone.png");
    sfSprite_setOrigin(g->mia.spritemia_minimap, (sfVector2f){34, 34});
    sfSprite_setOrigin(g->mia.view_minimap, (sfVector2f){4454, 0});
    g->mia.vite = 0.5;
    g->mia.image_fortnite =
    sfImage_createFromFile("ressource/image_hitbox.png");
    g->mia.clock_mia = sfClock_create();
    g->mia.seconds_mia = 0;
    g->mia.rect_mia.top = 0;
    g->mia.rect_mia.left = 0;
    g->mia.rect_mia.width = 120;
    g->mia.rect_mia.height = 120;
}

void clockmouv(all_t *g, sfTexture *texture, int left, int limit)
{
    sfSprite_setTexture(g->mia.mia_sprite, texture, sfTrue);
    g->mia.time_mia = sfClock_getElapsedTime(g->mia.clock_mia);
    g->mia.seconds_mia =
    g->mia.time_mia . microseconds / 1000000.0;
    if (g->mia.seconds_mia > 0.0305){
        g->mia.rect_mia.left += left;
        sfClock_restart(g->mia.clock_mia);
        if (g->mia.rect_mia.left > limit)
            g->mia.rect_mia.left = 0;
    }
}

void movement_mia(all_t *g, sfImage *img)
{
    g->mia.time_mvt =
    sfClock_getElapsedTime(g->mia.clock_mvt);
    g->mia.seconds_mvt =
    g->mia.time_mvt . microseconds / 1000000.0;
    if (g->mia.seconds_mvt > 0.01) {
        moov_sprite(g, img);
        sfClock_restart(g->mia.clock_mvt);
    }
}
