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
	/*if (game->menu_type == ESCAPE)
		draw_escape_menu(game);*/
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
	//Draw combat phase
    	return (0);
}