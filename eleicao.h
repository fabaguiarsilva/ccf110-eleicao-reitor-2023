#include "candidato.h"
#include "eleitor.h"

void lerNumeroCandidatos(int *n_candidatos);
int lerNumeroEleitores();
void lerDadosCandidatos(int n_candidatos, Candidato candidatos[]);
void lerDadosEleitores(int n_eleitores, Eleitor eleitores[]);
void zeraVotos(int n, Candidato candidatos[]);
void exibeCandidatos(int n, Candidato candidatos[]);
void exibeEleitores(int n, Eleitor eleitores[]);
int is_voto_nulo(int n_candidatos, Candidato candidatos[], int voto);
void lerVotos(int n_candidatos, Candidato candidatos[], 
        int n_eleitores, Eleitor eleitores[],
        int *n_nulos);

void exibeVotos(int n_candidatos, Candidato candidatos[], int n_votos_nulos);

void apuracao(int n_candidatos, Candidato candidatos[], 
    int *indice_vencedor,int *empate);

    
void mostrarResultado(int empate, Candidato vencedor);

void salvaResultadoArquivo(int empate, Candidato vencedor);

void lerDadosCandidatosArquivo1(int n_candidatos, Candidato candidatos[]);
void lerDadosCandidatosArquivo(int n_candidatos, Candidato candidatos[]);