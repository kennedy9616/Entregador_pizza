#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include "funcao.h"


int main(){

  matriz m;
  ler_arquivo(&m, "cidade1.txt"); // matriz que está sendo usada pela IA 
  FILE *arquivo;
  arquivo = fopen("recorde.txt","r");
  int r = recorde(arquivo);
  printf("Recorde Atual: %d\n", r);
  int dificuldade;

  //tempo();
  //printa matriz bonita
  interface_Matriz(m);
  // função incompleta para o jogador
  player(m,r,arquivo);
  // chama a resolução da IA
  IA(m);

}

/*
--> ESTA FUNÇÃO LER A MATRIZ USADA PELA IA 
*/
/*
void tempo(){
int sec=0;//segundos
        int min=0;//minutos
        int hr=0;//horas
       
        int i=0;//controle do loop
               
        do {
                system("cls");//limpa a tela
               
                printf("Cronômetro\n\n");
               
                printf("\n\t\t\t\t%dh:%dm:%ds\n\n", hr,min,sec);
               
                if(sec==60){
                    sec=0;
                    min++;
                }
               
                if(min==60){
                    min=0;
                    hr++;
                }
               
                if(hr==24){
                    hr=0;
                }
               
                Sleep(1000);//tem a função de pausar a execução por um determinado tempo
                sec++;
               
        }while (i==0);//condição para o loop infinito
 
    system("pause");
}
*/
