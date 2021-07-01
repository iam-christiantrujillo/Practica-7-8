#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
	char marca[20];
	char modelo[30];
    int almacenamiento;
    char procesador[30];
    int memoria;
}Computadora;

Computadora crearComputadora(int, char*, char*, int, char*, int);
void imprimirComputadora(Computadora);

Computadora crearComputadora(int id, char *marca, char *modelo, int almacenamiento, char *procesador, int memoria ){
    Computadora computadoraCreada;
    computadoraCreada.id= id;
    strcpy(computadoraCreada.marca,marca);
    strcpy(computadoraCreada.modelo,modelo);
    computadoraCreada.almacenamiento = almacenamiento;
    strcpy(computadoraCreada.procesador,procesador);
    computadoraCreada.memoria = memoria;

    return computadoraCreada;
}

void imprimirComputadora(Computadora compuPrint){
    printf("ID: %d\n", compuPrint.id);
    printf("Marca: %s\n", compuPrint.marca);
    printf("Modelo: %s\n", compuPrint.modelo);
    printf("Almacenamiento en GB: %d\n", compuPrint.almacenamiento);
    printf("Procesador: %s\n", compuPrint.procesador);
    printf("Memoria en GB: %d\n", compuPrint.memoria);
}
