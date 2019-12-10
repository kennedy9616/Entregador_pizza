#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int numero_elementos;
    int** elementos;
} matriz;

typedef struct{
    int indice;
    int valor;
}casa;

matriz m;
FILE *arquivo;
int r;

void ler_arquivo( matriz* m, char* arquivo);
void interface_Matriz(matriz m,char *arquivo);
void construindo_caminho_IA( matriz m, int* caminho);
int calcular_custo( matriz m, int* caminho);
void linha();
int* receber_caminho(matriz m , int* caminho);
void imprimir_matriz( matriz m);
int repetida(int caminho, int i, int c[]);
void player(matriz m);
void IA(matriz m, int dificuldade);
void player_IA(matriz m, FILE *arquivo, int dificuldade);
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

        }
        FILE *arquivo;

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

void interface_Matriz(matriz m,char *arquivo){
  FILE* fp = fopen(arquivo,"r");

  if (fp == NULL){
    printf("Não abriu !\n");
  }

  char ch = fgetc(fp);

  while (ch != EOF){
  	printf("%c", ch);
    ch = fgetc(fp);
    }
  printf("\n");
free(fp);
}

int repetida(int caminho, int j, int *c){

  for(int i=0;i<j;i++){
    if(c[i]==caminho){
      return 1;
    }
  }
  return 0;
}

void player(matriz m){

    system("color 2");

  int proximoCaminho,d,caminhoAtual=0,cont=0,custo = 0,perda=0;
  int *c;
  int recorde;
  printf("\n");

  c = malloc(sizeof(int*)*m.numero_elementos);

////////////////////////////////////

  printf("\n\nVoce esta na casa 1 \n" );
////////////////////////////
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
        }

    custo = custo + m.elementos[caminhoAtual][proximoCaminho]; // CALCULA O CUTO DA ESCOLHA DO PLAYER
    printf("\nCusto ate agora: %d \n\n", custo);
    caminhoAtual = proximoCaminho ;
    /* FAZ COM QUE O PLAYER FIQUE NO CAint recorde(FILE *arquivo)MINHO ATUAL ANTES DE IR
    PARA A PROXIMA CIDADE
    */
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

  printf("\n SEU CAMINHO: 1 ");
  for(int i = 0; i<m.numero_elementos;i++){
    printf("%d ", c[i]+1);
  }

  printf("\n CUSTO: %d\n",custo);

}

void IA(matriz m, int dificuldade){

  int custo_IA = 0, menor = INT_MAX ;

  srand(time(NULL));

  int *solucao_aleatoria = malloc((m.numero_elementos + 1) * sizeof(int*));

  int *d=malloc(sizeof(int**)*m.numero_elementos);

// ESSE FOR ACHA A MELHOR JOGADA DA IA ENTRE UM DETERMINADO VALOR
    for(int i = 0; i < dificuldade; i++) {

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

  linha();
  free(d);
  free(solucao_aleatoria);
}

void player_IA(matriz m, FILE *arquivo, int dificuldade){
////////////////  PLAYER  ///////////////////

    system("color 2");

  int proximoCaminho,d,caminhoAtual=0,cont=0,custo = 0,perda=0;
  int *c;
  int recorde;
  printf("\n");

  c = malloc(sizeof(int*)*m.numero_elementos);

////////////////////////////////////
  printf("\n\nVoce esta na casa 1 \n" );
////////////////////////////
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
        }

    custo = custo + m.elementos[caminhoAtual][proximoCaminho]; // CALCULA O CUTO DA ESCOLHA DO PLAYER
    printf("\nCusto ate agora: %d \n\n", custo);
    caminhoAtual = proximoCaminho ;
    /* FAZ COM QUE O PLAYER FIQUE NO CAint recorde(FILE *arquivo)MINHO ATUAL ANTES DE IR
    PARA A PROXIMA CIDADE
    */

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

  printf("\n SEU CAMINHO: 1 ");
  for(int i = 0; i<m.numero_elementos;i++){
    printf("%d ", c[i]+1);
  }

  printf("\n CUSTO: %d\n",custo);
  int custo_Player = custo;
    ///////////////// IA /////////////////////////

  int custo_IA = 0, menor = INT_MAX ;

  srand(time(NULL));
 int *p = malloc((m.numero_elementos)*sizeof(int**));;

  int *solucao_aleatoria = malloc((m.numero_elementos + 1) * sizeof(int*));

// ESSE FOR ACHA A MELHOR JOGADA DA IA ENTRE UM DETERMINADO VALOR
    for(int i = 0; i < dificuldade; i++) {

        construindo_caminho_IA(m, solucao_aleatoria); // AQUI CONSTROI CAMINHOS ALEATORIOS
        custo_IA = calcular_custo(m, solucao_aleatoria);//

        if(menor>custo_IA){
          menor = custo_IA;
          p = receber_caminho(m, solucao_aleatoria);
        }
    }
    printf("custo IA: ");

  for(int i=0;i<m.numero_elementos;i++){
    printf("%d ", p[i]+1);
  }

  printf("1");
  printf("\nCusto solucao IA: %d\n", menor);
  custo_IA=menor;
  linha();

    printf("Player: %d \n IA: %d\n", custo_Player, custo_IA);
    if (custo_IA < custo_Player){
        printf("\nVOCE PERDEU!!\n");
    }else{
        printf("\nVOCE GANHOU\n");
    }
    free(p);
    free(solucao_aleatoria);
}
