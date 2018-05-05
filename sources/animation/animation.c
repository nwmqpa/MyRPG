/*
** EPITECH PROJECT, 2017
** anim.c
** File description:
** anim source file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "anim.h"

anim_t
*create_anim_rect(sfTexture *tex, int count , float speed, sfIntRect size)
{
	anim_t *anim = malloc(sizeof(anim_t));
	sfIntRect rect = {.top = 0};

	anim->tex = tex;
	anim->count = count;
	anim->speed = speed;
	anim->sprite = malloc(sizeof(sfSprite *) * count);
	anim->size = size.width;
	anim->frame = 0;
	anim->time = 0.f;
	for (int i = 0 ; i < count; i++){
		rect.left = (i * size.width);
		rect.width = size.width;
		rect.height = size.height;
		(anim->sprite)[i] = sfSprite_create();
		sfSprite_setTexture((anim->sprite)[i], anim->tex, sfTrue);
		sfSprite_setTextureRect((anim->sprite)[i], rect);
	}
	return (anim);
}

anim_t *create_anim(sfTexture *tex, int count , float speed, int size)
{
	anim_t *anim = malloc(sizeof(anim_t));
	sfIntRect rect = {.top = 0};

	anim->tex = tex;
	anim->count = count;
	anim->speed = speed;
	anim->sprite = malloc(sizeof(sfSprite*) * count);
	anim->size = size;
	anim->frame = 0;
	anim->time = 0.f;
	for (int i = 0 ; i < count; i++){
		rect.left = (i * size);
		rect.width = size;
		rect.height = size;
		(anim->sprite)[i] = sfSprite_create();
		sfSprite_setTexture((anim->sprite)[i], \
				anim->tex, sfTrue);
		sfSprite_setTextureRect((anim->sprite)[i], rect);
	}
	return (anim);
}

sfSprite 
*animate(sfRenderWindow *window, anim_t *anim, float delta_time)
{
	anim->time += (1 * delta_time);
	if (anim->time >= anim->speed) {
		anim->time = 0.f;
		if (anim->frame < anim->count - 1) {
			(anim->frame)++;
		} else
			(anim->frame) = 0;
	}
	sfRenderWindow_drawSprite(window, (anim->sprite)[anim->frame], NULL);
	return ((anim->sprite)[anim->frame]);
}

anim_t 
*create_anim_path_rect(const char *path, int cnt, float speed, sfIntRect rect)
{
	sfTexture *tex = sfTexture_createFromFile(path, NULL);
	anim_t *anim = create_anim_rect(tex, cnt, speed, rect);

	return (anim);
}

anim_t *create_anim_path(const char *path, int cnt, float speed, int size)
{
	sfTexture *tex = sfTexture_createFromFile(path, NULL);
	anim_t *anim = create_anim(tex, cnt, speed, size);

	return (anim);
}

#ifdef ANIMATION_COMPILE_
int main(void)
{
	sfRenderWindow *win = sfRenderWindow_create(
			(sfVideoMode){1920, 1080, 32}, "Test", sfResize, NULL);
	sfRenderWindow_setFramerateLimit(win, 60);
	
	anim_t *idle = create_anim_path_rect(
	"../../assets/textures/Player/PlayerIdleAnim.png",
	4, 0.1, (sfIntRect){0, 0, 100, 200});

	anim_t *running = create_anim_path_rect(
	"../../assets/textures/Player/PlayerRunningLeft.png",
	4, 0.05, (sfIntRect){0, 0, 100, 200});

	anim_t *lifes = create_anim_path(
	"../../assets/UI/LifesAnimation.png",
	2, 0.15, 100);
	
	anim_set_position(running, (sfVector2f){0, 400});
	anim_set_position(lifes, (sfVector2f){0, 400});

	while (1) {
		sfRenderWindow_clear(win, sfWhite);
		animate(win, idle,  0.016);
		animate(win, running, 0.016);
		
		if (sfSprite_getPosition(running->sprite[0]).x - 5 < -100)
			anim_set_position(running, (sfVector2f){1000, 200});
		anim_move(running, (sfVector2f){-5, 0});

		animate(win, lifes, 0.016);
		sfRenderWindow_display(win);
	}
	return (0);
}
#endif /* ANIMATION_COMPILE_ */
