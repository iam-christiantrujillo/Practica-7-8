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

void addPrincipioLista(Lista *lista,int val){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->val = val;

    if(lista->head==NULL){
        lista->head = nodo;
    	lista->head->next = lista->head;
        lista->ultimo = lista->head;
        lista->head->prev = lista->ultimo;
    }else{
        lista->head->prev=nodo;
        nodo->next= lista->head;
        lista->ultimo->next=nodo;
        nodo->prev=lista->ultimo;
        lista->head=nodo;
    }
    lista->tamano++; 
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

int agregarEn(int num, int posicion , Lista *lista){
    Nodo *new_node=(Nodo*)malloc(sizeof(Nodo));
	new_node->val=num;

    if(lista->tamano+1>=posicion){
        if(posicion==1){
            
                lista->head->prev=new_node;
                new_node->next= lista->head;
                lista->ultimo->next=new_node;
                new_node->prev=lista->ultimo;
                lista->head=new_node;
            
            lista->tamano++; 
        }else if(posicion==lista->tamano+1){
            
                lista->ultimo->next=new_node;
                new_node->next= lista->head;
                new_node->prev = lista->ultimo;
                lista->ultimo=new_node;
                lista->head->prev = lista->ultimo;
            
            lista->tamano++; 
        }else{
            printf("Valor de posicion: %d\n", posicion);
            printf("Entramos aqui\n");
            Nodo *current = lista->head;
	        for(int i=1; i<posicion;i++){
		        current=current->next;
                
	        }
            printf("Entramos en 1 %d\n", current->val);
            new_node->next=current;
            current->prev=new_node;
            current=lista->head;
            posicion--;
            printf("Valor de posicion: %d\n", posicion);
            for(int j=1; j<posicion;j++){
		        current=current->next;
            }
            printf("Entramos en 2 %d\n", current->val);
            current->next=new_node;
            new_node->prev=current;
            lista->tamano++; 
        }
    }else{
        printf("No es posible realizar la operacion debido al tamano de la lista\n");
    }


    return 0;
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

void imprimiTamano(Lista lista){
    printf("Tamano de la lista: %d\n", lista.tamano);
}