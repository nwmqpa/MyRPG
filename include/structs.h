/*
** EPITECH PROJECT, 2017
** includes/structs.h
** File description:
** structures header
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef unsigned int uint32_t;
typedef struct elem elem_t;
typedef struct elem list_t;
typedef struct hash_elem hash_elem_t;
typedef struct hash_elem hashmap_t;
typedef struct vector vec_t;
typedef unsigned long int hash_t;

struct elem {
	struct elem *next;
	struct elem *prev;
	void *data;
};

struct hash_elem {
	struct hash_elem *next;
	struct hash_elem *prev;
	void *data;
	hash_t hash;
};

struct vector {
	unsigned int x;
	unsigned int y;
};

hash_t hash(const char *str);

/*
** chained list funcs. 
*/
int insert_elem(list_t *list, void *data);
int pop_elem(list_t *list, int index);
void *get_elem(list_t, int index);
int len_list(list_t *list);

/*
** hashmap funcs.
*/
int insert_hash_elem(hashmap_t *hashmap, const char *key, void *data);
int pop_hash_elem(hashmap_t *hashmap, const char *key);
void *get_hash_elem(hashmap_t *hashmap, const char *key);
int has_hash_elem(hashmap_t *hashmap, const char *key);

#endif /* STRUCTS_H_ */