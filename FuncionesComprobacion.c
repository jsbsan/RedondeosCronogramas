/* fichero Busca */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FuncionesComprobacion.h"
#include "sumatorio.h"


int Comprobacion ( double m[], int sizeM, double DifAdm, int PorGG, int PorBI, int PorIVA, double GastosGenerales, double GastosBI, double PresupuestoPEMmasGGmasBI, double GastosIVA, double GastosPorEjecucionContrata )
{
	int a = 0;
	double sumaGG = 0;
	double sumaBI = 0;
	double sumaIVA = 0;
	double sumaSubtotales = 0;
	
	/*comprobacion de sumas GG*/
	for ( a = 0; a < sizeM; a++ ) {
		sumaGG +=  round ( m[a] * PorGG ) * 0.01;
	}
	
	if ( sumaGG >= ( GastosGenerales - DifAdm ) && ( sumaGG <= ( GastosGenerales + DifAdm ) ) ) {
		/*seguir calculando */
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	/* comrpobando sumas de Beneficio Industrial */
	for ( a = 0; a < sizeM; a++ ) {
		sumaBI += round ( m[a] * PorBI ) * 0.01;
	}
	
	if ( sumaBI >= ( GastosBI - DifAdm ) && ( sumaBI <= ( GastosBI + DifAdm ) ) ) {
		/*seguir calculando */
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	sumaIVA = 0;
	
	/* comrpobando suma IVA */
	for ( a = 0; a < sizeM; a++ ) {
		sumaIVA +=  round ( ( roundf ( m[a] * 100 ) * 0.01 + roundf ( m[a] * PorGG ) * 0.01 + roundf ( m[a] * PorBI ) * 0.01 ) * PorIVA ) * 0.01;
	}
	
	
	if ( sumaIVA >= ( GastosIVA - DifAdm ) && ( sumaIVA <= ( GastosIVA + DifAdm ) ) ) {
		/*seguir calculando */
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	sumaSubtotales = sumaBI + sumaGG + sumaIVA + sumatorio ( m, sizeM );
	
	if ( sumaSubtotales >= ( GastosPorEjecucionContrata - DifAdm ) && ( sumaSubtotales <= ( GastosPorEjecucionContrata ) ) ) {
		printf ( "--------------------------------\n" );
		printf ( "Suma GG: %.2f \n", sumaGG );
		printf ( "Suma BI: %.2f \n", sumaBI );
		printf ( "Suma IVA: %.2f \n", sumaIVA );
		printf ( "Suma Totales: %.2f \n", sumaSubtotales );
		printf ( "--------------------------\n" );
		printf ( "Se ha encontrado solución \n" );
		return 0; /* cumple */ /* correcto  0: true y -1:false */
		
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	/*si llegamos hasta este punto se cumplen todas las condiciones */
	return 0; /* cumple */ /* correcto  0: true y -1:false */
}
