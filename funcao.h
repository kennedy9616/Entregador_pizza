#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char elementos_char;
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

void ler_arquivo( matriz* m, char* arquivo);
void imprimir_matriz_jogador(FILE *arquivo );
void construindo_caminho_IA( matriz m, int* caminho);
int calcular_custo( matriz m, int* caminho);
void linha();
int* receber_caminho(matriz m , int* caminho);
void imprimir_matriz( matriz m);
int repetida(int caminho, int i, int c[]);
void player(matriz m, int recorde, FILE *arquivo);
void IA();
void interface_Matriz(matriz m);
void addRecorde(FILE *arquivo, int recorde);
int recorde(FILE *arquivo);

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
    printf("Não abriu !\n"); 
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
        }

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
void player(matriz m,int recorde, FILE *arquivo){



  int proximoCaminho,d,caminhoAtual=0,cont=0,custo = 0;
  int *c;
  printf("\n");
  

    //ESTE "FOR" EH PARA AS ENTRADAS DO PLAYER

  c = malloc(sizeof(int*)*m.numero_elementos);

////////////////////////////////////

//lembrar de mostrar os possíveis caminhos (Adson)
  printf("\n\nVocê esta na casa 1 \n\n" );
///////////////////////////////////
  for(int i=0; i<m.numero_elementos-1;i++){
    printf("Qual casa dejesa ir ?\n");
    scanf("%d", &proximoCaminho); // AQUI DIZ PARA QUAL CAMINHO ELE QUE IR 

    proximoCaminho--;
  if(proximoCaminho==0){
    printf("Voce nao pode retorna a mesma casa\n");
    i--;
    continue;
  }
    c[i] = proximoCaminho ; // VETOR QUE GUARDA O CAMINHO DO PLAYER 
    d = repetida(proximoCaminho,i,c);
    if(d==1){
      printf("Você não pode colocar numeros repetidos\n");
      i--;
      continue; 
    }
        for(int k=0;k<m.numero_elementos;k++){

          if((c[i])==k){
            printf("Casa %d: Você    ",(k+1));
          }else{
              if(repetida(k,i,c)==1){
                printf("Casa %d: Visitada ",(k+1));
                
              }
          }

          if(repetida(k,i,c)==0){
            if((k!=0)&&((c[i])!=k)){
              printf("Casa %d:   %d    ",(k+1),m.elementos[caminhoAtual][k]);
            }else{
              if(k==0)
                printf("Casa %d: Partida ",(k+1));
            }
          }

          if((k+1)%5==0){
            printf("\n\n");
          }
        }
  
    
    custo = custo + m.elementos[caminhoAtual][proximoCaminho]; // CALCULA O CUTO DA ESCOLHA DO PLAYER 
    printf("\nCusto até agora: %d \n\n", custo);
    caminhoAtual = proximoCaminho ; 
    /* FAZ COM QUE O PLAYER FIQUE NO CAMINHO ATUAL ANTES DE IR 
    PARA A PROXIMA CIDADE 
    */
     //interface_Matriz(m);

  }

  custo = custo + m.elementos[caminhoAtual][0];
if(custo<recorde){
  recorde = custo;
  addRecorde(arquivo, recorde);
}

printf("\n SEU CAMINHO: 1 ");
for(int i = 0; i<m.numero_elementos;i++){
  printf("%d ", c[i]+1);
}

printf("\n CUSTO: %d\n",custo);

}

void IA(matriz m){
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
  printf("\nCusto solução IA: %d\n", menor);
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
void addRecorde(FILE *arquivo, int recorde){
  if (arquivo == NULL){ 		
    printf("Não abriu !\n"); 
  } 
  arquivo = fopen("recorde.txt","w");
  fprintf(arquivo,"%d",recorde);

}
int recorde(FILE *arquivo){
  if (arquivo == NULL){ 		
    printf("Não abriu !\n"); 
  } 
  int ch;
  fscanf(arquivo,"%d", &ch);
  return ch;	

}