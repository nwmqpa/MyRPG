/*
** EPITECH PROJECT, 2017
** my_rpg.c
** File description:
** my rpg main file
*/

#include <SFML/Graphics.h>
#include "cybend2200.h"
#include "ui.h"
#include "event.h"
#include "utils.h"
#include <stdio.h>

int update_game(game_t *game)
{
	switch (game->gamemode) {
	case MENU:
		menu_event(game);
		draw_menu(game);
		break;
	case GAME:
		(!game->ui[DIALOG_UI]) ? game_event(game) : dialog_event(game);
		draw_game(game);
		break;
	case FIGHT:
		fight_event(game);
		draw_combat(game);
		break;
	}
	return (0);
}

int game_loop(game_t *game)
{
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->win)) {
		double a = sfClock_getElapsedTime(clock).microseconds / 100000;
		sfClock_restart(clock);
		get_dtime(a);
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