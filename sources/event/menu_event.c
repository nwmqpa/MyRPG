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

void interact_with_start(game_t *game)
{
	#ifdef BONUS_
	system("firefox https://www.meilleur-comparatif-banques.com/");
	#endif /* BONUS */
	#ifndef BONUS_
	cin_play(game->win, get_ressources(0x0)->cinematiques[1]);
	#endif /* !BONUS_ */
}

int interact_with_menu(game_t *game, sfVector2u click, sfVector2u win_size)
{
	sfSprite *spr = get_assets(0x0)->sprites[BUTTON];
	sfIntRect rect = sfSprite_getTextureRect(spr);
	sfVector2f pos =
	{(win_size.x - rect.width) / 2, (win_size.y - (rect.height * 6)) / 2};

	pos = (sfVector2f) {click.x - pos.x, click.y - pos.y};
	if (pos.x < 0 && pos.x > rect.width)
		return (0);
	if (game->menu_type == ESCAPE) {
		if (pos.y > 0 && pos.y < rect.height)
			game->gamemode = GAME;
		if (pos.y > 4 * rect.height && pos.y < 5 * rect.height)
			sfRenderWindow_close(game->win);
	} else if (game->menu_type == START) {
		if (pos.y > 0 && pos.y < rect.height)
			game->gamemode = GAME;
		if (pos.y > 4 * rect.height && pos.y < 5 * rect.height)
			sfRenderWindow_close(game->win);
		if (pos.y > 2 * rect.height && pos.y < 3 * rect.height)
			interact_with_start(game);
	}
	return (0);
}

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
		if (game->menu_type == START)
			break;
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
	} else if (game->menu_type == START || game->menu_type == ESCAPE) {
		interact_with_menu(game, click, win_size);
	}
	return (0);
}
