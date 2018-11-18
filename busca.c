/* fichero Busca */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "busca.h"


float DifAdm =0.001 ;/* comprobar que funciona mejor 0.001 o 0.0049 */
float MensualesAleatorios[36];/* hasta 36 meses */

void BuscarSoluciones(float PEMSuma,int PorGG,int PorBI,int PorIVA,float Mensualidades[],int sizeMensualidades,float GastosGenerales,float GastosBI,float PresupuestoPEMmasGGmasBI,float GastosIVA,float GastosPorEjecucionContrata)
{
srand(time(NULL)); /*iniciar RANDOMIZE */

	printf("Funcion en .h: PEMSuma:  %.2f \n",PEMSuma);
	
	for (int i=0;i<sizeMensualidades;i++){
		printf("Mensualides[%i]: %.2f \n",i,Mensualidades[i]);
	
	}
	printf("Sumatorio: %.2f \n",sumatorio(Mensualidades,sizeMensualidades));

float Mensuales[36][10];
float dato=0;
int a=0;
int b=0;
float SumaMensualidades=0;
int Contador=0;
int repite=0;
int Tanteos=100;/* numero de tanteos a realizar,... pueden ser millones */


printf("Creando matriz de datos posibles....\n") ;/* Creo la matriz con los posibles valores*/
for (a=0;a<sizeMensualidades;a++)
	{
		for (b=0;b<10;b++){
			float valor = Mensualidades[a]-0.05+b *0.01; 
			Mensuales[a][b] = valor;
		}
	
	}

/*Monstrando datos asignados en la matriz
for (a=0;a<sizeMensualidades;a++)
	{
		for (b=0;b<10;b++){
			printf("SumaM%.2f\n",Mensuales[a][b] );
			
		}
	printf("----\n");
	}
*/

printf("Creando datos meses aleatorios....\n") ;
/*aqui empiza el codigo principal de TANTEOS*/
for(a=0;a<Tanteos;a++){
	
/* eligo valores aleatorios */
	for(b=0;b<sizeMensualidades;b++){
		int fila = rand() % 10;
		MensualesAleatorios[b]=Mensuales[b][fila]; 
  	}
	/*presentarMeses(MensualesAleatorios,sizeMensualidades);*/
	
	/* calculo datos */
	SumaMensualidades=sumatorio(MensualesAleatorios,sizeMensualidades);
	
	if (PEMSuma == SumaMensualidades){
/*la suma es correcta, paso al siguiente calculo*/
		Contador +=1;
		printf("Suma encontrada [%i]\n",Contador);
		/* if  Comprobacion(MensualesAleatorios,sizeMensualidades){ */
			printf("------------------------\n");
			printf("Pruebas Completas Realizadas: %i \n",a);
			printf("Valores Mensuales Encontrados\n");
			for(repite=0;repite<sizeMensualidades;repite++){
				printf("Mes[%i]= %.2f ____ MesOriginal[%i]= %.2f ____Diferencia: %.2f \n",
				repite,MensualesAleatorios[repite],
				repite,Mensualidades[repite],
				Mensualidades[repite]-MensualesAleatorios[repite]
				);
			}
		/*}*/
		
	}
	
	
	
	
	
	
	
	}


printf("Presentando datos....\n") ;
  presentarMeses(MensualesAleatorios,sizeMensualidades);



printf("Fin del programa\n");
}


float sumatorio(float v[],int sizeDatos)
{
	float total=0;
	int i=0;
	
	while (i<sizeDatos)
	{
		total +=v[i];
		i++;
	}
	
	return  total;	
}


void presentarMeses(float m[],int sizeM){
	printf("---------Meses-----------\n");
	for(int a=0;a<sizeM;a++){
		printf("Mes[%d]=%.2f \n",a,m[a]);
	}
}


int Comprobacion(float m[],int sizeM){
	/* prueba commit */
	
	
	return 0; /* correcto  0: true y -1:false */
	
}