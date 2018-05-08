/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include "entities.h"
#include "particle.h"
#include "assets_manager.h"

static void do_player_movement(struct player *player, game_t *game)
{
	for (int i = 0; i < 4; ++i) {
		if (player->action[i]) {
			player_move(game, player, movement[i]);
		}
	}
}

static void player_change_anim(struct player *player)
{
	if (player->vec.y != 0) {
		player->actual = player->normal[N_JUMP];
	} else if (player->vec.x > 0) {
		player->actual = player->normal[N_RIGHT];
		player->normal[N_JUMP]->frame = 0;
		if (sfSound_getStatus(get_assets(NULL)->sounds[FOOTSTEP]) 
		== sfStopped)
			sfSound_play(get_assets(NULL)->sounds[FOOTSTEP]);
	} else if (player->vec.x < 0) {
		player->actual = player->normal[N_LEFT];
		player->normal[N_JUMP]->frame = 0;
		if (sfSound_getStatus(get_assets(NULL)->sounds[FOOTSTEP]) 
		== sfStopped)
			sfSound_play(get_assets(NULL)->sounds[FOOTSTEP]);
	} else {
		player->actual = player->normal[N_IDLE];
		player->normal[N_JUMP]->frame = 0;
	}
}

static void player_move_pos(struct player *player)
{
	if (player->vec.x < 1 && player->vec.x > -1)
		player->vec.x = 0;
	if (player->vec.x > 0)
		player->vec.x -= 50 * 0.016;
	if (player->vec.x < 0)
		player->vec.x += 50 * 0.016;
	player->hitbox.left += player->vec.y;
	player->hitbox.top += player->vec.x;
}

void draw_player(game_t *game, sfRenderWindow *win, struct player *player)
{
	do_player_movement(player, game);
	player_move_assets(player, player->vec);
	player_change_anim(player);
	if (player->actual)
		animate(win, player->actual, 0.016);
	if (player->entity->pos.y < 1080 - (200 + 200 * 0.5)) {
		player->vec.y += GRAVITY * 0.016 * 10;
	} else if (player->entity->pos.y > 1080 - (200 * 200 * 0.5)){
		player_set_position(player, (sfVector2f){
		player->entity->pos.x, 1080 - (200 + 200 * 0.5)});
		player->vec.y = 0;
	}
	player_move_pos(player);
}

int move_game(struct player *player, int dir)
{
	switch (dir) {
	case LEFT:
		player->vec.x = -SPEED * 0.016;
		break;
	case RIGHT:
		player->vec.x = SPEED * 0.016;
		break;
	default:
		//player->actual = player->normal[N_IDLE];
		break;
	}
	return (0);
}

int move_fight(struct player *player, int dir)
{
	switch (dir) {
	case LEFT:
		anim_move(player->actual, 
		(sfVector2f){player->vec.x * SPEED * 0.016, player->vec.y});
		break;
	case TOP:
		anim_move(player->actual, 
		(sfVector2f){player->vec.x * -SPEED * 0.016, player->vec.y});
		break;
	case RIGHT:
		anim_move(player->actual, (sfVector2f){SPEED, 0});
		break;
	case DOWN:
		anim_move(player->actual, (sfVector2f){0, SPEED});
		break;
	default:
		//player->actual = player->normal[F_IDLE];
		break;
	}
	return (0);
}