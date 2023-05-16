#include <stdio.h>
#include <stdlib.h>

#define M 31

typedef struct celula {
  int chave, ocorr;
  struct celula *prox;
} celula;

celula th[M];

int hash (int chave);

void inicializa_hash (celula *th);
int insere_hash (celula *th, int chave);
int remove_hash (celula *th, int chave);
int busca_ocorr (celula *th, int chave);
void destroi_hash (celula *th);

int hash (int chave) {
  return chave % M;
}

void inicializa_hash (celula *th) {
  for (int i = 0; i < M; i++) th[i].prox = NULL;
}

int insere_hash (celula *th, int chave) {
  celula *elem;
  int pos = hash (chave);

  for (elem = th[pos].prox;
       elem != NULL && elem->chave != chave;
       elem = elem->prox);

  if (elem != NULL) elem->ocorr++;
  else {
    celula *nova = malloc (sizeof (celula));
    if (nova == NULL) return 1;
    nova->chave = chave;
    nova->ocorr = 1;
    nova->prox = th[pos].prox;
    th[pos].prox = nova;
  }

  return 0;
}

int remove_hash (celula *th, int chave) {
  celula *elem;
  int pos = hash (chave);

  for (elem = &th[pos];
       elem->prox != NULL && elem->prox->chave != chave;
       elem = elem->prox);

  if (elem->prox != NULL) {
    celula *lixo = elem->prox;
    elem->prox = lixo->prox;
    free (lixo);

    return 0;
  }
  else {
    return 1;
  }
}

int busca_ocorr (celula *th, int chave) {
  celula *elem;
  int pos = hash (chave);

  for (elem = th[pos].prox;
       elem != NULL && elem->chave != chave;
       elem = elem->prox);

  if (elem != NULL) return elem->ocorr;
  else return 0;
}

void destroi_hash (celula *th) {
  for (int i = 0; i < M; i++) {
    celula *elem = th[i].prox;
    while (elem != NULL) {
      celula *lixo = elem;
      elem = elem->prox;
      free (lixo);
    }
  }
}