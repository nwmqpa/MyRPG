/*
** EPITECH PROJECT, 2017
** animation.c
** File description:
** animation source file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "animation.h"

Animation_t *create_anim_path(const char *path, int cnt, float speed, int size)
{
	sfTexture *tex = sfTexture_createFromFile(path, NULL);
	Animation_t *anim = create_animation(tex, cnt, speed, size);

	return (anim);
}

Animation_t *create_animation(sfTexture *tex, int count , float speed, int size)
{
	Animation_t *animation = malloc(sizeof(Animation_t));
	sfIntRect rect = {.top = 0};

	animation->tex = tex;
	animation->count = count;
	animation->speed = speed;
	animation->sprite = malloc(sizeof(sfSprite*) * count);
	animation->size = size;
	animation->frame = 0;
	animation->time = 0.f;
	for (int i = 0 ; i < count; i++){
		rect.left = (i * size);
		rect.width = size;
		rect.height = size;
		(animation->sprite)[i] = sfSprite_create();
		sfSprite_setTexture((animation->sprite)[i], \
				animation->tex, sfTrue);
		sfSprite_setTextureRect((animation->sprite)[i], rect);
	}
	return (animation);
}

sfSprite *animate(sfRenderWindow *window, animation_t *animation,\
		float delta_time)
{
	animation->time += (1 * delta_time);
	if (animation->time >= animation->speed) {
		animation->time = 0.f;
		if (animation->frame < animation->count - 1) {
			(animation->frame)++;
		} else
			(animation->frame) = 0;
	}
	sfRenderWindow_drawSprite(window, \
			(animation->sprite)[animation->frame], NULL);
	return ((animation->sprite)[animation->frame]);
}
