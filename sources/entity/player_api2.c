/*
** EPITECH PROJECT, 2017
** player_api2.c
** File description:
** Player api file 2
*/

#include "utils.h"
#include "map_parser.h"
#include "assets_manager.h"
#include "entities.h"

int pp_move(struct player *player, sfVector2f pos)
{
	sfSprite_move(player->n_idle, pos);
	for (int i = 0; i < NB_ANIM_N; ++i)
		anim_move(player->normal[i], pos);
	return 1;
}

int player_colliding(struct player *player, game_t *game)
{
	sfImage *collide = game->actual_map->collide;
	sfFloatRect hit = player->hitbox;
	int ret = 0;

	for (int x = 10; x < hit.width - 10; ++x) {
		if (sfImage_getPixel(collide, hit.left + x, hit.top).a > 0)
			ret |= DOWN_L;
		if (sfImage_getPixel(
		collide, hit.left + x, hit.top + hit.height).a > 0)
			ret |= DOWN_R;
	}
	for (int y = 10; y < hit.height - 10; ++y) {
		if (sfImage_getPixel(
		collide, hit.left + hit.width, hit.top + y).a > 0)
			ret |= TOP_R;
		if (sfImage_getPixel(collide, hit.left, hit.top + y).a > 0)
			ret |= TOP_L;
	}
	return (ret);
}

int move_game(struct player *player, int dir)
{
	double dtime = get_dtime(-1);

	switch (dir) {
	case LEFT:
		player->vec.x = -SPEED * dtime;
		break;
	case RIGHT:
		player->vec.x = SPEED * dtime;
		break;
	default:
		break;
	}
	return (0);
}

int move_fight(struct player *player, int dir)
{
	switch (dir) {
	case LEFT:
		anim_move(player->actual, (sfVector2f){
		player->vec.x * SPEED * get_dtime(-1), player->vec.y});
		break;
	case TOP:
		anim_move(player->actual, (sfVector2f){
		player->vec.x * -SPEED * get_dtime(-1), player->vec.y});
		break;
	case RIGHT:
		anim_move(player->actual, (sfVector2f){SPEED, 0});
		break;
	case DOWN:
		anim_move(player->actual, (sfVector2f){0, SPEED});
		break;
	default:
		break;
	}
	return (0);
}
