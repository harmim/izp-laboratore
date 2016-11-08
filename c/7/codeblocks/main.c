#include <stdio.h>

char cell[10];

/**
 * Funkce nacte jednu bunku CVS souboru
 * @param db CVS soubor
 * @return Vraci delku nactene bunky
 */
int csv_read_cell(FILE *db)
{
    int c, i = 0;
    while ((c = fgetc(db)) != EOF && c != ',' && c != '\n')
    {/// cteni souboru po znacich
      cell[i++] = c;
    }

    cell[i] = '\n';
    return i;
}

/**
 * Hlavni program.
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    /// otevreni souboru pro cteni
    FILE *csv = fopen(argv[1], "r");
    /// cteni CSV souboru po bunkach
    int len = csv_read_cell(csv);
    while (len > 0)
    {
        printf(cell);
        len = csv_read_cell(csv);
    }
    return 0;
}
