/*
** EPITECH PROJECT, 2017
** update.c
** File description:
** update file for game
*/

#include "ui.h"

int draw_ui(game_t *game)
{
	if (game->ui[POPUP_UI]) {
		draw_popup(game);
	} else {
		popup_reset(game->popup);
	}
	if (game->ui[DIALOG_UI]) {
		draw_dialog(game);
	}
}