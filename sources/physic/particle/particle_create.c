/*
** EPITECH PROJECT, 2017
** particle_create.c
** File description:
** particle enitity creation
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "particle.h"

particle_system_t *particle_system_create(
	sfTexture *texture, int nb_elem, int is_gravity, float speed)
{
	particle_system_t *particle = malloc(sizeof(particle_system_t));

	particle->texture    = texture;
	particle->speed      = speed;
	particle->is_gravity = is_gravity;
	particle->nb_elem    = nb_elem;
	particle->dispersion = 0.5f;
	particle->is_light   = false;
	particle->particles  = malloc(sizeof(particle_t *) * (nb_elem + 1));
	particle->vectors    = malloc(sizeof(particle_t *) * (nb_elem + 1));
	for (int i = 0; i < nb_elem; ++i) {
		particle->particles[i] = sfSprite_create();
		sfSprite_setTexture(particle->particles[i], texture, sfTrue);
		particle->vectors[i] = random_vector2f();
	}
	return (particle);
}

void set_particle_dispertion(particle_system_t *particle, float dispertion)
{
	particle->dispersion = dispertion;
}

void set_particle_infinite(particle_system_t *particle, int is_infinite)
{
	particle->is_infinite = (bool) is_infinite;
}

void set_particle_light(particle_system_t *particle, _Bool is_light)
{
	particle->is_light = is_light;
}
