/*
** EPITECH PROJECT, 2017
** name
** File description:
** as
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define HEIGHT 1080
#define WIDTH  1920

#define GRAVITY 9.8

#define RAD(x) ((x) * M_PI / 180)

typedef struct part_s {
	sfVertex *vertex;
	float *lifes;
	float life_time;
	sfColor color;
	sfVector2f *speed;
	sfVector2f pos;
	unsigned int size;
	int size_part;
	bool infinite;
	float gravity;
} particles;

void update_particles(particles *system, float delta_time);
sfVector2f rand_angle(int disp);
sfVector2f rand_vector(int disp);
particles *create_particles(size_t size, sfColor color, bool inf, bool grav);
void draw_particles(
particles *this, sfRenderWindow *win, sfRenderStates *shader);
void set_particles(particles *this, sfVector2f speed, int size, size_t id);
