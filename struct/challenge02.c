#include <stdio.h>

struct etudiant
{
    char nom[100];
    char prenom[100];
    int note[3];
};

struct etudiant info;

int main(){

    printf("entrer le nom d\'etudiant :\n");
    scanf("%s", info.nom);

    printf("entrer le prenom d\'etudiqnt : \n ");
    scanf("%s", info.prenom);

    printf("entrer la note de math :\n");
    scanf("%d", &info.note[0]);

    printf("entrer la note de pc :\n");
    scanf("%d", &info.note[1]);

    printf("entrer la note de sport : \n");
    scanf("%d", &info.note[2]);

    printf("=================================\n");
    printf("le nom : %s\n", info.nom);
    printf("le prenom : %s\n", info.prenom);
    printf("la note de math : %d\n", info.note[0]);
    printf("la note de pc : %d\n", info.note[1]);
    printf("la note de sport : %d\n", info.note[2]);
}