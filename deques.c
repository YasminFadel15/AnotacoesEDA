//Deques: filas encadeadas

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    struct No* anterior;
    struct No* proximo;
    int valor;
} No;

typedef struct{
    No* cabeca;
    No* cauda;
} Deque;


Deque* criar(){
    Deque* deque = malloc(sizeof(Deque));
    deque -> cabeca = NULL;
    deque -> cauda = NULL:

    return deque;
}

int vazia(Deque* deque){
    return deque -> cabeca == NULL && deque -> cauda == NULL;
}


void adicionarFim(Deque* deque, int valor){
    No* no = malloc(sizeof(No));
    no -> valor = valor;
    no -> proximo = NULL;
    no -> anterior = deque -> cauda;
    
    if(!vazia(deque))
        deque -> cauda -> proximo = no;
    else
        deque -> cabeca = no;

    deque -> cauda = no;
}


void adicionarInicio(Deque* deque, int valor){
    No* no = malloc(sizeof(No));
    no -> valor = valor;
    no -> proximo = NULL;
    no -> anterior = deque -> cabeca;
    
    if(!vazia(deque))
        deque -> cabeca -> proximo = no;
    else
        deque -> cauda = no;

    deque -> cauda = no;
}


int removerFim(Deque* deque) {
    if (vazia(deque)) {
        printf("Deque vazio\n");
        return 0;
    }

    No* no = deque -> cauda;
    int valor = no -> valor;
    deque -> cauda = (No*) deque -> cauda -> anterior;

    if(deque -> cauda == NULL)
        deque -> cabeca = NULL;
    else
        deque -> cauda -> anterior = NULL;
        
    free(no);

    return valor;
}


int removerInicio(Deque* deque) {
    if (vazia(deque)) {
        printf("Deque vazio\n");
        return 0;
    }

    No* no = deque -> cabeca;
    int valor = no -> valor;
    deque -> cabeca = (No*) deque -> cabeca -> proximo;

    if(deque -> cabeca == NULL)
        deque -> cauda = NULL;
    else
        deque -> cabeca -> anterior = NULL;

    free(no);

    return valor;
}
