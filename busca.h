/* File busca.h */
#ifndef BUSCA_H
#define BUSCA_H


void BuscarSoluciones(float PEMSuma,int PorGG,int PorBI,int PorIVA,float Mensualidades[],int sizeMensualidades,float GastosGenerales,float GastosBI,float PresupuestoPEMmasGGmasBI,float GastosIVA,float GastosPorEjecucionContrata);
float sumatorio(float v[],int sizeDatos);
void presentarMeses(float m[],int sizeM);
int Comprobacion(float m[],int sizeM);
#endif
