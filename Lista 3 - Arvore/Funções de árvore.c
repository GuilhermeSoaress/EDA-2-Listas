#include <stdio.h>

typedef struct no {
    int valor;
    int *esq;
    int *dir
}no;
//calcular altura 
int altura (no *raiz){
    if (raiz == NULL) return -1;
    else{
        int he = altura (raiz->esq);
        int hd = altura(raiz->dir);
        if (he>hd) return he + 1;
        else{
            return hd + 1;
        }
    }
}