/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include "entities.h"
#include "particle.h"

void draw_player(sfRenderWindow *win, struct player *player)
{
	player_move_assets(player, player->vec);
	if (player->vec.x > 0)
		player->actual = player->normal[N_RIGHT];
	else if (player->vec.x < 0)
		player->actual = player->normal[N_LEFT];
	else
		player->actual = player->normal[N_IDLE];
	if (player->actual)
		animate(win, player->actual, 0.016);
	
	if (player->entity->pos.y < 1080 - (200 + 200 * 0.5)) {
		player->vec.y += GRAVITY * 0.016 * 10;
	} else if (player->entity->pos.y > 1080 - (200 * 200 * 0.5)){
		player_set_position(player, (sfVector2f){
		player->entity->pos.x, 1080 - (200 + 200 * 0.5)});
		player->vec.y = 0;
	}
	if (player->vec.x < 0.5 && player->vec.x > -0.5) {
		player->vec.x = 0;
	} if (player->vec.x > 0) {
		player->vec.x -= 20 * 0.016;
	} if (player->vec.x < 0) {
		player->vec.x += 20 * 0.016;
	}
}

int move_game(struct player *player, int dir)
{
	switch (dir) {
	case LEFT:
		//player->actual = player->normal[N_LEFT];
		player->vec.x = -SPEED * 0.016;
		//player->entity->pos = (struct vector) {
		//player->entity->pos.x * -SPEED * 0.016, player->entity->pos.y};
		break;
	case RIGHT:
		//player->actual = player->normal[N_RIGHT];
		player->vec.x = SPEED * 0.016;
		//player->entity->pos = (struct vector) {
		//player->entity->pos.x * SPEED * 0.016, player->entity->pos.y};
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
		player->actual = player->normal[F_IDLE];
	}
	return (0);
}