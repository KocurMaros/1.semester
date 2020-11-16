// Kocur Maros, 111119, cvicenie 9
#include<stdio.h>
int **create(int riadky, int stlpce){
    int **p, i;
    p = (int **) malloc(riadky * sizeof(int *));
    for(i = 0; i < riadky; i++)
        p[i] = (int *) malloc(stlpce * sizeof(int));
    return p;
}
void uvolni(int **pole,int riadky,int stlpce){
    for(int i=0;i<riadky;i++)
        free(pole[i]);
    free(pole);
    pole = NULL;
}
int SumTab(int **pole, int riadky, int stlpce){
    int sucet = 0;
    for(int i=0;i<riadky;i++)
        for(int j=0;j<stlpce;j++)
            if(pole[i][j]>0)
                sucet+=pole[i][j];
    return sucet;
}
int **nacitaj(int *riadky,int *stlpce){
    int **pole;
    int x,y;
    FILE *fr;
    if((fr=fopen("vstup.txt", "r"))!=NULL){
        fscanf(fr,"%d %d",&x,&y);
        *riadky=x;
        *stlpce=y;
        pole = create(x,y);
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                fscanf(fr, "%d", *(pole+i)+j);
    }
    fclose(fr);
    return pole;
}
int main(){
    int **pole;
    int a,b;
    pole = nacitaj(&a,&b);
    printf("sucer kladnych prvkov je: %d",SumTab(pole,a,b));
    uvolni(pole,a,b);
    return 0;
}
