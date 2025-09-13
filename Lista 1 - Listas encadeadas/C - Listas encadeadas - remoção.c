#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p == NULL || p->prox == NULL)
    {
        return 0;
    }

    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);

    return 1;
}

void remove_elemento(celula *le, int x)
{
    celula *p = le;
    while (p->prox != NULL && p->prox->dado != x)
    {
        p = p->prox;
    }

    if (p->prox != NULL)
    {
        remove_depois(p);
    }
}

void remove_todos_elementos(celula *le, int x)
{
    celula *p = le;
    while (p->prox != NULL)
    {
        if (p->prox->dado == x)
        {
            remove_depois(p);
        }
        else
        {
            p = p->prox;
        }
    }
}