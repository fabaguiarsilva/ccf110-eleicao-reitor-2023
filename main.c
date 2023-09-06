#include <stdio.h>

int main(){
    int n_candidatos = 3;
    int n_eleitores = 5;

    int votos_candidatos[n_candidatos];
    int n_votos_nulos;
    int voto;


    //inicializa votação
    for(int i=0; i<n_candidatos; i++){
        votos_candidatos[i] = 0; 
    }
    n_votos_nulos = 0;

    //Leitura dos votos
    for(int i=1; i<=n_eleitores; i++){
        printf("Voto do eleitor %d: ",i);
        scanf("%d",&voto);

        switch(voto){
            case 1:
                votos_candidatos[0]++;
                break;
            case 2:
                votos_candidatos[1]++;
                break;
            case 3:
                votos_candidatos[2]++;
                break;
            default:
                n_votos_nulos++;
        }
    }

    //Apuração
    printf("Votos por candidato:\n");
    printf("Candidato 1: %d\n",votos_candidatos[0]);
    printf("Candidato 2: %d\n",votos_candidatos[1]);
    printf("Candidato 3: %d\n",votos_candidatos[2]);
    printf("Nulos: %d\n",n_votos_nulos);
    

    return 0;
}