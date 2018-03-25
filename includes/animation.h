/*
** EPITECH PROJECT, 2017
** animation.h
** File description:
** header of animation file
*/

#include <SFML/Graphics.h>

#ifndef ANIMATION_H_
#define ANIMATION_H_

typedef struct {
	sfTexture *tex;
	sfSprite **sprite;
	int count;
	int size;
	int frame;
	float time;
	float speed;
} animation_t;

void animation_scale(animation_t *animation, sfVector2f factor);
sfSprite *animate(sfRenderWindow *window,
	 animation_t *animation, float delta_time);
animation_t *create_animation(sfTexture *tex, int count,
	 float speed, int size);
animation_t *create_anim_path(const char *path,
	 int count , float speed, int size);
void animation_setPosition(animation_t *anim, sfVector2f factor);
void animation_move(animation_t *anim, sfVector2f factor);

#endif /* ANIMATION_H_ */
