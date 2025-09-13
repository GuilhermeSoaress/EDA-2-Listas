#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 140009

typedef struct no
{
    int numero;
    struct no *prox;
} No;

int hash(int numero)
{
    return abs(numero) % TAMANHO_TABELA;
}

void inserir(No *tabela[], int numero)
{
    int indice = hash(numero);

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        exit(1);
    }
    novo_no->numero = numero;

    novo_no->prox = tabela[indice];
    tabela[indice] = novo_no;
}

int buscar(No *tabela[], int numero)
{
    int indice = hash(numero);
    No *atual = tabela[indice];

    while (atual != NULL)
    {
        if (atual->numero == numero)
        {
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

void liberar_tabela(No *tabela[])
{
    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        No *atual = tabela[i];
        while (atual != NULL)
        {
            No *proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }
}

int main()
{
    No *tabela[TAMANHO_TABELA];

    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        tabela[i] = NULL;
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int numero_proibido;
        scanf("%d", &numero_proibido);
        inserir(tabela, numero_proibido);
    }

    int consulta;
    long capacidade_resultados = 1024;
    long n_resultados = 0;
    int *resultados = (int *)malloc(capacidade_resultados * sizeof(int));
    if (resultados == NULL)
    {
        liberar_tabela(tabela);
        return 1;
    }

    while (scanf("%d", &consulta) != EOF)
    {
        if (n_resultados == capacidade_resultados)
        {
            capacidade_resultados *= 2;
            int *temp = (int *)realloc(resultados, capacidade_resultados * sizeof(int));
            if (temp == NULL)
            {
                liberar_tabela(tabela);
                free(resultados);
                return 1;
            }
            resultados = temp;
        }

        resultados[n_resultados] = buscar(tabela, consulta);
        n_resultados++;
    }

    for (long i = 0; i < n_resultados; i++)
    {
        if (resultados[i] == 1)
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
    }

    liberar_tabela(tabela);
    free(resultados);

    return 0;
}