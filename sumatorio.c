
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sumatorio.h"


float sumatorio ( float v[], int sizeDatos )
{
	float total = 0;
	int i = 0;
	while ( i < sizeDatos ) {
		total += v[i];
		i++;
	}
	return  total;
}
