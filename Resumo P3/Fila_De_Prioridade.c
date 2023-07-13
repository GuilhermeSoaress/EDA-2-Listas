#include<stdio.h>
#include<stdlib.h>

typedef int Item;

typedef struct FP{
    Item *v;
    int n,tam; // n = quantidade de elementos , tam = tamanho do vetor
}FP;

void troca (Item *v, int i, int j){
    Item tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void sobe_no_heap(FP *fp,int i){
    int Pai = (i-1)/2;
    if(i> 0 && fp->v[Pai] < fp->v[i]){
        troca(fp->v,i,Pai);
        sobe_no_heap(fp,Pai);
    }
}

void desce_no_heap(FP *fp,int i){
    int fe = 2*i+1;
    int fd = fe+1;
    if(i < fp->n && fp->v[i] < fp->v[maxind(fp->v[fe],fp->v[fd])]){
        troca(fp->v,i,maxind(fp->v[fe],fp->v[fd]));
        desce_no_heap(fp,maxind(fp->v[fe],fp->v[fd]));
    }
}

void insere(FP *fp,Item it){
    if(fp->n == fp->tam){ //pode redimensionar o tamanho ou atingiu o limite
        fp->v = realloc(fp->v,2*fp->tam*sizeof(Item));
        fp->tam *=2;
    }
    fp->v[fp->n] = it;
    sobe_no_heap(fp,fp->n);
    fp->n++;
}

void remove_maximo(FP *fp){
    troca(fp->v,0,fp->n-1);
    desce_no_heap(fp,0);
    fp->n--;
    return fp->v[fp->n+1];
}



