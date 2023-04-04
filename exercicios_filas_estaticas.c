//Ler números e retornar na ordem lida
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tamanho;
    int* vetor;
    int cabeca;
    int cauda;
} Fila;

Fila* criar(int tamanho){
    Fila* fila = malloc(sizeof(Fila));
    fila -> tamanho = tamanho;
    fila -> cabeca = -1;
    fila -> cauda = -1;
    fila -> vetor = malloc(sizeof(int) * tamanho);
    return fila;
}

int vazia(Fila* fila){
    return fila -> cabeca == -1 && fila -> cauda == -1;
}

int cheia(Fila* fila){
    return (fila -> cauda + 1) % fila -> tamanho == fila -> cabeca;
}

void adicionar(Fila* fila, int valor){
    if (!cheia(fila)){
        fila -> cauda = (fila->cauda + 1) % fila -> tamanho;
        fila -> vetor[fila -> cauda] = valor;

        if (fila -> cabeca == -1){
            fila -> cabeca = fila -> cauda;
        }
    }
}

int remover(Fila* fila){
    if (!vazia(fila)){
        int valor = fila -> vetor[fila -> cabeca];

        if (fila -> cabeca == fila -> cauda) {
            fila -> cabeca = -1;
            fila -> cauda = -1;
        } else {
            fila -> cabeca = (fila -> cabeca + 1) % fila -> tamanho;
        }

        return valor;
    }

    return -1;
}

int main(){
    int tamanho;
    printf("Digite o tamanho da fila: \n");
    scanf("%d", &tamanho);
    
    Fila* fila = criar(tamanho);
    int valor[tamanho];

    printf("Digite os valores:\n");
    for(int i = 0 ; i < tamanho ; i++){
        scanf("%d", &valor[i]);
        adicionar(fila, valor[i]);
    }
    
    printf("Enfileirando: ");
    for(int i = 0 ; i < tamanho ; i++)
        printf("%d ", valor[i]);

    printf("\nDesenfileirando: ");
    for(int i = 0 ; i < tamanho ; i++){
        printf("%d ", remover(fila));
    }
    printf("\n");

    free(fila -> vetor);
    free(fila);

    return 0;
}

//////////////////////////////////////

//Ler caracteres até um limite e retornar na ordem lida
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tamanho;
    int* vetor;
    char cabeca;
    char cauda;
} Fila;

Fila* criar(int tamanho){
    Fila* fila = malloc(sizeof(Fila));
    fila -> tamanho = tamanho;
    fila -> cabeca = -1;
    fila -> cauda = -1;
    fila -> vetor = malloc(sizeof(int) * tamanho);
    return fila;
}

int vazia(Fila* fila){
    return fila -> cabeca == -1 && fila -> cauda == -1;
}

int cheia(Fila* fila){
    return (fila -> cauda + 1) % fila -> tamanho == fila -> cabeca;
}

void adicionar(Fila* fila, char valor){
    if (!cheia(fila)){
        fila -> cauda = (fila->cauda + 1) % fila -> tamanho;
        fila -> vetor[fila -> cauda] = valor;

        if (fila -> cabeca == -1){
            fila -> cabeca = fila -> cauda;
        }
    }
}

char remover(Fila* fila){
    if (!vazia(fila)){
        char valor = fila -> vetor[fila -> cabeca];

        if (fila -> cabeca == fila -> cauda) {
            fila -> cabeca = -1;
            fila -> cauda = -1;
        } else {
            fila -> cabeca = (fila -> cabeca + 1) % fila -> tamanho;
        }

        return valor;
    }

    return '\0';
}

int main(){
    int tamanho;
    printf("Digite o limite: \n");
    scanf("%d", &tamanho);
    
    Fila* fila = criar(tamanho);
    char valor[tamanho];

    printf("Digite os caracteres:\n");
    for(int i = 0 ; i < tamanho ; i++){
        scanf(" %c", &valor[i]);
        adicionar(fila, valor[i]);
    }

    printf("\nCaracteres: ");
    for(int i = 0 ; i < tamanho ; i++){
        printf("%c ", remover(fila));
    }
    printf("\n");

    free(fila -> vetor);
    free(fila);

    return 0;
}

//////////////////////////////////////

//Ler números inteiros e valor k; retornar 'true' caso k exista na fila
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tamanho;
    int* vetor;
    int cabeca;
    int cauda;
} Fila;

Fila* criar(int tamanho){
    Fila* fila = malloc(sizeof(Fila));
    fila -> tamanho = tamanho;
    fila -> cabeca = -1;
    fila -> cauda = -1;
    fila -> vetor = malloc(sizeof(int) * tamanho);
    return fila;
}

int vazia(Fila* fila){
    return fila -> cabeca == -1 && fila -> cauda == -1;
}

int cheia(Fila* fila){
    return (fila -> cauda + 1) % fila -> tamanho == fila -> cabeca;
}

void adicionar(Fila* fila, int valor){
    if (!cheia(fila)){
        fila -> cauda = (fila->cauda + 1) % fila -> tamanho;
        fila -> vetor[fila -> cauda] = valor;

        if (fila -> cabeca == -1){
            fila -> cabeca = fila -> cauda;
        }
    }
}

int remover(Fila* fila){
    if (!vazia(fila)){
        int valor = fila -> vetor[fila -> cabeca];

        if (fila -> cabeca == fila -> cauda) {
            fila -> cabeca = -1;
            fila -> cauda = -1;
        } else {
            fila -> cabeca = (fila -> cabeca + 1) % fila -> tamanho;
        }

        return valor;
    }

    return -1;
}

int validar(Fila* fila, int k, int tamanho, int valor[tamanho]){
    for(int i = 0 ; i < tamanho ; i++){
        if(valor[i] == k)
            return 1;
    }
    return 0;
}

int main(){
    int tamanho, k;
    printf("Digite o tamanho da fila: \n");
    scanf("%d", &tamanho);
    
    printf("Digite um valor k: \n");
    scanf("%d", &k);
    
    Fila* fila = criar(tamanho);
    int valor[tamanho];

    printf("Digite os valores:\n");
    for(int i = 0 ; i < tamanho ; i++){
        scanf("%d", &valor[i]);
        adicionar(fila, valor[i]);
    }

   int verdade = validar(fila, k, tamanho, valor);
   if(verdade)
    printf("true");
   else
    printf("false");

   free(fila -> vetor);
   free(fila);

    return 0;
}
