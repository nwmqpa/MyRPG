/*
** EPITECH PROJECT, 2017
** sources/inventory/draw_inventory.c
** File description:
** draw_inventories.
*/

#include <SFML/Graphics.h>
#include "cybend2200.h"
#include "assets_manager.h"
#include "ress_manager.h"
#include "objects.h"
#include "entities.h"
#include "str_utils.h"

static int draw_item_number(item_t item, game_t *game, sfVector2f off)
{
	sfText *text = sfText_create();

	sfText_setColor(text, sfWhite);
	printf("\t%d\n", item.qty);
	sfText_setString(text, my_itoa(item.qty));
	sfText_setFont(text, get_assets(0x0)->fonts[FLIGHTER]);
	sfText_setCharacterSize(text, 24);
	off = (sfVector2f) {off.x + 50, off.y + 50};
	sfText_setPosition(text, off);
	sfRenderWindow_drawText(game->win, text, 0x0);
	sfText_destroy(text);
}

static int draw_inv_object(item_t item, int nb, sfVector2f off, game_t *game)
{
	sfSprite *weapon = get_assets(0x0)->sprites[GUN_1];
	sfIntRect size;
	union to_data object;

	object.object = item;
	if (object.data == 0 || item.qty == 0)
		return (0);
	size = sfSprite_getTextureRect(weapon);
	off = (sfVector2f) {off.x + 62, off.y + 60};
	off = (sfVector2f) {off.x, off.y + ((nb % 4) * 141)};
	off = (sfVector2f) {off.x + ((nb / 4) * 280), off.y};
	if (nb / 4 == 2)
		off = (sfVector2f) {off.x + 8, off.y};
	off = (sfVector2f) {off.x + ((103 - size.width) / 2), off.y};
	off = (sfVector2f) {off.x, off.y + ((103 - size.height) / 2)};
	sfSprite_setPosition(weapon, off);
	sfRenderWindow_drawSprite(game->win, weapon, 0x0);
	draw_item_number(item, game, off);
	return (1);
}

static int draw_cont_object(item_t item, int nb, sfVector2f off, game_t *game)
{
	sfSprite *weapon = get_assets(0x0)->sprites[GUN_1];
	sfIntRect size;
	union to_data object;

	object.object = item;
	if (object.data == 0 || item.qty == 0)
		return (0);
	size = sfSprite_getTextureRect(weapon);
	off = (sfVector2f) {off.x + 62, off.y + 60};
	off = (sfVector2f) {off.x, off.y + ((nb % 3) * 141)};
	off = (sfVector2f) {off.x + ((nb / 3) * 140), off.y};
	off = (sfVector2f) {off.x + ((103 - size.width) / 2), off.y};
	off = (sfVector2f) {off.x, off.y + ((103 - size.height) / 2)};
	sfSprite_setPosition(weapon, off);
	sfRenderWindow_drawSprite(game->win, weapon, 0x0);
	draw_item_number(item, game, off);
	return (1);
}

int draw_inventory(game_t *game)
{
	sfVector2u sz_w = sfRenderWindow_getSize(game->win);
	sfSprite *inv_sprite = get_assets(0x0)->sprites[INVENTORY];
	sfIntRect s_sz = sfSprite_getTextureRect(inv_sprite);
	sfVector2f off = {(sz_w.x - s_sz.width), (sz_w.y - s_sz.height)};
	struct inventory *inv = get_ressources(0x0)->player->inv;

	off = (sfVector2f) {off.x / 2, off.y / 2};
	sfSprite_setPosition(inv_sprite, off);
	sfRenderWindow_drawSprite(game->win, inv_sprite, 0x0);
	for (int i = 0; i < inv->size; i++) {
		draw_inv_object(inv->objects[i], i, off, game);
	}
	return (0);
}

int draw_containers(game_t *game)
{
	sfVector2u sz_w = sfRenderWindow_getSize(game->win);
	sfSprite *cont_spr = get_assets(0x0)->sprites[CHEST];
	sfSprite *inv_spr = get_assets(0x0)->sprites[INVENTORY];
	sfIntRect inv_sz = sfSprite_getTextureRect(inv_spr);
	sfIntRect cont_sz = sfSprite_getTextureRect(cont_spr);
	sfVector2f off_c = {0, (sz_w.y - cont_sz.height) / 2};
	sfVector2f off_i = {0, (sz_w.y - inv_sz.height) / 2};
	struct inventory *inv = get_ressources(0x0)->player->inv;

	off_i = (sfVector2f) {sz_w.x - inv_sz.width - cont_sz.width, off_i.y};
	off_i = (sfVector2f) {(off_i.x - 200) / 2, off_i.y};
	off_c = (sfVector2f) {off_i.x + 200 + inv_sz.width, off_c.y};
	sfSprite_setPosition(cont_spr, off_c);
	sfSprite_setPosition(inv_spr, off_i);
	sfRenderWindow_drawSprite(game->win, cont_spr, 0x0);
	sfRenderWindow_drawSprite(game->win, inv_spr, 0x0);
	for (int i = 0; i < inv->size; i++)
		draw_inv_object(inv->objects[i], i, off_i, game);

	printf("%d =>\n", game->container->size);
	for (int i = 0; i < game->container->size; i++)
		draw_cont_object(game->container->objects[i], i, off_c, game);
	return (0);
}
