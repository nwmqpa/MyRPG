/*
** EPITECH PROJECT, 2017
** update.c
** File description:
** update file for game
*/

#include "ui.h"

void next_dialog(game_t *game, struct dialog *dialog)
{
	dialog->count++;
	if (!dialog->string[dialog->count]) {
		dialog->count = 0;
		game->ui[DIALOG_UI] = 0;
	} else {
		sfText_setString(dialog->text, dialog->string[dialog->count]);
	}
}

int draw_ui(game_t *game)
{
	if (game->ui[POPUP_UI]) {
		draw_popup(game);
	} else {
		popup_reset(game->popup);
	}
	if (game->ui[DIALOG_UI]) {
		draw_dialog(game->win, game->dialog);
	}
	return (0);
}