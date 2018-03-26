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

/* typedef particle */
typedef struct particle_s {
	sfVector2f velocity;
	sfVector2f position;
	sfSprite   *sprite;
	float	   life_time;
} particle_t;

/*
** Particle system:
**	Particle drawer system
*/ 
typedef struct particle_system_s {
	sfTexture    *texture;
	particle_t   *particles;
	unsigned int nb_elem;
	sfVector2f   point;
	float	     global_life_time;
	float	     dispersion;
	float	     speed;
	bool	     is_light;
	bool	     is_infinite;
	bool	     is_gravity;
} particle_system_t;

sfVector2f random_vector2f(void);
void particle_system_draw(particle_system_t *particle_sys, sfRenderWindow *win);
particle_system_t *particle_system_create(
        sfTexture *texture, int nb_elem, int is_gravity, float speed);
void set_particle_dispertion(particle_system_t *particle, float dispertion);
void set_particle_light(particle_system_t *particle, _Bool is_light);
void set_particle_infinite(particle_system_t *particle, int is_infinite);

//TODO: Make this shit
//typedef struct animated_particle_system_s {
//	animation_t  animation;
//	unsigned int dispersion;
//	unsigned int speed;
//	unsigned int nb_elem;
//	_Bool	     is_light;
//	_Bool	     is_gravity;
//} animated_particle_system_t;


#endif /* PARTICLE_H_ */
