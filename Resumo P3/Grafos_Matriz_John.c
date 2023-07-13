#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
} fila;

typedef struct {
    int **adj;  // MATRIZ DE ADJACENCIA
    int n;      // QTDE DE VERTICES
} grafo;

grafo *cria_grafo(int n) {
    grafo *g = malloc(sizeof(grafo));
    g->n = n;
    g->adj = malloc(sizeof(int *));
    for (int i = 0; i < n; i++) g->adj[i] = calloc(n, sizeof(int));
    return g;
}

void destroi_grafo(grafo *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

void insere_aresta(grafo *g, int u, int v) {
    g->adj[u][v] = g->adj[v][u] = 1;  // apenas se for um grafo não dirigido,
                                      // tem duas arestas pq é não dirigido
}

void remove_aresta(grafo *g, int u, int v) { g->adj[u][v] = g->adj[v][u] = 0; }

int tem_aresta(grafo *g, int u, int v) { return g->adj[u][v]; }

// n(quantidade de vertices)
//<pares de vertices = arestas>

grafo *le_grafo() {
    int n, u, v;
    scanf("%d", &n);
    grafo *g = cria_grafo(n);
    while (scanf("%d %d", &u, &v) != EOF) {
        insere_aresta(g, u, v);
    }
    return g;
}

//    ./executavel <grafo.txt> out

int grau(grafo *g, int u) {
    int grau = 0;
    for (int v = 0; v < g->n; v++) {
        if (g->adj[u][v]) grau++;
    }
    return grau;
}

// Problema: temos um grafo G que representa conexões de um n pessoas no
// facebook Faça um algoritmo para recomendar amigps da seguintes forma : Dada
// uma pessoa qualquer, suas recomendações serão amigos de amigos não
// pertecentes à sua lista de amigos.

void recomenda(grafo *g, int u) {  // O(n^2)
    int *rec = calloc(g->n, sizeof(int));
    for (int v = 0; v < g->n; v++) {
        if (g->adj[u][v])
            ;
        for (int w = 0; w < g->n; v++) {
            if (g->adj[v][w] && g->adj[u][w] == 0 && w != u && !rec[w]) {
                ;
                printf("%d", w);
                rec[w] = 1;
            }
        }
    }
}

int busca_rec(grafo *g, int u, int v, int *visitado) {  // O(n)
    if (u == v) return 1;
    for (int w = 0; w < g->n; w++) {
        if (g->adj[u][w] && !visitado[w]) {
            if (busca_rec(g, w, v, visitado)) {
                return 1;
            }
        }
    }
    return 0;
}

int busca_caminho(grafo *g, int u, int v) {
    int *visitado = calloc(g->n, sizeof(int));
    return busca_rec(g, u, v, visitado);
}

void busca_profundidade(grafo *g, int *pai, int p,
                        int v) {  // DFS (Depth-First-Search)
    pai[v] = p;
    for (int w = 0; w < g->n; w++) {
        if (g->adj[v][w] && pai[w] == -1) {
            busca_profundidade(g, pai, v, w);  // Empilha de ordem decrescente
        }
    }
}

int *caminhos(grafo *g, int s) {
    int *pai = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) {
        pai[i] = -1;
        busca_profundidade(g, pai, s, s);
        return pai;
    }
}

int busca_largura(grafo *g, int s) {
    int *pai = malloc(g->n * sizeof(int));
    fila *f = cria_fila();
    for (int i = 0; i < g->n; i++) pai[i] = -1;
    enfileira(f, s);
    pai[s] = s;
    while (!fila_vazia(f)) {
        int v = desenfileira(f);
        for (int w = 0; w < g->n; w++) {
            if (g->adj[v][w] && pai[w] == -1) {
                pai[w] = v;
                enfileira(f, w);
            }
        }
    }
}