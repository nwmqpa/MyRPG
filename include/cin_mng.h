/*
** EPITECH PROJECT, 2017
** cin_mng.h
** File description:
** manager
*/

#ifndef CIN_MNG_H_
#define CIN_MNG_H_

struct cinematique_s {
	float time;
	char *string;
	sfText *text;
	sfFont *font;
	int char_size;
	sfColor color;
	sfVector2f pos;
};

typedef struct cinematique_s cin_t;

cin_t *cin_create(float time, char *string, sfFont *font, sfColor color);
void cin_update(sfRenderWindow *win, cin_t *cin);
void cin_reset(cin_t *cin);

#endif /* CIN_MNG_H_ */
