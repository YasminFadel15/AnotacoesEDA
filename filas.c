//Fila estática: utilização de vetor circular com vetor sem dinamicidade - FIFO

//Definição
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* vetor;
  int cabeca, cauda;
  int tamanho;
} Fila;

//Criação da fila
Fila* criar(int tamanho){
 Fila* fila = malloc(sizeof(Fila));
 fila -> tamanho = tamanho;
 fila -> cabeca == -1; //índice inválido para a inicialização de uma fila vazia 
 fila -> cauda == -1;
 fila -> vetor = malloc(sizeof(int) * tamanho); //alocação dinâmica do vetor
 
  return fila;
} 
  
//Verificação - fila vazia
int vazia(Fila* fila){
 return fila -> cabeca == -1 && fila -> cauda == -1; 
}

//Verificaçõa - fila cheia
int cheia(Fila* fila){
  return (fila -> cauda + 1) % fila -> tamanho == fila -> cabeca;
}

void adicionar(Fila* fila, int valor){
 if(!cheia(fila)){
   fila -> cauda = (fila -> cauda + 1) % fila -> tamanho;
   fila -> vetor[fila -> cauda] = valor;
   
   if(fila -> cabeca == -1)
     fila -> cabeca = fila -> cauda;
     
 } else
    printf("Fila cheia.");
}
  
int remover(Fila* fila){
 if(!vazia(fila)){
   int valor = fila -> vetor[fila -> cabeca];
   
   if(fila -> cabeca == fila -> cauda){
     fila -> cabeca = -1;
     fila -> cauda = -1;
   } else
      fila -> cabeca = (fila -> cabeca + 1) % fila -> tamanho;
   
   return valor;
   
 } else
    printf("Fila vazia.");
}

int main(){
  Fila* fila = criar(5);
 
  int i = 0;
  
  while(!cheia(fila)){
    push(fila, ++i);
  }
  
  while(!vazia(fila)){
    printf("%d ", remover(fila));
  }
  printf("\n");
  
  return 0;
}


//Fila dinâmica: elementos encadeados com alocação de memória - FIFO

//Definição
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    struct Elemento* proximo;
} Elemento;

typedef struct {
    Elemento* cabeca;
    Elemento* cauda;
} Fila;

Fila* criar() {
    Fila* fila = malloc(sizeof(Fila));
    fila->cabeca = NULL;
    fila->cauda = NULL;

    return fila;
}

int vazia(Fila* fila) {
    return fila->cabeca == NULL && fila->cauda == NULL;
}

void adicionar(Fila* fila, int valor) {
    Elemento* elemento = malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->proximo = NULL;

    if (fila->cauda != NULL) {
        fila->cauda->proximo = (struct Elemento*) elemento;
    } else {
        fila->cabeca = elemento;
    }

    fila->cauda = elemento;
}

int remover(Fila* fila) {
    if (vazia(fila)) {
        printf("Fila vazia\n");
        return 0;
    }

    int valor = fila->cabeca->valor;
    Elemento* elemento = (Elemento*) fila->cabeca;

    fila->cabeca = (Elemento*) elemento->proximo;
    free(elemento);

    return valor;
}

void limpar(Fila* fila) {
    while (!vazia(fila)) {
        remover(fila);
    }
}

void percorrer(Fila* fila) {
    Elemento* elemento = fila->cabeca;

    while (elemento != NULL) {
        printf("%d ", elemento->valor);
        elemento = (Elemento*) elemento->proximo;
    }

    printf("\n");
}

int main(){
  Fila* fila = criar();
  
  for(int i = 0 ; i < 10 ; i++)
    adicionar(fila, i);
  
  printf("Percorrendo fila...");
  percorrer(fila);
   
  while(!vazia(fila)){
    printf("%d ", remover(fila));
  }
  
  return 0;
}
