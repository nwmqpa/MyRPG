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
		play->action[N_LEFT] = true;
		break;
	case sfKeyRight:
		play->action[N_RIGHT] = true;
		break;
	case sfKeyUp:
		//action
		break;
	case sfKeySpace:
		player_jump(play);
		break;
	default:
		break;
	}
	return (0);
}

int game_key_released(game_t *game)
{
	struct player *play = get_ressources(NULL)->player;

	switch  (game->event.key.code) {
	case sfKeyLeft:
		play->action[N_LEFT] = false;
		break;
	case sfKeyRight:
		play->action[N_RIGHT] = false;
		break;
	default:
		break;
	}
	return (0);
}