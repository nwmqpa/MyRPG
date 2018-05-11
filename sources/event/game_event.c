/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include "event.h"
#include "entities.h"
#include "ress_manager.h"
#include "ui.h"
#include "utils.h"

static int game_key_extended(game_t *game)
{
	switch (game->event.key.code) {
	case sfKeyEscape:
		game->gamemode = MENU;
		game->menu_type = ESCAPE;
		break;
	default:
		break;
	}
	return 0;
}

int game_key(game_t *game)
{
	char *test = NULL;
	switch  (game->event.key.code) {
	case sfKeyLeft:
		get_ressources(NULL)->player->action[N_LEFT] = true;
		break;
	case sfKeyRight:
		get_ressources(NULL)->player->action[N_RIGHT] = true;
		break;
	case sfKeyUp:
		check_interactions(game);
		break;
	case sfKeySpace:
		return (player_jump(get_ressources(NULL)->player));
	case sfKeyI:
		game->gamemode = MENU;
		game->menu_type = INVENTORY_PLAYER;
		break;
	default:
		game_key_extended(game);
	}
	return 0;
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