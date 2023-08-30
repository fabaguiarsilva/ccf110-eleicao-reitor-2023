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


    return 0;
}