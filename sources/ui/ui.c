/*
** EPITECH PROJECT, 2017
** ui.c
** File description:
** main ui api
*/

#include "ui.h"

void draw_life(sfRenderWindow *win, int nb_life)
{
    for (int i = 0; i < nb_life; ++i) {
        ass_mng_get_anim("life");
    }
}

void ui_draw(sfRenderWindow *win, player_t *player)
{
    draw_life(win, player->lifes);
    draw_minimap(win);
}
