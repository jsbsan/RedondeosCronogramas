#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "busca.h"

int main ( int argc, char **argv )
{
	/*Array Mensualidades*/
/*Estos datos tendriamos que leerlo desde un archivo pasado como argumento*/
	
	double Mensualidades[36] = {
8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07,8179.07
};
	/*Definición de lo que tiene que sumar el presupuesto de Ejecución Material */
	
	double PEMSuma = 0;
     PEMSuma=294446.52; /* aqui poner el PEM con 2 decimales*/
	/* Definicion de porcentajes de G.G, B.I. e I.V.A */
	int PorGG = 13;
	int PorBI = 6;
	int PorIVA = 21;


	/*calculo automatico del tamaño de los datos*/
    int sizeMensualidades = sizeof(Mensualidades)/sizeof(double); 
	double GastosGenerales = round ( PEMSuma * PorGG  ) / 100;
	double GastosBI = round ( PEMSuma * PorBI  ) / 100;
	double PresupuestoPEMmasGGmasBI = PEMSuma + GastosGenerales + GastosBI;
	double GastosIVA = round ( PresupuestoPEMmasGGmasBI * PorIVA  ) / 100;
	double GastosPorEjecucionContrata = round((GastosBI + GastosGenerales + GastosIVA + PEMSuma)*100) * 0.01;
	printf ( "-----------------------------------------------------------------\n" );
	printf ( "Datos Iniciales: \n" );
	printf ( "-----------------------------------------------------------------\n" );
	printf ( "-> PEM: %.2f \n", PEMSuma );
	printf ( "Datos Objetivos:\n" );
	printf ( "-> Gastos Generales [PEM x GG (%i)]: %.2f \n", PorGG, GastosGenerales );
	printf ( "-> Beneficio Industrial [PEM x BI (%i)]: %.2f \n", PorBI, GastosBI );
	printf ( "-> Presupuesto [PEM + BI + GG =]: %.2f \n", PresupuestoPEMmasGGmasBI );
	printf ( "-> Iva  [%i]: %.2f \n", PorIVA, GastosIVA );
	printf ( "-> Presupuesto por Ejecución Contrata: %.2f \n", GastosPorEjecucionContrata );
	
	printf ( "-----------------------------------------------------------------\n" );
	
	BuscarSoluciones ( PEMSuma, PorGG, PorBI, PorIVA, Mensualidades, sizeMensualidades, GastosGenerales, GastosBI, PresupuestoPEMmasGGmasBI, GastosIVA, GastosPorEjecucionContrata );
	
	return 0;
}
