/**
 * Priklad 2: vypocet pi pomoci zretezeneho zlomku
 */

#include<stdio.h>
#include<stdlib.h>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068

/**
 * Vypocita cislo pi pomoci zretezeneho zlomku
 * @param n uroven zanoreni zretezeneho zlomku
 * @return hodnotu cisla pi pro n-tou uroven zanoreni
 */
double cfracPi(unsigned int n)
{
    /// mocnina
    unsigned int square;
    /// castecny soucet
    double sum;

    /// koeficient
    unsigned int k = 2 * n - 1;

    /// spocteme prvni castecny soucet
    sum = k ;

    /// cyklus - podle toho, jake mame n (rozvoj), postup odspodu
    while(n != 1)
    {/// protoze v cyklu snizujeme n, potom musime koncit s hodnotou n = 1
        /// postupne snizujeme koeficient
        k = k - 2;
        /// snizujeme rad
        n--;
        /// postupne se snizuji mocniny
        square = n * n;
        /// tvorba zlomku
        sum = square / sum;
        /// pricteni koeficientu k castecnemu souctu - tvorba noveho jmenovatele
        sum = k + sum;
    }

    /// nakonec vratime 4/soucet (dle vzorce pro pi)
    return (4/sum);
}

/**
 * Hlavní program.
 */
int main()
{
    double result = cfracPi(5);
    printf("PI:       %.30f\n", PI);
    printf("cfrac_pi: %.30f\n", result);
    return 0;
}
