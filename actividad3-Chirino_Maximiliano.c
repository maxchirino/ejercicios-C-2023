/* 
  Detectar si un número es primo o no.
  Para saber si un número es primo es suficiente con comprobar la divisibilidad 
  por números inferiores a la raíz cuadrada del número dado.

  Chirino, Maximiliano (DNI: 41116761) - C4
*/

#include <stdio.h>
#include <math.h>

int num, divisores, i;

int main() {
  divisores = 0;
  printf("Ingrese un numero: ");
  scanf("%d", &num);

  if (num < 1) {
    printf("Numero invalido.\n");
    return 0;
  } else {
    for(i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        divisores++;
      }
    }
  }

  if (divisores == 0 && num > 1) {
    printf("%d es un numero primo.\n", num);
  } else {
    printf("%d no es un numero primo.\n", num);
  }

  return 0;
}