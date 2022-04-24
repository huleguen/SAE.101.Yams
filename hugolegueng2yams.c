/**
*
* \brief Programme permettant de jouer au Yams.
*
* \author LE GUEN Hugo G2
*
* \version 1.0
*
* \date 28 novembre 2021
*
* Ce programme propose de jouer au Yams à deux,
* utilisant la génération de dés possédant des valeurs aléatoires comprises entre 1 et 6,
* et affichant une feuille de jeu répertoriant les points.
*
*/

/**
*
* \def N
*
* \brief constante pour la Taille Max d'un tableau comprenant les dés.
*
*/

/**
*
* \def 
*
* \brief constante pour la Taille Max d'un tableau des scores.
*
*/

/**
*
* \typedef tabdes
*
* \brief type tableau de N caractères
*
* Le type typTab sert de stockage pour stocker
* les valeurs (entiers) des dés.
*
*/

/**
*
* \typedef tabscore
*
* \brief type tableau de M caractères
*
* Le type typTab sert de stockage stocker
* les valeurs (entiers) de la feuille de jeu.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 5 
#define M 14
typedef int tabdes[N];
typedef char tabscore[M];

/************************
 * CONSTANTES UTILISEES *
 ************************/

const int NTOURS=13;
const int NRELANCE=3;
const int MINIMUMBONUS=62;
const int BONUS=35;
const int FULLHOUSE=25;
const int PETITESUITE=30;
const int GRANDESUITE=40;
const int YAMS=50;

/***************************************
 * FONCTIONS UTILITAIRES ET PROCEDURES *
 ***************************************/

/**
*
* \fn void remiseAzero(tabscore scoresj1, tabscore scoresj2)
*
* \brief Procédure qui remet à zero la feuille du jeu en début de partie.
*
* \param scorej1 : un tableau de score à reinitialiser.
*
* \param scorej2 : un tableau de score à reinitialiser.
*
* Consiste à remettre à zéro les scores
*
*/
void remiseAZero(tabscore scoresj1, tabscore scoresj2){

    int i;
    for ( i = 0; i < M; i++)
    {
        scoresj1[i]=0;
        scoresj2[i]=0;
    }
    
}

