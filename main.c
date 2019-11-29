#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

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
// struct recebe em qual casa o player está
void ler_arquivo( matriz* m, char* arquivo);
void imprimir_matriz_jogador(FILE *arquivo );
void construindo_caminho_IA( matriz m, int* caminho);
int calcular_custo( matriz m, int* caminho);
void linha();
void imprimir_caminho(int n, int* caminho);
void imprimir_matriz( matriz m);
void player(matriz m);
void IA();
void interface_Matriz(matriz m);

int main(){
  matriz m;
  ler_arquivo(&m, "cidade1.txt"); // matriz que está sendo usada pela IA 
  
  //printa matriz bonita
  interface_Matriz(m);
  // função incompleta para o jogador
  player(m);
  // chama a resolução da IA
  IA(m);

 
}

/*
--> ESTA FUNÇÃO LER A MATRIZ USADA PELA IA 
*/
void ler_arquivo( matriz* m, char* arquivo) {
    FILE *fp = fopen(arquivo, "r");

    fscanf(fp, "%d", &m->numero_elementos);

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
    printf("Não abriu"); 
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

void imprimir_caminho(int n, int* caminho) {
    int i;
    
    for(i = 0; i < n; i++) {
      printf(" %d ",caminho[i]);
    }
    printf("\n");
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
void player(matriz m){
   int proximoCaminho,caminhoAtual=0,cont=0,c[10]={'0'} ,custo = 0;

int tam = m.numero_elementos;
  
printf("\n");

imprimir_matriz(m);

    //ESTE "FOR" EH PARA AS ENTRADAS DO PLAYER

  for(int i=0; i< tam;i++){
    printf("Qual casa dejesa ir ?\n");
    scanf("%d", &proximoCaminho); // AQUI DIZ PARA QUAL CAMINHO ELE QUE IR 

    c[i] = proximoCaminho ; // VETOR QUE GUARDA O CAMINHO DO PLAYER 
    
    custo = custo + m.elementos[caminhoAtual][proximoCaminho]; // CALCULA O CUTO DA ESCOLHA DO PLAYER 

    caminhoAtual = proximoCaminho ; 
    /* FAZ COM QUE O PLAYER FIQUE NO CAMINHO ATUAL ANTES DE IR 
    PARA A PROXIMA CIDADE 
    */
}
printf("\n SEU CAMINHO: ");
for(int i = 0; i<10;i++){
  printf("%d ", c[i]);
}
printf("\n CUSTO: %d\n",custo);

}

void IA(matriz m){
  int custo_IA = 0, menor = INT_MAX ;
  
// A PARTIR DAQUI É A JOGADA DA IA 
      srand(time(NULL));

    int *solucao_aleatoria = malloc((m.numero_elementos + 1) * sizeof(int*));/*
    --> ESSE PONTEIRO RECEBE O TAMANHO DA MATRIZ + 1 ESPAÇO ADCIONAL 
    */ 
// ESSE FOR ACHA A MELHOR JOGADA DA IA ENTRE UM DETERMINADO VALOR 
    for(int i = 0; i < 10000; i++) {

        construindo_caminho_IA(m, solucao_aleatoria); // AQUI CONSTROI CAMINHOS ALEATORIOS 
        custo_IA = calcular_custo(m, solucao_aleatoria);//

        if(menor>custo_IA){
          menor = custo_IA;

           printf("\n O CAMINHO DA IA FOI: ");
            imprimir_caminho(m.numero_elementos,solucao_aleatoria);
           }
        }

    printf("Custo solução IA: %d\n", menor);
    linha();

}
void interface_Matriz(matriz m){

  FILE *arquivo;
  arquivo = fopen("cidade_Jogador.txt","r");
  imprimir_matriz_jogador(arquivo); /* --> aqui está lendo os arquivos referente a matriz que o jodador vai
  visualizar */

}