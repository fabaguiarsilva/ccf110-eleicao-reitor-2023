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

    //Impressão dos
    printf("Votos por candidato:\n");
    printf("Candidato 1: %d\n",votos_candidatos[0]);
    printf("Candidato 2: %d\n",votos_candidatos[1]);
    printf("Candidato 3: %d\n",votos_candidatos[2]);
    printf("Nulos: %d\n",n_votos_nulos);
    
    int indice_vencedor = 0;
    //indicador se houve empate (1) ou não (0)
    int empate = 0;

    for(int i=1; i<n_candidatos; i++){
        if(votos_candidatos[i] 
            > votos_candidatos[indice_vencedor]){
                indice_vencedor = i;
                empate = 0;
        }else if(votos_candidatos[i] 
            == votos_candidatos[indice_vencedor]){
                empate = 1;
        }
    }

    if(empate == 1){
        printf("Empate!");
    }else{

        printf("O vencedor é o candidato %d com %d votos\n",
            indice_vencedor+1, votos_candidatos[indice_vencedor]);

    }
    return 0;
}