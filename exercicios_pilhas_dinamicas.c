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



//Passar os elementos da pilha estática para a pilha dinâmica
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

typedef struct {
    int* valor; //vetor que armazena os elementos da pilha dinâmica
    int topo; //índice do topo da pilha
    int tamanho; //capacidade máxima da pilha dinâmica
} Pilha;


Pilha* criar(int tamanho){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha -> valor = malloc(tamanho * sizeof(int));
    pilha -> topo = -1; //inicializa o topo da pilha com -1 para indicar pilha vazia
    pilha -> tamanho = tamanho;
    return pilha;
}


int vazia(Pilha* pilha) {
    return pilha -> topo == -1;
}


//Inserir um novo elemento na pilha dinâmica
void push(Pilha* pilha, int valor){
    if(pilha -> topo == pilha -> tamanho - 1){
        printf("Erro: pilha cheia!\n");
        exit(-1);
    }
    pilha -> topo++;
    pilha -> valor[pilha->topo] = valor;
}


//Remover elemento do topo da pilha dinâmica
int pop(Pilha* pilha){
    if(vazia(pilha)){
        printf("Erro: pilha vazia!\n");
        exit(-1);
    }
    int valor = pilha -> valor[pilha->topo];
    pilha -> topo--;
    return valor;
}


int main() {
    int pilha_est[TAM_MAX];
    int n = 0;

    printf("Informe o tamanho da pilha: ");
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &pilha_est[i]);
    }
    
    Pilha* pilha_din = criar(n);

    for(int i = 0 ; i < n ; i++){
        push(pilha_din, pilha_est[i]);
    }

    while (!vazia(pilha_din)) {
        printf("%d ", pop(pilha_din));
    }

    printf("\n");
    
    free(pilha_din -> valor);
    free(pilha_din);
    
return 0;
}
