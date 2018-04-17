/*
** EPITECH PROJECT, 2017
** particle_draw.c
** File description:
** particle system drawer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "particle.h"

static void set_new_position(part_sys_t *particle_sys, particle_t *particle)
{
	particle->position.x += particle->velocity.x * 
		particle_sys->speed * 0.3;
	particle->position.y += particle->velocity.y * 
		particle_sys->speed * 0.3;
	switch (particle_sys->is_gravity) {
	case true:
		particle->velocity.y += GRAVITY * 0.3;
		break;
	case false:
		particle->velocity.y -= GRAVITY * 0.3;
		break;
	}
	(particle->life_time) += 0.03;
}

/*
** Particle system drawer:
**	Should draw each particle and update there position and
**	velocity at each cycle in time.
*/
void part_sys_draw(part_sys_t *particle_sys, sfRenderWindow *win)
{
	particle_t *particle;

	for (unsigned int i = 0; i < particle_sys->nb_elem; ++i) {
		particle = &particle_sys->particles[i];
		if (particle->life_time >= particle_sys->global_life_time &&
		particle_sys->is_infinite) {
			particle->life_time = 0;
			particle->position  = particle_sys->point;
			particle->velocity  = 
				random_vector2f(particle_sys->speed, particle_sys->dispersion);
			continue;
		}
	sfSprite_setPosition(particle_sys->sprite, particle->position);
	sfRenderWindow_drawSprite(win, particle_sys->sprite, NULL);
	set_new_position(particle_sys, particle);
	}
}

void destroy_particle_sys(part_sys_t *particle)
{
	for (unsigned int i = 0; i < particle->nb_elem; ++i) {
		//free(particle->particles[i].sprite);
	}
	free(particle->particles);
}
