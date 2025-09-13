#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101
#define MAX_KEY_LEN 16

char *tabela[TABLE_SIZE];

long long h(const char *key)
{
    long long sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += (long long)key[i] * (i + 1);
    }
    return 19 * sum;
}

int hash_key(const char *key)
{
    long long hash_val = h(key);
    return (int)((hash_val % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE);
}

int buscar_chave(const char *key)
{
    int initial_pos = hash_key(key);
    for (int j = 0; j < 20; j++)
    {
        int pos = (initial_pos + j * j + 23 * j) % TABLE_SIZE;
        if (tabela[pos] != NULL && strcmp(tabela[pos], key) == 0)
        {
            return pos;
        }
    }
    return -1;
}

void inserir_chave(const char *key)
{
    if (buscar_chave(key) != -1)
    {
        return;
    }

    int initial_pos = hash_key(key);
    for (int j = 0; j < 20; j++)
    {
        int pos = (initial_pos + j * j + 23 * j) % TABLE_SIZE;
        if (tabela[pos] == NULL)
        {
            tabela[pos] = (char *)malloc(MAX_KEY_LEN * sizeof(char));
            if (tabela[pos] != NULL)
            {
                strcpy(tabela[pos], key);
            }
            return;
        }
    }
}

void deletar_chave(const char *key)
{
    int pos = buscar_chave(key);
    if (pos != -1)
    {
        free(tabela[pos]);
        tabela[pos] = NULL;
    }
}

void resolver_caso_teste()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tabela[i] = NULL;
    }

    char operacao[5];
    char chave[MAX_KEY_LEN];

    for (int i = 0; i < n; i++)
    {
        scanf(" %4[^:]:%s", operacao, chave);
        if (strcmp(operacao, "ADD") == 0)
        {
            inserir_chave(chave);
        }
        else if (strcmp(operacao, "DEL") == 0)
        {
            deletar_chave(chave);
        }
    }

    int contador_chaves = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tabela[i] != NULL)
        {
            contador_chaves++;
        }
    }

    printf("%d\n", contador_chaves);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (tabela[i] != NULL)
        {
            printf("%d:%s\n", i, tabela[i]);
            free(tabela[i]);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        resolver_caso_teste();
    }
    return 0;
}