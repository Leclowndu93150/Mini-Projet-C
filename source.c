/******************************************************************************
*  ASR => partie R2.04 du S2.03                                               *
*******************************************************************************
*                                                                             *
*  N° du Sujet : 2                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé du sujet : Analyse d’adresses IP                                  *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Groupe-Nom-prénom1 : E-PATOUILLARD-Arno                                    *
*                                                                             *
*  Groupe-Nom-prénom2 : E-BEN ABDELGHAFAR-Abdelkerim                          *
*                                                                             *                                                                            *
*******************************************************************************
*                                                                             *
*  Nom du fichier : source.c                                                  *
*                                                                             *
******************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Entête.h"
#include <stdlib.h>

bool verification(char ip[]) {
    // la taille doit être entre 9 et 18 caractères
    int len = strlen(ip);
    if (len < 9 || len > 18) {
        return false;
    }
    // on compte le nombre de points
    int comptePoint = 0;
    for (int i = 0; i < len; i++) {
        if (ip[i] == '.') {
            comptePoint++;
        }
    }
    if (comptePoint != 3) {
        return false;
    }
    // on compte le nombre de /
    int compteSlash = 0;
    for (int i = 0; i < len; i++) {
        if (ip[i] == '/') {
            compteSlash++;
        }
    }
    if (compteSlash != 1) {
        return false;
    }
    return true;
}

struct addresseIP extraire(char input[]) {
    struct addresseIP addresse;

    char *slash = strchr(input, '/');
    addresse.masque = (unsigned char)atoi(slash + 1);

    char *tok = strtok(input, "./");
    int i = 0;
    while (tok != NULL && i < 4) {
        addresse.octets[i] = (unsigned char)atoi(tok);
        i++;
        tok = strtok(NULL, "./");
    }

    return addresse;
}

struct addresseIPNum calculeR(struct addresseIPNum ip){
    struct addresseIPNum addresse;
    addresse.unNum = ip.unNum;
    addresse.deuxNum = ip.deuxNum;
    addresse.troisNum = ip.troisNum;
    addresse.quatreNum = 0;
    addresse.masqueNum = ip.masqueNum;

    return addresse;
}

int calculeH(struct addresseIPNum ip){
    return ip.quatreNum;
}

struct addresseIPNum convertions(struct addresseIP ip){
    struct addresseIPNum ipNum;
    ipNum.unNum = ip.octets[0];
    ipNum.deuxNum = ip.octets[1];
    ipNum.troisNum = ip.octets[2];
    ipNum.quatreNum = ip.octets[3];
    ipNum.masqueNum = ip.masque;
    return ipNum;
}

char trouveClasse(struct addresseIPNum ip){
    int premierOctet = ip.unNum;
    if (premierOctet >= 0 && premierOctet <= 127) {
        return 'A';
    } else if (premierOctet >= 128 && premierOctet <= 191) {
        return 'B';
    } else if (premierOctet >= 192 && premierOctet <= 223) {
        return 'C';
    } else if (premierOctet >= 224 && premierOctet <= 239) {
        return 'D';
    } else {
        return 'E';
    }
}

bool estPrivee(struct addresseIPNum ip){
    if ((ip.unNum == 10) || (ip.unNum == 172 && ip.deuxNum >= 16 && ip.deuxNum <= 31) || (ip.unNum == 192 && ip.deuxNum == 168)) {
        return true;
    }
    return false;
}
    
void affichage(char classe, bool privee, struct addresseIPNum ip, struct addresseIPNum r, int h){
    printf("Classe : %c\n", classe);
    if (privee) {
        printf("L'adresse IP est privée.\n");
    } else {
        printf("L'adresse IP est publique.\n");
    }
    printf("Adresse IP : %d.%d.%d.%d/%d\n", ip.unNum, ip.deuxNum, ip.troisNum, ip.quatreNum, ip.masqueNum);
    printf("Adresse réseau : %d.%d.%d.%d/%d\n", r.unNum, r.deuxNum, r.troisNum, r.quatreNum, r.masqueNum);
    printf("Adresse hôte : 0.0.0.%d\n", h);
}

void ecritureFichier(char classe, bool privee, struct addresseIPNum ip, struct addresseIPNum r, int h){
    FILE *fichier = fopen("resultats.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return;
    }
    fprintf(fichier, "Classe : %c\n", classe);
    if (privee) {
        fprintf(fichier, "L'adresse IP est privée.\n");
    } else {
        fprintf(fichier, "L'adresse IP est publique.\n");
    }
    fprintf(fichier, "Adresse IP : %d.%d.%d.%d/%d\n", ip.unNum, ip.deuxNum, ip.troisNum, ip.quatreNum, ip.masqueNum);
    fprintf(fichier, "Adresse réseau : %d.%d.%d.%d/%d\n", r.unNum, r.deuxNum, r.troisNum, r.quatreNum, r.masqueNum);
    fprintf(fichier, "Adresse hôte : 0.0.0.%d\n", h);
    fclose(fichier);
}