#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    FILE *fichier;
    char pseudo[15];
    int min = 1;
    int max = 100;
    int essai = 0;
    int tentative;
    int nombreMystere = (rand() % (max - min + 1)) + min;

    fichier = fopen("essais.txt", "a");
    if(fichier == NULL){
        fputs("erreur lors de l'ouverture du fichier\n", stderr);
        return EXIT_FAILURE;
    }
    
    printf("Retrouver le nombre Mystere compris entre 1 et 100\n");

    
    while (tentative != nombreMystere){
        printf(">> ");
        scanf("%d", &tentative);

        essai++;
        fprintf(fichier, "Essai %d: %d\n", essai, tentative);

        if (tentative == nombreMystere){
            printf("Felicitation, %d est le nombre mystere que vous avez trouve apres %d essais\n", nombreMystere, essai);
        }else{
            if (tentative < nombreMystere){
                printf("le nombre mystere est plus grand que celui de votre tentative\n");
            }else{
                printf("le nombre mystere est plus petit que celui de votre tentative\n");
            }
        }
    }
    printf("Enregistre ta performance\nTon Pseudo: ");
    scanf("%c", &pseudo);
    fgets(pseudo, 15, stdin);
    fprintf(fichier, "\nPseudo: ");
    if (fputs(pseudo, fichier) == EOF){
        fputs("Erreur lors de l'ecriture du pseudo dans le fichier", stderr);
        return EXIT_FAILURE;
    }
    fprintf(fichier, "Nombre Mystere trouve apres : %d essais.\n\n", essai);
    fclose(fichier); 

    return (0);
}