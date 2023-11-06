#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "candidato.h"

#define FLAG_TESTE 1

int main(){
    
    //define a quantidade de candidatos e eleitores
    int n_candidatos;
    int n_eleitores;

    if(FLAG_TESTE == 0){
        printf("Digite o número de candidatos: ");
        scanf("%d",&n_candidatos);

        printf("Digite o número de eleitores: ");
        scanf("%d",&n_eleitores);
    }else{
        n_candidatos = 3;
        n_eleitores = 5;
    }

    //int numeros_candidatos[n_candidatos];
    //int votos_candidatos[n_candidatos];
    //char nomes_candidatos[n_candidatos][30];
    Candidato candidatos[n_candidatos];

    int n_votos_nulos;
    int voto;

    //ler numeros dos candidatos
    for(int i=0; i<n_candidatos; i++){

        if(FLAG_TESTE == 0){
            printf("Digite o numero do candidato %d: ",i+1);
            scanf("%d",&candidatos[i].numero);

            //lê o \n do scanf anterior e descarta
            getchar();
            printf("Digite o nome do candidato %d: ",i+1);
            //fflush(stdin);
        
            gets(candidatos[i].nome);
            //scanf("%s",&nomes_candidatos[i]);
            
        }else{
            //numeros_candidatos[i] = i+1;
            candidatos[i].numero = rand() % 100 + 1;
            char num[3];
            sprintf(num, "%d", candidatos[i].numero);
            strcat(strcpy(candidatos[i].nome, "Candidato "), num);
        }
    }

    //inicializa votação
    for(int i=0; i<n_candidatos; i++){
        candidatos[i].n_votos = 0; 
    }
    n_votos_nulos = 0;

    printf("Candidatos:\n");
    for(int i=0; i<n_candidatos; i++){
        printf("Candidato %d: %s\n",
                candidatos[i].numero,
                candidatos[i].nome);
    }

    //Leitura dos votos
    for(int i=1; i<=n_eleitores; i++){
        printf("Voto do eleitor %d: ",i);
        scanf("%d",&voto);

        int flag_nulo = 1;
        for(int i=0; i<n_candidatos; i++){
            if(voto == candidatos[i].numero){
                candidatos[i].n_votos++;
                flag_nulo = 0;
            }
        }

        if(flag_nulo == 1){
            n_votos_nulos++;
        }
    }

    //Impressão dos votos
    printf("Votos por candidato:\n");
    for(int i=0; i<n_candidatos; i++){
        printf("Candidato %d tem %d votos\n",
            candidatos[i].numero, candidatos[i].n_votos);
    }
    printf("Nulos: %d\n",n_votos_nulos);
    

    //apuração da votação
    int indice_vencedor = 0;
    //indicador se houve empate (1) ou não (0)
    int empate = 0;

    for(int i=1; i<n_candidatos; i++){
        if(candidatos[i].n_votos 
            > candidatos[indice_vencedor].n_votos){
                indice_vencedor = i;
                empate = 0;
        }else if(candidatos[i].n_votos 
            == candidatos[indice_vencedor].n_votos){
                empate = 1;
        }
    }

    if(empate == 1){
        printf("Empate!");
    }else{
        printf("O vencedor é o candidato %s (%d) com %d votos\n",
            candidatos[indice_vencedor].nome,
            candidatos[indice_vencedor].numero, 
            candidatos[indice_vencedor].n_votos);
    }
    return 0;
}