/**
*
* \fn void afficheFeuille(char j1[9], char j2[9], tabscore scoresj1, tabscore scoresj2)
*
* \brief Procédure qui affiche la feuille du jeu avec les scores.
*
* \param j1[9] : un tableau de score du joueur 2.
*
* \param j2[9] : un tableau de score du joueur 2.
*
* \param scorej1 : un tableau de score du joueur 1.
*
* \param scorej2 : un tableau de score du joueur 2.
*
* Consiste à afficher la feuille du jeu avec les noms des joueurs et leurs scores.
*
*/
void afficheFeuille(char j1[9], char j2[9], tabscore scoresj1, tabscore scoresj2){
    
    int totsupj1, totsupj2, totinfj1, totinfj2, bonusj1, bonusj2;
    bonusj1=0;
    bonusj2=0;
    totsupj1=scoresj1[0]+scoresj1[1]+scoresj1[2]+scoresj1[3]+scoresj1[4]+scoresj1[5]+bonusj1;
    totsupj2=scoresj2[0]+scoresj2[1]+scoresj2[2]+scoresj2[3]+scoresj2[4]+scoresj2[5]+bonusj2;
    if (totsupj1>MINIMUMBONUS){
        bonusj1=35;
    }
    if (totsupj2>MINIMUMBONUS){
        bonusj2=35;
    }
    totsupj1=scoresj1[0]+scoresj1[1]+scoresj1[2]+scoresj1[3]+scoresj1[4]+scoresj1[5]+bonusj1;
    totsupj2=scoresj2[0]+scoresj2[1]+scoresj2[2]+scoresj2[3]+scoresj2[4]+scoresj2[5]+bonusj2;
    totinfj1=scoresj1[6]+scoresj1[7]+scoresj1[8]+scoresj1[9]+scoresj1[10]+scoresj1[11]+scoresj1[12];
    totinfj2=scoresj2[6]+scoresj2[7]+scoresj2[8]+scoresj2[9]+scoresj2[10]+scoresj2[11]+scoresj2[12];
    scoresj1[13]=totsupj1+totinfj1;
    scoresj2[13]=totsupj2+totinfj2;
    printf("  _______________________________________\n");
    printf("  |                 |%9s|%9s|\n", j1 , j2 );
    printf("1 |1 [total de 1]   |%9d|%9d|\n", scoresj1[0], scoresj2[0]);
    printf("2 |2 [total de 2]   |%9d|%9d|\n", scoresj1[1], scoresj2[1]);
    printf("3 |3 [total de 3]   |%9d|%9d|\n", scoresj1[2], scoresj2[2]);
    printf("4 |4 [total de 4]   |%9d|%9d|\n", scoresj1[3], scoresj2[3]);
    printf("5 |5 [total de 5]   |%9d|%9d|\n", scoresj1[4], scoresj2[4]);
    printf("6 |6 [total de 6]   |%9d|%9d|\n", scoresj1[5], scoresj2[5]);
    printf("  |Bonus si>62 [35] |%9d|%9d|\n", bonusj1, bonusj2);
    printf("  |Total supérieur  |%9d|%9d|\n", totsupj1, totsupj2);
    printf("  |                 |         |         |\n");
    printf("7 |Brelan [total]   |%9d|%9d|\n", scoresj1[6], scoresj2[6]);
    printf("8 |Carré [total]    |%9d|%9d|\n", scoresj1[7], scoresj2[7]);
    printf("9 |Full House [25]  |%9d|%9d|\n", scoresj1[8], scoresj2[8]);
    printf("10|Petite Suite [30]|%9d|%9d|\n", scoresj1[9], scoresj2[9]);
    printf("11|Grande suite [40]|%9d|%9d|\n", scoresj1[10], scoresj2[10]);
    printf("12|Yams [50]        |%9d|%9d|\n", scoresj1[11], scoresj2[11]);
    printf("13|Chance [total]   |%9d|%9d|\n", scoresj1[12], scoresj2[12]);
    printf("  |Total inférieur  |%9d|%9d|\n", totinfj1, totinfj2);
    printf("  |                 |         |         |\n");
    printf("  |Total            |%9d|%9d|\n", scoresj1[13], scoresj2[13]);
    printf("  |_________________|_________|_________|\n");

}

/**
*
* \fn int lancer(tabdes numDes)
*
* \brief Procédure lance les dés.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* Consiste à les dés et à leur affecter une valeur entre 1 et 6.
*
*/
int lancer(tabdes numDes){ 

    int n, i;
    n=5;
    srand(time(NULL));
    for ( i = 0; i < n; i++)
    {   
        numDes[i]=(rand()%6)+1;
    }
    return 0;

}

/**
*
* \fn echange(tabdes numDes, int i, int j)
*
* \brief Procédure qui permet d'échanger deux valeurs.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \param i : entier permettant d'incrémenter dans la procédure trisel.
*
* \param j : entier permettant d'incrémenter dans la procédure trisel.
*
* Consiste à échanger deux valeurs données en paramètres.
*
*/
void echange(tabdes numDes, int i, int j){
    int tmp;
    tmp=numDes[i];
    numDes[i]=numDes[j];
    numDes[j]=tmp;
}

/**
*
* \fn void trisel(tabdes numDes
*
* \brief Fonction qui permet de trier les dés.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* Consiste à trier les  5 dés par ordre croissant.
*
*/
void trisel(tabdes numDes){
    int i,j,min,indmin;
    for(i=0;i<N-1;i++){
        min=numDes[i];
        indmin=i;
        for(j=i+1;j<N;j++){
            if (numDes[j]<min){
                min=numDes[j];
                indmin=j;
            }
        }
        echange(numDes,i,indmin);
    }
}

