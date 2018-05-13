/*
** EPITECH PROJECT, 2017
** update.c
** File description:
** update file for game
*/

#include "cybend2200.h"
#include "utils.h"
#include "map_parser.h"
#include "ress_manager.h"
#include "entities.h"
#include "ui.h"
#include "npc.h"
#include "utils.h"
#include "assets_manager.h"

int draw_menu_str(game_t *game, sfVector2f pos, int off)
{
	sfText *first = sfText_create();
	sfText *second = sfText_create();
	sfText *third = sfText_create();
	
	sfText_setString(first, game->menu_type == 1 ? "START" : "RESUME");
	sfText_setString(second, "CREDITS");
	sfText_setString(third, "QUIT");
	sfText_setFont(first, get_assets(0x0)->fonts[THORN]);
	sfText_setFont(second, get_assets(0x0)->fonts[THORN]);
	sfText_setFont(third, get_assets(0x0)->fonts[THORN]);
	sfText_setPosition(first, pos);
	sfText_setPosition(second, (sfVector2f) {pos.x, pos.y + off});
	sfText_setPosition(third, (sfVector2f) {pos.x, pos.y + (2 * off)});
	sfText_setColor(first, sfWhite);
	sfText_setColor(second, sfWhite);
	sfText_setColor(third, sfWhite);
	sfRenderWindow_drawText(game->win, first, 0x0);
	sfRenderWindow_drawText(game->win, second, 0x0);
	sfRenderWindow_drawText(game->win, third, 0x0);
	return (0);
}

int draw_escape_menu(game_t *game)
{
	sfVector2u size = sfRenderWindow_getSize(game->win);
	sfSprite *spr = get_assets(0x0)->sprites[BUTTON];
	sfIntRect rect = sfSprite_getTextureRect(spr);
	sfVector2f pos = 
	{(size.x - rect.width) / 2, (size.y - (rect.height * 6)) / 2};
	int value = rect.height * 2;

	sfRenderWindow_clear(game->win, sfBlack);
	sfSprite_setPosition(spr, pos);
	sfRenderWindow_drawSprite(game->win, spr, 0x0);
	sfSprite_setPosition(spr, (sfVector2f) {pos.x, pos.y + value});
	sfRenderWindow_drawSprite(game->win, spr, 0x0);
	sfSprite_setPosition(spr, (sfVector2f) {pos.x, pos.y + (value * 2)});
	sfRenderWindow_drawSprite(game->win, spr, 0x0);
	pos = (sfVector2f) {pos.x + (rect.width / 2) - 50,
	pos.y + (rect.height / 2) - 24};
	return (draw_menu_str(game, pos, value));
}

int draw_menu(game_t *game)
{
	union to_data i;
	sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
	NULL, get_assets(0x0)->shaders[WEAPONS]};
	sfSprite *spr = 0x0;

	i.object = game->handed;
	get_ressources(NULL)->player->vec.x = 0;
	draw_map(game);
	if (game->menu_type == INVENTORY_PLAYER)
		draw_inventory(game);
	if (game->menu_type == CONTAINER)
		draw_containers(game);
	if (game->menu_type == ESCAPE || game->menu_type == START)
		draw_escape_menu(game);
	if (i.data && game->menu_type != ESCAPE) {
		transform_shader(get_assets(0x0)->shaders[WEAPONS], i.object);
		spr = get_spr_item(game->handed);
		sfSprite_setPosition(spr, game->handed_pos);
		sfRenderWindow_drawSprite(game->win, spr, &st);
	}
	return (0);
}

int draw_game(game_t *game)
{
	draw_map(game);
	draw_player(game, game->win, get_ressources(NULL)->player);
	draw_ui(game);
	return (0);
}

int draw_combat(UNUSED game_t *game)
{
	return (0);
}
