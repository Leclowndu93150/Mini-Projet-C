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
*  Nom du fichier : Entête.h                                                  *
*                                                                             *
******************************************************************************/


#include <stdio.h>
#include <string.h>


//structure du format de l'addressse source : "xxx.xxx.xxx.xxx/xx"

struct addresseIP {
    unsigned char octets[4];
    unsigned char masque;
};

struct addresseIPNum {
    int unNum;
    int deuxNum;
    int troisNum;
    int quatreNum;
    int masqueNum;
};

bool verification(char ip[]); //renvoi True = si l'addresse à le bon format

struct addresseIP extraire(char input[]); //renvoie les char sous forme de structure

struct addresseIPNum convertions(struct addresseIP ip); //renvoie une version numérique de l'addresse IP

char trouveClasse(struct addresseIPNum ip); //renvoi la classe de l'addresse IP (A,B,C,D,E)

bool estPrivee(struct addresseIPNum ip); //renvoi True = si l'addresse est privée

struct addresseIPNum calculeR(struct addresseIPNum ip); //renvoie IP + masque sans "4"

int calculeH(struct addresseIPNum ip); //renvoie IP que le "4"

void affichage(char classe, bool privee, struct addresseIPNum ip, struct addresseIPNum r, int h); //affiche les résultats

void ecritureFichier(char classe, bool privee, struct addresseIPNum ip, struct addresseIPNum r, int h); //écrit les résultats dans un fichier