#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
int custo_Player = INT_MAX, custo_IA = INT_MAX;
typedef struct {
    int numero_elementos;
    int** elementos;
} matriz;
/* struct recebe o tamanho da matriz
e um ponteiro de ponteiro que recebe os elementos da matriz
*/
typedef struct{
    int indice;
    int valor;
}casa;
matriz m;
FILE *arquivo;
int r;
void ler_arquivo( matriz* m, char* arquivo);
void imprimir_matriz_jogador(FILE *arquivo );
void construindo_caminho_IA( matriz m, int* caminho);
int calcular_custo( matriz m, int* caminho);
void linha();
int* receber_caminho(matriz m , int* caminho);
void imprimir_matriz( matriz m);
int repetida(int caminho, int i, int c[]);
void player(matriz m, FILE *arquivo);
void IA(matriz m);
void interface_Matriz(matriz m);
void addRecorde(FILE *arquivo, int recorde);
int recorde(FILE *);

void ler_arquivo( matriz* m, char* arquivo) {
    FILE *fp = fopen(arquivo, "r");

    if(arquivo==NULL){
      printf("Nao Abriu ! \n");
    }

    fscanf(fp, "%d", &m->numero_elementos);
    // FAZ COM QUE A PRIMEIRA LINHA RECEBA O NUMERO DE ELEMENTOS

    m->elementos = malloc(m->numero_elementos * sizeof(int*));

    for(int i = 0; i < m->numero_elementos; i++) {
        m->elementos[i] = malloc(m->numero_elementos * sizeof(int));
        for(int j = 0; j < m->numero_elementos; j++) {
            fscanf(fp, "%d ", &m->elementos[i][j]);
        }
    }


    fclose(fp);
}

 void imprimir_matriz_jogador(FILE *arquivo ){
  if (arquivo == NULL){
    printf("Nao abriu !\n");
  }

  char ch = fgetc(arquivo);

  while (ch != EOF){
  	printf("%c", ch);
    ch = fgetc(arquivo);
    }
  printf("\n");

 }



void construindo_caminho_IA( matriz m, int* caminho) {
    int *inseridos = malloc(m.numero_elementos * sizeof(int));
    casa *vizinhos = malloc(m.numero_elementos * sizeof(casa));

    for(int i = 0; i < m.numero_elementos; i++) {
        inseridos[i] = FALSE;
    }

    caminho[0] = 0;
    inseridos[0] = TRUE;

    for(int i = 0; i < m.numero_elementos; i++) {
        int iv = 0;

        for(int j = 0; j < m.numero_elementos; j++) {
            if(!inseridos[j]) {
                vizinhos[iv].indice = j;
                vizinhos[iv].valor = m.elementos[i][j];
                iv++;
            }
        }FILE *arquivo;

        if(iv == 0) {
            caminho[i + 1] = 0;
        } else {
            int vizinho_selecionado = rand() % iv;

            caminho[i + 1] = vizinhos[vizinho_selecionado].indice;
            inseridos[vizinhos[vizinho_selecionado].indice] = TRUE;
        }
    }

    free(inseridos);
    free(vizinhos);
}

int calcular_custo( matriz m, int* caminho) {
    int custo = 0;

    for(int i = 0; i < m.numero_elementos; i++) {
        custo = custo + m.elementos[caminho[i]][caminho[i + 1]];
    }

    return custo;
}
void linha() {
    int i;
    printf("\n");
    for(i = 0; i < 80; i++) printf("_");
    printf("\n");

}

int* receber_caminho(matriz m , int* caminho) {
  int *c;
  c = malloc(sizeof(int)*m.numero_elementos);
  for(int i=0;i<m.numero_elementos;i++){
    c[i]=0;
  }
  for(int i = 0; i < m.numero_elementos; i++) {
    c[i] = caminho[i];
  }
  return c;
}

