/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include "event.h"

int game_key(game_t *game)
{
	switch  (game->event.key.code) {
	case sfKeyLeft:
		//player move_left
		break;
	case sfKeyRight:
		//player move_left
		break;
	case sfKeyUp:
		//action
		break;
	case sfKeySpace:
		//jump
		break;
	default:
		break;
	}
	return (0);
}