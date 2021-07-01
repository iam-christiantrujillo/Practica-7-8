#include <stdio.h>
#include <stdlib.h>
#include "listaCircD.h"

struct Nodo{
    int val;
    struct Nodo* next;
    struct Nodo* prev;
};

struct Lista{
	struct Nodo* head;
    struct Nodo* ultimo;
	int tamano;
};

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
    lista.ultimo = NULL;
	lista.tamano = 0;
	return lista;
}

void imprimirIF(Lista lista) {
    Nodo *temp=(Nodo*)malloc(sizeof(Nodo));
    temp = lista.head;
    if(lista.head!=NULL){
        printf("Los elementos de la lista son: \n");
        do{
            printf("%d \n", temp->val);
            temp=temp->next;

        }while(temp!=lista.head);
    }else{
        printf("LA LISTA ESTA VACIA \n");
    }

}

void imprimirFI(Lista lista) {
    Nodo *temp=(Nodo*)malloc(sizeof(Nodo));
    temp = lista.ultimo;
    if(lista.head!=NULL){
        printf("Los elementos de la lista son: \n");
        do{
            printf("%d \n", temp->val);
            temp=temp->prev;

        }while(temp!=lista.ultimo);
    }else{
        printf("LA LISTA ESTA VACIA \n");
    }

}

void addFinalLista(Lista *lista, int val) {
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->val = val;
	
	if(lista->head==NULL){
        lista->head = nodo;
    	lista->head->next = lista->head;
        lista->ultimo = lista->head;
        lista->head->prev = lista->ultimo;
	}else{
		lista->ultimo->next=nodo;
        nodo->next= lista->head;
        nodo->prev = lista->ultimo;
        lista->ultimo=nodo;
        lista->head->prev = lista->ultimo;
	}	
	lista->tamano++; 
}

void borrarPrimero(Lista* lista){
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
        if(lista->head->next==lista->head){
    		lista->head = NULL;
			free(lista->head);
			lista->tamano--;	
    	}else{
        Nodo *nuevo_head = NULL;
    	Nodo *temp = lista->head;
    	nuevo_head=lista->head->next;
        free(lista->head);
        lista->head=nuevo_head;
        lista->head->prev= lista->ultimo;
        lista->ultimo->next=lista->head;
		lista->tamano--;
        }
	}
}

void borrarUltimo(Lista* lista){
    Nodo *temp = lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
        if(temp->next==lista->head){
    		lista->head = NULL;
			free(lista->head);
			lista->tamano--;	
    	}else{
            Nodo *nuevo_ultimo = NULL;
    	    Nodo *current = lista->ultimo;
            nuevo_ultimo= lista->ultimo->prev;
            free(lista->ultimo);
            lista->ultimo=nuevo_ultimo;
            lista->ultimo->next= lista->head;
            lista->head->prev=lista->ultimo;
			lista->tamano--;
        }
    	
    		
    	
	}
}