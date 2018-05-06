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

void player_move_assets(struct player *player, sfVector2f pos)
{
	sfSprite_move(player->n_idle, pos);
	for (int i = 0; i < 5; ++i)
		if (player->normal[i])
			anim_move(player->normal[i], pos);
}

static int move_game(struct player *player, int dir)
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

static int move_fight(struct player *player, int dir)
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

int player_move(game_t *game, struct player *player, int dir)
{
	if (game->gamemode == GAME) {
		player->actual = player->normal[N_IDLE];
		move_game(player, dir);
	} else if (game->gamemode == FIGHT) {
		player->actual = player->fight[F_IDLE];
		move_fight(player, dir);
	}
	return (0);
}