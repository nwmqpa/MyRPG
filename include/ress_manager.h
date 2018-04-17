/*
** EPITECH PROJECT, 2017
** ressources_manager.h
** File description:
** ressource manager file
*/

#ifndef RESS_MANAGER_H_
#define RESS_MANAGER_H_

/*
** Assets Manager:
**	Represent one instance of all the ressources
**	of the game currently load.
*/
typedef struct {
	//TODO Add ress attribute it 
} ress_mng_t;

ress_mng_t *create_ress_mng(char *path_to_ress);
ress_mng_t *get_ress_mng(ress_mng_t *ress);

#endif /* RESSOURCES_MANAGER_H */
