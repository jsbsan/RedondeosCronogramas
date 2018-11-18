/* fichero Busca */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FuncionesComprobacion.h"
#include "sumatorio.h"


int Comprobacion ( float m[], int sizeM,
                   float DifAdm,
                   int PorGG,
                   int PorBI,
                   int PorIVA,
                   float GastosGenerales,
                   float GastosBI,
                   float PresupuestoPEMmasGGmasBI,
                   float GastosIVA,
                   float GastosPorEjecucionContrata
                 )
{
	int a = 0;
	float sumaGG = 0;
	float sumaBI = 0;
	float sumaIVA = 0;
	float sumaSubtotales = 0;
	
	/*comprobacion de sumas GG*/
	for ( a = 0; a < sizeM; a++ ) {
		sumaGG += roundf ( m[a] * PorGG * 0.01 * 100 ) / 100;
	}
	
	if ( sumaGG >= ( GastosGenerales - DifAdm ) && ( sumaGG <= ( GastosGenerales + DifAdm ) ) ) {
		/*seguir calculando */
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	/* comrpobando sumas de Beneficio Industrial */
	for ( a = 0; a < sizeM; a++ ) {
		sumaBI += roundf ( m[a] * PorBI * 0.01 * 100 ) / 100;
	}
	
	if ( sumaBI >= ( GastosBI - DifAdm ) && ( sumaBI <= ( GastosBI + DifAdm ) ) ) {
		/*seguir calculando */
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	/* comrpobando suma IVA */
	for ( a = 0; a < sizeM; a++ ) {
		sumaIVA +=
		    roundf ( m[a] * PorGG * 0.01 * 100 ) / 100 +
		    roundf ( m[a] * PorBI * 0.01 * 100 ) / 100 +
		    roundf ( m[a] * PorIVA * 0.01 * 100 ) / 100 ;
	}
	
	if ( sumaIVA >= ( GastosIVA - DifAdm ) && ( sumaIVA <= ( GastosIVA + DifAdm ) ) ) {
		/*seguir calculando */
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	sumaSubtotales = sumaBI + sumaGG + sumaIVA + sumatorio ( m, sizeM );
	
	if (sumaSubtotales >= ( GastosPorEjecucionContrata - DifAdm ) && ( sumaSubtotales <= ( GastosPorEjecucionContrata ) ) ) {
		printf ( "Se ha encontrado solución \n" );
	return 0; /* cumple */ /* correcto  0: true y -1:false */
	} else {
		return -1; /* no cumple */ /* correcto  0: true y -1:false */
	}
	
	/*si llegamos hasta este punto se cumplen todas las condiciones */
	return 0; /* cumple */ /* correcto  0: true y -1:false */
}
