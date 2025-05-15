/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-corentin.pierrat
** File description:
** moov
*/

#include "../include/my.h"

const char *keys[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8",
    "Num9", "Escape", "LControl", "LShift", "LAlt", "LSystem", "RControl",
    "RShift", "RAlt", "RSystem", "Menu", "LBracket", "RBracket", "Semicolon",
    "Comma", "Period", "Quote", "Slash", "Backslash", "Tilde", "Equal",
    "Hyphen", "Space", "Enter", "Backspace", "Tab", "PageUp", "PageDown",
    "End", "Home", "Insert", "Delete", "Add", "Subtract", "Multiply",
    "Divide", "Left", "Right", "Up", "Down", "Numpad0", "Numpad1", "Numpad2",
    "Numpad3", "Numpad4", "Numpad5",
    "Numpad6", "Numpad7", "Numpad8", "Numpad9", "F1", "F2", "F3",
    "F4", "F5", "F6", "F7",
    "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15", "Pause",
    "Unknown"
};

char *get_key(sfKeyCode key)
{
    if (key >= 0) {
        return (char *)keys[key];
    } else {
        return "Unknown";
    }
}

static void changecontrol_use(all_t *g, sfEvent event)
{
    if (g->mia.e_keybool == 1) {
        if (event.type == sfEvtKeyPressed && event.type != sfEvtMouseMoved) {
            g->mia.ekey = event.key.code;
            sfText_setString(g->set->e_key, get_key(g->mia.ekey));
            g->mia.e_keybool = 0;
        }
    }
    if (g->mia.sprint_keybool == 1) {
        if (event.type == sfEvtKeyPressed && event.type != sfEvtMouseMoved) {
            g->mia.sprintkey = event.key.code;
            sfText_setString(g->set->shift_key, get_key(g->mia.sprintkey));
            g->mia.sprint_keybool = 0;
        }
    }
}

void changecontrol_next(all_t *g, sfEvent event)
{
    if (g->mia.left == 1) {
        if (event.type == sfEvtKeyPressed && event.type != sfEvtMouseMoved) {
            g->mia.leftkey = event.key.code;
            sfText_setString(g->set->left_key, get_key(g->mia.leftkey));
            g->mia.left = 0;
        }
    }
    if (g->mia.right == 1) {
        if (event.type == sfEvtKeyPressed && event.type != sfEvtMouseMoved) {
            g->mia.rightkey = event.key.code;
            sfText_setString(g->set->right_key, get_key(g->mia.rightkey));
            g->mia.right = 0;
        }
    }
    changecontrol_use(g, event);
}

void change_control(all_t *g, sfEvent event)
{
    if (g->mia.up == 1) {
        if (event.type == sfEvtKeyPressed && event.type != sfEvtMouseMoved) {
            g->mia.upkey = event.key.code;
            sfText_setString(g->set->up_key, get_key(g->mia.upkey));
            g->mia.up = 0;
        }
    }
    if (g->mia.down == 1) {
        if (event.type == sfEvtKeyPressed && event.type != sfEvtMouseMoved) {
            g->mia.downkey = event.key.code;
            sfText_setString(g->set->down_key, get_key(g->mia.downkey));
            g->mia.down = 0;
        }
    }
    changecontrol_next(g, event);
}
