/*
Kocur Maors, 111119, cv.6
*/
#include<stdio.h>
void vypis(int cisla[],int dlzka){
    int j=0;
    for(int i=0;i<dlzka;i++){
        if(cisla[i]<0&&cisla[i]>-10)    printf("  %d",cisla[i]);
        else if(cisla[i]<=-10&&cisla[i]>-100)    printf(" %d",cisla[i]);
        else if(cisla[i]<=-100&&cisla[i]>-1000)    printf("%d",cisla[i]);
        else if(cisla[i]<=-1000)    printf("%d",cisla[i]);
        else if(cisla[i]<10) printf("   %d",cisla[i]);
        else if(cisla[i]<100)   printf("  %d",cisla[i]);
        else if(cisla[i]<1000)  printf(" %d",cisla[i]);
        else    printf("%d",cisla[i]);
        printf(" ");
        j++;
        if(j==10)
            printf("\n",j=1);
    }
}
int najdlhsie_opakovanie(char x[],int pocet,char *znak){
    printf("%c",x[2]);
    int sum=0,max=0;
    char c;
    for (int i = 0; x[i]; i++) {
        c = x[i];
        for (int v = 0; x[v]; v++)
            if (c == x[v]) sum++;
        if (sum > max) {
            max = sum;
            znak = c;
        }
        sum = 0;
}
return max,znak;
}
int main(){
    pr2();
    //volitelny_pr3();
    //volitelny_pr4();
    //volitelny_pr5();
    //volitelny_pr6();
    //volitelny_pr7();
    //volitelny_pr8();
    //volitelny_pr9();
}
int pr2(){
    int n,number,in[1000],mensie[1000],vacsie[1000];
    int i=0,g=0,h=0;
    printf("zadaj cele cislo: ");
    scanf("%d", &n);
    FILE *fr;
    fr = fopen("vstup.txt","r");
    if(fr!=NULL){
        while(!feof(fr)){
            fscanf(fr, "%d", &number);
            in[i]=number;
            i++;
        }
        printf("nacital som:\n");
        vypis(in,i);
    }
    else
        printf("Nepodarilo sa otvorit\n");
    for(int j=0;j<i;j++){
        if(in[j]<n){
            mensie[g]=in[j];
            g++;
        }
        else if(in[j]>n){
            vacsie[h]=in[j];
            h++;
        }
    }
    printf("\nmensie ako %d su:\n",n);
    vypis(mensie,g);
    printf("\nvacsie ako %d su:\n",n);
    vypis(vacsie,h);
    fclose(fr);
}
int volitelny_pr3(){
    int i=0;
    char a[20];
    printf("zadajte retazec(max 20 znakov): ");
    do{
        scanf("%c",&a[i]);
        i++;
    }while(a[i-1]!='\n');
    for(i=(20-(20-i));i>= 0;i--)
        printf("%c",a[i]);
    printf("\n");
}
int volitelny_pr4(){
    int j,i=0,c=10;
    char a[10];
    printf("zadajte retazec: ");
    do{
        scanf("%c",&a[i]);
        i++;
    }while(a[i-1]!='\n');
    for(j=0;j<c;j++){
        if(a[j]=='*'){
            printf("+%c-",a[j]);
            c-=2;}
        else
            printf("%c",a[j]);
    }
    if(j+1<i)
        printf(" text je skrateny");
    printf("\n");
}
int volitelny_pr5(){
    int i=0,j=0,h=0;
    char a[50],b[15];
    do{
        scanf("%c",&a[i]);
        i++;
    }while(a[i-1]!='\n');
    do{
        scanf("%c",&b[j]);
        j++;
    }while(b[j-1]!='\n');
    while(h<i){
        if(a[h]==b[0]&&a[h+1]==b[1]&&a[h+2]==b[2])
            for(int m=0;m<i-h;m++)
                a[h+m]=a[h+m+3];
    printf("%c",a[h]);
    h++;
    }
    printf("\n");
}
int volitelny_pr6(){
    int slovo=1;
    char c;
    FILE *fr, *fw;
    fr=fopen("vstup.txt","r");
    fw=fopen("vystup.txt","w");
    if(fr!=NULL&&fw!=NULL){
        do{
            c = fgetc(fr);
            if(c=='\n')
                c=' ';
            if(slovo%2==0&&c!=EOF)
                fputc(c,fw);
            if(c==' '||c=='\n')
                slovo++;
        }while(c!=EOF);
    }
    fclose(fw);
    fclose(fr);
}
int volitelny_pr7(){
    int slovo=2,i=1;
    char c1,c2;
    FILE *fr1, *fr2, *fw;
    fr1=fopen("prvy.txt","r");
    fr2=fopen("druhy.txt","r");
    fw=fopen("treti.txt","w");
    if(fr1!=NULL&&fw!=NULL&&fr2!=NULL){
        fprintf(fw,"+");
        while(i==1){
            if(slovo%2==0){
                c1 = fgetc(fr1);
                if(c1!=EOF)
                    fputc(c1,fw);
                if(c1==32||c1=='\n'||c1==EOF){
                    if(c2!=EOF){
                        fprintf(fw,"-");
                        fputc(c2,fw);
                        slovo++;
                        c1 = fgetc(fr1);}
                    else
                        fprintf(fw,"+");
                }
            }
            else{
                c2 = fgetc(fr2);
                if(c2!=EOF)
                    fputc(c2,fw);
                if(c2==32||c2=='\n'||c2==EOF){
                    if(c1!=EOF){
                        fprintf(fw,"+");
                        fputc(c1,fw);
                        slovo++;
                        c2 = fgetc(fr2);}
                    else
                        fprintf(fw,"-");
                }
            }
        if(c1==EOF&&c2==EOF)
                i=0;
        }
    }
    fclose(fw);
    fclose(fr1);
    fclose(fr2);
}
int volitelny_pr8(){
    int i=0,n;
    int array[255] = {0};
    char x[30],znak;
    printf("zadaj retazec max 30 znakov: ");
    do{
        scanf("%c",&x[i]);
        i++;
    }while(x[i-1]!='\n');

    znak = najdlhsie_opakovanie(x,&n,&znak);
    for(int j=0;j<i;j++)
        if(x[j]==znak)
            n++;
    printf("najviac opakujuce pismeno je \"%c\" a opakuje sa %d krat\n",najdlhsie_opakovanie(x,n,&znak),n);
}
int volitelny_pr9(){
    int i=0,j=0,h=0;
    char a[50],b[15];
    do{
        scanf("%c",&a[i]);
        i++;
    }while(a[i-1]!='\n');
    do{
        scanf("%c",&b[j]);
        j++;
    }while(b[j-1]!='\n');
    for(int k=0;k<i/3;k++){
        h=0;
        while(h<i){
            if(a[h]==b[0]&&a[h+1]==b[1]&&a[h+2]==b[2])
                for(int m=0;m<i-h;m++)
                    a[h+m]=a[h+m+3];
        h++;
        }
    }
    printf("%s",a);
}
