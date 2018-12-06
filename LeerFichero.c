#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "strsplit.h"

char* ReemplazarComaPorPunto ( char *cadena )
{
	int i;
	
	for ( i = 0; i <= strlen ( cadena ); i++ ) {
		if ( cadena[i] == ',' ) {
			cadena[i] = '.';
		}
	}
	
	return cadena;
}

void ayuda(){
printf("\n");
printf("-------------------------------------\n");
printf("AYUDA      \n");
printf("-------------------------------------\n");
printf("\n");

printf("\n");
printf("El programa funciona mediante consola, añadiendo parametros al nombre del programa. \n");
printf("El primer parametro es el nombre del archivo de datos. Se suele colocar en el mismo directorio donde este el programa.\n");
printf("El segundo parametro  es opcinal e indica el numero maximo que hara el ciclo de calculo. Si no se pone, el programa aplicará un ciclo de varios millones de pruebas aleatoria para encontra la posible solucion.\n");
printf("\n");
printf("Este programa necesita al menos un archivo de datos, que se introduce como parametro.\n");
printf("Estructura del fichero de datos\n");
printf("Tendra la informacion en varias lineas:\n");
printf("      En la primera linea se pone separados por tabulador los valorres de ejecucion material por meses.\n");
printf("      En las segunda linea se pone la cantidad del Presupuesto de Ejecucion Material (PEM).\n");
printf("      En la tercera linea el porcentaje de Gastos Generales (puede variar entre 13 y 17 segun la normativa).\n");
printf("      En la cuarta linea el porcentaje de Beneficio Industrial (BI) suele ser el .6\n");
printf("      Y por ultimao en la quinta linea se pondra el porcentaje de IVA, que suele ser el 21.\n");
printf("\n");
printf("\n");
printf("Autor: Julio Sanchez Berro (jsbsan)\n");
printf("Licencia GNU-GPL\n");
printf("Dos Hermanas, Sevilla,  2018\n");
}



void LeerficheroYSacarValores ( int argc, char **argv, double * PEMSuma, int * PorGG, int * PorBI, int * PorIVA, double  Mensualidades[], int *LongitudArray )
{
	int i;
	int LineaLeidas = 0; //lineas contenidas en el fichero
	
	printf ( "Argumentos de la linea de ordenes\n\n" );
	
	for ( i = 0; i < argc; i++ ) {
		//  printf ( "El agurmento [%i] es %s \n", i, argv[i] );
	}
	
	if ( i < 2 ) {
		printf ( "\n Error: No hay parametros suficientes \n" );
       ayuda();
		return ;
	}
	

	
	
	char nombre_fichero[300] ;
	
	strcpy ( nombre_fichero, argv[1] );




	
	char linea[1024];
	int contador = 0;





	FILE *fich;
	
	fich = fopen ( nombre_fichero, "r" );
	
	//Lee línea a línea y escribe en pantalla hasta el fin de fichero
	while ( fgets ( linea, 1024, ( FILE* ) fich ) ) {
		contador += 1;
		
//analisis del contenido del fichero por cada linea....
		switch ( contador ) {
			case 1:
//aqui esta el array de valores de meses
//procesar varios valores ....
				printf ( " " );
				
				char ** tokens;
				double meses;
				
				//printf ( "AsignaLineaAMeses-> linea: %s \n", linea );
				
				tokens = str_split ( ReemplazarComaPorPunto ( linea ), '\t' );
				
				if ( tokens ) {
					int i;
					int ci;
					
					for ( ci = 0; * ( tokens + ci ); ci++ ) {
					}
					
					*LongitudArray = ci;
					
					
					for ( i = 0; * ( tokens + i ); i++ ) {
						meses =      strtod ( * ( tokens + i ), NULL );
						//printf ( "meses (convertido a numeros) (%2i)=[%2f]\n", i, meses );
						free ( * ( tokens + i ) );
						Mensualidades[i] = meses;
					}
					
				}
				
				LineaLeidas = 1;
				break;
				
			case 2:
//aqui esta la suma total PEM
				*PEMSuma = atof ( ReemplazarComaPorPunto ( linea ) );
				LineaLeidas = 2;
				break;
				
			case 3:
//aqui esta GG
				*PorGG = atoi ( linea ); // es un integer
				LineaLeidas = 3;
				break;
				
				
			case 4:
//aqui esta BI
				LineaLeidas = 4;
				*PorBI = atoi ( linea ); // es un integer
				break;
				
			case 5:
//aqui esta IVA
				*PorIVA = atoi ( linea ); // es un integer
				LineaLeidas = 5;
				break; //salir del switch
				
		}
	}
	
	if ( LineaLeidas < 5 ) {
		printf ( "\n" );
		printf ( ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" );
		printf ( "NOTA: \nPosible Error: Faltan lineas de datos en el archivo pasado\n" );
		printf ( ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" );
	}
	
	
	fclose ( fich );
	
	return ;
}
