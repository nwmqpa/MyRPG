/*
** EPITECH PROJECT, 2017
** my_rpg.c
** File description:
** my rpg main file
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "event.h"
#include "entities.h"
#include "utils.h"
#include "assets_manager.h"
#include "ress_manager.h"
#include "cin_mng.h"
#include "cybend2200.h"
#include "ui.h"
#include "str_utils.h"
#include "utils.h"

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
		double a =
		sfClock_getElapsedTime(clock).microseconds / 1000000.0;
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
	char *dial = string_from_file("ressources/dialog/wake.txt");

	cin_play(game->win, get_ressources(0x0)->cinematiques[0]);
	dialog_launch(game, game->dialog, dial);
	free(dial);
	game_loop(game);
	return (0);
}
