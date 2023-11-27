#include "candidato.h"
#include "eleitor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FLAG_TESTE 1

//passagem de parâmetro por referência
void lerNumeroCandidatos(int *n_candidatos){
    if(FLAG_TESTE == 0){
        printf("Digite o número de candidatos: ");
        scanf("%d",n_candidatos);
    }else{
        *n_candidatos = 5;
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
            (*n_nulos)++;
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
                *indice_vencedor = i;
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

void salvaResultadoArquivo(int empate, Candidato vencedor){

    FILE *arquivoResultado;

    if((arquivoResultado = fopen("resultado.txt","a")) == NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }

    if(empate == 1){
        fprintf(arquivoResultado,"Empate!");
    }else{
        fprintf(arquivoResultado,"O vencedor é o candidato %s (%d) com %d votos\n",
            vencedor.nome,
            vencedor.numero, 
            vencedor.n_votos);
    }   

    fclose(arquivoResultado); 
}


void lerDadosCandidatosArquivo1(int n_candidatos, Candidato candidatos[]){
    
    FILE *arquivoCandidatos;

    if((arquivoCandidatos = fopen("candidatos1.txt","r")) == NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }

    int cont=0;
    for(int i=0; i<n_candidatos; i++){
        char c;
        
        printf("i=%d\n",i);
        cont=0;
        while(1){
            c = fgetc(arquivoCandidatos);
            if(c != ';'){
                printf("C=%c\n",c);
                candidatos[i].nome[cont] = c;
                cont++;
            }else{
                break;
            }
        }

        char num[5];
        cont = 0;
        while(1){
            c = fgetc(arquivoCandidatos);
            if(c != ';'){
                num[cont] = c;
                cont++;
            }else{
                candidatos[i].numero = atoi(num);
                break;
            }    
        }
        fgetc(arquivoCandidatos);

        printf("Nome arquivo: %s (%d)\n",candidatos[i].nome,candidatos[i].numero);

    }
    fclose(arquivoCandidatos);
}



void lerDadosCandidatosArquivo(int n_candidatos, Candidato candidatos[]){
    
    FILE *arquivoCandidatos;

    if((arquivoCandidatos = fopen("candidatos.txt","r")) == NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }

    char linha[30];
    for(int i=0; i<n_candidatos; i++){
        fgets(linha, 30, arquivoCandidatos);
        //printf("LINHA: %s\n",linha);
        strcpy(candidatos[i].nome, linha);

        fgets(linha, 30, arquivoCandidatos);
        candidatos[i].numero = atoi(linha);

    }

    fclose(arquivoCandidatos);

}