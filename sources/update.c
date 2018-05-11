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
#include "utils.h"

int draw_menu(game_t *game)
{
	get_ressources(NULL)->player->vec.x = 0;
	draw_map(game);
	if (game->menu_type == INVENTORY_PLAYER)
		draw_inventory(game);
	if (game->menu_type == CONTAINER)
		draw_containers(game);
	/*if (game->menu_type == ESCAPE)
		draw_escape_menu(game);*/
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