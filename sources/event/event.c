/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include "event.h"
#include "ui.h"
#include "ress_manager.h"

int fight_event(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->win, &game->event)) {
		switch (game->event.type) {
		case sfEvtClosed:
			sfRenderWindow_close(game->win);
			break;
		case sfEvtKeyPressed:
			fight_key(game);
			break;
		default:
			break;
		}
	}
	return (0);
}

int dialog_event(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->win, &game->event)) {
		switch (game->event.type) {
		case sfEvtClosed:
			sfRenderWindow_close(game->win);
			break;
		case sfEvtKeyPressed:
			next_dialog(game, game->dialog);
			break;
		default:
			break;
		}
	}
	return (0);
}

int menu_event(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->win, &game->event)) {
		switch (game->event.type) {
		case sfEvtClosed:
			sfRenderWindow_close(game->win);
			break;
		case sfEvtKeyPressed:
			menu_key(game);
			break;
		case sfEvtMouseMoved:
			game->handed_pos = (sfVector2f)
			{game->event.mouseMove.x, game->event.mouseMove.y};
			get_ressources(NULL)->particles->pos = game->handed_pos;
			break;
		case sfEvtMouseButtonPressed:
			menu_mouse_but(game);
			break;
		default:
			break;
		}
	}
	return (0);
}

int game_event(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->win, &game->event)) {
		switch (game->event.type) {
		case sfEvtClosed:
			sfRenderWindow_close(game->win);
			break;
		case sfEvtKeyPressed:
			game_key(game);
			break;
		case sfEvtKeyReleased:
			game_key_released(game);
			break;
		case sfEvtMouseMoved:
			break;
		default:
			break;
		}
	}
	return (0);
}
