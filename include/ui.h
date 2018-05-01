/*
** EPITECH PROJECT, 2017
** ui.h
** File description:
** ui header
*/

#ifndef UI_H_
#define UI_H_

#include <SFML/Graphics.h>

void ui_draw(sfRenderWindow *win, player_t *player);
void ui_update(player_t *player);

#endif