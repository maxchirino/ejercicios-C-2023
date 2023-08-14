/*
  Dada una Matriz de [n x m] de enteros, con n >= 3 y m >=3, determinar si la 
  sumatoria de las celdas límites (cáscara) es igual que la sumatoria las celdas del interior 
  (todas menos las límites).
  
  Chirino, Maximiliano (DNI: 41116761) - C3
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

void MostrarMatriz(TData matriz);
void CargarMatriz(TData *matriz);
void sumatoriaCascaraCorazon(TData matriz);

int main() {
  CargarMatriz(&matriz);
  printf("\n");
  MostrarMatriz(matriz);
  printf("\n");
  sumatoriaCascaraCorazon(matriz);
  return 0;
}

// Función para determinar la sumatoria de la cáscara
void sumatoriaCascaraCorazon(TData matriz) {
  int sumCascara = 0;
  int sumCorazon = 0;
  for(int i = 0; i < matriz.cantFila; i++) {
    for(int j = 0; j < matriz.cantCol; j++) {
      if (
        (i == 0) ||
        (i == matriz.cantFila-1) ||
        (j == 0) ||
        (j == matriz.cantCol-1)
      ) {
        // Estoy parado en la cascara
        sumCascara = sumCascara + matriz.m[i][j];
      } else {
        // Estoy parado en el corazon
        sumCorazon = sumCorazon + matriz.m[i][j];
      }
    }
  }
  printf("Sumatoria de Cascara: %d\n", sumCascara);
  printf("Sumatoria de Cascara: %d\n", sumCorazon);
  if (sumCascara == sumCorazon) {
    printf("Las sumatorias son iguales\n");
  } else {
    printf("Las sumatorias NO son iguales\n");
  }
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
  printf("Cantidad de Filas (3 o mas): ");
  scanf("%d", &matriz->cantFila);
  printf("Cantidad de Columnas (3 o mas): ");
  scanf("%d", &matriz->cantCol);
  for(int i = 0; i < matriz->cantFila; i++) {
    for(int j = 0; j < matriz->cantCol; j++) {
      printf("Ingresar numero a insertar en la matriz: ");
      scanf("%d", &matriz->m[i][j]);
    }
  }
}
