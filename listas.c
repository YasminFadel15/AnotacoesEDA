#include <stdio.h>

typedef struct{
  No* anterior;
  No* proximo;
  void* v;
} No;

typedef struct{
  No* cabeca;
  No* cauda;
} Lista;

void adicionarInicio(Lista* l, void* v, size_t t){
  No* no = malloc(sizeof(No));
  
  no -> v = malloc(t);
  memcpy(no -> v, v, t);
  
  no -> anterior = NULL;
  no -> proximo = l -> cabeca;
  
  l -> cabeca = no;
  
  if(l -> cauda == NULL){
    l -> cauda = l -> cabeca;
  }
}

void adicionarFim(Lista* l, void* v, size_t){
    No* no = malloc(sizeof(No));

    no -> v = malloc(t);
    memcpy(no -> v, v, t);
  
    no -> anterior = l -> cauda;
    no -> proximo = NULL;
  
    l -> cabeca = no;
  
    if(l -> cabeca == NULL){
        l -> cabeca = l -> cauda;
    }
}
