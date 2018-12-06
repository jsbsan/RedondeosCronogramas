#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "busca.h"
#include "FuncionesComprobacion.h"
#include "strsplit.h"
#include "sumatorio.h"
#include "LeerFichero.h"

int main ( int argc, char **argv )
{
	/*Array Mensualidades*/
	/*Estos datos tendriamos que leerlo desde un archivo pasado como argumento*/
	
	double Mensualidades[60];
	/*Definición de lo que tiene que sumar el presupuesto de Ejecución Material */
	
	double PEMSuma = 0;
	/* Definicion de porcentajes de G.G, B.I. e I.V.A */
	int PorGG = 0;
	int PorBI = 0;
	int PorIVA = 0;
	int sizeMensualidades = 0;
	
	
	LeerficheroYSacarValores ( argc, argv, &PEMSuma, &PorGG, &PorBI, &PorIVA, Mensualidades, &sizeMensualidades );
	
	if ( sizeMensualidades == 0 ) {
		printf ( "\n\nError:  No hay datos de mensualidades.... revise argumentos o archivo de datos\n\n" );
		return 0;
	}
	
	
	if ( PEMSuma == 0 ) {
		printf ( "\n\nError:  PEMSuma no puede ser 0.00 \n\n" );
		return 0;
	}
	
	if ( PorGG == 0 ) {
		printf ( "\n\nPosible Error:  PorGG no puede ser 0.00 \n\n" );
	}
	
	if ( PorBI == 0 ) {
		printf ( "\n\nPosible Error:  PorBI no puede ser 0.00 \n\n" );
	}
	
	if ( PorIVA == 0 ) {
		printf ( "\n\nError:  PorIVA no puede ser 0.00 \n\n" );
		return 0;
	}
	
	
	
	
	
	
	/*calculo automatico del tamaño de los datos*/
	double GastosGenerales = Redondear ( PEMSuma * PorGG * 0.01, 2 ) ;
	double GastosBI = Redondear ( PEMSuma * PorBI  * 0.01, 2 );
	double PresupuestoPEMmasGGmasBI = PEMSuma + GastosGenerales + GastosBI;
	double GastosIVA = Redondear ( PresupuestoPEMmasGGmasBI * PorIVA * 0.01, 2 ) ;
	double GastosPorEjecucionContrata = Redondear ( ( GastosBI + GastosGenerales + GastosIVA + PEMSuma ), 2 );
	printf ( "-----------------------------------------------------------------\n" );
	printf ( "Datos Iniciales: \n" );
	printf ( "-----------------------------------------------------------------\n" );
	printf ( "-> PEM: %.2f \n", PEMSuma );
	printf ( "Datos Objetivos:\n" );
	printf ( "-> Gastos Generales [PEM x GG (%i)]: %.2f \n", PorGG, GastosGenerales );
	printf ( "-> Beneficio Industrial [PEM x BI (%i)]: %.2f \n", PorBI, GastosBI );
	printf ( "-> Presupuesto [PEM + BI + GG =]: %.2f \n", PresupuestoPEMmasGGmasBI );
	printf ( "-> Iva  [%i]: %.2f \n", PorIVA, GastosIVA );
	printf ( "-> Presupuesto por Ejecucion Contrata: %.2f \n", GastosPorEjecucionContrata );
	
	printf ( "-----------------------------------------------------------------\n" );
	
	
	
	double Tanteos = 0;
	
	if (argc == 3) {
// indicamos el numero de operaciones maximas...

	char numeroTexto[300] ;
	
		strcpy ( numeroTexto, argv[2] );
		
		Tanteos = atoi ( numeroTexto );
		
		printf ( "\n Operaciones Maximas Indicas: %.2f \n", Tanteos );
	} else {
		Tanteos = 0; //en la subrutina ya le da un valor muy alto
	}
	
	BuscarSoluciones ( PEMSuma, PorGG, PorBI, PorIVA, Mensualidades, sizeMensualidades, GastosGenerales, GastosBI, PresupuestoPEMmasGGmasBI, GastosIVA, GastosPorEjecucionContrata , Tanteos );
	
	return 0;
}
