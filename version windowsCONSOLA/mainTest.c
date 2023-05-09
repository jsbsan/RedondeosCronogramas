#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main2(int argc, char **argv)
{
/*semilla de numeros aleatorios*/
srand(time(NULL));

float numero = rand() % 10; 
printf("Numero aleatorio: %.3f \n",numero);



	printf("Redondear\n");
	float val=37.777779;
	float rounded_dow=floorf(val*100)/100;
	float nearest = roundf(val * 100) / 100;  /* Result: 37.78 */
	float rounded_up = ceilf(val * 100) / 100;      /* Result: 37.78 */
	
	
	printf("Valor: %.3f",val);
	printf("\n");
	printf("%.3f",rounded_dow);
	printf("\n");
	printf("%.3f",rounded_up);
	printf("\n");
	printf("%.3f",nearest);
	printf("\n");
	
	
		 val=37.774;
	 rounded_dow=floorf(val*100)/100;
	 nearest = roundf(val * 100) / 100;  
	 rounded_up = ceilf(val *100) / 100;
	printf("------------------------");
	printf("Valor: %.3f",val);
	printf("\n");
	printf("%.3f",rounded_dow);
	printf("\n");
	printf("%.3f",rounded_up);
	printf("\n");
	printf("%.3f",nearest);
	printf("\n");
	
	
	 val=37.775;
	 rounded_dow=floorf(val*100)/100;
	 nearest = roundf(val * 100) / 100;  
	 rounded_up = ceilf(val * 100) / 100;      
	printf("------------------------");
	printf("Valor: %.3f",val);
	printf("\n");
	printf("%.3f",rounded_dow);
	printf("\n");
	printf("%.3f",rounded_up);
	printf("\n");
	printf("%.3f",nearest);
	printf("\n");
	
	return 0;
}
