/*
** EPITECH PROJECT, 2017
** particle.h
** File description:
** Particle system for my_rpg
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

#define GRAVITY 9.8

/* typedef particle velocity => direction | position => pos in 2D*/
typedef struct particle_s {
	sfVector2f velocity;
	sfVector2f position;
	float	   life_time;
} particle_t;

/*
** Particle system:
**	Particle drawer system
**	texture => texture use for all particle
**	point   => space position in 2 dimension of the source
**	is_light => //TODO
**	dispertion => the way particle are expanding 
**	is_infinite => if the particle when they are dead repop
**	global_life_time => life time of all particle
**	is_gravity => are they sensible to gravity or are they volatile
**	nb_elem => nomber of particles
**	speed => speed of the particle
**	sprite => the sprite use for the particle
*/ 
typedef struct particle_system_s {
	sfTexture    *texture;
	particle_t   *particles;
	unsigned int nb_elem;
	sfVector2f   point;
	float	     global_life_time;
	int	     dispersion;
	float	     speed;
	sfSprite     *sprite;
	bool	     is_light;
	bool	     is_infinite;
	bool	     is_gravity;
} part_sys_t;

//------------------NaN
sfVector2f random_vector2f(float speed, int dispertion);
//------------------Constuctor
part_sys_t 
*part_sys_create(sfTexture *texture, int nb_elem, int is_gravity, float speed);
//------------------Use this to draw the particle sys as sfSprite_draw();
void part_sys_draw(part_sys_t *particle_sys, sfRenderWindow *win);
#endif /* PARTICLE_H_ */
