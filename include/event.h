/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for all things
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "cybend2200.h"
#include <SFML/Graphics.h>

int get_event(game_t *game);
int menu_event(game_t *game);
int fight_event(game_t *game);
int game_event(game_t *game);
int game_key(game_t *game);
int menu_key(game_t *game);
int fight_key(game_t *game);

#endif /* EVENT_H_ */