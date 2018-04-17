/*
** EPITECH PROJECT, 2017
** get_struct.c
** File description:
** getter setter of struct
*/

#include "assets_manager.h"
#include "my_rpg.h"

assets_mng_t *get_assets_manager(assets_mng_t *assets)
{
	static assets_mng_t *assets_manager = NULL;

	if (!assets_mng_t) {
		assets_manager = assets;
	}
	return (assets_manager);


game_t *get_game(game_t *game_given)
{
	static game_t *game = NULL;

	if (!game) {
		game = game_given;
	}
	return (game);
}