/**
*
* \fn int afficherDes(tabdes numDes)
*
* \brief Fonction qui permet d'afficher les dés.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* Consiste à afficher les 5 dés.
*
*/
int afficherDes(tabdes numDes){
    
    trisel(numDes);
    int i;
    for ( i = 0; i < N; i++)
    {
        printf("\nDé %d: %d\n", i+1, numDes[i]);
    }
    return 0;
}    

/**
*
* \fn choixDes(tabdes numDes)
*
* \brief Fonction qui permet de choisir les dés à garder et qui relance ceux qui ne sont pas choisis.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return le tableau des dés triés.
*
* Consiste à choisir les dés à garder et relance ceux qui ne sont pas choisis, puis les trient, et les affichent.
*
*/
int choixDes(tabdes numDes){
    
    int i, n;
    for ( i =0; i < 5; i++){
        n=-1;
        while ((n!=0)&&(n!=1)){
            printf("\nVoulez vos relancer le dé %d, si oui appuyer sur 1 sinon appuyer sur 0\n", i+1);
            scanf("%d", &n);  
        }
        if (n==0)
        {
            printf("Pas de relance pour le dé %d\n", i+1);
        }
        else if (n==1)
        {
            printf("Relance du dé %d\n", i+1);
            numDes[i]=rand()%6+1;
        }
    }
    trisel(numDes);
    afficherDes(numDes);
    return (*numDes);
    
}

/**
*
* \fn int fTot1(tabdes numDes)
*
* \brief Fonction qui permet de détecter le nombre de 1 et qui renvoie l'addition de tous les 1 présents.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return l'addition de tous les 1 présents.
*
* Consiste à renvoyer l'addition de tous les 1 présents dans les dés et qui renvoie cette addition.
*
*/
int fTot1(tabdes numDes){
    
    int i, tot1;
    tot1=0;
    for ( i =0; i < 5; i++)
    {
        if (numDes[i]==1){
            tot1=tot1+1;
        }
    }
    return tot1;
}

/**
*
* \fn int fTot2(tabdes numDes)
*
* \brief Fonction qui permet de détecter le nombre de 2 et qui renvoie l'addition de tous les 2 présents.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return l'addition de tous les 2 présents.
*
* Consiste à renvoyer l'addition de tous les  2présents dans les dés et qui renvoie cette addition.
*
*/int fTot2(tabdes numDes){
    
    int i, tot2;
    tot2=0;
    for ( i =0; i < 5; i++)
    {
        if (numDes[i]==2){
            tot2=tot2+2;
        }
    }
    return tot2;
}

/**
*
* \fn int fTot3(tabdes numDes)
*
* \brief Fonction qui permet de détecter le nombre de 3 et qui renvoie l'addition de tous les 3 présents.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return l'addition de tous les 3 présents.
*
* Consiste à renvoyer l'addition de tous les 3 présents dans les dés et qui renvoie cette addition.
*
*/
int fTot3(tabdes numDes){
    
    int i, tot3;
    tot3=0;
    for ( i =0; i < 5; i++)
    {
        if (numDes[i]==3){
            tot3=tot3+3;
        }
    }
    return tot3;
}

/**
*
* \fn int fTot4(tabdes numDes)
*
* \brief Fonction qui permet de détecter le nombre de 4 et qui renvoie l'addition de tous les 4 présents.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return l'addition de tous les 4 présents.
*
* Consiste à renvoyer l'addition de tous les 4 présents dans les dés et qui renvoie cette addition.
*
*/
int fTot4(tabdes numDes){
    
    int i, tot4;
    tot4=0;
    for ( i =0; i < 5; i++)
    {
        if (numDes[i]==4){
            tot4=tot4+4;
        }
    }
    return tot4;
}

/**
*
* \fn int fTot5(tabdes numDes)
*
* \brief Fonction qui permet de détecter le nombre de 5 et qui renvoie l'addition de tous les 5 présents.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return l'addition de tous les 5 présents.
*
* Consiste à renvoyer l'addition de tous les 5 présents dans les dés et qui renvoie cette addition.
*
*/
int fTot5(tabdes numDes){
    
    int i, tot5;
    tot5=0;
    for ( i =0; i < 5; i++)
    {
        if (numDes[i]==5){
            tot5=tot5+5;
        }
    }
    return tot5;
}

