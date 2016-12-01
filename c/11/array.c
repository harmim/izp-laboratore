#include "array.h"

/**
 * Konstruktor pole. Vytvori pole o velikosti size a kazdy prvek
 * v nem inicializuje na hodnoty 0, NULL.
 */
Array array_ctor(unsigned size)
{
	/// vytvorime promennou pole
	Array arr;

	/// alokujeme pamet pro nove pole
	arr.items = malloc(size*sizeof(Object));

	/// pokud byla alokace uspesna
	if (arr.items != NULL)
	{
		/// alokujeme jednotlive objekty pomoci konstruktoru
		for (unsigned i = 0; i < size; i++)
		{
			arr.items[i] = object_ctor(0, NULL);
		}
		/// ulozime velikost pole
        arr.size = size;
	}

	/// vratime hodnotu
	return arr;
}

/**
 * Uvolni pole (a vsechny jeho objekty) z pameti.
 */
void array_dtor(Array *arr)
{
	/// projdeme pres vsechny objekty v poli a uvolnime je pomoci destruktoru
	for (unsigned i = 0; i < arr->size; i++)
		object_dtor(&arr->items[i]);

	/// uvolnime pamet pro pole (funkce free)
	free(arr->items);
}

/**
 * Zmena velikosti pole. Zmeni/realokuje zadane pole na novou velikost.
 * V pripade zvetseni jeste inicializuje kazdy prvek na hodnoty 0, NULL.
 * V pripade zmenseni uvolni objekty odstranene z pole.
 */
Array array_resize(Array *arr, unsigned size)
{
	/// pokud neni duvod nic menit, muzeme vratit puvodni pole a skoncit
	if (size == arr->size)
		return *arr;

	/// pokud budeme zmensovat, uvolnime objekty pred realokaci
	if (size < arr->size)
	{
		for (unsigned i = size; i < arr->size; i++)
		{
			object_dtor(&arr->items[i]);
		}
	}

	/// provedeme realokaci
	arr->items = realloc(arr->items, size*sizeof(Object));

	if (arr->items != NULL && size > arr->size)
	{/// pokud je nova velikost vetsi nez puvodni, pridame nove objekty
		for (unsigned i = arr->size; i < size; i++)
		{
            arr->items[i] = object_ctor(0,NULL);
		}
	}

	/// ulozime novou velikost
	arr->size = size;

	return *arr;

}

/**
 * Hledani prvku v poli podle identifikatoru prvku. Vraci index prvku v poli
 * nebo -1, pokud prvek pole neobsahuje.
 */
int array_find_id(Array *arr, int id)
{
	/// projdeme pole
	for (unsigned i=0; i<arr->size; i++)
	{
		/// pokud najdeme hledane id, vratime index
		if (arr->items[i].id == id)
			return i;
	}
	/// jinak jsme prvek nenasli a vracime -1
	return -1;
}


/**
 * Hledání prvku v poli podle nazvu. Vraci index prvku v poli
 * nebo -1, pokud prvek pole neobsahuje.
 */
int array_find_name(Array *arr, char *name)
{
	/// projdeme pole
	for (unsigned i=0; i<arr->size; i++)
	{
		/// pokud najdeme hledany nazev, vratime index
		if (strcmp(arr->items[i].name,name) == 0)
			return i;
	}

	/// jinak jsme prvek nenasli a vracime -1
	return -1;
}

/**
 *  Vlozeni prvku do pole na zadany index. Pokud je index obsazen, funkce vlozi data na prvni
 *  volny index (pokud zadny neni, vraci -1).
 *  Vraci index vlozeneho prvku (idx) nebo -1, pokud se operace nezdarila.
 */
int array_insert_item(Array *arr, Object *item, unsigned idx)
{
	/// pokud bychom chteli zapsat za mez pole, vracime -1
	if (idx > arr->size)
		return -1;

	/// pokud je dany index prazdny po inicializaci, vlozime ho
	if (arr->items[idx].id == 0 && arr->items[idx].name == NULL)
	{
		arr->items[idx] = *item;
		return idx;
	}

    /// pokud neni puvodni index volny, budeme testovat indexy az do konce pole
    unsigned int i;
    for (i=idx+1; i<arr->size; i++)
    {
        /// pokud je volno, vlozime
        if (arr->items[i].id == 0 && arr->items[i].name == NULL)
        {
            arr->items[i] = *item;
            return i;
        }
    }
    return -1;
}

/**
 * Hledani prvku s nejmensim identifikatorem. Vraci index prvku nebo -1,
 * pokud je pole prazdne.
 */
int array_find_min(Array *arr)
{
	/// pokud je pole prazdne, vraci -1 (implementujte funckci array_empty)
	if (array_empty(arr))
		return -1;

    /// inicializace promenne pro nejmensi id
    int minID = arr->items[0].id;
    /// inicializace promenne pro index
    int index = 0;

    for (unsigned i = 1; i < arr->size; i++)
    {
        /// pokud je aktualni id mensi nez aktualne nejmensi, aktualizace
        if (arr->items[i].id < minID)
        {
            minID = arr->items[i].id;
            index = i;
        }
    }

    /// vratime nejmensi index
    return index;
}

/**
 * Funkce otestuje, zda je pole prazdne.
 * Pokud ano, funkce vrati 1, jinak 0.
 */
bool array_empty(Array* arr)
{
    /// projdeme pole
	for (unsigned i = 0; i < arr->size; i++)
	{/// pokud nejaka polozka neni prazdna vratime false
		if (arr->items[i].id != 0 && arr->items[i].name != NULL)
            return false;
	}
	/// jinak vratime true
	return true;
}


/**
 * Razeni prvku v poli podle jejich identifikatoru. (bubble sort)
 */
void array_sort_bubble(Array *arr)
{
	/// vnejsi cyklus
	for (unsigned int i = 0; i < (arr->size - 1); i++)
    {
		/// zarazka
        for (unsigned int j = 0; j < arr->size - i - 1; j++)
        {
			/// pokud je aktualni prvek vetsi nez nasledujici (< - sestupne, > - vzestupne)
            if (arr->items[j].id > arr->items[j+1].id)
            {
				/// provedeme prohozeni pomoci funkce object_swap
                object_swap(&arr->items[j], &arr->items[j+1]);
            }
        }
    }

}

/**
 *  Razeni prvku v poli podle jejich identifikatoru. (select sort)
 */
void array_sort_select(Array *arr)
{
    // sorted part of the list
    for (unsigned i=0; i<arr->size; i++) {
        // unsorted part of the list
        for (unsigned j=i+1; j<arr->size; j++) {
            // if found item is smaller than the sorted part
            if (arr->items[j].id < arr->items[i].id)
                // perform swap
                object_swap(&arr->items[i],&arr->items[j]);
        }
    }
}


/**
 * Vypis vsech prvku pole.
 */
void array_print(char* str, Array* arr)
{
	printf("%s\n",str);

	for (unsigned i = 0; i < arr->size; i++)
	{
		printf("Prvek na indexu: %d\n", i);
		print_object(&arr->items[i]);
	}
}

