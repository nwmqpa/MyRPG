/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include "entities.h"

void player_move_assets(struct player *player, sfVector2f pos)
{
	player->entity->pos.x += pos.x;
	player->entity->pos.y += pos.y;
	sfSprite_move(player->n_idle, pos);
	for (int i = 0; i < NB_ANIM_N; ++i)
		anim_move(player->normal[i], pos);
}

int player_set_position(struct player *player, sfVector2f pos)
{
	player->entity->pos.x = pos.x;
	player->entity->pos.y = pos.y;
	sfSprite_setPosition(player->n_idle, pos);
	for (int i = 0; i < NB_ANIM_N; ++i)
		anim_set_position(player->normal[i], pos);
	return (0);
}

int player_jump(struct player *player)
{
	if (player->vec.y == 0)
		player->vec.y = -15;
	return (0);
}

int player_scale(struct player *player, sfVector2f scale)
{
	sfSprite_scale(player->n_idle, scale);
	for (int i = 0; i < NB_ANIM_N; ++i)
		anim_scale(player->normal[i], scale);
	return (0);
}

int player_move(game_t *game, struct player *player, int dir)
{
	if (game->gamemode == GAME) {
		move_game(player, dir);
	} else if (game->gamemode == FIGHT) {
		move_fight(player, dir);
	}
	return (0);
}