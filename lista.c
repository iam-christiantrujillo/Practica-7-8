#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Nodo{
    int val;
    struct Nodo* next;
};

struct Lista{
	struct Nodo* head;
};

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (current != 0) {
        	printf("%d \n",current->val);
			current = current->next;
   	 	}
	}
}

void addPrincipioLista(Lista *lista, int val) {
	Nodo *new_node;
    new_node = (Nodo*)malloc(sizeof(Nodo));
    new_node->val = val;
    new_node->next = lista->head;
    lista->head = new_node;
}

void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){
		
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->val = val;
    	nodo->next = NULL;
    	lista->head = nodo;
	}	
	else
	{
		Nodo *current = lista->head;
		while (current->next != 0) {
       		current = current->next;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	nuevoNodo->val = val;
    	nuevoNodo->next = NULL;
 		current->next = nuevoNodo;
	}	
}



void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	Nodo *nuevo_head = NULL;
    	Nodo *temp = lista->head;
    	nuevo_head=temp->next;
    	free(lista->head);
    	lista->head = nuevo_head;
	}
}

void borrarUltimo(Lista *lista) {
    Nodo *temp = lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	if(temp->next==NULL){
    		lista->head = NULL;
			free(lista->head);	
    	}else{
    		Nodo *current = lista->head;
    		while (current->next->next != NULL) {
        		current = current->next;
    		}
    		current->next = NULL;
			free(current->next);
    		
    	}
	}

}

int primerElemento(Lista lista){
	return lista.head->val;
}

int agregarEn(int num, int posicion, Lista *lista){
	Nodo *new_node;
	new_node = (Nodo*)malloc(sizeof(Nodo));
	new_node->val=num;
	if(posicion==1){
		new_node->next = lista->head;
    	lista->head = new_node;
		return 0;
	}
	Nodo *temp = lista->head;
	for(int i=1; i<posicion;i++){
		temp=temp->next;
	}
	new_node->next=temp;
	temp=lista->head;
	posicion--;
	for(int j=1; j<posicion;j++){
		temp=temp->next;
	}
	temp->next=new_node;
	return 0;

}

void buscarElemento(Lista lista, int x){
	int contador=0;
	Nodo *temp=lista.head;

	while(temp!=NULL){
		if(temp->val==x){
			contador++;
			temp=temp->next;
		}else{
			temp=temp->next;	
		}	
	}

	if(contador==0){
		printf("No se encontro este elemento en la lista\n");
	}else{
		printf("Este elemento fue encontrado %d veces en la lista\n", contador);
	}
}

int borrarElemento(Lista *lista, int posicion){

	if(posicion==1){
		Nodo *nuevo_head = NULL;
    	Nodo *temp = lista->head;
		if(temp->next==NULL){
    		lista->head = NULL;
			free(lista->head);	
    	}else{
			nuevo_head=temp->next;
    		free(lista->head);
    		lista->head = nuevo_head;
		}
    	
	}else{
		Nodo *current = lista->head;
		posicion--;
    	for(int i=1; i<posicion;i++){
        	current = current->next;
		}
		if(current->next->next == NULL){
			printf("Solo son dos\n");
			current->next = NULL;
			free(current->next);
			return 0;
		}
		
    	current->next = current->next->next;
		
		return 0;
	}

}

int eliminarMenores(Lista *lista, int num){
	int contador=0;
	int posicion=0;
	Nodo *temp=lista->head;

	while(temp==lista->head){
		if(temp->val<num){
			
			Nodo *nuevo_head = NULL;
			if(temp->next==NULL){
				lista->head = NULL;
				free(lista->head);
				return 0;	
			}else{
				nuevo_head=temp->next;
				free(lista->head);
				lista->head = nuevo_head;
			}
			temp=lista->head;
			
		}else{
			break;
		}
	}

	while(temp->next!=NULL){
		if(temp->next->val<num){
			temp->next=temp->next->next;	
			
		}else{
			temp=temp->next;
		}
	}




}