#include <stdio.h>

typedef struct no {
    int v;
    struct no* prox;
} no;

typedef struct grafo {
    no** adj;
    int n;
} grafo;

grafo* cria_grafo(int n) {
    grafo* g = malloc(sizeof(grafo));
    g->adj = calloc(n * sizeof(no*));
    g->n = n;
    return g;
}

no* insere_lista(no* lista, int v) {
    no* novo = malloc(sizeof(no));
    novo->v = v;
    novo->prox = lista;
    lista = novo;
    return lista;
}

void insere_aresta(grafo* g, int u, int v) {
    g->adj[u] = insere_lista(g->adj[u], v);
    g->adj[v] = insere_lista(g->adj[v], u);
}

no* remove_lista(no* lista, int v) {
    for (no* t = lista; t->prox != NULL; t = t->prox) {
        if (t->v == v) {
            no* x = t;
            t = t->prox;
            free(x);
        }
        if (t->prox->v == v) {
            no* lixo = t->prox;
            t->prox = lixo->prox;
            free(lixo);
        }
    }
    return lista;
}

void remove_aresta(grafo* g, int u, int v) {
    g->adj[u] = remove_lista(g->adj[u], v);
    g->adj[v] = remove_lista(g->adj[v], u);
}

// Custos
//             Matriz      Lista       Grau(G) = maior grau dentre todos
// Inserção     O(1)        O(1)                       os vertices
// Remoção      O(1)        O(grau(G))
// Existência   O(1)        O(grau(G))
// de aresta

// Caminhos num grafo
//     Dizemos que um caminho entre V e U é
// uma sequencia, sem repetições, de vértices
// adjacentes entre V e U.

// Componentes Conexa
//     Para quaisquer dois vertices de um grafo dizemos que
// eles pertencem à mesma componente conexa se existir
// um caminho entre eles.

void visita(grafo* g, int* comp, int c, int v) {
    comp[v] = c;
    for (no* t = g->adj[v]; t != NULL; t = t->prox) {
        if (!comp[t->v]) {
            visita(g, comp, c, v);
        }
    }
}

int *componentes(grafo* g) {
    int c = 0, *comp;
    comp = malloc(g->n * sizeof(int));

    for (int v = 0; v < g->n; v++) {
        if (!comp[v]) {
            c++;
            visita(g, comp, c, v);
        }
    }
    return comp;
}
