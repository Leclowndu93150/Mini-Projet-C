#include <stdio.h>
#include <string.h>
#include "Entête.h"

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