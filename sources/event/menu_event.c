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
		//menu up
		break;
	case sfKeyDown:
		//menu down
		break;
	case sfKeyReturn:
		//menu trigger_selected
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