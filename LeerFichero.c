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






void LeerficheroYSacarValores ( int argc, char **argv, double * PEMSuma, int * PorGG, int * PorBI, int * PorIVA, double  Mensualidades[], int *LongitudArray )
{
	int i;
	
	
	printf ( "Argumentos de la linea de ordenes\n\n" );
	
	for ( i = 0; i < argc; i++ ) {
		//  printf ( "El agurmento [%i] es %s \n", i, argv[i] );
	}
	
	if ( i < 2 ) {
		printf ( "\n Error: No hay parametros suficientes \n" );
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
				
				break;
				
			case 2:
//aqui esta la suma total PEM
				*PEMSuma = atof ( ReemplazarComaPorPunto ( linea ) );
				break;
				
			case 3:
//aqui esta GG
				*PorGG = atoi ( linea ); // es un integer
				break;
				
				
			case 4:
//aqui esta BI
				*PorBI = atoi ( linea ); // es un integer
				break;
				
			case 5:
//aqui esta IVA
				*PorIVA = atoi ( linea ); // es un integer
				break; //salir del switch
				
		}
	}
	
	fclose ( fich );
	
	return ;
}
