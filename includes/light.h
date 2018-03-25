/*
** EPITECH PROJECT, 2017
** light.h
** File description:
** header for lightning system
*/

#ifndef LIGHT
#define LIGHT

/*
** Light: Structure that represent the basic light point
** by it's intensity and ...
*/
typedef struct light_point_s {
	int n_raycast;
	int intensity;
	int hash_name;
} light_point_t;

/*
** Light Manager: Structure that will contain all 
** light points and will draw them in the order.
*/
typedef struct light_manager_t {
	light_point_t **light_array;
} light_manager_s;

#endif /* LIGHT */
