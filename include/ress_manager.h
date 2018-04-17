/*
** EPITECH PROJECT, 2017
** ressources_manager.h
** File description:
** ressource manager file
*/

#ifndef ASSETS_MANAGER_H_
#define ASSETS_MANAGER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "anim.h"

enum sprite {
	NAME_1,
	NAME_2
};

enum sound {
	NAME_1,
	NAME_2
};

enum music {
	NAME_1,
	NAME_2
};

enum animation {
	NAME_1,
	NAME_2
};

/*
** Assets Manager:
**	Represent one instance of all the ressources
**	of the game currently load.
*/
typedef struct {
	//TODO Add ress attribute it 
} ress_mng_t;

ressources_mng_t *create_ress_mng(char *path_to_ress);
ressources_mng_t *get_ress_mng(void);

#endif /* RESSOURCES_MANAGER_H */
