#include "struct.h"

/**
 * Inizializace objektu. Nazev objektu kopiruje. Objekt bude mit nazev
 * roven NULL, pokud se inicializace nezdarila.
 */
Object object_ctor(int id, char *name)
{
	/// inicializace nove promenne pro objekt
	Object o;

	/// ulozeni id
	o.id = id;

	/// pokud neni predane jmeno NULL
	if (name != NULL)
	{
		/// alokace pameti (funkce malloc)
		o.name = malloc((strlen(name)+1)*sizeof(char));

		/// pokud alokace probehla uspesne, zkopirujeme jmeno do objektu
		if (o.name != NULL)
			strcpy(o.name, name);
	}
	else /// jinak vlozime ukazatel do objektu (v tomto pripade to bude asi NULL)
	{
		o.name = name;
	}

	/// vracime nove vytvoreny objekt
	return o;
}

/**
 * Zamena dat dvou objektu.
 */
void object_swap(Object *i1, Object *i2)
{
	/// vymeni data dvou objektu (je potreba pomocny objekt)
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
	/// objekt dst pripravime pomoci konstruktoru
	*dst = object_ctor(src->id, src->name);

	/// pokud se alokace povedla, vratime dst, jinak NULL
	if (dst->name != NULL)
		return dst;
	else
		return NULL;

}

/**
 * Uvolni objekt (resp. jeho jmeno) z pameti.
 */
void object_dtor(Object *o)
{
	/// uvolnime alokovanou pamet pro retezec (funkce free)
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

