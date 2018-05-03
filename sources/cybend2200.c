/*
** EPITECH PROJECT, 2017
** my_rpg.c
** File description:
** my rpg main file
*/

#include <SFML/Graphics.h>
#include "cybend2200.h"

int update_game(game_t *game)
{
	switch (game->scene) {
	case MENU:
		draw_menu(game);
	case GAME:
		draw_game(game);
	case COMBAT:
		draw_combat(game);
	}
	return (0);
}

int game_loop(game_t *game)
{
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		update_game(game);
		sfRenderWindow_display(game->win);
	}
	return (0);
}

int my_rpg(game_t *game)
{
	game_loop(game);
	return (0);
}