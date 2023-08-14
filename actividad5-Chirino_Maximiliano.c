/*
  Práctica 6, Ejercicio 11
  Chirino, Maximiliano (DNI: 41116761) - C4
*/

#include <stdio.h>

int a,b;

/*
  P: ¿Que hace esta acción implementada en lenguaje C?
  La acción Swap intercambia los valores de dos variables de tipo Entero.
*/
void Swap (int *x,int *y) {
  *x = (*x)+(*y);
  *y = (*x)-(*y); 
  *x = (*x)-(*y); 
}

int main() {
  /*
    P: ¿Qué resultado mostraría cada uno de los printf de a, b, a, en el siguiente programa C? 
  */
  printf("Introduce el valor de la variable a: ");
  scanf("%i",&a);
  printf("Introduce el valor de la variable b: ");
  scanf("%i",&b); 
  Swap (&a, &b);
  printf ("El valor de a es %d \n", a); // Muestra el valor de "a", una vez intercambiado por el valor de "b".
  printf ("El valor de b es %d \n", b); // Muestra el valor de "b", una vez intercambiado por el valor de "a".
  printf("******** A partir de ahora llamo a Swap con 'a' en ambos parámetros ********\n");
  printf("Introduce el valor de la variable a: ");
  scanf("%i",&a);
  printf("Introduce el valor de la variable b: ");
  scanf("%i",&b);
  Swap (&a, &a);
  printf ("El valor de a es: %d \n", a); // Muestra el valor 0, independientemente de cuáles sean los valores ingresados para "a" y "b".

  printf("(Caso 1, a=10 y b=3) \n");
  printf("Introduce el valor de la variable a: "); // Introducir 10
  scanf("%i",&a);
  printf("Introduce el valor de la variable b: "); // Introducir 3
  scanf("%i",&b);
  Swap (&a, &a);
  printf ("El valor de a es: %d \n", a); // Debe mostrar 0

  printf("(Caso 2, a=2 y b=8) \n");
  printf("Introduce el valor de la variable a: "); // Introducir 2
  scanf("%i",&a);
  printf("Introduce el valor de la variable b: "); // Introducir 8
  scanf("%i",&b);
  Swap (&a, &a);
  printf ("El valor de a es: %d \n", a); // Debe mostrar 0

  return 0;
}

/*
  Razón por la que el último printf siempre muestra 0:
  Dado que en C no existe el pasaje de parámetros por Dato-Resultado en sí, si no que lo emulamos mediante el uso de punteros, al llamar a la acción Swap con la misma variable en ambos parámetros, sucede lo siguiente:
  Los valores que recibe Swap (y usa como parámetros formales dentro de la acción) es la dirección de memoria de la variable "a", dos veces. Esto es, *x y *y tienen ambos la dirección de memoria de "a". A modo de ejemplo, supongamos que llamamos la acción con el valor de a = 10
  En la línea 1 hace *x = (*x)+(*y), por lo que  x = 10 + 10, o sea x = 20.
  Ahora, como ambos parámetros contienen la misma dirección de memoria, esto hace que "y" también sea 20. Este comportamiento se repite en toda la acción, donde x e y contienen el mismo valor. Entendiendo esto:
  En la línea 2 hace *y = (*x)-(*y), por lo que y = 20 - 20, o sea y = 0, x = 0.
  En la línea 3 hace *x = (*x)-(*y), por lo que x = 0 - 0. o sea x = 0, y = 0.

  Esto explica por qué, independientemente del valor que ingresemos en "a", si llamamos a Swap(&a,&a), el valor final de "a" siempre será 0.

  Casos de prueba (ver el código modificado):
  Swap(10, 3)
  Swap (2, 8)
*/