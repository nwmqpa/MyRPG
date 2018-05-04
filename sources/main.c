/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for all things
*/

#include <unistd.h>
#include "cybend2200.h"
#include "utils.h"
#include "ress_manager.h"
#include "assets_manager.h"

static game_t *init_game(UNUSED char *assets_path, UNUSED char *ressources_path)
{
	game_t *game = my_calloc(sizeof(game_t));
	sfVideoMode mode = {WIDTH, HEIGHT, 32};

	get_assets(create_assets());
	get_ressources(create_ressources());
	game->size[X] = WIDTH;
	game->size[Y] = HEIGHT;
	game->win = sfRenderWindow_create(mode, NAME, sfResize | sfClose , NULL);
	sfRenderWindow_setFramerateLimit(game->win, MAX_FPS);
	sfRenderWindow_setVerticalSyncEnabled(game->win, sfTrue);
	game->delta_time = 1.0 / MAX_FPS;
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
