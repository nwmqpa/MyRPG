/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for all things
*/

#include <unistd.h>
#include "my_rpg.h"
#include "utils.h"
#include "ress_manager.h"
#include "assets_manager.h"

static game_t *init_game(char *assets_path, char *ressources_path)
{
	game_t *game = my_calloc(sizeof(game_t));
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	get_assets_mng(create_assets_mng(assets_path));
	get_ress_mng(create_ress_mng(ressources_path));

	game->size[X] = WIDTH;
	game->size[Y] = HEIGHT;
	game->win = sfRenderWindow_create(mode, NAME, sfResize , NULL);
	sfRenderWindow_setFramerateLimit(game->win, MAX_FPS);
	game->delta_time = 1 / MAX_FPS;
	return (game);
}

int main(void)
{
	game_t *game = init_game("assets/", "ressources/");

	if (!game) {
		write(2, "Error while loading the game try to reclone\n", 44);
		return (84);
	}
	my_rpg(game);
	return (0);
}
