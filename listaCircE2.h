#include "Computadora.h"
typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,Computadora);
void addFinalLista(Lista*,Computadora);
int buscarElemento(Lista, int);
int recorrerLista(Lista);