/**
*
* \fn int fTot6(tabdes numDes)
*
* \brief Fonction qui permet de détecter le nombre de 6 et qui renvoie l'addition de tous les 6 présents.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return l'addition de tous les 6 présents.
*
* Consiste à renvoyer l'addition de tous les 6 présents dans les dés et qui renvoie cette addition.
*
*/
int fTot6(tabdes numDes){
    
    int i, tot6;
    tot6=0;
    for ( i =0; i < 5; i++)
    {
        if (numDes[i]==6){
            tot6=tot6+6;
        }
    }
    return tot6;
}

/**
*
* \fn int fBrelan(tabdes numDes)
*
* \brief Fonction qui permet de détecter s'il y a 3 dés de la même valeur et qui renvoie la somme de ces dés dans ce cas et 0 sinon.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return brelan
*
*/
int fBrelan(tabdes numDes){
    
    int brelan;
    brelan=0;
    if ((numDes[0]==numDes[1])&&(numDes[1]==numDes[2])){
       brelan=numDes[0]+numDes[1]+numDes[2];
    }
    else if ((numDes[1]==numDes[2])&&(numDes[2]==numDes[3])){
       brelan=numDes[1]+numDes[2]+numDes[3];
    }
    else if ((numDes[3]==numDes[4])&&(numDes[4]==numDes[5])){
       brelan=numDes[2]+numDes[3]+numDes[4];
    }
    return brelan;
}

/**
*
* \fn int fCarre(tabdes numDes)
*
* \brief Fonction qui permet de détecter s'il y a 4 dés de la même valeur et qui renvoie la somme de ces dés dans ce cas et 0 sinon.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return carre.
*
*/
int fCarre(tabdes numDes){
    
    int carre;
    carre=0;
    if ((numDes[0]==numDes[1])&&(numDes[1]==numDes[2])&&(numDes[2]==numDes[3])){
       carre=numDes[0]+numDes[1]+numDes[2]+numDes[3];
    }
    else if ((numDes[1]==numDes[2])&&(numDes[2]==numDes[3])&&(numDes[3]==numDes[4])){
       carre=numDes[1]+numDes[2]+numDes[3]+numDes[4];
    }
    return carre;
}

/**
*
* \fn int fFullHouse(tabdes numDes)
*
* \brief Fonction qui permet de détecter s'il y 3 dés de la même valeur et deux autres dés de la même valeur et qui renvoie 25 dans ce cas et 0 sinon.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return fullhouse.
*
*/
int fFullHouse(tabdes numDes){
    
    int fullhouse;
    fullhouse=0;
    if (((numDes[0]==numDes[1])&&(numDes[1]==numDes[2]))&&(numDes[3]==numDes[4])){
       fullhouse=FULLHOUSE;
    }
    else if ((numDes[0]==numDes[1])&&((numDes[2]==numDes[3])&&(numDes[3]==numDes[4]))){
        fullhouse=FULLHOUSE;
    }
    return fullhouse;
    
}

/**
*
* \fn int fPetiteSuite(tabdes numDes)
*
* \brief Fonction qui permet de détecter s'il y a une suite de 4 dés et qui renvoie 30 dans ce cas et 0 sinon.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return petitesuite.
*
*/
int fPetiteSuite(tabdes numDes){
    
    int petitesuite;
    petitesuite=0;
    if ((numDes[1]==numDes[0]+1)&&(numDes[2]==numDes[1]+1)&&(numDes[3]==numDes[2]+1)){
        petitesuite=PETITESUITE;
    }
    else if ((numDes[2]==numDes[1]+1)&&(numDes[3]==numDes[2]+1)&&(numDes[4]==numDes[3]+1)){
        petitesuite=PETITESUITE;
    }
    else if ((numDes[1]==numDes[0]+1)&&(numDes[2]==numDes[1])&&(numDes[3]==numDes[2]+1)&&(numDes[4]==numDes[3]+1)){
        petitesuite=PETITESUITE;    
    }
    else if ((numDes[1]==numDes[0]+1)&&(numDes[2]==numDes[1]+1)&&(numDes[3]==numDes[2])&&(numDes[4]==numDes[3]+1)){
        petitesuite=PETITESUITE;    
    }
    return petitesuite;
}

