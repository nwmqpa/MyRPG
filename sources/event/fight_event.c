/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include "event.h"

int fight_key(game_t *game)
{
	switch  (game->event.key.code) {
	case sfKeyLeft:
		break;
	case sfKeyRight:
		break;
	case sfKeyUp:
		break;
	case sfKeyDown:
		break;
	default:
		break;
	}
	return (0);
}