void imprimir_matriz( matriz m){
    printf("Matriz\n\n");
    for(int i = 0; i < m.numero_elementos; i++) {
        for(int j = 0; j < m.numero_elementos; j++){
            printf("%d ", m.elementos[i][j]);
            printf("|");
        }

        printf("\n");
    }

    linha();
}
int repetida(int caminho, int j, int *c){

  for(int i=0;i<j;i++){
    if(c[i]==caminho){
      return 1;
    }
  }
  return 0;
}
void player(matriz m, FILE *arquivo){


    system("color 2");
  //arquivo = fopen("recorde.txt","r");
  //int r = recorde(arquivo);
  //printf("Recorde Atual: %d\n", r);
  interface_Matriz(m);
  int proximoCaminho,d,caminhoAtual=0,cont=0,custo = 0,perda=0;
  int *c;
  int recorde;
  printf("\n");


    //ESTE "FOR" EH PARA AS ENTRADAS DO PLAYER

  c = malloc(sizeof(int*)*m.numero_elementos);

////////////////////////////////////

//lembrar de mostrar os possíveis caminhos (Adson)
  printf("\n\nVoce esta na casa 1 \nVoce tem 12 segundos para fazer uma escolha.\n" );
////////////////////////////FILE *arquivo;///////
  for(int i=0; i<m.numero_elementos-1;i++){
    printf("Qual casa dejesa ir ?\n");
    time_t inicio = time(NULL);
    scanf("%d", &proximoCaminho); // AQUI DIZ PARA QUAL CAMINHO ELE QUE IR

    proximoCaminho--;
  if(proximoCaminho<=0 || proximoCaminho >= m.numero_elementos){
    printf("Digite um valor valido\n");
    i--;
    continue;
  }
    c[i] = proximoCaminho ; // VETOR QUE GUARDA O CAMINHO DO PLAYER
    d = repetida(proximoCaminho,i,c);
    if(d==1){
      printf("Voce nao pode colocar numeros repetidos\n");
      i--;
      continue;
    }
        for(int k=0;k<m.numero_elementos;k++){

          if((c[i])==k){
            printf("Casa %d: Voce   | ",(k+1));
          }else{
              if(repetida(k,i,c)==1){
                printf("Casa %d: Visitada | ",(k+1));

              }
          }

          if(repetida(k,i,c)==0){
            if((k!=0)&&((c[i])!=k)){
              printf("Casa %d:   %d    | ",(k+1),m.elementos[caminhoAtual][k]);
            }else{
              if(k==0)
                printf("Casa %d: Partida | ",(k+1));
            }
          }

          if((k+1)%5==0){
            printf("\n\n");
          }
        }system("color 4");


    custo = custo + m.elementos[caminhoAtual][proximoCaminho]; // CALCULA O CUTO DA ESCOLHA DO PLAYER
    printf("\nCusto ate agora: %d \n\n", custo);
    caminhoAtual = proximoCaminho ;
    /* FAZ COM QUE O PLAYER FIQUE NO CAint recorde(FILE *arquivo)MINHO ATUAL ANTES DE IR
    PARA A PROXIMA CIDADE
    */
     //interface_Matriz(m);
    time_t fim = time(NULL);

    if((fim-inicio)>12){
      i=m.numero_elementos;
      printf("   PERDEU!!!\n O TEU TEMPO ACABOU!!!");
      perda=1;
      }

  }

  custo = custo + m.elementos[caminhoAtual][0];

  if(perda==1){
    custo = 9999999;
  }
if(custo<recorde){
  recorde = custo;
  addRecorde(arquivo, recorde);
}

printf("\n SEU CAMINHO: 1 ");
for(int i = 0; i<m.numero_elementos;i++){
  printf("%d ", c[i]+1);
}

printf("\n CUSTO: %d\n",custo);
custo_Player = custo;

}

void IA(matriz m){

  interface_Matriz(m);
  int custo_IA = 0, menor = INT_MAX ;
// A PARTIR DAQUI É A JOGADA DA IA
      srand(1);

    int *solucao_aleatoria = malloc((m.numero_elementos + 1) * sizeof(int*));/*
    --> ESSE PONTEIRO RECEBE O TAMANHO DA MATRIZ + 1 ESPAÇO ADCIONAL
    */
  int *d=malloc(sizeof(int**)*m.numero_elementos);

// ESSE FOR ACHA A MELHOR JOGADA DA IA ENTRE UM DETERMINADO VALOR
    for(int i = 0; i < 100000; i++) {

        construindo_caminho_IA(m, solucao_aleatoria); // AQUI CONSTROI CAMINHOS ALEATORIOS
        custo_IA = calcular_custo(m, solucao_aleatoria);//

        if(menor>custo_IA){
          menor = custo_IA;
          d = receber_caminho(m, solucao_aleatoria);
        }
    }
    printf("custo IA: ");
  for(int i=0;i<m.numero_elementos;i++){
    printf("%d ", d[i]+1);
  }
  printf("1");
  printf("\nCusto solucao IA: %d\n", menor);
  custo_IA = menor;
  linha();
  free(solucao_aleatoria);
}
void interface_Matriz(matriz m){

  FILE *arquivo;
  arquivo = fopen("cidade_Jogador1.txt","r");
  imprimir_matriz_jogador(arquivo); /* --> aqui está lendo os arquivos referente a matriz que o jodador vai
  visualizar */
free(arquivo);
}
void player_IA(){
    player(m, arquivo);
    IA(m);

    printf("Player: %d \n IA: %d", custo_Player, custo_IA);
    if (custo_IA > custo_Player){
        printf("VOCE PERDEU!!");
    }else{
        printf("VOCE GANHOU");
    }
}
void addRecorde(FILE *arquivo, int recorde){
  if (arquivo == NULL){
    printf("Não abriu !\n");
  }
  arquivo = fopen("recorde.txt","w");
  fprintf(arquivo,"%d",recorde);

}
int recorde(FILE *arquivo){
  if (arquivo == NULL){
    printf("Nao abriu !\n");
  }
  int ch;
  fscanf(arquivo,"%d", &ch);
  return ch;

}
