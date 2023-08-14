#include <stdio.h>

float lado, areaRayada, areaTriangulo, areaCuadrado;

void main() {
  scanf("%f", &lado);
  areaTriangulo = ((lado/2)*(lado/2))/2;
  areaCuadrado = lado*lado;
  areaRayada = areaCuadrado - areaTriangulo;
  printf("Area rayada: %f\n", areaRayada);
}