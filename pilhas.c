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
 int v; //valor do nó
} No;
typedef struct {
 No* topo; //ponteiro para o topo da pilha
} Pilha;


//Criar nova pilha
Pilha* cria(){
 Pilha *p = malloc(sizeof(Pilha));
 p->topo = NULL; //inicializa o topo da pilha com nulo
 return p;
}


//Inserir um novo elemento na pilha
void push(Pilha *p, int v){
 No *no = malloc(sizeof(No));
 no->v = v;
 no->anterior = p->topo;
 p->topo = no;
}


//Verificar se a pilha está vazia
int vazia(Pilha *p){
 return p->topo == NULL;
}


//Remover elemento do topo da pilha
int pop(Pilha *p){
 int v;

 if (vazia(p)) {
 printf("Pilha vazia");
 exit(-1);
 } else {
 No* no = p->topo;
 v = no->v; //recupera valor do topo
 p->topo = no->anterior;
 free(no);
 }
 return v;
}


//Libera memória da pilha
void limpa(Pilha *p){
 while (p->topo != NULL) {
 No *no = p->topo;
 p->topo = no->anterior;
 free(no);
 }
 free(p);
}


//Visitar todos os elementos da pilha
void percorre(Pilha *p){
 while (vazia(p)) {
 int v = pop(p);

 printf("%d", v);
 }
}
