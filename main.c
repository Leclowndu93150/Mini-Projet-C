#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Entête.h"

int main(void){
    char ip[32];

    do {
        printf("Entrez l'adresse IP à analyser: ");
        if (scanf("%31s", ip) != 1) {
            return 1;
        }
        if (!verification(ip)) {
            printf("L'adresse IP n'est pas au bon format.\n");
        } else {
            break;
        }
    } while (1);

    struct addresseIP addresse = extraire(ip);
    struct addresseIPNum ipNum = convertions(addresse);
    char classe = trouveClasse(ipNum);
    bool privee = estPrivee(ipNum);
    struct addresseIPNum r = calculeR(ipNum);
    int h = calculeH(ipNum);
    affichage(classe,privee,ipNum,r,h);
    ecritureFichier(classe,privee,ipNum,r,h);
    return 0;
}