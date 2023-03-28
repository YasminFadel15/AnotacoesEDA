//Operações: empilhar (push) e desempilhar (pop).

/////////////////////
//PILHAS ESTÁTICAS

//Definição
#define MAX 10
typedef struct {
 int topo; //posição atual do vetor (topo)
 int v[MAX]; //vetor contendo o conteúdo da pilha
} Pilha;


//Criar nova pilha
Pilha* criar(int tamanho){
 Pilha* pilha = malloc(sizeof(Pilha)); //alocação dinâmica
 pilha -> topo = 0; //inicializa a posição atual com zero
 pilha -> tamanho = tamanho; //atribuir tamanho
 pilha -> vetor = malloc(sizeof(int) * tamanho); //alocação dinâmica do vetor da pilha
 
 return pilha;
}


//Verificar se a pilha está cheia
int cheia(Pilha* pilha){
 return pilha -> topo == pilha -> tamanho;
}


//Inserir novo elemento na pilha
void push(Pilha* pilha, int valor){
 if (!cheia(pilha)) { //verificar a capacidade da pilha
  printf("Capacidade máxima da pilha foi alcançada");
  exit(-1);
 } else {
  pilha -> vetor[pilha -> topo] = valor; //insere elemento na próxima posição livre
  pilha -> topo++;
  //pode ser: pilha -> vetor[pilha -> topo++] = valor; //atribui o valor para o topo da pilha e incrementa o topo
 }
}


//Verificar se a pilha está vazia
int vazia(Pilha* pilha){
 return pilha->topo == 0;
}


//Remover elemento do topo da pilha
int pop(Pilha* pilha){
int v;

 if (vazia(pilha)) {
  printf("Pilha vazia");
  exit(-1);
 } else {
    v = p[p->topo--]; //recupera valor do topo
 }
 return v;
 //return pilha -> vetor[-- pilha -> topo]; //decrementa o vetor e acessa o valor
}


//Libera memória da pilha
void limpa(Pilha *p){
 if (p != NULL) {
  free(p);
 }

 p = NULL;
}


//Visitar todos os elmentos da pilha
void percorre(Pilha *p){
 while (vazia(p)) {
  int v = pop(p);

  printf("%d", v);
 }
}

/////////////////////
//PILHAS DINÂMICAS

//Definição
#define MAX 10
typedef struct {
 int topo; //posição atual do vetor (topo)
 int tamanho;
 int **vetor; //ponteiro de ponteiro do vetor
} Pilha;


//Implementação com ponteiros e alocação dinâmica de memória
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


//Inserir um novo elemento na pilha
void push(Pilha* pilha, int valor){
 No* no = malloc(sizeof(No));
 no -> valor = valor; //o valor do nó recebe o valor do parâmetro
 no -> anterior = (struct No*) pilha -> topo; //elemento anterior recebe o topo da pilha
 pilha -> topo = no; //atualização do topo
}


//Verificar se a pilha está vazia
int vazia(Pilha* pilha){
 return pilha -> topo == NULL;
}


//Remover elemento do topo da pilha
int pop(Pilha* pilha){
 int valor;

 if (vazia(pilha)) {
  printf("Pilha vazia");
  exit(-1);
 } else {
  No* no = pilha -> topo;
  valor = no -> valor; //recupera valor do topo
  pilha -> topo = no -> anterior;
  free(no);
 }
 return valor;
}

//Desempilhar
int desempilhar(Pilha* pilha){
 if(!vazia(pilha)){
  int valor = pilha -> topo -> valor;
  No* antigo_topo = pilha -> topo; 
  pilha -> topo = (No*) pilha -> topo -> anterior; //ponteiro do topo da pilha igual ao elemento anterior do topo da pilha
  free(antigo_topo); //liberar a memória 
  
  return valor;
 }
 return -1;
}


//Esvaziar uma pilha/desalocar
void esvaziar(Pilha* pilha){
 free(pilha -> vetor);
 free(pilha);
}
  
  
//Libera memória da pilha
void limpar(Pilha* pilha){
 while (pilha -> topo != NULL) {
  No* no = pilha -> topo;
  pilha -> topo = no -> anterior;
  free(no);
 }
 free(pilha);
}


//Visitar todos os elementos da pilha
void percorre(Pilha* pilha){
 while (vazia(pilha)) {
  int valor = pop(pilha);

  printf("%d", valor);
 }
}


int main(){
 Pilha* pilha = criar();
 
 int valor;
 
 while(valor < 0){
  empilhar pilha, valor;
  printf("Informe um número positivo ou -1 para parar: \n");
  scanf("%d", &valor);
 } 
 
 while(!vazia(pilha)){
  printf("%d", desempilhar(pilha);
 }
 
 printf("\n");
        
 return 0;
}
