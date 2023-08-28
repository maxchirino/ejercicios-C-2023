#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ejercicio 1 
typedef struct nodo {
	int info;
	struct nodo *next;
} TNodo;

TNodo *q, *r, *s, *t, *p;

void MostrarLista1(TNodo *puntero);

// Ejercicio 4
typedef struct {
	char nom[50];
	char ape[50];
	int dni;
	int edad;
} Tpers;

typedef struct elem {
	Tpers info;
	struct elem *next;
} Telem;

Telem *l;
Tpers reg;
int opcion;

void Listar(Telem *list);
void Crear(Telem **list);
int vacia(Telem *list);
void InsertarCab(Telem **list, Tpers reg);
void MostrarMenu();

int main() {
	// Ejercicio 1 - Creacion de la LSE
	printf("INICIO - Ejercicio 1\n");
	q = (TNodo *) malloc(sizeof(TNodo));
	q->info = 14;
	q->next = NULL;
	s = (TNodo *) malloc(sizeof(TNodo));
	s->info = 25;
	s->next = q;
	q = s;
	s = (TNodo *) malloc(sizeof(TNodo));
	s->info = 20;
	s->next = q;
	q = s;
	s = (TNodo *) malloc(sizeof(TNodo));
	s->info = 11;
	s->next = q;
	q = s;
	s = NULL;
	// Estado inicial creado
	MostrarLista1(q);
	printf("FIN - Ejercicio 1\n");
	
	// Ejercicio 4
	printf("INICIO - Ejercicio 4\n");
	MostrarMenu();
	scanf("%d",&opcion);
	while (opcion == 1 || opcion == 2 || opcion == 3) {
		if (opcion == 1) { 
			if (!vacia(l)) { Crear(&l); }
			printf("Nombre a insertar: \n");
			scanf("%s", &reg->nom);
			printf("Apellido a insertar: \n");
			scanf("%s", &reg->ape);
			printf("DNI a insertar: \n");
			scanf("%d", &reg->dni);
			printf("Edad a insertar: \n");
			scanf("%d", &reg->edad);
			InsertarCab(&l, reg);
		}
		if (opcion == 3) { Listar(l); }
		MostrarMenu();
		scanf("%d",&opcion);
	}
	printf("FIN - Ejercicio 4\n");

	return 0;
}

// Ejercicio 1 - Muestra la lista
void MostrarLista1(TNodo *puntero) {
    int i=0;
    //printf("Mostrando la lista completa:\n");
    while (puntero!=NULL) {
          printf( "Numero: %d \n", puntero->info);
          puntero = puntero->next;
          i++;
    }
    if (i==0) printf( "\nLa lista esta vacia!!\n" );
}

// Ejercicio 4
void Listar(Telem *list) {
	Telem *aux;
	aux = list;
	while (aux != NULL) {
		printf("Nombre: %s\n", aux->info.nom);
		printf("Apellido: %s\n", aux->info.ape);
		printf("DNI: %d\n", aux->info.dni);
		printf("Edad: %d\n", aux->info.edad);
		aux = aux->next;
	}
}

void Crear(Telem **list) {
	*list = NULL;
}

int vacia(Telem *list) {
	return *list = NULL;
}

void InsertarCab(Telem **list, Tpers reg) {
	Telem *aux;
	aux = (Telem *) malloc(sizeof(Telem));
	strcpy(aux->info.nom, reg.nom);
	strcpy(aux->info.ape, reg.ape);
	aux->info.dni = reg.dni;
	aux->info.edad = reg.edad;
	aux->next = *list;
	*list = aux;
}

void MostrarMenu() {
      printf("\n\nMenu:\n=====\n\n");
      printf("1.- Insertar a la cabeza\n");
      printf("2.- Suprimir a la cabeza\n");
      printf("3.- Mostrar lista\n");
      printf("Otro valor.- Salir\n\n");
      printf("Escoge una opcion: ");
      fflush(stdout);
 }
