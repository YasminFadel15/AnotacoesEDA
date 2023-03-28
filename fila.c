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
 fila -> cabeca == -1; //índice inválido para a inicialização de uma fila vazia 
 fila -> cauda == -1;
 fila -> vetor = malloc(sizeof(int) * tamanho); //alocação dinâmica do vetor
 
  return fila;
} 
  




















//Fila dinâmica: elemento encadeados
