#include "object.h"

/**
 * Inizializace objektu. Název objektu kopíruje. Objekt bude mít název
 * roven NULL, pokud se inicializace nezdařila. 
 */
Object object_ctor(int id, char *name) 
{
    Object o = {
        .id = id,
    };
    
    if (name != NULL) 
    {
       o.name = malloc((strlen(name)+1)*sizeof(char));
        
       // allocate memory for name of the object    
       if (o.name != NULL)
           strcpy(o.name, name);    
        else // if allocation fails
            o.name = NULL;
    }
    else
        o.name = NULL;                    
    

    return o;
}

/**
 * Uvolní objekt (resp. jeho jméno) z paměti.
 */
void object_dtor(Object *o) 
{
    if (o->name != NULL)
    {
        free(o->name);    
    }
}

/**
* Vypise informace o objektu.
*/
void print_obj(Object* o) 
{
    printf("id: %d\t, name: %s\n", o->id, o->name);
}

