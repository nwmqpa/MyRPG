/*
** EPITECH PROJECT, 2017
** particle_draw.c
** File description:
** particle system drawer
*/

#include <SFML/Graphics.h>
#include "particle.h"

/*
** Particle system drawer:
**	Should draw each particle and update there position and
**	velocity at each cycle in time.
*/
void particle_system_draw(particle_system_t *particle_sys, sfRenderWindow *win)
{
	int x = 0;
	int y = 0;
	particle_t *particle;

	for (int i = 0; i < particle_sys->nb_elem; ++i) {
		particle = &particle_sys->particles[i];
		if (particle->life_time >= particle_sys->global_life_time) {
			particle->life_time = 0;
			particle->position  = particle_sys->point;
			particle->velocity  = random_vector2f();
			continue;
		}
		sfRenderWindow_drawSprite(win, particle->sprite, NULL);
		x = particle->position.x += particle->velocity.x;
		y = particle->position.y += particle->velocity.y;
		particle->velocity.y	 += (particle_sys->is_gravity) ? GRAVITY * 0.06 : 0;
		sfSprite_setPosition(particle_sys->particles[i].sprite, (sfVector2f){x, y});
		(particle->life_time) += 0.03;
	}
}
