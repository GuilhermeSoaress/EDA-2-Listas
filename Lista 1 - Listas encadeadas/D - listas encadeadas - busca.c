#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x){
    celula *ptr = le->prox;

    while (ptr!= NULL){
        if (ptr->dado == x)
            return ptr;
        
        ptr = ptr ->prox;
    }
    return NULL;
}

celula *busca_rec(celula *le, int x){

    if (le == NULL){
        return NULL;
    }

    if (le->dado == x) return le;
    
    le = le->prox;
    return busca_rec(le, x);
}