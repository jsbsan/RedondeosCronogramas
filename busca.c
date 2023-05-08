#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "busca.h"
#include "sumatorio.h"
#include "FuncionesComprobacion.h"


double MensualesAleatorios[60];/* hasta 36 meses */

//double Tanteos = 0; /* numero de tanteos a realizar,... pueden ser millones */


void BuscarSoluciones ( double PEMSuma, double PorGG, double PorBI, double PorIVA, double Mensualidades[], int sizeMensualidades, double GastosGenerales, double GastosBI, double PresupuestoPEMmasGGmasBI, double GastosIVA, double GastosPorEjecucionContrata , double Tanteos )
{
	srand ( time ( NULL ) ); /*iniciar RANDOMIZE */
	
	if ( Tanteos == 0 ) {
		Tanteos = 10000000000;
	}
	
	printf ( "Comprobaciones.....\n" );
	printf ( "Funcion en .h: PEMSuma:  %.2f \n ", PEMSuma );
	
	for ( int i = 0; i < sizeMensualidades; i++ ) {
	
		printf ( "Mensualides[%2i]: %.2f \t", i + 1, Mensualidades[i] );
		
		if  ( ceil ( (i / 4 ) * 4 == i )) printf ( "\n" );
	}
	
	printf ( "\n" );
	
	double sumatorioCalculo = 0;
	
	sumatorioCalculo =	 sumatorio ( Mensualidades, sizeMensualidades ) ;
	
	if ( ( sumatorioCalculo < ( PEMSuma - 1 ) ) || ( sumatorioCalculo > ( PEMSuma + 1 ) ) ) {
//si sumataorio es inferiore a la suma PEMSuma en una unidad o es mayor en una unidad ,.error: no hay que seguir calculando.
		printf ( "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n" );
		printf ( "Error en los datos del PEMsuma y Meses. \n" );
		printf ( "La suma de los meses no coincide con la suma PEM dada el el archivo de datos (se adminte un intervarlo entre +1.00 y -1.00). \n" );
		printf ( "%.2f   -> Suma de Meses \n", sumatorioCalculo );
		printf ( "%.2f   -> Suma PEM (dato archivo)\n", PEMSuma );
		printf ( "%.2f  -> Diferencia\n", sumatorioCalculo - PEMSuma );
		printf ( "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n" );
		return ;
	}
	
	printf ( "Sumatorio: %.2f \n", sumatorio ( Mensualidades, sizeMensualidades ) );
	
	
	
	
	double DifAdm = 0.001 ; /* comprobar que funciona mejor 0.001 o 0.0049 */
	double Mensuales[60][10];  // aumentado hasta 60 meses
	int a = 0;
	int b = 0;
	double SumaMensualidades = 0;
	int Contador = 0;
	int repite = 0;
	double RepiteBucleComprobaciones = 0; //'el contador puede ser muy grande'
	
	int solucionEncontrada = 0; //bandera para indicar si se ha encontrado solucion (valor 1)  o no (valor=0)
	
	printf ( "Creando matriz de datos posibles....\n" ) ; /* Creo la matriz con los posibles valores*/
	
	for ( a = 0; a < sizeMensualidades; a++ ) {
		for ( b = 0; b < 10; b++ ) {
			double valor = Redondear ( ( Mensualidades[a] - 0.05 + b * 0.01 ), 2 );
			Mensuales[a][b] = Redondear ( valor, 2 );
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
		SumaMensualidades = Redondear ( sumatorio ( MensualesAleatorios, sizeMensualidades ), 2 );
		
		if ( PEMSuma == SumaMensualidades ) {
			/*la suma es correcta, paso al siguiente calculo*/
			Contador += 1;
			/*printf ( "Suma encontrada [%i]\n", Contador ); */
			
			if ( Comprobacion ( MensualesAleatorios, sizeMensualidades, DifAdm, PorGG, PorBI, PorIVA, GastosGenerales, GastosBI, PresupuestoPEMmasGGmasBI, GastosIVA, GastosPorEjecucionContrata ) == 0 ) {
			
				printf ( "------------------------\n" );
				printf ( "Pruebas Completas Realizadas: %-.0f \n", RepiteBucleComprobaciones );
				printf ( "Valores Mensuales Encontrados\n" );
				solucionEncontrada = 1;
				
				for ( repite = 0; repite < sizeMensualidades; repite++ ) {
					printf ( "Mes[%2i]= %.2f ____ MesOriginal[%2i]= %.2f ____Diferencia: %.2f \n",
					         repite + 1, MensualesAleatorios[repite],
					         repite + 1, Mensualidades[repite],
					         Redondear ( ( MensualesAleatorios[repite] - Mensualidades[repite] ), 2 )
					       );
				}
				
				break;
			}
		}
		
	}
	
	if ( solucionEncontrada == 0 ) {
		printf ( "\n\n" );
		printf ( "________________________________________________________________________________________\n" );
		printf ( "No se ha encontrado ninguna solución. \n" );
		printf ( "Comprobaciones aleatorias realizadas han sido %.2f\n", Tanteos );
		printf ( "________________________________________________________________________________________\n\n" );
		printf ( "Fin del programa\n" );
	}
	
}

void presentarMeses ( double m[], int sizeM )
{
	printf ( "---------Meses-----------\n" );
	
	for ( int a = 0; a < sizeM; a++ ) {
		printf ( "Mes[%d]=%.2f \n", a + 1, m[a] );
	}
}
