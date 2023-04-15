#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le){
    if (le->prox == NULL){
        printf("NULL\n");
    }
    else{
        
        while (le->prox != NULL){
            le = le->prox;
            int dado = le->dado;

            printf("%d -> ", dado);
        }
        printf("NULL\n");
    }
}

void imprime_rec(celula *le){
    
    if (le->prox == NULL){
        printf("NULL\n");
        return;
    }

    else{
        le = le->prox;
        int dado = le->dado;
        printf("%d -> ", dado);
    }
    imprime_rec(le);
}