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

#ifndef DEBUG_MODE
int main(int argc, char *argv[])
{
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *win = sfRenderWindow_create(mode, "Test", sfResize | sfFullscreen, NULL);
	part_sys_t *particles;
	sfTexture *texture;
	sfRenderWindow_setFramerateLimit(win, 30);
	sfEvent event;
	bool active = true;

	srandom((long) texture);
	texture = sfTexture_createFromFile("../../../assets/test_2.png", NULL);
	particles = part_sys_create(texture, 20000, false, 3);
	particles->dispersion = 25;
	particles->is_infinite = true;
	while (sfRenderWindow_isOpen(win)) {
		while (sfRenderWindow_pollEvent(win, &event)) {
			if (event.type == sfEvtMouseMoved) {
				particles->point = 
				(sfVector2f){event.mouseMove.x, event.mouseMove.y};
			}
		}
		sfRenderWindow_clear(win, sfBlack);
		part_sys_draw(particles, win);
		sfRenderWindow_display(win);
	}
	return (0);
}
#endif /* DEBUG_MODE */
