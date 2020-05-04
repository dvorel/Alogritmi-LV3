#include <stdio.h>
#include <time.h>

#define N 30

#define MAXS 2000
long stog1[MAXS];
long stog2[MAXS];
int sp1 = 0, sp2 = 0;
int t1 = 0, t2 = 0;
long izracun = 0;

struct Stog {
    long data;
    struct Stog* next;
};

void pushn(long broj) {
    stog1[sp1] = broj;
    sp1++;
}

void pushm(long broj) {
    stog2[sp2] = broj;
    sp2++;
}

long popn() {
    if (sp1 >= 1) {
        sp1--;
        return stog1[sp1];
    }
    else {
        return NULL;
    }
}

long popm() {
    if (sp2 >= 1) {
        sp2--;
        return stog2[sp2];
    }
    else {
        return NULL;
    }
}

long povrh(long n, long m) {
    if (n == 1 || n == m || m == 0) {
        return 1;
    }
    else {
        return povrh(n - 1, m - 1) + povrh(n-1, m);
    }
}

long povrhs(long n, long m) {
    pushn(n);
    pushm(m);

    long povrh = 0;

    while (sp1 != 0) {
        n = popn();
        m = popm();

        if (n == m || m == 0) {
            povrh++;
        }
        else {
            pushn(n - 1);
            pushm(m - 1);
            pushn(n - 1);
            pushm(m);
        }
    }
    return povrh;
}
void pushP(long data, ) {


}

long povrhPovezana(long n, long m) {
    
    struct Stog* prviN = NULL;
    prviN = (struct Stog*)malloc(sizeof(struct Stog));
    struct Stog* prviM = NULL;
    prviM = (struct Stog*)malloc(sizeof(struct Stog));

    pushn(n);
    pushm(m);

    long povrh = 0;

    while (sp1 != 0) {
        n = popn();
        m = popm();

        if (n == m || m == 0) {
            povrh++;
        }
        else {
            pushn(n - 1);
            pushm(m - 1);
            pushn(n - 1);
            pushm(m);
        }
    }
    return povrh;
}



int main() {
    long n = N;
    long m = N / 2;
    /*Rekurzivno*/
    t1 = clock();
    izracun = povrh(n, m);
    t2 = clock();
    printf("Povrh %d | %d = %d\n", n, m, izracun);
    printf("Rekurzivno = %dms\n", t2 - t1);
    /*Obican stog*/
    t1 = clock();
    izracun = povrhs(n, m);
    t2 = clock();
    printf("PovrhS %d | %d = %d\n", n, m, izracun);
    printf("Stog = %dms\n", t2 - t1);
    /*Povezana lista*/
    /*alokacija prvog elementa*/

    /*-----------------------*/


    t1 = clock();
    izracun = povrh(n, m);
    t2 = clock();
    printf("PovrhP %d | %d = %d\n", n, m, izracun);
    printf("Povezana = %dms\n", t2 - t1);
    
    return 0;
}
