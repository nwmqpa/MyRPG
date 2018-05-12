/*
** EPITECH PROJECT, 2017
** sources/inventory/mouse_interactions.c
** File description:
** Mouse interactions
*/

#include "cybend2200.h"
#include "objects.h"
#include "entities.h"
#include "assets_manager.h"
#include "ress_manager.h"

void swap_items(struct inventory *inv, int slot, game_t *game)
{
	union to_data handed;

	handed.object = game->handed;
	game->handed = inv->objects[slot];
	inv->objects[slot] = handed.object;
}

void interact_with_inv(game_t *game, sfVector2u m_pos, sfVector2u ws)
{
	sfIntRect r = sfSprite_getTextureRect
	(get_assets(0x0)->sprites[INVENTORY]);
	sfVector2f off_i = {(ws.x - r.width) / 2, (ws.y - r.height) / 2};
	sfVector2i c_pos;
	int slot = 0;

	off_i = (sfVector2f) {off_i.x + 62, off_i.y + 60};
	c_pos = (sfVector2i) {m_pos.x - off_i.x, m_pos.y - off_i.y};
	if (c_pos.x < 0 || c_pos.y < 0 || c_pos.x > 670 || c_pos.y > 526)
		return;
	slot = ((c_pos.x / 280) * 4) + (c_pos.y / 141);
	swap_items(get_ressources(0x0)->player->inv, slot, game);
}

void interact_with_cont_bis(game_t *game, sfVector2i pos_i, sfVector2i pos_c)
{
	int slot = 0;

	if (pos_i.x < 0 || pos_i.y < 0 || pos_i.x > 670 || pos_i.y > 526) {
		slot = ((pos_c.x / 141) * 3) + (pos_c.y / 141);
		swap_items(game->container, slot, game);
	}
	if (pos_c.x < 0 || pos_c.y < 0 || pos_c.x > 388 || pos_c.y > 388) {
		slot = ((pos_i.x / 280) * 4) + (pos_i.y / 141);
		swap_items(get_ressources(0x0)->player->inv, slot, game);
	}
}

void interact_with_cont(game_t *game, sfVector2u m_pos, sfVector2u ws)
{
	sfIntRect ir = sfSprite_getTextureRect
	(get_assets(0x0)->sprites[INVENTORY]);
	sfIntRect cr = sfSprite_getTextureRect
	(get_assets(0x0)->sprites[CHEST]);
	sfVector2f off_c = {0, (ws.y - cr.height) / 2};
	sfVector2f off_i = {0, (ws.y - ir.height) / 2};
	sfVector2i c_posi;
	sfVector2i c_posc;

	off_i = (sfVector2f) {ws.x - ir.width - cr.width, off_i.y};
	off_i = (sfVector2f) {(off_i.x - 200) / 2, off_i.y};
	off_c = (sfVector2f) {off_i.x + 200 + ir.width, off_c.y};
	off_i = (sfVector2f) {off_i.x + 62, off_i.y + 60};
	off_c = (sfVector2f) {off_c.x + 58, off_c.y + 56};
	c_posi = (sfVector2i) {m_pos.x - off_i.x, m_pos.y - off_i.y};
	c_posc = (sfVector2i) {m_pos.x - off_c.x, m_pos.y - off_c.y};
	interact_with_cont_bis(game, c_posi, c_posc);
}