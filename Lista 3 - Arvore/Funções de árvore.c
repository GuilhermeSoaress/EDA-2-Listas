#include<stdio.h>

enum Cor{vermelho,preto};

typedef struct no {
    int dado;
    enum Cor cor;
    struct  no *esq , *dir;
}no;
 
void preordem(no *raiz){
    if(raiz==NULL) return ;
    printf("%d\n",raiz->dado);
    preordem(raiz->esq);
    preordem(raiz->dir);
}

void emordem(no *raiz){
    if(raiz==NULL) return ;
    emordem(raiz->esq);
    printf("%d\n",raiz->dado);
    emordem(raiz->dir);
}

void posordem(no *raiz){
    if(raiz==NULL) return ;
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("%d\n",raiz->dado);
}

int altura(no *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int he = altura(raiz->esq);
        int hd = altura(raiz->dir);
        if(he>hd) return he+1;
        else return hd+1;
    }
}

no *busca (no* raiz, int x){
    if(raiz == NULL || raiz->dado == x)return raiz;
    if(x < raiz->dado){
        return busca(raiz->esq,x);
    }
    else{
        return busca (raiz->dir,x);
    }
}

no *insere(no* raiz,int x){
    if(raiz == NULL){
        no *novo = malloc(sizeof(no));
        novo->dado = x;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }
    if( x< raiz->dado){
        raiz->esq = insere(raiz->esq,x);
    }
    else{
        raiz->dir = insere (raiz->dir,x);
    }
}

no *minimo (no* raiz){
    if(raiz->esq == NULL) return raiz;
    return minimo (raiz->esq);
}

no *maximo (no* raiz){
    if(raiz->dir == NULL) return raiz;
    return maximo (raiz->dir);
}

no *remove(no *raiz, int x){ //Complexidade O(h)
        if(x<raiz->dado){
            raiz->esq = remove(raiz->esq,x);
        }
        else if(x>raiz->dado){
            raiz->dir = remove(raiz->dir,x);
        }
        else if(raiz->dir == NULL){
            no* ret = raiz->esq ;
            free(raiz);
            return ret;
        }
        else if(raiz->esq == NULL){
            no* ret = raiz->dir;
            free(raiz);
            return ret;
        }
        else {
            remove_sucessso(raiz);
        }
    return raiz;
}

void remove_sucessor(no*raiz){
    no *pai = raiz;
    no *min = raiz->dir;
    while(min->esq != NULL){
        pai = min;
        min = min->esq;
    }
    raiz->dado = min->dado;
    if(min == pai->dir){
        pai->dir = min->dir;
    }
    else {
        pai->dir = min->dir;
        free(min);
    }
}

int ehVermelho(no*x){
    if(x== NULL) return 0;
    return x->cor == vermelho;
}

int ehPreto(no*x){
    if(x== NULL) return 1;
    return x->cor == preto;
}

no *rotaciona_esquerda(no *raiz){
    no *tmp = raiz->dir;
    raiz->dir = tmp->esq;
    tmp->esq = raiz;
    tmp->cor = raiz->cor;
    raiz->cor = vermelho;
    return tmp;
}

// no *rotaciona_direita(no *raiz){
//     no *tmp = raiz->dir;
//     raiz->dir = tmp->esq;
//     tmp->esq = raiz;
//     tmp->cor = raiz->cor;
//     raiz->cor = vermelho;
//     return tmp;
// }


no *insere_RedBlack(no*raiz,int x){
    if(raiz == NULL){
        no *novo = calloc(1,sizeof(no));
        novo->dado = x;
        novo->cor = vermelho;
        return novo;
    }
    if( x< raiz->dado){
        raiz->esq = insere(raiz->esq,x);
    }
    else{
        raiz->dir = insere (raiz->dir,x);
    }
    if(ehVermelho(raiz->dir) && ehPreto(raiz->esq)){
        raiz = rotaciona_esquerda(raiz);
    }
    if(ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq)){
        raiz = rotaciona_direita(raiz);
    }
    if(ehVermelho(raiz->dir) && ehVermelho(raiz->esq)){
        sobe_cor(raiz);
    }
    return raiz;
}