/**
*
* \fn int fGrandSuite(tabdes numDes)
*
* \brief Fonction qui permet de détecter s'il y a une suite de 5 dés et qui renvoie 40 dans ce cas et 0 sinon.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return grandesuite.
*
*/
int fGrandeSuite(tabdes numDes){
    
    int grandesuite;
    grandesuite=0;
    if ((numDes[1]==numDes[0]+1)&&(numDes[2]==numDes[1]+1)&&(numDes[3]==numDes[2]+1)&&(numDes[4]==numDes[3]+1)){
        grandesuite=GRANDESUITE;
    }
    return grandesuite;
}

/**
*
* \fn int fYams(tabdes numDes)
*
* \brief Fonction qui permet de détecter si un yams est possible et qui renvoie 50 dans ce cas et 0 sinon.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return yams.
*
*/
int fYams(tabdes numDes){
    
    int yams;
    if ((numDes[0]==numDes[1])&&(numDes[1]==numDes[2])&&(numDes[2]==numDes[3])&&(numDes[3]==numDes[4]))
    {
        yams=YAMS;
    }
    else
    {
        yams=0;
    }
    return yams;
}

/**
*
* \fn int fChance(tabdes numDes)
*
* \brief Fonction qui permet d'additionner les dés et qui renvoie l'addition.
*
* \param numDes : un tableau où sont placés les valeurs des dés.
*
* \return chance.
*
*/
int fChance(tabdes numDes){
    
    int i, chance;
    chance=0;
    for ( i =0; i < 5; i++)
    {
        chance=chance+numDes[i];
    }
    return chance;
}

