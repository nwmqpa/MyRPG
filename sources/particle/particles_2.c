/*
** EPITECH PROJECT, 2017
** particles_2.c
** File description:
** particle file part 2
*/

#include "particle.h"

particles *create_particles(size_t size, sfColor color, bool inf, bool grav)
{
	particles *system = malloc(sizeof(particles));

	system->vertex    = malloc(sizeof(sfVertex) * size * 4);
	system->speed     = malloc(sizeof(sfVector2f) * size);
	system->color	  = color;
	system->size      = size;
	system->lifes     = malloc(sizeof(float) * size);
	system->life_time = 1;
	system->infinite  = inf;
	system->gravity   = (grav) ? GRAVITY : -GRAVITY;
	system->pos	  = (sfVector2f){0, 0};
	system->size_part = 5;
	for (unsigned int i = 0; i < system->size; ++i) {
		set_particles(system, rand_angle(30), 8, i);
		system->speed[i] = rand_vector(10);
		system->lifes[i] = (float)rand() /
			(float)(RAND_MAX/system->life_time);
	}
	return (system);
}
