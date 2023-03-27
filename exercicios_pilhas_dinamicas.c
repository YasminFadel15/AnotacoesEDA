//Ler caracteres e retorno 'true' ou 'false'; se '0', retorna a string
#include <stdio.h>
#include <stdlib.h>

//Definição das estruturas
typedef struct {
 struct No* anterior; //ponteiro para o nó anterior
 int valor; //valor do nó
} No;

typedef struct {
 No* topo; //ponteiro para o topo da pilha
} Pilha;



//Criar nova pilha
Pilha* criar(){
 Pilha* pilha = malloc(sizeof(Pilha));
 pilha -> topo = NULL; //inicializa o topo da pilha com nulo para evitar lixo de memória
 return pilha;
}


void push(Pilha* pilha, char valor) {
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->anterior = (struct No*) pilha->topo;
    pilha->topo = no;
}
 

int vazia(Pilha* pilha){
 return pilha -> topo == NULL;
}


char pop(Pilha* pilha) {
    if (!vazia(pilha)) {
        char valor = pilha->topo->valor;
        No* antigo = pilha->topo;
        pilha->topo = (No*) pilha->topo->anterior;
        free(antigo);

        return valor;
    }
}


int balanceada(char caractere[]){
    Pilha* pilha = criar();

    for(int i = 0 ; caractere[i] != '\0' ; i++){
        if(caractere[i] == '('){
            push(pilha, '(');
        } else if(caractere[i] == ')'){
            char excluido = pop(pilha);
            if(excluido != '(')
                return 0; //Parênteses não balanceados
        }
    }
    int eh_vazia = (pilha -> topo == NULL);
    free(pilha);
    return eh_vazia;
}


int main() {
    char caractere[100];
    int fim = 0;
    char resultado[100] = "";
    
    while(!fim){
        scanf("%s", caractere);
        if(caractere[0] == '0')
            fim = 1;
        else{
            int balanceado = balanceada(caractere);
            printf("%s\n", balanceado ? "true" : "false");
            strcat(resultado, caractere); //concatena string lida na variável 'resultado'
        }
    }
    printf("%s\n", resultado);
    
    return 0;
}



