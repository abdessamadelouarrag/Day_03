#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct contact
{
    char nom[100];
    char numerodetelephone[30];
    char email[100];
};

struct contact contacts[100];

int nombredecontacts = 0;

// clear screen

void clearscreen(){
    system("cls || clear");
}

//fonction d'ajouter un contact

void ajouteruncontact(){

    clearscreen();

    printf("==== A J O U T E R  U N  C O N T A C T ====\n");

    printf("entrer le nom : \n");
    scanf(" %[^\n]", contacts[nombredecontacts].nom);
    printf("entre numero de telephone : \n");
    scanf(" %[^\n]", contacts[nombredecontacts].numerodetelephone);
    printf("entrer l\'email : \n");
    scanf(" %[^\n]", contacts[nombredecontacts].email);

    printf(ANSI_COLOR_GREEN "ajouter un contact good !\n" ANSI_COLOR_RESET);

    nombredecontacts++;

    printf("pour continer appuyez sur entre...\n");
    getchar();
    getchar();

    clearscreen();
}

//fonction d'afficher tous les contacts 

void affichertouslescontacts(){

    clearscreen();

    printf("==== A F F I C H E R  T O U S  L E S  C O N T A C T S ====\n");

    for (int i = 0; i < nombredecontacts; i++)
    {
        printf("\n******************************\n");
        printf("le nom : %s\t", contacts[i].nom);
        printf("numero de telephone : %s\t", contacts[i].numerodetelephone);
        printf("l\'email : %s\t", contacts[i].email);
        printf("\n");
    }

    if (nombredecontacts == 0)
    {
        printf("\nnon contact !!!\n");
    }
    printf("\n");
    printf("pour continer appuyez sur entre...\n");
    getchar();
    getchar();

    clearscreen();
}

//fonction de rechercher un contact

void rechercheruncontact(){

    clearscreen();

    printf("==== R E C H E R C H E R  U N  C O N T A C T ====\n");

    char nvnom[100];
    int kayn = 0;

    if (nombredecontacts == 0)
    {
        printf("\nnon contact ici !!\n");

        printf("\npour continer appuyez sur entre...\n");
        getchar();
        getchar();

        clearscreen();
    }


    if (nombredecontacts >= 1)
    {
        printf("entrer le nom de contact : \n");
        scanf(" %[^\n]", nvnom);
        getchar();
    
        
        for (int i = 0; i < nombredecontacts; i++)
        {
    
            if (strcmp(nvnom, contacts[i].nom) == 0)
            {
                printf("\n*****************************************\n");
                printf("j\'ai trouve le contact avec le nom de (%s) : \n", contacts[i].nom);
                printf("\t \n");
                printf("==>\t");
                printf("le nom : %s\t", contacts[i].nom);
                printf("numero de telephone : %s\t", contacts[i].numerodetelephone);
                printf("l\'email : %s\t", contacts[i].email);
                printf("\n");
                kayn = 1;
            }
        }
    
        
        if (kayn != 1)
        {
            printf("!!!!!!!!!!!\n");
            printf("non contact avec le nom de (%s) ajoute le contact ou entrer autre nom \n", nvnom);
        }

        printf("\npour continer appuyez sur entre...\n");
        getchar();
    
        clearscreen();
    }
}

//fonction de modifier un contact

