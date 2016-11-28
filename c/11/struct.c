#include "struct.h"

/**
 * Inizializace objektu. Nazev objektu kopiruje. Objekt bude mit nazev
 * roven NULL, pokud se inicializace nezdarila.
 */
Object object_ctor(int id, char *name)
{	
	Object o;
	o.id = id;
	o.name = malloc(strlen(name) + 1 * sizeof(char));	
	if (o.name == NULL) {
		fprintf(stderr, "Chyba alokace.\n");
		return o;
	}
	strcpy(o.name, name);

	return o;
}

/**
 * Zamena dat dvou objektu.
 */
void object_swap(Object *i1, Object *i2)
{
	Object tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

/**
 * Hluboka kopie objektu src na dst. Vraci dst, pokud se operace povedla,
 * jinak NULL.
 */
Object *item_cpy(Object *dst, Object *src)
{
	*dst = object_ctor(src->id, src->name);
	
	if (dst->name == NULL) {
		return NULL;
	}

	return dst;
}

/**
 * Uvolni objekt (resp. jeho jmeno) z pameti.
 */
void object_dtor(Object *o)
{
	free(o->name);	
}


/**
 * Pomocne funkce pro vypis objektu (ukazatel)
 */
void print_object(Object* o)
{
	printf("Id:\t %d\n", o->id);
	printf("Name:\t %s\n", o->name);
	printf("\n");
}

