/**
 * Bodovany ukol 2: Implementace e^x pomoci Taylorovy rady
 */

#include<stdio.h>
#include<math.h>

/**
 * Vypocita e^x pomoci Taylorovy rady
 * e^x = 1 + x + (x*x / 2!) + (x*x*x / 3!)
 * @param x cislo
 * @return Vraci vypoctanou hodnotu e^x
 */
double expMy(double x)
{
	double eps = 0.01;

	/// promenna, ktera reprezentuje soucet rady
	double y = 1;

	/// inicializace prvniho clenu rady
	double citatel = 1;
	double jmenovatel = 1;

	/// inicializace promenne pro faktorial
	double faktorial = 1;

	/// inicializace promenne pro term
	double t = citatel/jmenovatel;

	while ((fabs(t)) > eps)
	{
		/// nova hodnota citatele
		citatel *= x;

		/// nova hodnota jmenovatele
		jmenovatel *= faktorial;

		/// novy clen rady: citatel/jmenovatel
		t = citatel/jmenovatel;

		/// novy clen rady pricteme k celkovemu souctu
		y += t;

		/// inkrementujeme faktorial
		faktorial++;
	}

	/// vratime sectenou radu
	return y;

}

/**
 * Hlavni program
 */
int main()
{
	/// cislo v exponentu e
	double x = 4.2;

	double result = expMy(x);

	printf("math.h %.10f\n", exp(x));
	printf("expMy %.10f\n", result);

	return 0;
}
