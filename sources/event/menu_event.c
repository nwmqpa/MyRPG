/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include <SFML/Graphics.h>
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

int menu_mouse_moved(game_t *game)
{
	sfVector2u vec = {game->event.mouseMove.x, game->event.mouseMove.x};
}

int menu_mouse_but(game_t *game)
{
	sfVector2u click =
	{game->event.mouseButton.x, game->event.mouseButton.y};
	printf("%d, %d\n", click.x, click.y);
}