/**
*
* \fn void choixCase(tabscore scores, int tot1, int tot2, int tot3, int tot4, int tot5, int tot6, int brelan, int carre, int fullhouse, int petitesuite, int grandesuite, int yams, int chance, int *choixtot1, int *choixtot2, int *choixtot3, int *choixtot4, int *choixtot5, int *choixtot6, int *choixbrelan, int *choixcarre, int *choixfullhouse, int *choixpetitesuite, int *choixgrandesuite, int *choixyams, int *choixchance)
*
* \brief Procédure qui permet de choisir la case à remplir dans la feuille du jeu.
*
* \param scores : un tableau de score du joueur.
*
* \param tot1 : addition des 1 présents dans les dés.
*
* \param tot2 : addition des 2 présents dans les dés.
*
* \param tot3 : addition des 3 présents dans les dés.
*
* \param tot4 : addition des 4 présents dans les dés.
*
* \param tot5 : addition des 5 présents dans les dés.
*
* \param tot6 : addition des 6 présents dans les dés.
*
* \param brelan : addition de 3 dés qui ont la même valeur et 0 sinon.
*
* \param carre : addition de 4 dés qui ont la même valeur et 0 sinon.
*
* \param fullhouse : possède une valeur de 25 si les dés forment une paire et un brolan.
*
* \param petitesuite : possède une valeur de 30 si les dés forment une suite croissante de 4 dés.
*
* \param grandesuite : possède une valeur de 40 si les dés forment une suite croissante de 5 dés.
*
* \param yams : possède une valeur de 50 si les 5 dés ont la même valeur.
*
* \param chance : addition des 5 dés.
*
* \param choixtot1 : un entier qui possède 0 si la case Total de 1 n'a pas été affecté et 1 sinon.
*
* \param choixtot2 : un entier qui possède 0 si la case Total de 2 n'a pas été affecté et 1 sinon.
*
* \param choixtot3 : un entier qui possède 0 si la case Total de 3 n'a pas été affecté et 1 sinon.
*
* \param choixtot4 : un entier qui possède 0 si la case Total de 4 n'a pas été affecté et 1 sinon.
*
* \param choixtot5 : un entier qui possède 0 si la case Total de 5 n'a pas été affecté et 1 sinon.
*
* \param choixtot6 : un entier qui possède 0 si la case Total de 6 n'a pas été affecté et 1 sinon.
*
* \param choixbrelan : un entier qui possède 0 si la Brelan n'a pas été affecté et 1 sinon.
*
* \param choixcarre : un entier qui possède 0 si la Carré n'a pas été affecté et 1 sinon.
*
* \param choixfullhouse : un entier qui possède 0 si la case FullHouse n'a pas été affecté et 1 sinon.
*
* \param choixpetitesuite : un entier qui possède 0 si la case PetiteSuite n'a pas été affecté et 1 sinon.
*
* \param choixgrandesuite : un entier qui possède 0 si la case GrandeSuite n'a pas été affecté et 1 sinon.
*
* \param choixyams : un entier qui possède 0 si la case Yams n'a pas été affecté et 1 sinon.
*
* \param choixchance : un entier qui possède 0 si la case Chance n'a pas été affecté et 1 sinon.
*
*/
void choixCase(tabscore scores, int tot1, int tot2, int tot3, int tot4, int tot5, int tot6, int brelan, int carre, int fullhouse, int petitesuite, int grandesuite, int yams, int chance, int *choixtot1, int *choixtot2, int *choixtot3, int *choixtot4, int *choixtot5, int *choixtot6, int *choixbrelan, int *choixcarre, int *choixfullhouse, int *choixpetitesuite, int *choixgrandesuite, int *choixyams, int *choixchance){
    
    int j=0;
    while ((j<1)||(j>13))
    {
        printf("Quel case choisissez-vous ?\n");
        scanf("%d", &j);
    }
    switch (j)
    {
    case 1 :
    if (*choixtot1==0){
        scores[0]=tot1;
        *choixtot1=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 2 :
    if (*choixtot2==0){
        scores[1]=tot2;
        *choixtot2=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break; 

    case 3 :
    if (*choixtot3==0){
        scores[2]=tot3;
        *choixtot3=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 4 :
    if (*choixtot4==0){
        scores[3]=tot4;
        *choixtot4=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 5 :
    if (*choixtot5==0){
        scores[4]=tot5;
        *choixtot5=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 6 :
    if (*choixtot6==0){
        scores[5]=tot6;
        *choixtot6=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 7 :
    if (*choixbrelan==0){
        scores[6]=brelan;
        *choixbrelan=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 8 :
    if (*choixcarre==0){
        scores[7]=carre;
        *choixcarre=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break; 

    case 9 :
    if (*choixfullhouse==0){
        scores[8]=fullhouse;
        *choixfullhouse=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 10 :
    if (*choixpetitesuite==0){
        scores[9]=petitesuite;
        *choixpetitesuite=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 11 :
    if (*choixgrandesuite==0){
        scores[10]=grandesuite;
        *choixgrandesuite=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;

    case 12 :
    if (*choixyams==0){
        scores[11]=yams;
        *choixyams=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break;
        
    case 13 :
    if (*choixchance==0){
        scores[12]=chance;
        *choixchance=1;
    }
    else{
        printf("Case déjà prise, choisissez une autre case\n");
        choixCase(scores, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, choixtot1, choixtot2, choixtot3, choixtot4, choixtot5, choixtot6, choixbrelan, choixcarre, choixfullhouse, choixpetitesuite, choixgrandesuite, choixyams, choixchance);
    }
        break; 
    }
}

/***********************
 * PROGRAMME PRINCIPAL *
 ***********************/

/**
*
* \var numDes : un tableau où sont placés les valeurs des dés.
*
* \var scoresj1 : un tableau où sont placés les valeurs des scores de chaque tour pour le joueur 1.
*
* \var scoresj2 : un tableau où sont placés les valeurs des scores de chaque tour pour le joueur 2.
*
* \var j1 : nom du joueur 1.
* 
* \var j2 : nom du joueur 2.
*
* \var tot1 : addition des 1 présents dans les dés.
*
* \var tot2 : addition des 2 présents dans les dés.
*
* \var tot3 : addition des 3 présents dans les dés.
*
* \var tot4 : addition des 4 présents dans les dés.
*
* \var tot5 : addition des 5 présents dans les dés.
*
* \var tot6 : addition des 6 présents dans les dés.
*
* \var brelan : addition de 3 dés qui ont la même valeur et 0 sinon.
*
* \var carre : addition de 4 dés qui ont la même valeur et 0 sinon.
*
* \var fullhouse : possède une valeur de 25 si les dés forment une paire et un brolan.
*
* \var petitesuite : possède une valeur de 30 si les dés forment une suite croissante de 4 dés.
*
* \var grandesuite : possède une valeur de 40 si les dés forment une suite croissante de 5 dés.
*
* \var yams : possède une valeur de 50 si les 5 dés ont la même valeur.
*
* \var chance : addition des 5 dés.
*
* \var choixtot1j1 : un entier qui possède 0 si la case Total de 1 n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixtot2j1 : un entier qui possède 0 si la case Total de 2 n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixtot3j1 : un entier qui possède 0 si la case Total de 3 n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixtot4j1 : un entier qui possède 0 si la case Total de 4 n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixtot5j1 : un entier qui possède 0 si la case Total de 5 n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixtot6j1 : un entier qui possède 0 si la case Total de 6 n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixbrelanj1 : un entier qui possède 0 si la Brelan n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixcarrej1 : un entier qui possède 0 si la Carré n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixfullhousej1 : un entier qui possède 0 si la case FullHouse n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixpetitesuitej1 : un entier qui possède 0 si la case PetiteSuite n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixgrandesuitej1 : un entier qui possède 0 si la case GrandeSuite n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixyamsj1 : un entier qui possède 0 si la case Yams n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixchancej1 : un entier qui possède 0 si la case Chance n'a pas été affecté et 1 sinon pour le joueur 1.
*
* \var choixtot1j2 : un entier qui possède 0 si la case Total de 1 n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixtot2j2 : un entier qui possède 0 si la case Total de 2 n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixtot3j2 : un entier qui possède 0 si la case Total de 3 n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixtot4j2 : un entier qui possède 0 si la case Total de 4 n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixtot5j2 : un entier qui possède 0 si la case Total de 5 n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixtot6j2 : un entier qui possède 0 si la case Total de 6 n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixbrelanj2 : un entier qui possède 0 si la Brelan n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixcarrej2 : un entier qui possède 0 si la Carré n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixfullhousej2 : un entier qui possède 0 si la case FullHouse n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixpetitesuitej2 : un entier qui possède 0 si la case PetiteSuite n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixgrandesuitej2 : un entier qui possède 0 si la case GrandeSuite n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixyamsj2 : un entier qui possède 0 si la case Yams n'a pas été affecté et 1 sinon pour le joueur 2.
*
* \var choixchancej2 : un entier qui possède 0 si la case Chance n'a pas été affecté et 1 sinon pour le joueur 2.
*
*/
int main () {

    char rep;
    int i, j;
    int tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance;
    int choixtot1j1=0, choixtot2j1=0, choixtot3j1=0, choixtot4j1=0, choixtot5j1=0, choixtot6j1=0, choixbrelanj1=0, choixcarrej1=0, choixfullhousej1=0, choixpetitesuitej1=0, choixgrandesuitej1=0, choixyamsj1=0, choixchancej1=0;
    int choixtot1j2=0, choixtot2j2=0, choixtot3j2=0, choixtot4j2=0, choixtot5j2=0, choixtot6j2=0, choixbrelanj2=0, choixcarrej2=0, choixfullhousej2=0, choixpetitesuitej2=0, choixgrandesuitej2=0, choixyamsj2=0, choixchancej2=0;
    char j1[9], j2[9];
    tabdes numDes;
    tabscore scoresj1, scoresj2;
    remiseAZero(scoresj1, scoresj2);
    printf("Rentrer un  premier nom\n");
    scanf("%s", j1);
    while(strlen(j1)>8){
        printf("Rentrer un  premier nom\n");
        scanf("%s", j1);
    }
    printf("Rentrer un  deuxième nom\n");
    scanf("%s", j2);
    while(strlen(j2)>8){
        printf("Rentrer un  deuxième nom\n");
        scanf("%s", j2);
    }
    for ( i = 0; i < NTOURS; i++){
        printf("Tour numéro %d\n", i+1);
        printf("Tour de %s\n", j1);
        afficheFeuille(j1,j2,scoresj1,scoresj2);
        lancer(numDes);
        afficherDes(numDes);
        for ( j = 0; j < NRELANCE; j++){
            rep='A';
            while((rep!='O')&&(rep!='N')){
            printf("\nVoulez-vous relancer ? O/N\n");
            scanf("\n%c", &rep);
            }
            if (rep=='O'){
                choixDes(numDes);  
            }
            else{
                printf("Pas de relances\n");
            }
        }
        tot1=fTot1(numDes);
        tot2=fTot2(numDes);
        tot3=fTot3(numDes);
        tot4=fTot4(numDes);
        tot5=fTot5(numDes);
        tot6=fTot6(numDes);
        brelan=fBrelan(numDes);
        carre=fCarre(numDes);
        fullhouse=fFullHouse(numDes);
        petitesuite=fPetiteSuite(numDes);
        grandesuite=fGrandeSuite(numDes);
        yams=fYams(numDes);
        chance=fChance(numDes);
        afficheFeuille(j1,j2,scoresj1,scoresj2);
        choixCase(scoresj1, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, &choixtot1j1, &choixtot2j1, &choixtot3j1, &choixtot4j1, &choixtot5j1, &choixtot6j1, &choixbrelanj1, &choixcarrej1, &choixfullhousej1, &choixpetitesuitej1, &choixgrandesuitej1, &choixyamsj1, &choixchancej1);

        printf("Tour de %s\n", j2);
        afficheFeuille(j1,j2,scoresj1,scoresj2);
        lancer(numDes);
        afficherDes(numDes);
        for ( j = 0; j < NRELANCE; j++){
            rep='A';
            while((rep!='O')&&(rep!='N')){
            printf("\nVoulez-vous relancer ? O/N\n");
            scanf("\n%c", &rep);
            }
            if (rep=='O'){
                choixDes(numDes);  
            }
            else{
                printf("Pas de relances\n");
            }
        }
        tot1=fTot1(numDes);
        tot2=fTot2(numDes);
        tot3=fTot3(numDes);
        tot4=fTot4(numDes);
        tot5=fTot5(numDes);
        tot6=fTot6(numDes);
        brelan=fBrelan(numDes);
        carre=fCarre(numDes);
        fullhouse=fFullHouse(numDes);
        petitesuite=fPetiteSuite(numDes);
        grandesuite=fGrandeSuite(numDes);
        yams=fYams(numDes);
        chance=fChance(numDes);
        afficheFeuille(j1,j2,scoresj1,scoresj2);
        choixCase(scoresj2, tot1, tot2, tot3, tot4, tot5, tot6, brelan, carre, fullhouse, petitesuite, grandesuite, yams, chance, &choixtot1j2, &choixtot2j2, &choixtot3j2, &choixtot4j2, &choixtot5j2, &choixtot6j2, &choixbrelanj2, &choixcarrej2, &choixfullhousej2, &choixpetitesuitej2, &choixgrandesuitej2, &choixyamsj2, &choixchancej2);
    }
    if (scoresj1[13]>scoresj2[13]){
        printf("Le gagnant est %s", j1);
    }
    else if(scoresj1[13]<scoresj2[13]){
        printf("Le gagnant est %s", j2);
    }
    else if (scoresj1[13]==scoresj2[13]){
        printf("Egalité");
    }
    return EXIT_SUCCESS;
    
}