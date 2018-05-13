/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include "map_parser.h"
#include "entities.h"

void player_move_assets(game_t *game, struct player *player, sfVector2f pos)
{
	sfSprite *spr = player->actual->sprite[0];
	struct layer *map = game->actual_map->layers->data;
	sfFloatRect rect = sfSprite_getGlobalBounds(spr);
	sfIntRect map_rect = sfSprite_getTextureRect(map->sprite);
	float act_pos = rect.left - game->delta_pos.x;

	if (act_pos < map_rect.width * 0.25 || act_pos > map_rect.width * 0.75) {
		player->entity->pos.x += pos.x;
		player->entity->pos.y += pos.y;
		sfSprite_move(player->n_idle, pos);
		for (int i = 0; i < NB_ANIM_N; ++i)
			anim_move(player->normal[i], pos);
	} else {
		game->delta_pos.x -= pos.x;
		player->entity->pos.y += pos.y;
		pos.x = 0;
		sfSprite_move(player->n_idle, pos);
		for (int i = 0; i < NB_ANIM_N; ++i)
			anim_move(player->normal[i], pos);
	}
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
	if (player->vec.y >= 0 && player->entity->pos.y + 200 * 0.5 >= 880)
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
