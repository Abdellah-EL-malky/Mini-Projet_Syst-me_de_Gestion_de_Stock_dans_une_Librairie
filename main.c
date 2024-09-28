#include <stdio.h>
#include <string.h>

int main() {
        int nombre_de_livres = 1000;
        int choix;
        char titre[nombre_de_livres][100], auteur[nombre_de_livres][100];
        float prix[nombre_de_livres];
        int quantite[nombre_de_livres];
        int livres_ajoutes = 0;
        int i = 0;
    do{
        printf("          Menu Principal :\n");
        printf("1.Ajouter un livre au stock.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Mettre a jour la quantite d'un livre.\n");
        printf("4.Supprimer un livre du stock.\n");
        printf("5.Afficher le nombre total de livres en stock.\n");
        printf("0.Quitter\n\n");
        printf("Saisissez votre choix:");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                //Ajouter un livre au stock
                        printf("Entrez les informations du livre que vous souhaitez ajouter:\n\n");
                        printf("Saisissez le titre:\n");
                        scanf("%s", titre[livres_ajoutes]);
                        printf("Saisissez l'auteur:\n");
                        scanf("%s", auteur[livres_ajoutes]);
                        printf("Saisissez le prix:\n");
                        scanf("%f", &prix[livres_ajoutes]);
                        printf("Saisissez la quantite que vous voulez ajouter:\n");
                        scanf("%d",&quantite[livres_ajoutes]);
                        livres_ajoutes++;
                 break;
            case 2:
                //Afficher tous les livres disponibles
                    if (livres_ajoutes == 0) {
                        printf("Aucun livre n'est disponibe en stock.\n");
                    } else {
                    printf("Il y a %d livres.\n ",livres_ajoutes);
                    for (int i = 0; i < livres_ajoutes; i++) {
                        printf("Il y a:  Titre:\"%s\"  Auteur:\"%s\"  Prix:\"%.2f\"  Quantite:\"%d\"\n", titre[i],auteur[i],prix[i],quantite[i]);
                    }
                break;
            case 3:
                        //Mettre a jour la quantite d'un livre
                    char titre_de_livres[100];
                    printf("Entre le livre que vous cherchez:\n");
                    scanf("%s", titre_de_livres);
                    int trouver = 0;
                    for (int i = 0; i < livres_ajoutes; i++) {
                        if (strcmp(titre[i], titre_de_livres) == 0) {
                            printf("Entrez la nouvelle quantite:\n");
                            scanf("%d", &quantite[i]);
                            printf("La quantite a ete mise a jour\n");
                            trouver = 1;
                            break;
                        }
                    }
                    if (!trouver) {
                        printf("Le livre renseigne ne se trouve pas dans nos stocks:\n");
                        break;
                    }
                 break;
            case 4:
                    //Supprimer un livre du stock
                    char titre_a_supprimer[100];
                    printf("Quel titre souhaitez-vous supprimer?\n");
                    scanf("%s", titre_a_supprimer);
                    int Trouve = 0;
                    for (int i = 0; i < livres_ajoutes; i++) {
                        if (strcmp(titre[i], titre_a_supprimer) == 0) {
                            for (int j = i; j < livres_ajoutes - 1; j++) {
                                strcpy(titre[j], titre[j + 1]);
                                strcpy(auteur[j], auteur[j + 1]);
                                prix[j] = prix[j + 1];
                                quantite[j] = quantite[j + 1];
                            }
                            livres_ajoutes--;
                            printf("Le livre a ete supprime avec succes.\n");
                            Trouve = 1;
                            break;
                        }
                    }
                    if (!Trouve) {
                        printf("Le livre renseigné ne se trouve pas dans nos stocks.\n");
                    }
                 break;
                        case 5: {
                            if (livres_ajoutes == 0) {
                                printf("Aucun livre n'est disponible en stock.\n");
                            } else if (livres_ajoutes > 0){
                                printf("Il y a %d livres.\n",livres_ajoutes);
                            }
                            break;
                        }





                }


        }
    }while (choix != 0);
    printf("Il y a %d livres.",livres_ajoutes);
    return 0;
}
