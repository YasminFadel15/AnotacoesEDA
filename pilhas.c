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
Pilha* cria(){
 Pilha *p = malloc(sizeof(Pilha));
 p->topo = 0; //inicializa a posição atual com zero
 return p;
}


//Inserir novo elemento na pilha
void push(Pilha *p, int v){
 if (p->topo == MAX) {
 printf("Capacidade máxima da pilha foi alcançada");
 exit(-1);
 } else {
 p[p->topo++] = v; //insere elemento na próxima posição livre
 }
}


//Verificar se a pilha está vazia
int vazia(Pilha *p){
 return p->topo == 0;
}


//Remover elemento do topo da pilha
int pop(Pilha *p){
int v;

 if (vazia(p)) {
 printf("Pilha vazia");
 exit(-1);
 } else {
 v = p[p->topo--]; //recupera valor do topo
 }
 return v;
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
