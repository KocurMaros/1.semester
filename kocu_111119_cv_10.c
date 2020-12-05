/*
Maros Kocr, 111119, cv. 10
*/
#include<stdio.h>

typedef struct clovek {
     char meno[30];
     int rocnik;
     struct clovek *next;
} CLOVEK;

CLOVEK *nacitajPole(int *pocet){
    int i,j;
    char c;
    CLOVEK *meno;
    FILE *fr;
    if((fr=fopen("vstup.txt", "r"))!=NULL){
        fscanf(fr,"%d ", pocet);
        meno=(CLOVEK*)malloc(*pocet*sizeof(CLOVEK));
        for(i=0; i<*pocet; i++){
            j=0;
            while((c=fgetc(fr))!='\n'){
                meno[i].meno[j]=c;
                j++;
            }
            meno[i].meno[j]='\0';
            fscanf(fr,"%d", &meno[i].rocnik);
            c=fgetc(fr);
        }
        fclose(fr);
        return meno;
        printf("\n");
    }
}

CLOVEK *nacitajSpajany(){
    int a,n,i,j;
    CLOVEK *meno,*ziak;
    FILE *fr;
    if((fr=fopen("vstup.txt", "r"))!=NULL){
        fscanf(fr, "%d ", &n);
        meno=(CLOVEK*)malloc(sizeof(CLOVEK));
        j=0;
        while((a=fgetc(fr))!='\n'){
            meno->meno[j]=a;
            j++;
        }
        meno->meno[j]='\0';
        fscanf(fr,"%d ", &meno->rocnik);
        ziak=meno;
        for(i=1; i<n; i++){
            ziak->next=(CLOVEK*)malloc(sizeof(CLOVEK));
            ziak=ziak->next;
            j=0;
            while((a=fgetc(fr))!='\n'){
                ziak->meno[j]=a;
                j++;
            }
            ziak->meno[j]='\0';
            fscanf(fr,"%d ", &ziak->rocnik);
        }
        fclose(fr);
        ziak->next=NULL;
        return meno;
    }
}
void vypisPole(CLOVEK*p, int velkost){
    int i;
    printf("Pole\n");
    for(i=0; i<velkost; i++){
        printf("Meno: %s Rocnik: %d\n", p[i].meno, p[i].rocnik);
    }
    printf("\n");
}

void vypisSpajany(CLOVEK*s){
    CLOVEK *ziak=s;
    printf("Spajany zoznam\n");
    while(ziak!=NULL){
        printf("Meno: %s, Rocnik: %d\n", ziak->meno, ziak->rocnik);
        ziak=ziak->next;
    }
}
void uvolniPole(CLOVEK*pole){
    free(pole);
}

void uvolniSpajany(CLOVEK*prvy){
    CLOVEK *ziak=prvy,*dalsi;
    while(ziak!=NULL){
        dalsi=ziak->next;
        free((void*)ziak);
        ziak=dalsi;
    }
}

int main() {
    CLOVEK *pole, *spajany;
    int pocet;
    pole = nacitajPole(&pocet);
    vypisPole(pole, pocet);
    spajany = nacitajSpajany();
    vypisSpajany(spajany);
    uvolniPole(pole);
    uvolniSpajany(pole);
}
