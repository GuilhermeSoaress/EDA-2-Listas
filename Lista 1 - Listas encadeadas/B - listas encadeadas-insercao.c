#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

celula* inicializaCelula(){
    celula *le = malloc(sizeof(celula));

    if (le==NULL)
        return NULL;
    else{
        le->prox=NULL;
        le->dado=NULL;
    }
    return le;
}

celula *busca(celula *le, int x){
    celula *ptr = le->prox;

    while (ptr!= NULL){
        if (ptr->dado == x)
            return ptr;
        
        ptr = ptr ->prox;
    }
    return NULL;
}

void insere_inicio(celula *le, int x){
    if (le->prox == NULL){
        celula *no = inicializaCelula();
        no->dado = x;
        le->prox = no;
    }
    else{
        celula *no = inicializaCelula();
        no->dado = x;
        no->prox = le->prox;
        le->prox = no;
    }
    return;
}

void insere_antes(celula *le, int x, int y){
    
    if (busca(le, y)==NULL){
        celula *no = inicializaCelula;
        
    }

    else{

    }
}
