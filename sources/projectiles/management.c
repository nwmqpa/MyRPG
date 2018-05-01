/*
** EPITECH PROJECT, 2017
** sources/projectiles/management.c
** File description:
** Management for projectiles.
*/

#include "projectiles.h"

struct vector proj_compute_pos(struct projectile *proj, float t)
{
	struct vector base_pos = proj->base_pos;
	struct vector cur_pos = proj->fire_pos;
	struct vector delta = {cur_pos.x - base_pos.x, cur_pos.y - base_pos.y};

	delta.x *= proj->speed * t;
	delta.y *= proj->speed * t;
	return (delta);
}

struct vector proj_compute_delta(struct projectile *proj, float delta)
{
	struct vector vec1 = proj_compute_pos(proj, 0.0f);
	struct vector vec2 = proj_compute_pos(proj, delta);

	return ((struct vector) {vec2.x - vec1.x, vec2.y - vec1.y});
}