#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCircE2.c"

int main(){
    Lista a = crearLista();
    Computadora uno = crearComputadora(1, "Apple", "Macbook Pro", 500, "Chip M1", 50); 
    Computadora dos = crearComputadora(2, "Apple", "Macbook Air", 200, "Intel Core", 30); 
    Computadora tres = crearComputadora(3, "Apple", "iMac", 900, "Intel Core", 50); 
    Computadora cuatro = crearComputadora(4, "Apple", "iMac Pro", 1200, "Chip M1", 60);
    addPrincipioLista(&a, uno);
    addFinalLista(&a, dos);
    addFinalLista(&a, tres);
    addFinalLista(&a, cuatro);
    print_list(a);

    int opc;
    int idItem;
    int aux;

    while(1){
        printf("\n¿Que operación te gustaria hacer en la lista de Computadoras?\n");
        printf("1) Imprimir elementos de la lista\n");
        printf("2) Buscar computadora por su ID\n");
        printf("3) Recorrer lista de computadoras\n");
        printf("4) Salir\n");
        

        scanf("%d", &opc);

        switch(opc){
            case 1:
                print_list(a);
                break;

            case 2:
                printf("¿Cual es el id de la computadora que quieres buscar?\n");
                scanf("%d", &idItem);
                buscarElemento(a, idItem);
                break;

            case 3:
                aux = recorrerLista(a);
                break;
            
            case 4:
                return 0;

            default:
                printf("Opción no valida\n");
        }

    }


    return 0;
}