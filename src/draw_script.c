/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** usine
*/

#include "../include/my.h"
#include <pthread.h>

void printlist(all_t *g)
{
    node_t *current = g->script.head;
    sfVector2f viewposition = sfView_getCenter(g->view);

    g->script.gap = 0.0;
    while (current != NULL) {
        sfText_setPosition(current->text, (sfVector2f)
            {viewposition.x + (current->position.x - 30)
            + g->mia.v_gui1.x,
            viewposition.y - ((current->position.y + 60)- g->script.gap)
            + g->mia.v_gui1.y});
        if (g->store.b_disp_store != 1)
            sfRenderWindow_drawText(g->window, current->text, NULL);
        current = current->next;
        g->script.gap += 10.0;
    }
    g->script.gap = 0;
}
