/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** script
*/

#include "../include/my.h"
#include <pthread.h>

static void *createnode(char *text)
{
    node_t *newNode = malloc(sizeof(node_t));
    sfFont *font = sfFont_createFromFile("ressource/arial_narrow_7.ttf");

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->text = sfText_create();
    sfText_setString(newNode->text, text);
    sfText_setFont(newNode->text, font);
    sfText_setCharacterSize(newNode->text, 30);
    sfText_setScale(newNode->text, (sfVector2f){0.25, 0.25});
    if (text[0] == ' ')
        sfText_setFillColor(newNode->text, sfWhite);
    else
        sfText_setFillColor(newNode->text, sfColor_fromRGB(24, 140, 255));
    newNode->position.x = 190.0;
    newNode->position.y = -45.0;
    newNode->next = NULL;
    return newNode;
}

static void openfile(FILE *file)
{
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file \"%s\".\n",
            "ressource/files/script.txt");
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

void *readscriptfromfile(all_t *g, int inewline)
{
    node_t *head = NULL;
    char line[256];
    char *newline;
    FILE *file = fopen("ressource/files/script.txt", "r");

    openfile(file);
    for (int loop = 0; loop < g->script.line + inewline; loop++) {
        if (fgets(line, sizeof(line), file) == NULL)
            break;
        if (loop < g->script.line)
            continue;
        newline = strchr(line, '\n');
        if (newline != NULL)
            *newline = '\0';
        add(&head, line);
    }
    fclose(file);
    g->script.line += inewline;
    g->script.gap = 0;
    return head;
}

/*
 * Function: set_script
 * --------------------
 * initialize the script
 *
 * - g: global structure
 */
void set_script(all_t *g)
{
    g->script.line = 0;
    g->script.gap = 0.0;
    g->script.drawe_mother = 0;
    g->script.exit_house = 0;
    g->script.first_factory = 0;
    g->script.history = 0;
}

void add(node_t **headref, char *text)
{
    node_t *newNode = (node_t *) createnode(text);
    node_t *lastNode;

    if (*headref == NULL) {
        *headref = newNode;
        return;
    }
    lastNode = *headref;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void freelist(node_t *head)
{
    node_t *current = head;
    node_t *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        sfText_destroy(temp->text);
        free(temp);
    }
}

/*
 * Function: script
 * --------------------
 * main function of the script it allows
 * you to create the thread which will be
 * separated from the rest of the program.
 *
 * - g: global structure
 * - newline: number of new lines of the script to display.
 */
void script(all_t *g, int newline)
{
    freelist(g->script.head);
    g->script.head = readscriptfromfile(g, newline);
}
