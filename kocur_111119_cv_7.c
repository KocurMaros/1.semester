/*
MAROS KOCUR, 111119, cv.7
*/
#include<stdio.h>
#include<string.h>
char Nahrady(char n[]){
    int length = strlen(n);
    for(int i=0;i<length;i++){
        if(n[i]=='*'){
            for(int j=i;j<length;j++)
                n[j]=n[j+1];
            i--;
        }
        if(n[i]=='.'){
            for(int j=length;j>i;j--)
                n[j+2]=n[j];
            for(int j=i;j<i+3;j++)
                n[j]='$';
        }
        length= strlen(n);
    }
}
int Vymen(char *s1,char *s2){
    int k,ch=0;
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    char temp;
    if(length1!=length2)
        if(length1>length2)
            k = length2;
        else
            k = length1;
    else
        k = length1;
    for(int i = 0;i<k;i++){
        if(s1[i]!=s2[i]){
            temp = s1[i];
            s1[i] = s2[i];
            s2[i] = temp;
            ch++;
        }
    }
    return ch;
}
char volitelny_pr3(char *s1,char *s2){
    int c,d;
    int j=0;
    for(int i=0;i<strlen(s1);i++){
        c=s1[i];
        d=s2[j++]-64;
        if(c+d>90)
            c=65+(c+d-91);
        else
            c+=d;
        s1[i]=c;
        if(j==strlen(s2))
            j=0;
    }
}
char encoder(char *s1,char *s2){
    int c,d;
    int j=0;
    for(int i=0;i<strlen(s1);i++){
        c=s1[i];
        d=s2[j++]-64;
        if(c-d<65)
            c=64+d;
        else
            c-=d;
        s1[i]=c;
        if(j==strlen(s2))
            j=0;
    }
}
void volitelny_pr4(){
    char c,s1[100],s2[100];
    int l=0;
    FILE *fr, *fw;
    fr = fopen("vstup.txt","r");
    fw = fopen("vystup.txt","w");
    if(fr!=NULL)
        while(!feof(fr))
            if(fgets(s1, 100, fr))
    printf("zadaj kod na sifrovanie: ");
    scanf("%s",s2);
    volitelny_pr3(s1,s2);
    fputs(s1,fw);
    fclose(fr);
    fclose(fw);
}
int main() {
     char n[500], s1[100], s2[100];
     int p;
     printf("zadanie 1: retazec pre funkciu nahrady:");
     scanf("%s", n);
     Nahrady(n);
     printf("vysledok zadania 1: %s\n", n);

     printf("zadanie 2\n");
     printf("prvy retazec:"); scanf("%s", s1);
     printf("druhy retazec:"); scanf("%s", s2);
     p = Vymen(s1,s2);
     printf("vysledok zadania 2:\n");
     printf("pocet vymen: %d\n", p);
     printf("prvy retazec: %s\n", s1);
     printf("druhy retazec: %s\n", s2);

     printf("zadanie 3\n");
     printf("zadaj spravu:"); scanf("%s",s1);
     printf("zadaj kod:"); scanf("%s",s2);
     volitelny_pr3(s1,s2);
     printf("%s\n",s1);

     printf("zadanie 4\n");
     volitelny_pr4();

     printf("zadanie 5\n");
     printf("zadaj zakodovanu spravu:"); scanf("%s",s1);
     printf("zadaj kod:"); scanf("%s",s2);
     encoder(s1,s2);
     printf("%s\n",s1);

}
