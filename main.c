#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "busca.h"

int main(int argc, char **argv)
{
	/*Array Mensualidades*/
	float Mensualidades[2]={50,50.15};
	int sizeMensualidades=2; /* Numero de Meses */
	
	Mensualidades[0]=75;
	Mensualidades[1]=25.15;
	
	
	/*Definición de lo que tiene que sumar el presupuesto de Ejecución Material */
	float PEMSuma=100.15;/* aqui poner el PEM con 2 decimales*/
	/* Definicion de porcentajes de G.G, B.I. e I.V.A */
	int PorGG=13;
	int PorBI=6;
	int PorIVA=21;
	
	float GastosGenerales= roundf(PEMSuma * PorGG / 100 *100)/100;
	float GastosBI= roundf(PEMSuma * PorBI / 100*100)/100;
	float PresupuestoPEMmasGGmasBI=PEMSuma+GastosGenerales+GastosBI;
	float GastosIVA=roundf(PresupuestoPEMmasGGmasBI * PorIVA / 100*100)/100;
	float GastosPorEjecucionContrata= GastosBI+GastosGenerales+GastosIVA+PEMSuma;
	printf("-----------------------------------------------------------------\n");
	printf("Datos Iniciales: \n");
	printf("-----------------------------------------------------------------\n");
	printf("-> PEM: %.2f \n", PEMSuma);
	printf("Datos Objetivos:\n");
	printf("-> Gastos Generales [PEM x GG (%i)]: %.2f \n", PorGG,GastosGenerales);
	printf("-> Beneficio Industrial [PEM x BI (%i)]: %.2f \n", PorBI,GastosBI);
	printf("-> Presupuesto [PEM + BI + GG =]: %.2f \n", PresupuestoPEMmasGGmasBI);
	printf("-> Iva  [%i]: %.2f \n", PorIVA,GastosIVA);
	printf("-> Presupuesto por Ejecución Contrata: %.2f \n",GastosPorEjecucionContrata);
		
	printf("-----------------------------------------------------------------\n");
	
	 BuscarSoluciones(PEMSuma,PorGG,PorBI,PorIVA,Mensualidades,sizeMensualidades,GastosGenerales,GastosBI,PresupuestoPEMmasGGmasBI,GastosIVA,GastosPorEjecucionContrata);
	
	return 0;
}