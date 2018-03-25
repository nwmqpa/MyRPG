/*
** EPITECH PROJECT, 2017
** particle_draw.c
** File description:
** particle system drawer
*/

#include <SFML/Graphics.h>
#include "particle.h"

void particle_update(particle_t *particle, float speed)
{
	//sfSprite_move(particle, (sfVector2f){speed, gravity * speed)});
}

void particle_system_draw(particle_system_t *particle_sys, sfRenderWindow *win)
{

	for (int i = 0; i < particle_sys->nb_elem; ++i) {
		sfRenderWindow_drawSprite(win, particle_sys->particles[i], NULL);
		sfSprite_move(particle_sys->particles[i], (sfVector2f) \
			{particle_sys->speed * particle_sys->vectors[i].x \
			, ((particle_sys->is_gravity) ? GRAVITY : 1) *	  \
			particle_sys->speed * particle_sys->vectors[i].y});
	}
}
