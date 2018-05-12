/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include "event.h"

int menu_key(game_t *game)
{
	switch  (game->event.key.code) {
	case sfKeyUp:
		break;
	case sfKeyDown:
		break;
	case sfKeyReturn:
		break;
	case sfKeyEscape:
		game->gamemode = GAME;
		game->menu_type = NOTHING;
		break;
	default:
		break;
	}
	return (0);
}
