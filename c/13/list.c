#include "list.h"
#include "object.h"

/**
 * Inicializace seznamu. Vytvoří prázdný seznam.
 */
List list_ctor() 
{
	List list = {
		.first = NULL,
	};

	return list;
}
 
/**
 * Inicializace položky seznamu. Z objektu vytvoří položku bez následníka.
 */
Item item_ctor(Object data) 
{
	Item item = {
		.data = data,
		.next = NULL,
	};

	return item;
}
 
/**
 * Uvolnění seznamu.
 */
void list_dtor(List *list) 
{
	for (Item *item = list->first; item != NULL; item = item->next) {
		object_dtor(&item->data);
	}	
}
 
/**
 * Vloží položku na začátek seznamu.
 */
void list_insert_first(List *list, Item *i) 
{
	i->next = list->first;
	list->first = i;

}
 
/**
 * Vrátí počet položek seznamu.
 */
unsigned list_count(List *list) 
{
	unsigned count = 0;
	for (Item *item = list->first; item != NULL; item = item->next) {
		count++;
	}

	return count;
}
 
/**
 * Vrátí true, pokud je seznam prázdný.
 */
bool list_empty(List *list) 
{
	if (list->first == NULL) {
		return true;
	}    

	return false;
}
 
/**
 * Najde položku seznamu s nejmenším identifikátorem. Vrací NULL, pokud je
 * seznam prázdný.
 */
Item *list_find_minid(List *list) 
{
	if (list_empty(list)) {
		return NULL;
	}

	Item *item = list->first;
	Item *min_id_item = item;
	for (item = item->next; item != NULL; item = item->next) {
		if (item->data.id < min_id_item->data.id) {
			min_id_item = item;
		}
	}

	return min_id_item;
}
 
/**
 * Najde položku seznamu s odpovídajícím jménem objektu. Vrací NULL, pokud
 * taková položka v seznamu není, nebo pokud je seznam prazdny.
 */
Item *list_find_name(List *list, char *name) 
{
	for (Item *item = list->first; item != NULL; item = item->next) {
		if (strcmp(item->data.name, name) == 0) {
			return item;
		}
	}

	return NULL;
}

/**
 * Vytiskne všechny položky seznamu list.
 */
void print_list(List* list) 
{
	for (Item *item = list->first; item != NULL; item = item->next) {
		print_obj(&item->data);	
	}
}

