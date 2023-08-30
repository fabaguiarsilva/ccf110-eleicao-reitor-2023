#include <stdio.h>

int main(){
    int n_votos_candidato1, 
        n_votos_candidato2,
        n_votos_candidato3;

    int voto_eleitor1,
        voto_eleitor2,
        voto_eleitor3,
        voto_eleitor4,
        voto_eleitor5;


    //inicializa votação
    n_votos_candidato1 = 0;
    n_votos_candidato2 = 0;
    n_votos_candidato3 = 0;

    //Leitura dos votos
    printf("Voto do eleitor 1: ");
    scanf("%d",&voto_eleitor1);

    printf("Voto do eleitor 2: ");
    scanf("%d",&voto_eleitor2);

    printf("Voto do eleitor 3: ");
    scanf("%d",&voto_eleitor3);

    printf("Voto do eleitor 4: ");
    scanf("%d",&voto_eleitor4);

    printf("Voto do eleitor 5: ");
    scanf("%d",&voto_eleitor5);


    printf("Votos: \n");
    printf("Eleitor 1: %d\n",voto_eleitor1);
    printf("Eleitor 2: %d\n",voto_eleitor2);
    printf("Eleitor 3: %d\n",voto_eleitor3);
    printf("Eleitor 4: %d\n",voto_eleitor4);
    printf("Eleitor 5: %d\n",voto_eleitor5);

    //Contagem dos votos
    if(voto_eleitor1 == 1) {
        n_votos_candidato1++;
    }else if(voto_eleitor1 == 2){
        n_votos_candidato2++;
    }else if(voto_eleitor1 == 3){
        n_votos_candidato3++;
    }else{
        printf("Eleitor 1 votou nulo");
    }
    
    if(voto_eleitor2 == 1) {
        n_votos_candidato1++;
    }else if(voto_eleitor2 == 2){
        n_votos_candidato2++;
    }else if(voto_eleitor2 == 3){
        n_votos_candidato3++;
    }else{
        printf("Eleitor 2 votou nulo");
    }

    if(voto_eleitor3 == 1) {
        n_votos_candidato1++;
    }else if(voto_eleitor3 == 2){
        n_votos_candidato2++;
    }else if(voto_eleitor3 == 3){
        n_votos_candidato3++;
    }else{
        printf("Eleitor 3 votou nulo");
    }   

    if(voto_eleitor4 == 1) {
        n_votos_candidato1++;
    }else if(voto_eleitor4 == 2){
        n_votos_candidato2++;
    }else if(voto_eleitor4 == 3){
        n_votos_candidato3++;
    }else{
        printf("Eleitor 4 votou nulo");
    }

    if(voto_eleitor5 == 1) {
        n_votos_candidato1++;
    }else if(voto_eleitor5 == 2){
        n_votos_candidato2++;
    }else if(voto_eleitor5 == 3){
        n_votos_candidato3++;
    }else{
        printf("Eleitor 5 votou nulo");
    }

    //Apuração
    printf("Votos por candidato:\n");
    printf("Candidato 1: %d\n",n_votos_candidato1);
    printf("Candidato 2: %d\n",n_votos_candidato2);
    printf("Candidato 3: %d\n",n_votos_candidato3);

    return 0;
}