
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sumatorio.h"
#include "FuncionesComprobacion.h"

double sumatorio ( double v[], int sizeDatos )
{
	double total = 0;
	int i = 0;
	while ( i < sizeDatos ) {
		total += Redondear(v[i],2); /* redondeo a 2 decimales */
		i++;
	}
	return  total;
}
