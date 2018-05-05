/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event source file
*/

#include "event.h"

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
		case sfEvtMouseMoved:
			//TODO: Make that
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
			//TODO: Make that
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
		case sfEvtMouseMoved:
			//TODO: Make that
			break;
		default:
			break;
		}
	}
	return (0);
}