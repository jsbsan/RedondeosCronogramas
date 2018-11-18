#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "busca.h"
#include "sumatorio.h"
#include "FuncionesComprobacion.h"


double MensualesAleatorios[36];/* hasta 36 meses */

double Tanteos = 10000000000; /* numero de tanteos a realizar,... pueden ser millones */


void BuscarSoluciones ( double PEMSuma, int PorGG, int PorBI, int PorIVA, double Mensualidades[], int sizeMensualidades, double GastosGenerales, double GastosBI, double PresupuestoPEMmasGGmasBI, double GastosIVA, double GastosPorEjecucionContrata )
{
	srand ( time ( NULL ) ); /*iniciar RANDOMIZE */
	
	printf ( "Funcion en .h: PEMSuma:  %.2f \n", PEMSuma );
	
	for ( int i = 0; i < sizeMensualidades; i++ ) {
		printf ( "Mensualides[%2i]: %.2f \n", i, Mensualidades[i] );
		
	}
	
	printf ( "Sumatorio: %.2f \n", sumatorio ( Mensualidades, sizeMensualidades ) );
	
	double DifAdm = 0.001 ; /* comprobar que funciona mejor 0.001 o 0.0049 */
	double Mensuales[36][10];
	int a = 0; 
	int b = 0;
	double SumaMensualidades = 0;
	int Contador = 0;
	int repite = 0;
	double RepiteBucleComprobaciones =0;//'el contador puede ser muy grande'
	
	printf ( "Creando matriz de datos posibles....\n" ) ; /* Creo la matriz con los posibles valores*/
	
	for ( a = 0; a < sizeMensualidades; a++ ) {
		for ( b = 0; b < 10; b++ ) {
			double valor = roundf((Mensualidades[a] - 0.05 + b * 0.01)*100)*0.01;
			Mensuales[a][b] = roundf(valor*100)*0.01;
		}
		
	}
	
	/*Monstrando datos asignados en la matriz
	for (a=0;a<sizeMensualidades;a++)
		{
			for (b=0;b<10;b++){
				printf("SumaM%.2f\n",Mensuales[a][b] );
	
			}
		printf("----\n");
		}PEMSuma
	*/
	
	printf ( "Creando datos meses aleatorios....\n" ) ;
	
	/*aqui empiza el codigo principal de TANTEOS*/
	for ( RepiteBucleComprobaciones = 0; RepiteBucleComprobaciones < Tanteos; RepiteBucleComprobaciones++ ) {
	
		/* eligo valores aleatorios */
		for ( b = 0; b < sizeMensualidades; b++ ) {
			int fila = rand() % 10;
			MensualesAleatorios[b] = Mensuales[b][fila];
		}
		
		/*presentarMeses(MensualesAleatorios,sizeMensualidades);*/
		
		/* calculo datos */
		SumaMensualidades = roundf(sumatorio ( MensualesAleatorios, sizeMensualidades )*100)*0.01;
		
		if ( PEMSuma == SumaMensualidades ) {
			/*la suma es correcta, paso al siguiente calculo*/
			Contador += 1;
			/*printf ( "Suma encontrada [%i]\n", Contador ); */
			
			if  (Comprobacion ( MensualesAleatorios, sizeMensualidades,DifAdm,PorGG,PorBI,PorIVA,GastosGenerales,GastosBI,PresupuestoPEMmasGGmasBI,GastosIVA,GastosPorEjecucionContrata)==0) {
				
				printf ( "------------------------\n" );
				printf ( "Pruebas Completas Realizadas: %-.0f \n", RepiteBucleComprobaciones);
				printf ( "Valores Mensuales Encontrados\n" );
				
				for ( repite = 0; repite < sizeMensualidades; repite++ ) {
					printf ( "Mes[%2i]= %.2f ____ MesOriginal[%2i]= %.2f ____Diferencia: %.2f \n",
					         repite+1, MensualesAleatorios[repite],
					         repite+1, Mensualidades[repite],
					         Mensualidades[repite] - MensualesAleatorios[repite]
					       );
				}
			break;
			}
		}
		
	}
	
	
	/*printf ( "Presentando datos....\n" ) ;
	presentarMeses ( MensualesAleatorios, sizeMensualidades );
*/
	printf ( "Fin del programa\n" );
}



void presentarMeses ( double m[], int sizeM )
{
	printf ( "---------Meses-----------\n" );
	
	for ( int a = 0; a < sizeM; a++ ) {
		printf ( "Mes[%d]=%.2f \n", a, m[a] );
	}
}
