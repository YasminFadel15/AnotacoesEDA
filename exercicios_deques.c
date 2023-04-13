//Ler deque e retornar na ordem normal e inversa
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    struct Elemento* proximo;
    struct Elemento* anterior;
} Elemento;

typedef struct {
    Elemento* cabeca;
    Elemento* cauda;
} Deque;

Deque* criar() {
    Deque* deque = malloc(sizeof(Deque));
    deque->cabeca = NULL;
    deque->cauda = NULL;

    return deque;
}

int vazia(Deque* deque) {
    return deque->cabeca == NULL && deque->cauda == NULL;
}

void adicionarInicio(Deque* deque, int valor) {
    Elemento* elemento = malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->anterior = NULL;
    elemento->proximo = (struct Elemento*) deque->cabeca;

    if (vazia(deque)) {
        deque->cauda = elemento;
    }

    deque->cabeca = elemento;
}

void adicionarFim(Deque* deque, int valor) {
    Elemento* elemento = malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->proximo = NULL;
    elemento->anterior = (struct Elemento*) deque->cauda;

    if (vazia(deque)) {
        deque->cabeca = elemento;
    } else {        
        deque->cauda->proximo = (struct Elemento*) elemento;
    }

    deque->cauda = elemento;
}

int removerFim(Deque* deque) {
    if (vazia(deque)) {
        printf("Deque vazia\n");
        return 0;
    }
    
    int valor = deque->cauda->valor;
    Elemento* elemento = (Elemento*) deque->cauda;

    deque->cauda = (Elemento*) elemento->anterior;
    free(elemento);

    if (deque->cauda == NULL) {
        deque->cabeca = NULL;
    } else {
        deque->cauda->proximo = NULL;
    }

    return valor;

}

int removerInicio(Deque* deque) {
    if (vazia(deque)) {
        printf("Deque vazia\n");
        return 0;
    }

    int valor = deque->cabeca->valor;
    Elemento* elemento = (Elemento*) deque->cabeca;

    deque->cabeca = (Elemento*) elemento->proximo;
    free(elemento);

    if (deque->cabeca == NULL) {
        deque->cauda = NULL;
    } else {
        deque->cabeca->anterior = NULL;
    }

    return valor;
}

void limpar(Deque* deque) {
    while (!vazia(deque)) {
        removerInicio(deque);
    }
}

void percorrerFim(Deque* deque) {
    Elemento* elemento = deque->cabeca;

    while (elemento != NULL) {
        printf("%d ", elemento->valor);
        elemento = (Elemento*) elemento->proximo;
    }

    printf("\n");
}

void percorrerInicio(Deque* deque, int tamanho) {
    Elemento* elemento = deque->cauda;

    for(int i = tamanho - 1 ; i > 0 ; i--) {
        printf("%d ", elemento->valor);
        elemento = (Elemento*) elemento->anterior;
    }

    printf("\n");
}

int main() {
    Deque* deque = criar();

    int tamanho;
    printf("Digite o tamanho do deque: ");
    scanf("%d", &tamanho);

    int valor[tamanho];
    for (int i = 0; i < tamanho; i++){
        scanf(" %d", &valor[i]);
        adicionarInicio(deque, valor[i]);
    }

    printf("\n");
    percorrerFim(deque);
    printf("\n");
    percorrerInicio(deque);
    printf("\n");
}
