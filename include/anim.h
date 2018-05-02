/*
** EPITECH PROJECT, 2017
** anim.h
** File description:
** header of anim file
*/

#include <SFML/Graphics.h>

#ifndef ANIMATION_H_
#define ANIMATION_H_

/*
** Animation:
** 	structure that represent a animation in the game
**	just give it a texture and how you want to cut it
**	and the speed
*/
typedef struct anim_s {
	sfTexture *tex;
	sfSprite **sprite;
	int count;
	int size;
	int frame;
	float time;
	float speed;
} anim_t;

/*
** Animate animation
** use it in a boucle when you want to draw
*/
sfSprite *anim(sfRenderWindow *window, anim_t *anim, float delta_time);
//Create anim from texture
anim_t *create_anim(sfTexture *tex, int count, float speed, int size);
//Create Animation from path of a file and some other things
anim_t *create_anim_path(const char *path, int count , float speed, int size);
//Set position of all sprites of the anim
void anim_set_position(anim_t *anim, sfVector2f factor);
//Move the anim
void anim_move(anim_t *anim, sfVector2f factor);
//Scale the anim 
void anim_scale(anim_t *anim, sfVector2f factor);

#endif /* ANIMATION_H_ */
