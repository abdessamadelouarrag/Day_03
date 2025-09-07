#include <stdio.h>

struct info
{
    char nom[100];
    char prenom[100];
    int age;
};

struct info infouser;

int main(){

    printf("entrer le nom :\n ");
    scanf(" %s", infouser.nom);
    printf("entrer le prenom : \n");
    scanf(" %s", infouser.prenom);
    printf("entrer l\'age : \n");
    scanf(" %d", &infouser.age);

    printf("==============================\n");
    printf("le nom : %s\n", infouser.nom);
    printf("le prenom : %s\n",infouser.prenom);
    printf("l\'age : %d", infouser.age);
    
}