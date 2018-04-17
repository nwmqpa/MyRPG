/*
** EPITECH PROJECT, 2017
** get_struct.c
** File description:
** getter setter of struct
*/

#include "ress_manager.h"
#include "assets_manager.h"
#include "my_rpg.h"

assets_mng_t *get_assets_mng(assets_mng_t *assets)
{
	static assets_mng_t *assets_manager = NULL;

	if (!assets_manager) {
		assets_manager = assets;
	}
	return (assets_manager);
}

ress_mng_t *get_ress_mng(ress_mng_t *ress)
{
	static ress_mng_t *ress_manager = NULL;

	if (!ress_manager) {
		ress_manager = ress;
	}
	return (ress_manager);
}

game_t *get_game(game_t *game_given)
{
	static game_t *game = NULL;

	if (!game) {
		game = game_given;
	}
	return (game);
}
