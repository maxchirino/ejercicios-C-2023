/*
  Práctica 8, Ejercicio 5
  Desarrolle una función que dado un arreglo bidimensional de enteros (tamaño n x m) y un número entero, 
  retorne verdadero si dicho número está repetido más de 3 veces en la matriz, y falso en caso contrario.

  Chirino, Maximiliano (DNI: 41116761) - C4
*/

#include <stdio.h>

#define Fil 10
#define Col 10

typedef struct {
  int m[Fil][Col];
  int cantFila;
  int cantCol;
} TData;

TData matriz;
int num = 0;

void MostrarMatriz(TData matriz);
void CargarMatriz(TData *matriz);
int seRepite(TData matriz, int num);

int main() {
  CargarMatriz(&matriz);
  printf("\n");
  MostrarMatriz(matriz);
  printf("\n");
  printf("Ingrese un numero a buscar en la matriz: ");
  scanf("%d", &num);
  printf("===============================================\n");
  if (seRepite(matriz, num)) {
    printf("El numero %d se repite mas de tres veces en la matriz.\n", num);
  } else {
    printf("El numero %d NO se repite mas de tres veces en la matriz.\n", num);
  }

  return 0;
}

// Función que dada una matriz y un número, devuelve verdadero 
// si el número se repite más de 3 veces en la matriz
int seRepite(TData matriz, int num) {
  int cant = 0;
  for(int i = 0; i < matriz.cantFila && cant <= 3; i++) {
    for(int j = 0; j < matriz.cantCol && cant <= 3; j++) {
      // Dentro de los "para" también veo si ya se cumplió la condición, para no ciclar innecesariamente
      if (matriz.m[i][j] == num) {
        cant++;
      }
    }
  }

  return (cant > 3);
}

// Función para mostrar la matriz
void MostrarMatriz(TData matriz) {
  for(int i = 0; i < matriz.cantFila; i++) {
    for(int j = 0; j < matriz.cantCol; j++) {
      if (j == 0) {
        printf("|");
      }
      printf(" %d |", matriz.m[i][j]);
    }
    printf("\n");
  }
}

// Función para cargar la matriz
void CargarMatriz(TData *matriz) {
  printf("Cantidad de Filas: ");
  scanf("%d", &matriz->cantFila);
  printf("Cantidad de Columnas: ");
  scanf("%d", &matriz->cantCol);
  for(int i = 0; i < matriz->cantFila; i++) {
    for(int j = 0; j < matriz->cantCol; j++) {
      printf("Ingresar numero a insertar en la matriz: ");
      scanf("%d", &matriz->m[i][j]);
    }
  }
}