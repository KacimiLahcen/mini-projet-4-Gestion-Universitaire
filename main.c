#include <stdio.h>

    struct Etudiant
    {
        int id;
        char nom[100];
        char prenom[100];
        int age;
        float moyenne;
    };

    struct Cours
    {
        int code;
        char nom[100];
        int credit;
        float note;
    };

    int AjouterEtudiant(struct Etudiant et[], int nouveauetudiant) {
        printf("Entrez le id d'etudiant : ");
        scanf("%d", &et[nouveauetudiant].id);

        printf("Entrez le nom d'etudiant : ");
        scanf("%s", et[nouveauetudiant].nom);

        printf("Entrez le prenom d'etudiant : ");
        scanf("%s", et[nouveauetudiant].prenom);

        printf("Entrez l'age d'etudiant : ");
        scanf("%d", &et[nouveauetudiant].age);

        printf("Entrez la moyenne d'etudiant : ");
        scanf("%f", &et[nouveauetudiant].moyenne);

        printf("Le nouvel etudiant est ajoute!\n");

        return ++nouveauetudiant;
    }

    int Ajoutercours(struct Cours cr[], int nouveauCour) {
        printf("Entrez le code du cours : ");
        scanf("%d", &cr[nouveauCour].code);

        printf("Entrez le nom du cours : ");
        scanf("%s", cr[nouveauCour].nom);

        printf("Entrez le credit du cours : ");
        scanf("%d", &cr[nouveauCour].credit);

        printf("Entrez la note du cours : ");
        scanf("%f", &cr[nouveauCour].note);

        printf("Le nouveau cours est ajoute!\n");

        return ++nouveauCour;
    }

    void AfficheEtudiants(struct Etudiant et[], int nombreEtudiants) { 
        
        printf("\n--- Liste des etudiants ---\n");
        if (nombreEtudiants == 0)
        {
            printf("Aucun etudiant enregistre.\n");
            return;
        }
        for (int i = 0; i < nombreEtudiants; i++)
        {
            printf("%d. ID : %d | Nom : %s | Prenom : %s | Age : %d | Moyenne : %.2f\n",
                i + 1, et[i].id, et[i].nom, et[i].prenom, et[i].age, et[i].moyenne);
        }
    }

    void AfficheCours(struct Cours cr[], int nombreCours)
    {                                                                                  
        printf("\n____||  La liste des cours  ||___\n");
        if (nombreCours == 0)
        {
            printf(" Aucun cours enregistre.\n");
            return;
        }
        for (int i = 0; i < nombreCours; i++)
        {
            printf("%d. Code : %d | Nom : %s | Credit : %d | Note : %.2f\n",
                i + 1, cr[i].code, cr[i].nom, cr[i].credit, cr[i].note);
        }
    }
    void RechercherEtudiant(struct Etudiant et[], int nombreEtudiants, int idRecherche)
    {                                                                                     
        for (int i = 0; i < nombreEtudiants; i++)
        {
            if (et[i].id == idRecherche)
            {
                printf("\n Etudiant trouvee :\n");
                printf("ID : %d | Nom : %s | Prenom : %s | Age : %d | Moyenne : %.2f\n",
                    et[i].id, et[i].nom, et[i].prenom, et[i].age, et[i].moyenne);
                return;
            }
        }
        printf("Aucun etudiant trouve avec l'ID %d.\n", idRecherche);
    }
    void ModifierNoteCours(struct Cours cr[], int nombreCours, int codeRecherche) {
        for (int i = 0; i < nombreCours; i++)
        {
            if (cr[i].code == codeRecherche)
            {
                printf("Cours trouve : %s (Code: %d)\n", cr[i].nom, cr[i].code);
                printf("Note actuelle : %.2f\n", cr[i].note);

                printf("Entrez la nouvelle note : ");
                scanf("%f", &cr[i].note);

                printf("La note du cours a ete modifiee avec succes!\n");
                return;
            }
        }
        printf("Aucun cours trouve avec le code %d.\n", codeRecherche);
    }



int main()
{
    struct Etudiant etudiants[100];
    struct Cours cours[100];

    int nombreetudiant = 0;
    int nombrecours = 0;
    int choix;
    int id;
    int code;

    do
    {
        printf("\n____||  Guide du programme  ||___\n");
        printf("--->  Cliquez '1' pour ajouter un etudiant\n");
        printf("--->  Cliquez '2' pour ajouter un cours\n");
        printf("--->  Cliquez '3' pour afficher la liste d'etudiants\n");
        printf("--->  Cliquez '4' pour afficher la liste des cours\n");
        printf("--->  Cliquez '5' pour recherche d'un etudiant\n");
        printf("--->  Cliquez '6' pour modifier la note d'un cours existant\n");
        printf("--->  Cliquez '0' pour quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            nombreetudiant = AjouterEtudiant(etudiants, nombreetudiant);
            break;
        case 2:
            nombrecours = Ajoutercours(cours, nombrecours);
            break;
        case 3:
            AfficheEtudiants(etudiants, nombreetudiant);
            break;
        case 4:
            AfficheCours(cours, nombrecours);
            break;
        case 5:
            printf("Entrez l'ID de l'etudiant a rechercher : ");
            scanf("%d", &id);
            RechercherEtudiant(etudiants, nombreetudiant, id);
            break;
        case 6:
            printf("Entrez le code du cours a modifier : ");
            scanf("%d", &code);
            ModifierNoteCours(cours, nombrecours, code);
            break;
        case 0:
            printf("Fin du programme.\n");
            break;
        default:
            printf("Votre choix invalide.\n");
            break;
        }
    } while (choix != 0);

    return 0;
}