void modifieruncontact(){

    clearscreen();

    printf("==== M O D I F I E R  U N  C O N T A C T ====\n");

    char nvcnt[100];
    char nvnom1[100];
    char nvphone[100];
    char nvemail[100];
    char yn;

    if (nombredecontacts == 0)
    {
        printf("\naucun contact pour modifier !\n");

        printf("\npour continue assuyez sur entre...\n");
        getchar();
        getchar();
    
        clearscreen();
    }
    
    if (nombredecontacts >= 1)
    {
        printf("entrer le nom de contact pour modifier : \n");
        scanf(" %[^\n]", nvcnt);
        getchar();

        clearscreen();

        printf("==== M O D I F I E R  U N  C O N T A C T ====\n");
    
        int kayna = 0;
    
        for (int i = 0; i < nombredecontacts; i++)
        {
            if (strcmp(nvcnt, contacts[i].nom) == 0)
            {
                kayna = 1;
    
                printf("le contact a trouve de nom %s: \n", contacts[i].nom);
    
                printf("voulez-vous changer le nom (Y = yes /N = no) : \n");
                scanf(" %c",&yn);
    
                if (yn == 'y' || yn == 'Y')
                {
                    printf("le nouvelle nom : \n");
                    scanf(" %[^\n]", contacts[i].nom);
                }
    
                printf("voulez-vous changer numero de telephone (Y = yes /N = no) : \n");
                scanf(" %c",&yn);
                getchar();
    
                if (yn == 'y' || yn == 'Y')
                {
                    printf("la nouvelle numero de telephone : \n");
                    scanf(" %[^\n]", contacts[i].numerodetelephone);
                }
                
                printf("voulez-vous changer l\'email (Y = yes /N = no) :\n");
                scanf(" %c", &yn);
                getchar();
    
                if (yn == 'y' || yn == 'Y')
                {
                    printf("le nouvelle email : \n");
                    scanf(" %[^\n]", contacts[i].email);
                } 
                printf("modification good !! \n");
            }
        }
    
        if (kayna != 1)
        {
            printf("non contact avec se nom !!!\n");
        }
    
        printf("pour continer appuyez sur entre...\n");
        getchar();
    
        clearscreen();
    }
}

//exit program

int exitprgrame(){

    clearscreen();

    printf("==== E X I T  L E  P R O G R A M E ====\n");

    char exitp;

    printf(ANSI_COLOR_BLUE "Voulez-vous quitter le programme ? (N = no /Y = yes)  : \n" ANSI_COLOR_RESET);
    scanf(" %c", &exitp);
    getchar();

    clearscreen();
    
    if (exitp == 'y' || exitp == 'Y')
    {
       printf("ok good byy !\n");
       return 0;
    }
    else
    {
        printf("continue le programe ... \n");
        return 1;
    }
}

//fonction supprimer un contact

void supprimeruncontact(){

    clearscreen();

    printf("==== S U P P R I M E R  U N  C O N T A C T ====\n");

    char nomdesupp[100];
    int delet = 0;

    if (nombredecontacts == 0)
    {
        printf("\nnon contact pour supprimer ! \n");

        printf("\npour continer appuyez sur entre...\n");
        getchar(); // get (/n)
        getchar();
    }
    
    clearscreen();

    if (nombredecontacts >= 1)
    {
        printf("entrer le nom de contact pour supprimer : \n");
        scanf(" %[^\n]", nomdesupp);
        getchar();
    
        for (int i = 0; i < nombredecontacts; i++)
        {
            if (strcmp(nomdesupp, contacts[i].nom) == 0)
            {
                for (int j = i; j < nombredecontacts; j++)
                {
                    strcpy(contacts[i].nom,contacts[i+1].nom);
                    strcpy(contacts[i].numerodetelephone,contacts[i+1].numerodetelephone);
                    strcpy(contacts[i].email,contacts[i+1].email);
                    delet = 1;
                }
                printf(ANSI_COLOR_GREEN "supprimer le contact good !\n" ANSI_COLOR_RESET);
                nombredecontacts--;
            }
        }
        if (delet != 1)
        {
            printf("non contact avec le nom de %s !!\n", nomdesupp);
        }
        printf("pour continer appuyez sur entre...\n");
        getchar();
    
        clearscreen();
    }
}

// main et (menu)

int main(){

    clearscreen();

    int choix;
    int exitp;

    do
    {
        printf("\n");
        printf("********** MENU *********\n");
        printf("1. ajouter un contact \n");
        printf("2. afficher tout les contacts \n");
        printf("3. recherche un contact \n");
        printf("4. modifier un contact \n");
        printf("5. supprimer un contact\n");
        printf("0. exit \n");
        printf("==> Entrer votre choix : ");
        scanf("%d", &choix);


        switch (choix)
        {
        case 0://exit
            if (exitprgrame() == 1)
            {
                choix = 37;
            }
            break;    
        case 1://pour ajouter un contact
            ajouteruncontact();
            break;
        case 2://pour afficher un contact
            affichertouslescontacts();
            break;
        case 3://pour rechercher un contact
            rechercheruncontact();
            break;
        case 4://pour modifier un contact
            modifieruncontact();
            break;
        case 5://pour supprimer un contact
            supprimeruncontact();
            break;
        default:
            clearscreen();

            printf(ANSI_COLOR_RED "entrer just un nombre entre 0 - 5 !! ok\n" ANSI_COLOR_RESET);
            break;
        }
    } while (choix != 0);
    
}
