/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** hacking_bot
*/

#include "../include/my.h"

void hack_drone(all_t *g, sfEvent event)
{
    if ((g->mia.x >= 1467 && g->mia.x <= 1575) &&
    (g->mia.y >= 2954 && g->mia.y <= 2988) &&
    g->script.history == 2) {
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {1520, 2980});
        if (event.key.code == sfKeyE)
            g->scene = 5;
    } else
        sfSprite_setPosition(g->gui.key_e_sprite, (sfVector2f) {-3000, 0});
}

static void open_hb_script_two(all_t *g, FILE *file)
{
    int line_count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
    if (line_count < 9) {
            g->hackbot.script_one = realloc(g->hackbot.script_one,
                strlen(g->hackbot.script_one) + strlen(line) + 1);
            malloc_checker(g->hackbot.script_one, "script_one");
            strcat(g->hackbot.script_one, line);
        } else {
            g->hackbot.script_two = realloc(g->hackbot.script_two,
                strlen(g->hackbot.script_two) + strlen(line) + 1);
            malloc_checker(g->hackbot.script_two, "script_two");
            strcat(g->hackbot.script_two, line);
        }
        line_count++;
    }
}

void open_hb_script(all_t *g)
{
    FILE *file = fopen("ressource/files/script_hack.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file script_hack\n");
        return;
    }
    g->hackbot.script_one = malloc(1);
    malloc_checker(g->hackbot.script_one, "script_one");
    g->hackbot.script_two = malloc(1);
    malloc_checker(g->hackbot.script_two, "script_two");
    g->hackbot.script_one[0] = '\0';
    g->hackbot.script_two[0] = '\0';
    open_hb_script_two(g, file);
    fclose(file);
}

void set_hb(all_t *g)
{
    g->hackbot.background_hb = create_sprite((int[2])
    {0, -62}, 1, 1, "ressource/hack_bg.png");
    g->hackbot.text_one = create_text((float[3])
    {60, 175, 35}, "ressource/arial_narrow_7.ttf", "", sfGreen);
    g->hackbot.text_two = create_text((float[3])
    {1000, 430, 35}, "ressource/arial_narrow_7.ttf", "", sfGreen);
    open_hb_script(g);
    g->hackbot.draw_one = malloc(strlen(g->hackbot.script_one) + 1);
    malloc_checker(g->hackbot.draw_one, "draw_one");
    g->hackbot.draw_two = malloc(strlen(g->hackbot.script_two) + 1);
    malloc_checker(g->hackbot.draw_two, "draw_two");
    g->hackbot.draw_one[0] = '\0';
    g->hackbot.draw_two[0] = '\0';
    g->hackbot.one = 0;
    g->hackbot.two = 0;
    g->hackbot.key = 0;
    g->hackbot.pause = 0;
    g->hackbot.last_scene = 0;
}

static void hand_event_hb_four(all_t *g)
{
    for (; g->hackbot.script_two[g->hackbot.two] != '^'; g->hackbot.two++) {
            g->hackbot.draw_two[g->hackbot.two] =
            g->hackbot.script_two[g->hackbot.two];
            sfText_setString(g->hackbot.text_two, g->hackbot.draw_two);
            if (g->hackbot.script_two[g->hackbot.two] == '%') {
                g->script.history = 3;
                script(g, 10);
                g->scene = g->hackbot.last_scene;
                return;
            }
        }
        if (g->hackbot.script_two[g->hackbot.two] == '^') {
            g->hackbot.draw_two[g->hackbot.two] = ' ';
            g->hackbot.two++;
        }
        g->hackbot.key = 0;
}

static void hand_event_hb_three(all_t *g)
{
    if (g->hackbot.script_one[g->hackbot.one] == '^') {
        g->hackbot.key = 1;
        g->hackbot.draw_one[g->hackbot.one] = ' ';
        g->hackbot.one++;
    }
}

static void hand_event_hb_two(all_t *g, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && g->hackbot.key == 0) {
        if (g->hackbot.one < (int)strlen(g->hackbot.script_one)) {
            hand_event_hb_three(g);
            g->hackbot.draw_one[g->hackbot.one] =
                g->hackbot.script_one[g->hackbot.one];
            g->hackbot.one++;
            g->hackbot.draw_one[g->hackbot.one] = '\0';
            sfText_setString(g->hackbot.text_one, g->hackbot.draw_one);
        }
    }
}

void hand_event_hb(all_t *g)
{
    sfEvent event;
    sfVector2i mousepos = sfMouse_getPosition((const sfWindow *) g->window);
    sfVector2f mouse_pos =
        sfRenderWindow_mapPixelToCoords(g->window, mousepos, NULL);

    sfSprite_setPosition(g->menu.souris, (sfVector2f)
    {mouse_pos.x - 10, mouse_pos.y - 3});
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        hand_event_hb_two(g, event);
    }
    if (g->hackbot.key == 1) {
        hand_event_hb_four(g);
    }
}

void update_hb(all_t *g)
{
    sfRenderWindow_setView(g->window,
    sfRenderWindow_getDefaultView(g->window));
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->hackbot.background_hb, NULL);
    sfRenderWindow_drawText(g->window, g->hackbot.text_one, NULL);
    sfRenderWindow_drawText(g->window, g->hackbot.text_two, NULL);
    sfRenderWindow_display(g->window);
}
