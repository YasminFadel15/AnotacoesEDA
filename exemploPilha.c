#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int topo;
    int* v;
    int tamanho;
} Pilha;


Pilha* criar(int tamanho){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha -> topo = 0;
    pilha -> tamanho = tamanho;
    pilha -> v = malloc(sizeof(int) * tamanho);
    
    return pilha;
}


int cheia(Pilha* pilha){
    return pilha -> topo == pilha -> tamanho;
}


void push(Pilha* pilha, int valor){
    if(cheia(pilha)){
        printf("Pilha cheia.");
        exit(-1);
    } else {
        pilha -> v[pilha -> topo++] = valor;
    } 
}


int vazia(Pilha* pilha){
    return pilha -> topo == 0;
}


int pop(Pilha* pilha){
    int valor;
    
    if(vazia(pilha)){
        printf("Pilha vazia.");
        exit(-1);
    } else {
        valor = pilha -> v[-- pilha -> topo];
    }
    return valor;
}


int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);
    
    Pilha* pilha = criar(tamanho);
    
    while(!cheia(pilha)){
        int valor;
        printf("Digite o número: \n");
        scanf("%d", &valor);
        push(pilha, valor);
    }
    
    printf("Desempilhando:\n");
    
    while(!vazia(pilha)){
        int valor = pop(pilha);
        
        printf("%d\n", valor);
    }

    return 0;
}
