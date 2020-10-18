/*
Maros Kocur, 111119, cv.5
*/

#include <stdio.h>
#include<stdlib.h>
int main(){
    pr1();
    //pr2();
    //volitelny_pr3();
    //volitelny_pr4();
    //volitelny_pr5();
    //volitelny_pr6();
    //volitelny_pr7();
    //volitelny_pr8();
    //volitelny_pr9();
    //volitelny_pr10();
    //volitelny_pr11();
    //volitelny_pr12();
    //volitelny_pr13();
    //volitelny_pr14();
   return 0;
}
int pr1(){
    int ch;
    FILE *fpw;
    fpw = fopen("vystup.txt","w");
    if(fpw == NULL){
        printf("nepodarilo sa otvorit subor na zapis");
        exit(1);}
    printf("Zadaj cislo z intervalu od 1 po 1000: ");
    scanf("%d",&ch);
    if(ch>=1&&ch<=1000){
        for(int i=1;i<=ch;i++)
            fprintf(fpw,"Toto je %d. veta z %d za odmenu\n",i,ch);}
    else
        printf("nespravny vstup\n");
    fclose(fpw);
}
int pr2(){
int big=0,small=0,num=0,line=0,space1=0,space2=0;
   char c,prev_c;
   FILE *fp;
   fp = fopen("vstup.txt", "r");
   if (fp == NULL)
   {
      printf("nepodarilo sa otvorit subor na citanie\n");
      exit(1);
   }
   while((c = fgetc(fp)) != EOF){
      if(c>='0' && c<='9')
            num++;
        else if(c>='a'&&c<='z')
            small++;
        else if(c>='A'&&c<='Z')
            big++;
        else if(c=='\n')
            line++;
        else if(c==32){
            if(prev_c != c)
                space1++;
            space2++;
        }
        prev_c = c;
   }
    printf("velke: %d\nmale: %d\ncisla: %d\nriadky: %d\nmedzery: %d\nmedzery_bonus: %d\n",big,small,num,line+1,space2,space1);

   fclose(fp);
}
int volitelny_pr3(){
    float n;
    printf("Zadaj realne cislo: ");
    scanf("%f",&n);
    FILE *fpw;
    fpw = fopen("nasobky.txt","w");
    for(int i=1;i<=10;i++)
        fprintf(fpw,"%d * %.2f = %.2f\n",i,n,(n*i));
}
int volitelny_pr4(){
    int q=1;
    char n;
    FILE *fpr;
    FILE *fpw;
    fpr = fopen("znak.txt","r");
    fpw = fopen("novy.txt","w");
    if(fpw == NULL||fpr == NULL){
        printf("nepodarilo sa otvorit subor na zapis\n");
        exit(1);}
    printf("zadaj znak 's' pre kopirovanie\n");
    while(q==1){
        if((n=getchar())=='s')
            fputc(fgetc(fpr),fpw);
        else
            q=0;
    }
    fclose(fpw);
    fclose(fpr);
}
int volitelny_pr5(){
    int diff=0, longer=0,q=1;
    char c1,c2;
    FILE *fpr1;
    FILE *fpr2;
    fpr1 = fopen("prvy.txt","r");
    fpr2 = fopen("druhy.txt","r");
    if(fpr1 == NULL||fpr2 == NULL){
        printf("nepodarilo sa otvorit subor na zapis\n");
        exit(1);}
    do{
        c1 = fgetc(fpr1);
        c2 =fgetc(fpr2);
        if(c1 == EOF||c2 == EOF)
            longer++;
        else if(c1!=c2)
            diff++;
    }while(c1 != EOF||c2!= EOF);
    printf("Pocet roznych znakov: %d\nJeden zo suborov je dlhsi o %d znakov\n",diff,longer-1);
    fclose(fpr1);
    fclose(fpr2);
}
int volitelny_pr6(){
    FILE *fpr;
    FILE *fpw;
    char buffer[256];
    int male=0;
    fpr=fopen("vstup.txt", "r");
    fpw=fopen("cisla.txt", "a");
    if(fpr==NULL||fpw==NULL) {
        perror("Nepodarilo sa otvorit subor");
        exit(1);
    }
    else {
        while(fgets(buffer, sizeof(buffer), fpr)) {
            fprintf(fpw, "%s", buffer);
            for(int i = 0; i <= strlen(buffer); i++)
                if(buffer[i] >= 'a'&&buffer[i]<='z')
                    male++;
            fprintf(fpw,"%d\n",male);
            male=0;
        }
    }
    fclose(fpr);
    fclose(fpw);
}
int volitelny_pr7(){
    char c;
    int space=0;
    FILE *fpr;
    fpr=fopen("text.txt", "r");
    if(fpr == NULL){
        printf("nepodarilo sa otvorit subor na zapis\n");
        exit(1);}
     while((c = fgetc(fpr)) != EOF){
        if(c=='x'||c=='X')
            printf("Precital som X\n");
        else if(c=='y'||c=='Y')
            printf("Precital som Y\n");
        else if(c=='#'||c=='$'||c=='&')
            printf("Precital som riadiaci znak\n");
        else if(c==32)
            space++;
        else if(c=='*'){
            printf("Koniec\n");
            break;
        }
    }
    printf("Pocet precitaych medzier: %d\n",space);
    fclose(fpr);
}
int volitelny_pr8(){
    char c;
    FILE *fpw;
    fpw=fopen("vystup.txt", "w");
    do{
        printf("Zadaj znaky:\n");
        c = getchar();
        if(c>='a'&&c<='z')
            fprintf(fpw,"%c",c-32);
        else if(c>='A'&&c<='Z')
            fprintf(fpw,"%c",c);
        else if(c=='\n'||c=='\t')
            fprintf(fpw,"%c",32);
        else if(c=='*')
            fprintf(fpw,"%c",c);
        else
            fprintf(fpw,"%c",'-');
    }while(c!='*');
fclose(fpw);
}
int volitelny_pr9(){
    int a,b,sucet=0,temp;
    printf("zadaj 2 cele cisla oddelene medzerou: ");
    scanf("%d %d",&a, &b);
    if(a>b){
        temp = a;
        a = b;
        b = temp;}
    if(b==(a+1)||a==(b-1))
        printf("Neda sa vypocitat\n");
    else{
        for(int i=a+1;i<b;i++)
            sucet+=i;
        printf("Sucet celych cisel v (%d,%d)= %d\n",a,b,sucet);
    }
}
int volitelny_pr10(){
    int a,sucin=1;
    printf("zadaj cele cislo: ");
    scanf("%d",&a);
    for(int i = a;i>0;i--)
        sucin*=i;
    printf("%d!= %d\n",a,sucin);
}
int volitelny_pr11(){
    int p, k;
    printf("zadaj cisla p a k (0 < p, k < 100): ");
    scanf("%d %d",&p,&k);
    for(int i=1;i<=p;i++){
        if(i%k==0)
            printf("-- ");
        else
            printf("%d ",i);

    }
    printf("\n");
}
int volitelny_pr12(){
    int i=-1;
    while(++i<10)
        printf("%d. \n", i+1);
}
int volitelny_pr13(){
    int n, p=1;
    float d,c;
    printf("Zadaj cislo n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%f",&c);
        if(i==0)
            if(c>0&&c<11)
                p=p;
            else
                p=0;
        if(i!=0){
            if(c<(2*d)&&c>(d/2))
                p=p;
            else
                p=0;
        }
        d=c;
    }
    if(p==1)
        printf("Postupnost je spravna\n");
    else
        printf("Postupnost nie je spravna\n");
}
int volitelny_pr14(){
    int n,s,v;
    printf("zadaj 3 cele cisla oddelene medzerami: ");
    scanf("%d %d %d",&n,&s,&v);
    if(n<1||n>15||n%2==0||s>5||s<1||v<1||v>5)
        printf("zly vstup\n");
    else{
        for(int t=0;t<v;t++){
            for(int i=1;i<=n;i++){
                for(int q=0;q<s;q++)
                    for(int j=1;j<=n;j++)
                        if(j<=i)
                            printf("%d",i);
                        else
                            printf(" ");
                printf("\n");
            }
            for(int i=n-1;i>0;i--){
                for(int q=1;q<=s;q++)
                    for(int j=1;j<=n;j++)
                        if((j<=i))
                            printf("%d",i);
                        else
                            printf(" ");
                printf("\n");
            }
        }
    }
}

