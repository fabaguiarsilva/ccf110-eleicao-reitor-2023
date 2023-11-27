#include "eleicao.h"
#include <stdio.h>

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
    //lerDadosCandidatos(n_candidatos, candidatos);
    lerDadosCandidatosArquivo(n_candidatos, candidatos);


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

    //mostrarResultado(empate, candidatos[indice_vencedor]);
    salvaResultadoArquivo(empate, candidatos[indice_vencedor]);
    return 0;
}