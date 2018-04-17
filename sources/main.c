/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for all things
*/

#include "my_rpg.h"

static game_t *init_game(char *assets_path, char *ressources_path)
{
	game_t *game = my_calloc(sizeof(game_t));
	assets_mng_t *ass_mng = my_calloc(sizeof(asset_mng_t));
	ress_mng_t *ress_mng = my_calloc(sizeof(ress_mng_t));

	load_assets(ass_mng, "assets_path");
	game->size[X] = WIDTH;
	game->size[Y] = HEIGHT;
	game->win     = sfRenderWindow_create((sfVideoMode){WIDTH, HEIGHT, 32},
			NAME, sfResize , NULL);
	sfRenderWindow_setFramerateLimit(game->win, MAX_FPS);
	game->delta_time = 1 / MAX_FPS;
	return (0x0);
}

int main(void)
{
	game_t *game = init_game("assets/", "ressources/");

	if (!game) {
		write(2, "Error while loading the game try to reclone\n", 43);
		return (84);
	}
	my_rpg();
	return (0);
}
