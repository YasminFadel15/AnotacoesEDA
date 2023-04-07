//Ler duas filas estáticas e retornar em uma fila dinâmica a interseção dos valores
#include <stdio.h>
#include <stdlib.h>


//Definições e criação
typedef struct{
    int tamanho;
    int* vetor;
    int cabeca;
    int cauda;
} FilaEst;

FilaEst* criarEst(int tamanho){
    FilaEst* fila = malloc(sizeof(FilaEst));
    fila -> tamanho = tamanho;
    fila -> cabeca = -1;
    fila -> cauda = -1;
    fila -> vetor = malloc(sizeof(int) * tamanho);
    return fila;
}

typedef struct{
    int tamanho;
    int* vetor;
    int cabeca;
    int cauda;
} FilaDin;

FilaDin* criarDin(int tamanho){
    FilaDin* fila = malloc(sizeof(FilaDin));
    fila -> tamanho = tamanho;
    fila -> cabeca = -1;
    fila -> cauda = -1;
    fila -> vetor = malloc(sizeof(int) * tamanho);
    return fila;
}

///////////////////////////////////////////////////////////////////////////

int cheiaEst(FilaEst* fila){
    return (fila -> cauda + 1) % fila -> tamanho == fila -> cabeca;
}

int cheiaDin(FilaDin* fila){
    return (fila -> cauda + 1) % fila -> tamanho == fila -> cabeca;
}

void adicionarEst(FilaEst* fila, int valor){
    if (!cheiaEst(fila)){
        fila -> cauda = (fila->cauda + 1) % fila -> tamanho;
        fila -> vetor[fila -> cauda] = valor;

        if (fila -> cabeca == -1){
            fila -> cabeca = fila -> cauda;
        }
    }
}

void adicionarDin(FilaDin* fila, int valor){
    if (!cheiaDin(fila)){
        fila -> cauda = (fila->cauda + 1) % fila -> tamanho;
        fila -> vetor[fila -> cauda] = valor;

        if (fila -> cabeca == -1){
            fila -> cabeca = fila -> cauda;
        }
    }
}


///////////////////////////////////////////////////////////////////////////

FilaDin* intersecao(FilaEst* fila1, FilaEst* fila2, int n, int m, int valor1[n], int valor2[m]){
    int tamanhoMaximo = (n < m) ? n : m; 
    FilaDin* fila3 = criarDin(tamanhoMaximo);
    int cont = 0;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(valor1[i] == valor2[j]){
                adicionarDin(fila3, valor1[i]);
                cont++;
                break;
            }
        }
    }
    
    fila3 -> tamanho = cont; 
    return fila3;
}

///////////////////////////////////////////////////////////////////////////

int main(){
    int n, m;
    
    printf("Digite o tamanho da primeira fila: \n");
    scanf("%d", &n);
    FilaEst* fila1 = criarEst(n);
    int valor1[n];
    
    printf("Digite os valores:\n");
    for(int i = 0 ; i < n ; i++){
        scanf(" %d", &valor1[i]);
        adicionarEst(fila1, valor1[i]);
    }
   
    printf("Digite o tamanho da segunda fila: \n");
    scanf("%d", &m);
    FilaEst* fila2 = criarEst(m);
    int valor2[m];
    
    printf("Digite os valores:\n");
    for(int i = 0 ; i < m ; i++){
        scanf(" %d", &valor2[i]);
        adicionarEst(fila2, valor2[i]);
    }
    
    FilaDin* fila3 = intersecao(fila1, fila2, n, m, valor1, valor2);
    printf("Interseção: ");
    for(int i = 0 ; i < fila3 -> tamanho ; i++)
        printf("%d ", fila3 -> vetor[i]);
    printf("\n");
    
    free(fila1->vetor);
    free(fila1);
    free(fila2->vetor);
    free(fila2);
    free(fila3->vetor);
    free(fila3);

    return 0;
}
