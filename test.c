#include <stdio.h>

const int Iva = 21;
float precioBruto;
float precioFinal;

void main() {
  scanf("%f", &precioBruto);
  precioFinal = precioBruto + (precioBruto*Iva)/100;
  printf("El precio final es: %f \n", precioFinal);
}