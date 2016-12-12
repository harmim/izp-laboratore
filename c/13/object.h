#ifndef OBJECT_H
#define OBJECT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int id;
  char *name;
} Object;
 
/**
 * Inizializace objektu. Název objektu kopíruje. Objekt bude mít název
 * roven NULL, pokud se inicializace nezdařila. 
 */
Object object_ctor(int id, char *name);
 
/**
 * Uvolní objekt (resp. jeho jméno) z paměti.
 */
void object_dtor(Object *o);

/**
* Vypise informace o objektu.
*/
void print_obj(Object* o);


#endif // OBJECT_H

