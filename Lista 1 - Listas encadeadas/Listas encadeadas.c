#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} No;

No *criarNo(int valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

No *inserirInicio(No *cabeca, int valor)
{
    No *novoNo = criarNo(valor);
    if (novoNo == NULL)
        return cabeca;

    novoNo->proximo = cabeca;
    return novoNo;
}

No *inserirFim(No *cabeca, int valor)
{
    No *novoNo = criarNo(valor);
    if (novoNo == NULL)
        return cabeca;

    if (cabeca == NULL)
    {
        return novoNo;
    }

    No *atual = cabeca;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
    return cabeca;
}

No *removerInicio(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }

    No *temp = cabeca;
    cabeca = cabeca->proximo;
    free(temp);
    printf("Primeiro elemento removido com sucesso!\n");
    return cabeca;
}

No *removerFim(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }

    if (cabeca->proximo == NULL)
    {
        free(cabeca);
        printf("Ultimo elemento removido com sucesso!\n");
        return NULL;
    }

    No *atual = cabeca;
    while (atual->proximo->proximo != NULL)
    {
        atual = atual->proximo;
    }

    free(atual->proximo);
    atual->proximo = NULL;
    printf("Ultimo elemento removido com sucesso!\n");
    return cabeca;
}

No *removerElemento(No *cabeca, int valor)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }

    if (cabeca->dado == valor)
    {
        No *temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
        printf("Elemento %d removido com sucesso!\n", valor);
        return cabeca;
    }

    No *atual = cabeca;
    while (atual->proximo != NULL && atual->proximo->dado != valor)
    {
        atual = atual->proximo;
    }

    if (atual->proximo != NULL)
    {
        No *temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
        printf("Elemento %d removido com sucesso!\n", valor);
    }
    else
    {
        printf("Elemento %d nao encontrado na lista!\n", valor);
    }

    return cabeca;
}

void imprimirLista(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    printf("Lista: ");
    No *atual = cabeca;
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

No *liberarLista(No *cabeca)
{
    while (cabeca != NULL)
    {
        No *temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
    }
    return NULL;
}

int main()
{
    No *lista = NULL;
    int opcao, valor;

    printf("=== LISTA ENCADEADA - OPERACOES DE REMOCAO ===\n");

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Remover elemento especifico\n");
        printf("6. Imprimir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            lista = inserirInicio(lista, valor);
            break;

        case 2:
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            lista = inserirFim(lista, valor);
            break;

        case 3:
            lista = removerInicio(lista);
            break;

        case 4:
            lista = removerFim(lista);
            break;

        case 5:
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            lista = removerElemento(lista, valor);
            break;

        case 6:
            imprimirLista(lista);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    lista = liberarLista(lista);

    return 0;
}
