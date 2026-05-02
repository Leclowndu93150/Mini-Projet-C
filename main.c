#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Entête.h"
#include "source.c"

void main(){
    char ip[20];
    printf("Entrez l'adresse IP à analyser");
    scanf("%s", ip);
    if (verification(ip)){
        struct addresseIP addresse = extraire(ip);
        struct addresseIPNum ipNum = convertions(addresse);
        char classe = trouveClasse(ipNum);
        bool privee = estPrivee(ipNum);
        struct addresseIPNum r = calculeR(ipNum);
        struct addresseIPNum h = calculeH(ipNum);
        affichage(classe,privee,ipNum,r,h);
        ecritureFichier(classe,privee,ipNum,r,h);
    } else {
        printf("L'adresse IP n'est pas au bon format.");
        //retourne au début
        goto main;
    }
}