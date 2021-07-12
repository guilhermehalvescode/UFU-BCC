#include <stdio.h>
#include <stdlib.h>
#include "FILA.h"



int main () {
    Fila fil;
    fil = criar();
    registro r1 = {"C language", "Gaspar", "C", 2002};
    registro r2 = {"Python language", "Cleber", "Python", 2007};
    registro r3 = {"Haskell language", "Felipe", "Haskell", 1985};
    registro r4 = {"Go language", "Google", "Go", 2012};
    registro r5 = {"Swift language", "Apple", "Swift", 2005};
    insereFila(&fil, r1);
    insereFila(&fil, r2);
    insereFila(&fil, r3);
    insereFila(&fil, r4);
    insereFila(&fil, r5);
    removeFila(&fil);
    return 0;
}