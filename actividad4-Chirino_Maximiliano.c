/*
  Dado un carácter determinar si el mismo es una consonante, una vocal, 
  o ninguno de estos (es decir o es un símbolo o un carácter número: 0, 1,..,9).

  Chirino, Maximiliano (DNI: 41116761) - C4
*/

#include <stdio.h>

char letra;

// ---- Declaración de funciones ----
int esMayuscula(char c);
int esMinuscula(char c);
int esVocal(char c);
int esNumero(char c);
int esConsonante(char c);

int main() {
  printf("Ingrese un caracter: ");
  scanf("%c", &letra);
  return esConsonante(letra);
}

// ---- Implementación de funciones ----
int esMayuscula(char c) {
  return ((c >= 'A') && (c <= 'Z'));
}

int esMinuscula(char c) {
  return ((c >= 'a') && (c <= 'z'));
}

int esVocal(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int esNumero(char c) {
  return ((c >= '0') && (c <= '9'));
}

int esConsonante(char c) {
  if (esVocal(letra)) {
    printf("%c es una vocal.\n", letra);
  } else if (esMayuscula(letra) || esMinuscula(letra)) {
    printf("%c es una consonante.\n", letra);
  } else if (esNumero(letra)) {
    printf("%c es un caracter numero.\n", letra);
  } else {
    printf("%c es un simbolo.\n", letra);
  }
  return 0;
}