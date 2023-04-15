#include <stdio.h>
#include <stdlib.h>

// os "le's" de diferentes funções nao precisam ter o mesmo nome de variável

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

void insereDadoNoInicio(celula *le, int x){
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

celula *busca(celula *le, int x){

    while (le->prox != NULL){
        if (le->prox->dado == x){
            printf(" - aqui - ");
            return le->prox;
            }
        else{
            le->prox = le->prox->prox;
        }
    }
}

int main(){

    celula *le = inicializaCelula();
    insereDadoNoInicio(le, 2);
    insereDadoNoInicio(le, 5);
    insereDadoNoInicio(le, 10);
    busca(le, 5);
    imprime(le);
    imprime_rec(le);
}