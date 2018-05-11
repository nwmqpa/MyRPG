/*
** EPITECH PROJECT, 2017
** my_rpg.c
** File description:
** my rpg main file
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "utils.h"
#include "assets_manager.h"
#include "cin_mng.h"
#include "cybend2200.h"
#include "ui.h"
#include "str_utils.h"
#include "event.h"

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
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		update_game(game);
		sfRenderWindow_display(game->win);
	}
	return (0);
}

int my_rpg(game_t *game)
{
	char *cine = string_from_file("ressources/cinematique/intro.txt");
	char *dial = string_from_file("ressources/dialog/wake.txt");
	cin_t *cin = cin_create(20, cine, get_assets(0x0)->fonts[THORN], sfWhite);

	free(cine);
	cin_play(game->win, cin);
	cin_free(cin);
	dialog_launch(game, game->dialog, dial);
	free(dial);
	game_loop(game);
	return (0);
}