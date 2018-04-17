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

/*
** Create a basic particles set
*/
part_sys_t 
*part_sys_create(sfTexture *texture, int nb_elem, int is_gravity, float speed)
{
	part_sys_t *particle = malloc(sizeof(part_sys_t));

	particle->texture    = texture;
	particle->speed      = speed;
	particle->is_gravity = is_gravity;
	particle->nb_elem    = nb_elem;
	particle->dispersion = 100;
	particle->is_light   = false;
	particle->global_life_time = 4;
	particle->sprite     = sfSprite_create();
	sfSprite_setTexture(particle->sprite, texture, sfTrue);
	particle->particles  = malloc(sizeof(particle_t) * (nb_elem + 1));
	particle->point      = (sfVector2f){400, 400};
	for (int i = 0; i < nb_elem; ++i) {
		particle->particles[i].velocity  = random_vector2f(particle->speed, particle->dispersion);
		particle->particles[i].life_time = (float)rand()/(float)(RAND_MAX/4);
	}
	return (particle);
}
