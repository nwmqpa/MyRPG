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

void interact_with_inv(game_t *game, sfVector2u m_pos, sfVector2u ws)
{
	sfIntRect r = sfSprite_getTextureRect
	(get_assets(0x0)->sprites[INVENTORY]);
	sfVector2f off_i = {(ws.x - r.width) / 2, (ws.y - r.height) / 2};
	sfVector2i c_pos;
	union to_data data;
	union to_data handed;
	int slot = 0;

	off_i = (sfVector2f) {off_i.x + 62, off_i.y + 60};
	c_pos = (sfVector2i) {m_pos.x - off_i.x, m_pos.y - off_i.y};
	if (c_pos.x < 0 || c_pos.y < 0 || c_pos.x > 670 || c_pos.y > 526)
		return;
	slot = ((c_pos.x / 280) * 4) + (c_pos.y / 141);
	data.object = get_ressources(0x0)->player->inv->objects[slot];
	handed.object = game->handed;
	game->handed = data.object;
	get_ressources(0x0)->player->inv->objects[slot] = handed.object;
}

int menu_mouse_moved(game_t *game)
{
	sfVector2u vec = {game->event.mouseMove.x, game->event.mouseMove.x};
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
	//	interact_with_cont(click, win_size);
	}
	return (0);
}