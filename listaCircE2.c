#include <stdio.h>
#include <stdlib.h>
#include "listaCircE2.h"

struct Nodo{
    Computadora val;
    struct Nodo* next;
};

struct Lista{
	struct Nodo* head;
	int tamano;
};

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano = 0;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	int tamano = lista.tamano;				//se define el tama�o
		printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano > 0 ) {					//tama�o como condicional
        	printf("id: %d, %s de %s \n", current->val.id, current->val.modelo, current->val.marca);
        	current = current->next;
        	tamano--;                           //se reduce tama�o
   	 	}
	}
}

void addFinalLista(Lista *lista, Computadora val) {
	int posicion=lista->tamano;
	if(lista->head==NULL){
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->val = val;
    	nodo->next = nodo;
    	lista->head = nodo;
	}	
	else
	{
		Nodo *current = lista->head;
		while (posicion!=1) {
       		current = current->next;
       		posicion--;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	current->next = nuevoNodo;
		nuevoNodo->val = val;
    	nuevoNodo->next = lista->head;
 		
	}	
	lista->tamano++; 
}

void addPrincipioLista(Lista *lista, Computadora val) {
	
	Nodo *node,*temp;
    node = (Nodo*)malloc(sizeof(Nodo));
    node->val = val;
    if(lista->head==NULL){
    	node->next=node;
	}
    else{
    	node->next = lista->head;
		temp = lista->head;
    	while(temp->next != lista->head){
    		temp=temp->next;
		}
		temp->next=node;
	}
	lista->head = node;
    lista->tamano++;
}

int buscarElemento(Lista lista, int x){
	
	Nodo *temp=lista.head;
	int tamano = lista.tamano;	

	while(tamano>0){
		if(temp->val.id==x){
			printf("%s de %s con %d GB de almacenamiento, procesador %s y memoria de %d GB\n", temp->val.modelo, temp->val.marca, temp->val.almacenamiento, temp->val.procesador, temp->val.memoria);
			return 0;
		}else{
			temp=temp->next;
			tamano--;
		}	
	}

	printf("No se encontro un elemento con este ID en la lista\n");
	return 0;
}

int recorrerLista(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
		int opc;
		int opc2;
    	int tamano = lista.tamano;				
		printf("Elemento de la lista: \n");
    	Nodo *current = lista.head;
   		while (1) {	
        	printf("id: %d, %s de %s \n", current->val.id, current->val.modelo, current->val.marca);
			printf("\nSeleccione:\n");
			printf("1) Ver detalles\n");
			printf("2) Siguiente computadora\n");
			printf("3) Salir\n");
			scanf("%d", &opc);
			switch(opc){
				case 1:
					printf("id: %d, %s de %s con %d GB de almacenamiento, procesador %s y memoria de %d GB\n", current->val.id,current->val.modelo, current->val.marca, current->val.almacenamiento, current->val.procesador, current->val.memoria);
					printf("\nSeleccione:\n");
					printf("1) Siguiente computadora\n");
					printf("2) Salir\n");
					scanf("%d", &opc2);
					if(opc2==1){
						current = current->next;
					}else if(opc2==2){
						return current->val.id;
					}else{
						printf("Opción no valida\n");
					}
					break;

				case 2:
					current = current->next;
					break;

				case 3:
					return current->val.id;

				default:
                	printf("Opción no valida\n");
			}
        	
        	                         
   	 	}
		
	}

	return 0;
}