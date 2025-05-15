/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** generate_pnj
*/

#include "../include/my.h"

static void push_pnj_continue(pnj_t *new)
{
    new->rect_spr.top = 0;
    new->rect_spr.left = 0;
    new->rect_spr.width = 140;
    new->rect_spr.height = 218;
    new->hitbox = createrect(new->coord.x, new->coord.y, (int[2]){20, 30},
    sfWhite);
    new->wait_att = 0;
    sfSprite_setOrigin(new->sprite, (sfVector2f){60, 60});
    sfRectangleShape_setOrigin(new->hitbox, (sfVector2f){10, 15});
    new->attack = 1;
    new->health = 50;
    new->death = false;
    new->display = false;
    new->clock_attack = sfClock_create();
}

static void push_pnj(pnj_t **begin, float c[2], char *diag, int scene[3])
{
    pnj_t *new = malloc(sizeof(pnj_t));

    new->coord = (sfVector2f){c[0], c[1]};
    new->diag = create_text((float[3]){0, 0, 40}, "ressource/cyber.ttf"
    , diag, sfBlack);
    new->scene = scene[0];
    new->when = scene[1];
    new->agro = scene[2];
    new->sprite = create_sprite((int[2]){c[0], c[1]}, 0.25, 0.25,
    "ressource/ennemi/walk_up.png");
    new->distance = 10000;
    new->track = false;
    new->clock = sfClock_create();
    new->travel = 0;
    new->dist = -1;
    new->direction = 0;
    new->wait = 0;
    push_pnj_continue(new);
    new->next = *begin;
    *begin = new;
    return;
}

static void set_text_pnj_s(all_t *g)
{
    g->all_pnj.punch_down_en = sfTexture_createFromFile
    ("ressource/ennemi/punch_down.png", NULL);
    g->all_pnj.punch_left_en = sfTexture_createFromFile
    ("ressource/ennemi/punch_left.png", NULL);
    g->all_pnj.punch_right_en = sfTexture_createFromFile
    ("ressource/ennemi/punch_right.png", NULL);
}

static void set_text_pnj(all_t *g)
{
    g->all_pnj.walk_up_en = sfTexture_createFromFile
    ("ressource/ennemi/walk_up.png", NULL);
    g->all_pnj.walk_down_en = sfTexture_createFromFile
    ("ressource/ennemi/walk_down.png", NULL);
    g->all_pnj.walk_left_en = sfTexture_createFromFile
    ("ressource/ennemi/walk_left.png", NULL);
    g->all_pnj.walk_right_en = sfTexture_createFromFile
    ("ressource/ennemi/walk_right.png", NULL);
    g->all_pnj.sprint_up_en = sfTexture_createFromFile
    ("ressource/ennemi/sprint_up.png", NULL);
    g->all_pnj.sprint_down_en = sfTexture_createFromFile
    ("ressource/ennemi/sprint_down.png", NULL);
    g->all_pnj.sprint_left_en = sfTexture_createFromFile
    ("ressource/ennemi/sprint_left.png", NULL);
    g->all_pnj.sprint_right_en = sfTexture_createFromFile
    ("ressource/ennemi/sprint_right.png", NULL);
    g->all_pnj.punch_up_en = sfTexture_createFromFile
    ("ressource/ennemi/punch_top.png", NULL);
    set_text_pnj_s(g);
}

void open_file(all_t *g)
{
    char *line = NULL;
    size_t len = 0;
    char **array = NULL;
    FILE *fd = fopen("config/pnj", "r");

    while (getline(&line, &len, fd) != -1) {
        array = my_str_to_word_array(line, ',');
        push_pnj(&g->all_pnj.pnj, (float[2]){atof(array[0]), atof(array[1])},
        array[2], (int[3]){atoi(array[3]), atoi(array[4]), atoi(array[5])});
    }
    set_text_pnj(g);
}

void draw_pnj(all_t *g)
{
    pnj_t *tmp = g->all_pnj.pnj;

    for (; tmp != NULL; tmp = tmp->next)
        if (((g->scene == tmp->scene && tmp->when == 0) ||
        (g->scene == tmp->scene && tmp->when == g->script.first_factory) ||
        (g->scene == tmp->scene && tmp->when == g->script.history)) &&
        tmp->health > 0)
            sfRenderWindow_drawSprite(g->window, tmp->sprite, NULL);
}

static void check_range_s(all_t *g, pnj_t *tmp, sfImage *img)
{
    tmp->distance = sqrt(pow(g->mia.x - tmp->coord.x, 2) +
    pow(g->mia.y - tmp->coord.y, 2));
    if (tmp->distance < 150 && tmp->agro == 1)
        tmp->track = true;
    else
        tmp->track = false;
    tmp->time = sfClock_getElapsedTime(tmp->clock_attack);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (tmp->distance < 30 && tmp->seconds > 0.5 && tmp->health > 0) {
        g->gui.current_life -= tmp->attack;
        sfClock_restart(tmp->clock_attack);
    }
    if (tmp->health > 0)
        displacement_pnj(g, tmp, img);
    if (tmp->distance <= 50)
        tmp->display = (tmp->display == false) ? true : false;
    tmp->wait_att++;
}

void check_range(all_t *g, sfImage *img)
{
    for (pnj_t *tmp = g->all_pnj.pnj; tmp != NULL; tmp = tmp->next) {
        if ((g->scene == tmp->scene && tmp->when == 0) ||
        (g->scene == tmp->scene && tmp->when == g->script.first_factory) ||
        (g->scene == tmp->scene && tmp->when == g->script.history))
            check_range_s(g, tmp, img);
    }
}
