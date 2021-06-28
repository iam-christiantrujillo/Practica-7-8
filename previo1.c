#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(){
    int opc;
    Lista a = crearLista();
    printf("¡Lista creada!\n");
    int num;
    int primero;
    int posicion;

    while(1){
        printf("¿Que operación te gustaria hacer en la lista?\n");
        printf("1) Imprimir elementos de la lista\n");
        printf("2) Agregar elemento al principio de la lista\n");
        printf("3) Agregar elemento al final de la lista\n");
        printf("4) Borrar primer elemento\n");
        printf("5) Borrar ultimo elemento\n");
        printf("6) Mostrar primer elemento\n");
        printf("7) Agregar elemento en una posición\n");
        printf("8) Salir\n");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                print_list(a);
                break;

            case 2:
                printf("¿Que valor entero te gustaria agregar?\n");
                scanf("%d", &num);
                addPrincipioLista(&a, num);
                printf("\n¡Operacion realizada!\n");
                break;

            case 3:
                printf("¿Que valor entero te gustaria agregar?\n");
                scanf("%d", &num);
                addFinalLista(&a, num);
                printf("\n¡Operacion realizada!\n");
                break;

            case 4:
                borrarPrimero(&a);
                printf("\n¡Operacion realizada!\n");
                break;

            case 5:
                borrarUltimo(&a);
                printf("\n¡Operacion realizada!\n");
                break;

            case 6:
                primero = primerElemento(a);
                printf("Primer elemento de la lista: %d\n", primero);
                break;

            case 7:
                printf("¿Que valor entero te gustaria agregar?\n");
                scanf("%d", &num);
                printf("¿En que posicion?\n");
                scanf("%d", &posicion);
                agregarEn(num, posicion, &a);
                printf("\n¡Operacion realizada!\n");
                break;
            
            case 8:
                return 0;

            default:
                printf("Opción no valida\n");
        }

        

    }

    return 0;

}