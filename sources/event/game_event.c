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
	struct player *play = get_ressources(NULL)->player;

	switch  (game->event.key.code) {
	case sfKeyLeft:
		player_move(game, play, LEFT);
		break;
	case sfKeyRight:
		player_move(game, play, RIGHT);
		break;
	case sfKeyUp:
		//action
		break;
	case sfKeySpace:
		player_jump(play);
		break;
	default:
		play->actual = play->normal[N_IDLE];
		break;
	}
	return (0);
}