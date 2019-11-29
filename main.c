#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int numero_elementos;
    int** elementos;
} matriz;


struct nodo {
    int indice;
    int valor;
};

void ler_arquivo(matriz*, char*);
void logo(FILE *arquivo );
void realizar_movimento_troca( matriz m, int* solucao_inicial, int* melhor_vizinho);

void construir_caminho_aleatorio( matriz m, int* caminho);

int calcular_custo( matriz, int*);

void construir_caminho( matriz, int*);

void construir_caminho_aleatorio( matriz, int*);

void imprimir_caminho(int, int*);

void imprimir_matriz( matriz);
void linha();

int main() {

  matriz m;
  FILE *arquivo;
  arquivo = fopen("cidade_Jogador.txt","r");
  logo(arquivo);
  int custo_solucao_aleatoria = 0, menor = INT_MAX ;
  ler_arquivo(&m, "cidade1.txt");

  int caminhoProximo, caminho[]={'0'};
  int custo = 0,cont=0,caminhoAtual=0;
  int tam = m.numero_elementos;
  int c[10]={'0'};
  
printf("\n");

imprimir_matriz(m);

  for(int i=0; i<tam;i++){
    printf("Qual casa dejesa ir ?\n");
    scanf("%d", &caminhoProximo);
  
    c[i] = caminhoProximo ;
    custo = custo + m.elementos[caminhoAtual][caminhoProximo];
    caminhoAtual = caminhoProximo ;
}
printf("\n SEU CAMINHO: \n");
for(int i = 0; i<10;i++){
  printf("%d ", c[i]);
}
printf("\n CUSTO: %d",custo);

/*

   int *solucao_inicial = malloc((m.numero_elementos)*sizeof(int*));

    construir_caminho(m, solucao_inicial);
printf("\n");
    printf("\nSolucao inicial: ");
    imprimir_caminho(m.numero_elementos, solucao_inicial);

    int custo_solucao_inicial = calcular_custo(m, solucao_inicial);
    printf("\nCusto solução inicial: %d\n", custo_solucao_inicial);

*/
      srand(time(NULL));
      linha();

    int *solucao_aleatoria = malloc((m.numero_elementos + 1) * sizeof(int*));

    for(int i = 0; i < 10000; i++) {

        construir_caminho_aleatorio(m, solucao_aleatoria);
        custo_solucao_aleatoria = calcular_custo(m, solucao_aleatoria);

        if(menor>custo_solucao_aleatoria){
          menor = custo_solucao_aleatoria;
          cont++;
           if(cont == 10){
            imprimir_caminho(m.numero_elementos,solucao_aleatoria);
           }
        }
    } 
    printf("Custo solução IA: %d\n", menor);
    linha();

}
//-----------------------------------------------------------------------------


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
//-----------------------------------------------------------------------------
void logo(FILE *arquivo ){      	
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

void copiar_caminho( matriz m, int* origem, int* destino) {
    int i;

    for(i = 0; i <= m.numero_elementos; i++) {
        destino[i] = origem[i];
    }
}

void construir_caminho_aleatorio( matriz m, int* caminho) {
    int *inseridos = malloc(m.numero_elementos * sizeof(int));
    struct nodo *vizinhos = malloc(m.numero_elementos * sizeof(struct nodo));

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

//-----------------------------------------------------------------------------

void construir_caminho( matriz m, int* caminho) {
    int *inseridos = malloc(m.numero_elementos * sizeof(int));

    for(int i = 0; i < m.numero_elementos; i++) {
        inseridos[i] = FALSE;
    }

    caminho[0] = 0;
    inseridos[0] = TRUE;

    for(int i = 0; i < m.numero_elementos; i++) {
        int valor_referencia = INT_MAX;
        int vizinho_selecionado = 0;

        for(int j = 0; j < m.numero_elementos; j++) {
            if(!inseridos[j] && valor_referencia > m.elementos[i][j] && m.elementos[i][j]>-1) {
                vizinho_selecionado = j;
                valor_referencia = m.elementos[i][j];
            }
        }

        caminho[i + 1] = vizinho_selecionado;
        inseridos[vizinho_selecionado] = TRUE;
    }

    caminho[m.numero_elementos] = 0;

    free(inseridos);
}



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------

void imprimir_caminho(int n, int* caminho) {
    int i,d;
    
    for(i = 0; i < n; i++) {
      printf(" %d ",caminho[i]);
    }
    printf("\n");
}

//-----------------------------------------------------------------------------

void linha() {
    int i;
    printf("\n");
    for(i = 0; i < 80; i++) printf("_");
    printf("\n");
  
}