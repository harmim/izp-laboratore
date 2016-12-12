#ifndef LIST_H
#define LIST_H

#include<limits.h>
#include<stdbool.h>

#include "object.h"

typedef struct item Item;
struct item {
  Object data;
  Item *next;
};
 
typedef struct {
  Item *first;
} List;
 
/**
 * Inicializace seznamu. Vytvoří prázdný seznam.
 */
List list_ctor();
 
/**
 * Inicializace položky seznamu. Z objektu vytvoří položku bez následníka.
 */
Item item_ctor(Object data);
 
/**
 * Uvolnění seznamu.
 */
void list_dtor(List *list);
 
/**
 * Vloží položku na začátek seznamu.
 */
void list_insert_first(List *list, Item *i);
 
/**
 * Vrátí počet položek seznamu.
 */
unsigned list_count(List *list);
 
/**
 * Vrátí true, pokud je seznam prázdný.
 */
bool list_empty(List *list);
 
/**
 * Najde položku seznamu s nejmenším identifikátorem. Vrací NULL, pokud je
 * seznam prázdný.
 */
Item *list_find_minid(List *list);
 
/**
 * Najde položku seznamu s odpovídajícím jménem objektu. Vrací NULL, pokud
 * taková položka v seznamu není.
 */
Item *list_find_name(List *list, char *name);

void print_list(List* list);

#endif // LIST_H

