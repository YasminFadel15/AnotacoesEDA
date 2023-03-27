//Ler conjunto de números inteiros e exibí-los na ordem inversa

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

/////////////////////////////////////////////////////////////////////////////

//Ler palavra e dizer se ela é palíndromo ou não

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    char topo;
    char* v;
    int tamanho;
} Pilha;


Pilha* criar(int tamanho){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha -> topo = 0;
    pilha -> tamanho = tamanho;
    pilha -> v = malloc(sizeof(char) * tamanho);
    
    return pilha;
}


int cheia(Pilha* pilha){
    return pilha -> topo == pilha -> tamanho;
}


void push(Pilha* pilha, char letra){
    if(cheia(pilha)){
        printf("Pilha cheia.");
        exit(-1);
    } else {
        pilha -> v[pilha -> topo++] = letra;
    } 
}


int vazia(Pilha* pilha){
    return pilha -> topo == 0;
}


char pop(Pilha* pilha){
    char letra;
    
    if(vazia(pilha)){
        printf("Pilha vazia.");
        exit(-1);
    } else {
        letra = pilha -> v[-- pilha -> topo];
    }
    return letra;
}


int palindromo(char* palavra){
    int tam = strlen(palavra);
    
    Pilha* pilha = criar(tam);
    
    for(int i = 0 ; i < tam ; i++){
        push(pilha, palavra[i]);
    }
    for(int i = 0 ; i < tam ; i++){
        if(pop(pilha) != palavra[i]){
            return 0;
        }
    } return 1;
}

int main() {
    int tamanho;
    printf("Digite o tamanho da palavra: \n");
    scanf("%d", &tamanho);
    
    char palavra[MAX];
    
    for(int i = 0 ; i < tamanho ; i++){
        scanf(" %c", &palavra[i]);
    }
    
    Pilha* pilha = criar(tamanho);
    
    if(palindromo(palavra)){
        printf("Palíndromo.");
    } else {
        printf("Não é palíndromo.");
    }
    

    return 0;
}


/////////////////////////////////////////////////////////////////////////////

//Ler conjunto de números inteiros e um valor k; retornar true caso k exista na pilha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    char topo;
    char* v;
    int tamanho;
} Pilha;


Pilha* criar(int tamanho){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha -> topo = 0;
    pilha -> tamanho = tamanho;
    pilha -> v = malloc(sizeof(char) * tamanho);
    
    return pilha;
}


int cheia(Pilha* pilha){
    return pilha -> topo == pilha -> tamanho;
}


void push(Pilha* pilha, int num){
    if(cheia(pilha)){
        printf("Pilha cheia.");
        exit(-1);
    } else {
        pilha -> v[pilha -> topo++] = num;
    } 
}


int vazia(Pilha* pilha){
    return pilha -> topo == 0;
}


int sequencia(int* vetor, int k, int tamanho){
    for(int i = 0 ; i < tamanho ; i++){
        if(vetor[i] == k){
            return 1;
        } 
    }
    return 0;
}

int main() {
    int tamanho;
    printf("Digite a quantidade de números: \n");
    scanf("%d", &tamanho);
    
    int k;
    printf("Digite k: \n");
    scanf("%d", &k);
    
    int vetor[MAX];
    
    printf("Digite a sequência de números:\n");
    for(int i = 0 ; i < tamanho ; i++){
        scanf(" %d", &vetor[i]);
    }
    
    Pilha* pilha = criar(tamanho);
    
    if(sequencia(vetor, k, tamanho)){
        printf("%d existe na sequência.", k);
    } else {
        printf("%d não existe na sequência.", k);
    }
    

    return 0;
}


//Versão 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    char topo;
    char* v;
    int tamanho;
} Pilha;


Pilha* criar(int tamanho){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha -> topo = 0;
    pilha -> tamanho = tamanho;
    pilha -> v = malloc(sizeof(char) * tamanho);
    
    return pilha;
}


int cheia(Pilha* pilha){
    return pilha -> topo == pilha -> tamanho;
}


void push(Pilha* pilha, int num){
    if(cheia(pilha)){
        printf("Pilha cheia.");
        exit(-1);
    } else {
        pilha -> v[pilha -> topo++] = num;
    } 
}


int vazia(Pilha* pilha){
    return pilha -> topo == 0;
}


int pop(Pilha* pilha){
    int num;
    
    if(vazia(pilha)){
        printf("Pilha vazia.");
        exit(-1);
    } else {
        num = pilha -> v[-- pilha -> topo];
    }
    return num;
}


int sequencia(Pilha* pilha, int k){
    int num;
    while(!vazia(pilha)){
        num = pop(pilha);
        
        if(num == k){
            return 1;
        }
    }
    return 0;
}

int main() {
    int tamanho;
    printf("Digite a quantidade de números: \n");
    scanf("%d", &tamanho);
    
    int k;
    printf("Digite k: \n");
    scanf("%d", &k);
    
    int vetor[MAX];
    
    printf("Digite a sequência de números:\n");
    for(int i = 0 ; i < tamanho ; i++){
        scanf(" %d", &vetor[i]);
    }
    
    Pilha* pilha = criar(tamanho);
    
    if(sequencia(pilha, k)){
        printf("%d existe na sequência.", k);
    } else {
        printf("%d não existe na sequência.", k);
    }
    

    return 0;
}
