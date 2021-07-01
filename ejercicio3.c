#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCircD.c"

int main(){

    Lista a = crearLista();

    int opc;
    int num;
    

    while(1){
        printf("\n¿Que operación te gustaria hacer en la lista ligada circular doble?\n");
        printf("1) Imprimir elementos de la lista de inicio a final\n");
        printf("2) Imprimir elementos de la lista del final al inicio\n");
        printf("3) Agregar elemento al inicio\n");
        printf("4) Agregar elemento al final\n");
        printf("5) Agregar elemento en alguna posicion\n");
        printf("6) Eliminar el primer elemento de la lista\n");
        printf("7) Eliminar el ultimo elemento de la lista\n");
        printf("8) Salir\n");
        
        scanf("%d", &opc);

        switch(opc){
            case 1:
                imprimirIF(a);
                break;

            case 2:
                imprimirFI(a);
                break;

            case 4:
                printf("¿Que valor entero te gustaria agregar?\n");
                scanf("%d", &num);
                addFinalLista(&a, num);
                printf("\n¡Operacion realizada!\n");
                break;

            case 6:
                borrarPrimero(&a);
                printf("\n¡Operacion realizada!\n");
                break;

            case 7:
                borrarUltimo(&a);
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