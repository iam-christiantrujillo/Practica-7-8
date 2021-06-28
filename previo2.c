#include <stdio.h>
#include <stdlib.h>
#include "listacirc.c"

int main(){
    int opc;
    Lista a = crearLista();
    printf("¡Lista circular creada!\n");
    int num;
    int primero;

    while(1){
        printf("¿Que operación te gustaria hacer en la lista circular?\n");
        printf("1) Imprimir elementos de la lista\n");
        printf("2) Agregar elemento al principio de la lista\n");
        printf("3) Agregar elemento al final de la lista\n");
        printf("4) Borrar primer elemento\n");
        printf("5) Borrar ultimo elemento\n");
        printf("6) Salir\n");
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
                return 0;

            default:
                printf("Opción no valida\n");
        }

        

    }

    return 0;

}