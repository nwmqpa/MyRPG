/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for all things
*/

#include <unistd.h>
#include "time.h"
#include "cybend2200.h"
#include "utils.h"
#include "ress_manager.h"
#include "assets_manager.h"
#include "map_parser.h"
#include "ui.h"

static game_t *init_game(void)
{
	game_t *game = my_calloc(sizeof(game_t));
	sfVideoMode mode = {WIDTH, HEIGHT, 32};

	get_assets(create_assets());
	get_ressources(create_ressources());
	get_map_mgr(map_create_manager("assets/maps"));
	parse_maps(get_map_mgr(0x0));
	map_all_graph_init(get_map_mgr(0x0));
	game->size[X] = WIDTH;
	game->size[Y] = HEIGHT;
	game->win = sfRenderWindow_create(mode, NAME, sfResize | sfClose , NULL);
	sfRenderWindow_setFramerateLimit(game->win, MAX_FPS);
	sfRenderWindow_setVerticalSyncEnabled(game->win, sfTrue);
	game->delta_time = 1.0 / MAX_FPS;
	game->gamemode = GAME;
	game->popup = popup_create("Error", 2);
	game->dialog = dialog_create("error");
	return (game);
}

int main(void)
{
	game_t *game = init_game();

	if (!game) {
		write(2, "Error while loading the game try to reclone\n", 44);
		return (84);
	}
	game->actual_map = get_hash_elem(get_map_mgr(NULL)->maps, MAPS[CITY]);
	my_rpg(game);
	sfRenderWindow_destroy(game->win);
	return (0);
}
