/*
  Práctica 7, Ejercicio 13
  Dado un arreglo A ya cargado con t números enteros positivos menores o iguales a 10, 
  y ordenado de menor a mayor, desarrolle una acción que permita insertar un elemento, 
  en el lugar que le corresponde para mantener el orden creciente.

  Chirino, Maximiliano (DNI: 41116761) - C4
*/

#include <stdio.h>

#define Max 10

typedef struct {
  int a[Max];
  int cant;
} TData;

TData datos;

void insertar(TData *arr);
void cargarArreglo(TData *arr);
void mostrarArreglo(TData arr);
int arregloEstaLleno(TData arr);

int main() {
  cargarArreglo(&datos);
  insertar(&datos);
  mostrarArreglo(datos);
}

// Función que inserta un nuevo número en un arreglo existente, manteniendo el orden ascendente
void insertar(TData *arr) {
  int num = 0;
  int i, pos; // i es para ciclar, pos es para la posición en la que se insertará el nuevo número
  
  if (arregloEstaLleno(*arr)) {
    printf("Arreglo lleno, no es posible insertar mas elementos.\n");
  } else {
    while ((num < 1) || (num > 10)) {
      printf("Ingrese un numero entero positivo menor a 10 para insertar en el arreglo: ");
      scanf("%d", &num);
    }
    // Determino en que posicion insertar el nuevo elemento
    for(i = 0; i < (*arr).cant; i++) {
      if (num < (*arr).a[i]) {
        pos = i;
        break;
      } else {
        pos = i + 1;
      }
    }
    // Muevo los demas elementos a la derecha
    for(i = (*arr).cant; i > pos; i--) {
      (*arr).a[i] = (*arr).a[i - 1];
    }
    // Inserto en la posicion adecuada e incremento la cantidad de elementos del arreglo
    (*arr).a[pos] = num;
    (*arr).cant++;
  }
}

// Función que dado un número entre 0 y 10, carga esa cantidad de números en un arreglo
void cargarArreglo(TData *arr) {
  int i;
  (*arr).cant = -1;
  while ((*arr).cant < 0 || (*arr).cant > 10) {
    printf("Ingrese cantidad de numeros a cargar (no mas de 10): ");
    scanf("%d", &arr->cant);
  }
  if ((*arr).cant > 0) {
    printf("Ingrese %d numeros enteros positivos menores o iguales a 10 (Importante: ingresarlos en orden ascendente): \n", arr->cant);
    for(i = 0; i < (*arr).cant; i++) {
      scanf("%d", &arr->a[i]);
    }
  }
}

// Función que muestra todos los elementos de un arreglo
void mostrarArreglo(TData arr) {
  int i;
  printf("----------------\n");
  printf("Arreglo: \n");
  for(i = 0; i < arr.cant; i++) {
    printf("%d ", arr.a[i]);
  }
  printf("\n----------------\n");
}

// Función que determina si un arreglo está lleno o no
int arregloEstaLleno(TData arr) {
  return (arr.cant == Max);
}