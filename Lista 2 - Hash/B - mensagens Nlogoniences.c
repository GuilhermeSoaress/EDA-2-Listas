#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long seq;
    char c;
} Pacote;

int compara_pacotes(const void *a, const void *b)
{
    Pacote *pacoteA = (Pacote *)a;
    Pacote *pacoteB = (Pacote *)b;

    if (pacoteA->seq < pacoteB->seq)
    {
        return -1;
    }
    if (pacoteA->seq > pacoteB->seq)
    {
        return 1;
    }
    return 0;
}

int main()
{
    long capacidade = 1024;
    long n_pacotes = 0;
    Pacote *pacotes = malloc(capacidade * sizeof(Pacote));

    if (pacotes == NULL)
    {
        return 1;
    }

    long long s;
    char c;
    char espaco;

    while (scanf("%lld%c%c", &s, &espaco, &c) != EOF)
    {
        if (n_pacotes == capacidade)
        {
            capacidade *= 2;
            Pacote *temp = realloc(pacotes, capacidade * sizeof(Pacote));
            if (temp == NULL)
            {
                free(pacotes);
                return 1;
            }
            pacotes = temp;
        }

        pacotes[n_pacotes].seq = s;
        pacotes[n_pacotes].c = c;
        n_pacotes++;
    }

    qsort(pacotes, n_pacotes, sizeof(Pacote), compara_pacotes);

    for (long i = 0; i < n_pacotes; i++)
    {
        if (i > 0 && pacotes[i].seq == pacotes[i - 1].seq)
        {
            continue;
        }

        if (pacotes[i].c == '_')
        {
            printf(" ");
        }
        else
        {
            printf("%c", pacotes[i].c);
        }
    }
    printf("\n");

    free(pacotes);

    return 0;
}