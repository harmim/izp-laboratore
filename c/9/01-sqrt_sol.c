/**
 * Bodovany ukol 1: vypocet druhe odmocniny cisla x Newtonovou metodou
 */

#include<stdio.h>
#include<math.h>

/**
 * Vypocita druhou odmocninu cisla Newtonovou metodou
 * y_{i+1} = (x/y_i + y_i) * 0.5
 * @param x cislo, ktere budeme odmocnovat
 * @return Vraci vypocitanou odmocninu
 */
double sqrtMy(double x)
{
	double eps = 1e-19; /// presnost vypoctu
	double y = x;       /// pocatecni odhad
	double yp = 0;      /// predchazejici hodnota y

	/// do-while (musime provest alespon 1)
	do
	{
		yp = y; /// inicializace predchazejici hodnoty
		y = ((x/yp) + yp)*0.5; /// dalsi hodnota
	} while (fabs(y-yp) > eps);

	return y;
}

/**
 * Hlavni program
 */
int main()
{
	/// cislo, ktere odmocnujeme
	double x = 7;

	double result = sqrtMy(x);

	printf("math.h %.10f\n", sqrt(x));
	printf("sqrtMy %.10f\n", result);

	return 0;
}
