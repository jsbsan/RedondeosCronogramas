
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sumatorio.h"


double sumatorio ( double v[], int sizeDatos )
{
	double total = 0;
	int i = 0;
	while ( i < sizeDatos ) {
		total += v[i]; /* redondeo a 2 decimales */
		i++;
	}
	return  total;
}
