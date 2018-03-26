/*
** EPITECH PROJECT, 2017
** graphical_test.c
** File description:
** graphic main test
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include "particle.h"

int main(int argc, char *argv[])
{
	sfVideoMode mode = {1600, 900, 32};
	sfRenderWindow *win = sfRenderWindow_create(mode, "Test", sfResize, NULL);
	particle_system_t *particles;
	sfTexture *texture;
	sfRenderWindow_setFramerateLimit(win, 30);
	sfEvent event;
	bool active = true;

	srandom((long) texture);
	texture = sfTexture_createFromFile("../../../ressources/test.png", NULL);
	particles = particle_system_create(texture, 1000, true, 10);
	set_particle_infinite(particles, true);
	while (sfRenderWindow_isOpen(win)) {
		while (sfRenderWindow_pollEvent(win, &event)) {
			if (event.type == sfEvtMouseMoved) {
				particle_system_set_point();
			}
		}
		sfRenderWindow_clear(win, sfBlack);
		(active) ? particle_system_draw(particles, win) : 1;
		sfRenderWindow_display(win);
	}
	return (0);
}
