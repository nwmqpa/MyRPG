/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include "event.h"
#include "entities.h"
#include "ress_manager.h"

int game_key(game_t *game)
{
	switch  (game->event.key.code) {
	case sfKeyLeft:
		player_move(game, get_ressources(NULL)->player, LEFT);
		break;
	case sfKeyRight:
		player_move(game, get_ressources(NULL)->player, RIGHT);
		break;
	case sfKeyUp:
		//action
		break;
	case sfKeySpace:
		//jump
		break;
	default:
		//r
		break;
	}
	return (0);
}