/*
** EPITECH PROJECT, 2024
** lib
** File description:
** main
*/

#include "../include/my.h"

static void set_all_bis(all_t *g)
{
    set_inventory(g);
    set_shop(g);
    set_usine(g);
    set_house(g);
    set_saloon(g);
    set_script(g);
    set_robot(g);
    set_haunted(g);
    set_hb(g);
    set_death(g);
    set_boss_bar(g);
    set_boss(g);
    g->script.head = NULL;
    g->mia.up = 0;
    g->mia.down = 0;
    g->mia.left = 0;
    g->mia.right = 0;
    g->mia.sprint_keybool = 0;
    g->mia.e_keybool = 0;
}

void set_all(all_t *g)
{
    g->gui.dollar = 350;
    g->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Hacktivist", sfDefaultStyle, NULL);
    g->all_pnj.pnj = NULL;
    srand(time(NULL));
    set_sprite(g);
    sfRenderWindow_setMouseCursorVisible(g->window, sfFalse);
    set_start_menu(g);
    set_setting(g);
    set_menu(g);
    set_text_digi(g);
    set_game_digi(g);
    set_esc_menu(g);
    set_gui(g);
    open_file(g);
    set_boutique(g);
    set_key_e(g);
    set_effect(g);
    set_all_bis(g);
    return;
}

void free_all(all_t *g)
{
    sfRenderWindow_destroy(g->window);
    sfMusic_destroy(g->start_menu.music_menu);
    sfMusic_destroy(g->mia.music_ambiance);
    sfMusic_destroy(g->mia.music_bar);
    sfMusic_destroy(g->mia.music_maison);
    sfMusic_destroy(g->mia.music_usine);
    sfMusic_destroy(g->mia.music_store);
    sfMusic_destroy(g->mia.music_manoir);
    sfSoundBuffer_destroy(g->mia.footstep);
    sfSoundBuffer_destroy(g->mia.footsteprun);
    sfSoundBuffer_destroy(g->mia.hit);
    sfSound_destroy(g->mia.footstepsound);
    freelist(g->script.head);
    free(g);
    return;
}

int main(void)
{
    all_t *g = malloc(sizeof(all_t));

    set_all(g);
    loop_game(g);
    free_all(g);
    return 0;
}
