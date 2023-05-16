#include <stdio.h>

int main(){
    int n, nota, v[1001];
    scanf("%d", &n);

    for (int i=0; i<1001; i++){
        v[i] = 0;
    }

    for (int i=0; i<n; i++){
        scanf("%d", &nota);
        v[nota]++;
    }

    int repNotas = 0, maiorNota = 0;

    for (int i=0; i<1001; i++){
        if (v[i] >= repNotas) {
            repNotas = v[i];
            maiorNota = i;
        }
    }

    printf("%d\n", maiorNota);
}