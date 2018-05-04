/*
** EPITECH PROJECT, 2017
** include/projectiles.h
** File description:
** Projectiles header.
*/

#ifndef PROJECTILES_H_
#define PROJECTILES_H_

#include "entities.h"
#include "structs.h"

#define GET_SPEED_FROM_LVL(speed_lvl) (4 * speed_lvl)

struct projectile {
	float speed;
	struct vector base_pos;
	struct vector fire_pos;
};

typedef struct projectile proj_t;

struct vector proj_compute_pos(struct projectile *proj, float time);
struct vector proj_compute_delta(struct projectile *proj, float delta);
struct projectile *proj_create(struct entity *entity, struct vector cur_pos);
void proj_free(struct projectile **proj);

#endif /* PROJECTILES_H_ */