#include "object.h"
#include "list.h"

int main() 
{
	// objekty
	Object o1 = object_ctor(20,"IUS");
 	Object o2 = object_ctor(40,"IZP");
	Object o3 = object_ctor(50,"IDA");
	
	// inicializace seznamu
	List l = list_ctor();
	
	// test, zda spravne funguji testy prohledavacich funkci na prazdny
	// seznam
	if ((list_find_minid(&l) == NULL) && (list_find_name(&l,"IUS") == NULL))
		printf("Vse OK\n");
	else
		fprintf(stderr,"Funkce nevraci NULL pro prazdny seznam\n");
 	
 	// inicializace prvku seznamu
	Item i1 = item_ctor(o1);
	Item i2 = item_ctor(o2);
	Item i3 = item_ctor(o3);
 	
	printf("Pocet prvku - prazdny seznam: %u\n",list_count(&l));

 	// vlozeni prvku do seznamu (posledni vlozeny bude prvni)
	list_insert_first(&l, &i1);
	list_insert_first(&l, &i2);
	list_insert_first(&l, &i3);
    	
	printf("Pocet prvku - naplneny seznam: %u\n",list_count(&l));

	printf("Polozky seznamu:\n");
	print_list(&l);
	
	// test funkci pro vyhledani prvku s nejmensim id a dle jmena
	printf("Polozka s nejmensim identifikatorem:");
	print_obj(&list_find_minid(&l)->data);

	printf("Polozka s neexistujicim identifikatorem (IOS): %p\n", list_find_name(&l,"IOS"));

	printf("Polozka s existujicim identifikatorem (IZP): ");
	print_obj(&list_find_name(&l,"IZP")->data);

	list_dtor(&l); 

	return 0;
}

