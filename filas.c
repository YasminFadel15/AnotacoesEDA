//Fila estática: utilização de vetor circular

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

void push(Fila* fila, int valor){
 if(!cheia(fila)){
   fila -> cauda = (fila -> cauda + 1) % fila -> tamanho;
   fila -> vetor[fila -> cauda] = valor;
   
   if(fila -> cabeca == -1)
     fila -> cabeca = fila -> cauda;
     
 } else
    printf("Fila cheia.");
}
  
int pop(Fila* fila){
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


//Fila dinâmica: elemento encadeados
