#include <stdio.h>

int main(){
    int n_candidatos = 3;
    int n_eleitores = 5;

    int numeros_candidatos[n_candidatos];

    int votos_candidatos[n_candidatos];
    int n_votos_nulos;
    int voto;

    //ler numeros dos candidatos
    for(int i=0; i<n_candidatos; i++){
        printf("Digite o numero do candidato %d: ",i+1);
        scanf("%d",&numeros_candidatos[i]);
    }

    //inicializa votação
    for(int i=0; i<n_candidatos; i++){
        votos_candidatos[i] = 0; 
    }
    n_votos_nulos = 0;

    printf("Candidatos:\n");
    for(int i=0; i<n_candidatos; i++){
        printf("Candidato %d: %d\n",(i+1),numeros_candidatos[i]);
    }

    //Leitura dos votos
    for(int i=1; i<=n_eleitores; i++){
        printf("Voto do eleitor %d: ",i);
        scanf("%d",&voto);

        int flag_nulo = 1;
        for(int i=0; i<n_candidatos; i++){
            if(voto == numeros_candidatos[i]){
                votos_candidatos[i]++;
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
        printf("Candidato %d tem %d votos\n",numeros_candidatos[i],votos_candidatos[i]);
    }
    printf("Nulos: %d\n",n_votos_nulos);
    

    //apuração da votação
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
            numeros_candidatos[indice_vencedor], 
            votos_candidatos[indice_vencedor]);
    }
    return 0;
}