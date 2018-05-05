/*
** EPITECH PROJECT, 2017
** my_rpg.c
** File description:
** my rpg main file
*/

#include <SFML/Graphics.h>
#include "cybend2200.h"
#include "event.h"

int update_game(game_t *game)
{
	switch (game->gamemode) {
	case MENU:
		menu_event(game);
		draw_menu(game);
		break;
	case GAME:
		game_event(game);
		draw_game(game);
		break;
	case COMBAT:
		fight_event(game);
		draw_combat(game);
		break;
	case DIALOG:
		draw_dialog(game);
		break;
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