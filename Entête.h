#include <stdio.h>
#include <string.h>

struct addresseIP {
    char un[];
    char deux[];
    char trois[];
    char quatre[];
    char masque[];
}
struct addresseIPNum {
    int unNum;
    int deuxNum;
    int troisNum;
    int quatreNum;
    int masqueNum;
}

boolean verification(char ip[]); //renvoi True = si l'addresse à le bon format

addresseIP extraire(char input[],char format); //renvoie les char sous forme de structure

addresseIPNum convertions(addresseIP ip); //renvoie une version numérique de l'addresse IP

char trouveClasse(addresseIPNum ip); //renvoi la classe de l'addresse IP (A,B,C,D,E)

bool estPrivee(addresseIPNum ip); //renvoi True = si l'addresse est privée

addresseIPNum calculeR(addresseIPNum ip); //renvoie IP + masque sans "4"

addresseIPNum calculeH(addresseIPNum ip); //renvoie IP que le "4"

void affichage(char classe, bool privee, addresseIPNum ip, addresseIPNum r, addresseIPNum h); //affiche les résultats