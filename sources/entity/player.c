/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include "entities.h"

void draw_player(sfRenderWindow *win, struct player *player)
{
	if (player->actual)
		animate(win, player->actual, 0.016);
}

int move_game(struct player *player, int dir)
{
	switch (dir) {
	case LEFT:
		player->actual = player->normal[N_LEFT];
		player_move_assets(player, (sfVector2f){-SPEED, 0});
		break;
	case RIGHT:
		player->actual = player->normal[N_RIGHT];
		player_move_assets(player, (sfVector2f){SPEED, 0});
		break;
	default:
		player->actual = player->normal[N_IDLE];
	}
	return (0);
}

int move_fight(struct player *player, int dir)
{
	switch (dir) {
	case LEFT:
		anim_move(player->actual, (sfVector2f){-SPEED, 0});
		break;
	case TOP:
		anim_move(player->actual, (sfVector2f){0, -SPEED});
		break;
	case RIGHT:
		anim_move(player->actual, (sfVector2f){SPEED, 0});
		break;
	case DOWN:
		anim_move(player->actual, (sfVector2f){0, SPEED});
		break;
	default:
		player->actual = player->normal[F_IDLE];
	}
	return (0);
}