/*
** EPITECH PROJECT, 2017
** particles.c
** File description:
** particle
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "particle.h"

sfVector2f rand_vector(int disp);

void reset_particles(particles *this, size_t i)
{
	this->vertex[i * 4 + 0].position = this->pos;
	this->vertex[i * 4 + 1].position =
	(sfVector2f){this->pos.x + this->size_part, this->pos.y};
	this->vertex[i * 4 + 2].position =
	(sfVector2f){this->pos.x + this->size_part,
			this->pos.y + this->size_part};
	this->vertex[i * 4 + 3].position =
	(sfVector2f){this->pos.x, this->pos.y + this->size_part};
	for (int x = 0; x < 4; ++x)
		this->speed[i] = rand_angle(360);
	this->lifes[i] = 0.0;
}

void draw_particles(particles *this, sfRenderWindow *win, sfRenderStates *state)
{
	sfRenderWindow_drawPrimitives(win,
		this->vertex, this->size, sfQuads, state);
}

static void delete_particle(particles *this, size_t i)
{
	for (int x = 0; x < 4; ++x)
		this->vertex[i * 4 + x].position = (sfVector2f){-2000, -2000};
}

void update_particles(particles *system, float delta_time)
{
	float speed_x;
	float speed_y;

	for (unsigned int i = 0; i < system->size; ++i) {
		speed_x = system->speed[i].x;
		speed_y = system->speed[i].y;
		if (system->lifes[i] < system->life_time) {
			for (int x = 0; x < 4; ++x) {
				system->vertex[i * 4 + x].position.x += speed_x;
				system->vertex[i * 4 + x].position.y += speed_y;
			}
			system->lifes[i] += delta_time;
			system->speed[i].y += system->gravity * delta_time * 5;
		} else if (system->infinite) {
			reset_particles(system, i);
		} else {
			delete_particle(system, i);
		}
	}
}

void set_particles(particles *this, sfVector2f speed, int size, size_t id)
{
	this->size_part = size;
	this->vertex[id * 4 + 0].position = this->pos;
	this->vertex[id * 4 + 1].position =
		(sfVector2f){this->pos.x + size, this->pos.y};
	this->vertex[id * 4 + 2].position =
		(sfVector2f){this->pos.x + size, this->pos.y + size};
	this->vertex[id * 4 + 3].position =
		(sfVector2f){this->pos.x , this->pos.y + size};
	this->speed[id] = speed;
	for (int x = 0; x < 4; ++x)
		this->vertex[id * 4 + x].color = this->color;
}
