/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include <SFML/Graphics.h>
#include "assets_manager.h"
#include "ress_manager.h"
#include "entities.h"
#include "entities.h"
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

int menu_mouse_but(game_t *game)
{
	sfVector2u click =
	{game->event.mouseButton.x, game->event.mouseButton.y};
	sfVector2u win_size = sfRenderWindow_getSize(game->win);

	if (game->menu_type == INVENTORY_PLAYER) {
		interact_with_inv(game, click, win_size);
	} else if (game->menu_type == CONTAINER) {
		interact_with_cont(game, click, win_size);
	}
	return (0);
}