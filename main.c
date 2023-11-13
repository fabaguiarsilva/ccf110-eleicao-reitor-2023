#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "candidato.h"
#include "eleitor.h"

#define FLAG_TESTE 1

//passagem de parâmetro por referência
void lerNumeroCandidatos(int *n_candidatos){
    if(FLAG_TESTE == 0){
        printf("Digite o número de candidatos: ");
        scanf("%d",n_candidatos);
    }else{
        *n_candidatos = 3;
    }
}

//retorno do valor lido
int lerNumeroEleitores(){
    int n_eleitores;
    if(FLAG_TESTE == 0){
        printf("Digite o número de eleitores: ");
        scanf("%d",&n_eleitores);
    }else{
        n_eleitores = 5;
    }

    return n_eleitores;

}


void lerDadosCandidatos(int n_candidatos, Candidato candidatos[]){
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
}

void lerDadosEleitores(int n_eleitores, Eleitor eleitores[]){
    for(int i=0; i<n_eleitores; i++){
        if(FLAG_TESTE == 0){
            printf("Digite a matricula do eleitor %d: ",i+1);
            scanf("%d",&eleitores[i].matricula);

            //lê o \n do scanf anterior e descarta
            getchar();
            printf("Digite o nome do eleitor %d: ",i+1);
            //fflush(stdin);
        
            gets(eleitores[i].nome);
        }else{
            eleitores[i].matricula = rand() % 1000 + 1;
            char num[3];
            sprintf(num, "%d", eleitores[i].matricula);
            strcat(strcpy(eleitores[i].nome, "Eleitor "), num);
        }    

        eleitores[i].ja_votou = 0;
    }    
}


void zeraVotos(int n, Candidato candidatos[]){
    for(int i=0; i<n; i++){
        candidatos[i].n_votos = 0; 
    }    
}

void exibeCandidatos(int n, Candidato candidatos[]){
    printf("Candidatos:\n");
    for(int i=0; i<n; i++){
        printf("Candidato %d: %s\n",
                candidatos[i].numero,
                candidatos[i].nome);
    }
}

void exibeEleitores(int n, Eleitor eleitores[]){
    printf("Eleitores:\n");
    for(int i=0; i<n; i++){
        printf("Eleitor %d: %s\n",
                eleitores[i].matricula,
                eleitores[i].nome);
    }
}

int is_voto_nulo(int n_candidatos, Candidato candidatos[], int voto){

    int flag_nulo = 1;
    for(int i=0; i<n_candidatos; i++){
        if(voto == candidatos[i].numero){
            candidatos[i].n_votos++;
            flag_nulo = 0;
        }
    }
    return flag_nulo;    
}

void lerVotos(int n_candidatos, Candidato candidatos[], 
        int n_eleitores, Eleitor eleitores[],
        int *n_nulos){
    for(int i=1; i<=n_eleitores; i++){
        
        int matricula;
        printf("Digite a matricula: ");
        scanf("%d",&matricula);

        int matricula_valida = 0;
        int indice_eleitor_valido;
        for(int j=0; j<n_eleitores; j++){
            if(matricula == 
                eleitores[j].matricula){
                    matricula_valida = 1;
                    indice_eleitor_valido = j;
                    break;
            }
        }
        
        if(matricula_valida == 0){
            printf("Matricula inválida. Proximo eleitor...\n");
            continue;
        }

        if(eleitores[indice_eleitor_valido].ja_votou == 1){
            printf("Eleitor já votou!\n");
            continue;
        }
        
        int voto;
        printf("Voto do eleitor %d: ",matricula);
        scanf("%d",&voto);

        int flag_nulo = is_voto_nulo(n_candidatos, candidatos, voto);
        if(flag_nulo == 1){
            *n_nulos++;
        }
        eleitores[indice_eleitor_valido].ja_votou = 1;

    }
}

void exibeVotos(int n_candidatos, Candidato candidatos[], int n_votos_nulos){
    printf("Votos por candidato:\n");
    for(int i=0; i<n_candidatos; i++){
        printf("Candidato %d tem %d votos\n",
            candidatos[i].numero, candidatos[i].n_votos);
    }
    printf("Nulos: %d\n",n_votos_nulos);

}

void apuracao(int n_candidatos, Candidato candidatos[], 
    int *indice_vencedor,int *empate){

    for(int i=1; i<n_candidatos; i++){
        if(candidatos[i].n_votos 
            > candidatos[*indice_vencedor].n_votos){
                indice_vencedor = i;
                *empate = 0;
        }else if(candidatos[i].n_votos 
            == candidatos[*indice_vencedor].n_votos){
                *empate = 1;
        }
    }    
}
void mostrarResultado(int empate, Candidato vencedor){
    if(empate == 1){
        printf("Empate!");
    }else{
        printf("O vencedor é o candidato %s (%d) com %d votos\n",
            vencedor.nome,
            vencedor.numero, 
            vencedor.n_votos);
    }    
}


int main(){
    
    //define a quantidade de candidatos e eleitores
    int n_candidatos;
    int n_eleitores;

    lerNumeroCandidatos(&n_candidatos);
    printf("Numero Candidatos: %d\n",n_candidatos);

    n_eleitores = lerNumeroEleitores();
    printf("Numero de eleitores: %d\n",n_eleitores);

    Candidato candidatos[n_candidatos];
    Eleitor eleitores[n_eleitores];


    //ler dados dos candidatos
    lerDadosCandidatos(n_candidatos, candidatos);

    //ler dados dos eleitores
    lerDadosEleitores(n_eleitores, eleitores);

    //inicializa votação
    zeraVotos(n_candidatos, candidatos);

    int n_votos_nulos = 0;
    int voto;

    exibeCandidatos(n_candidatos, candidatos);
    exibeEleitores(n_eleitores, eleitores);

    //Leitura dos votos
    lerVotos(n_candidatos, candidatos, n_eleitores, eleitores,&n_votos_nulos);

    //Impressão dos votos
    exibeVotos(n_candidatos, candidatos, n_votos_nulos);    

    //apuração da votação
    int indice_vencedor = 0;
    //indicador se houve empate (1) ou não (0)
    int empate = 0;

    apuracao(n_candidatos, candidatos, &indice_vencedor, &empate);

    mostrarResultado(empate, candidatos[indice_vencedor]);
    return 0;
}