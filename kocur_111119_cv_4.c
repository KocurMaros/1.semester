/*
Maros Kocur, 111119, cv.4
*/
#include <stdio.h>

int pr1(){
    int n,i,j;
    printf("Zadajte cislo od 1 do 9= ");
    scanf("%d",&n);
    if(n>=0 && n<=9){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(j>=i)
                    printf("%d ",j);
            }
            printf("\n");
        }
    }
    else
        printf("nespravny vstup");
}
int pr2(){
    int i,j,c;
    printf("Zadajte pismeno od A do Z= ");
    scanf("%c",&c);
    if(c>='A' && c<= 'Z'){
        for(i=1;i<=(c-64);i++){
                printf("%d= ", i);
            for(j=0;j<=(c-64);j++){
                if((c-j)>='A'&&(c-j-64)>(i-1))
                    printf("%c ",(c-j));
            }
            printf("\n");
        }
    }
    else
        printf("nespravny vstup");
}
int volitelny_pr3(){
    int n, i, j=1, h,g=1;
    printf("Zadajte pocet riadkov Floydovho trojuholnika od 1 do 10: ");
    scanf("%d",&n);
    printf("Floydov trojuholnik pre %d riadkov je:\n", n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++)
            printf("%d ",g++);
    printf("\n");
    }
}
int volitelny_pr4(){
    int n,i,j;
    printf("Zadajte pocet riadkov od 1 do 15: ");
    scanf("%d",&n);
    if(n>=1&&n<=15){
        for(i=0;i<n;i++){
            printf("%d: ",i+1);
            for(j=1;j<=n-i;j++)
                printf("%d ",j);
            printf("\n");
        }
    }
    else
        printf("Cislo nie je z daneho intervalu");
}
int volitelny_pr5(){
    int n,i,j;
    printf("Zadajte pocet riadkov od 1 do 15: ");
    scanf("%d",&n);
    if(n>=1&&n<=15){
        for(i=0;i<n;i++){
            printf("%d: ",i+1);
            for(j=n;j>=0;j--){
                if((j-i)>0)
                    printf("%d ",j-i);
            }
            printf("\n");
        }
    }
    else
        printf("Cislo nie je z daneho intervalu");
}
int volitelny_pr6(){
    int n,k,h;
    printf("nacitaj cele cislo n: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        k+=i;
        if(k%3==0)
            printf("%d,",i);
    }
}
int volitelny_pr7(){
    int n;
    printf("Zadajte neparne cislo od 1 do 15: ");
    scanf("%d",&n);
    if((n>0&&n<16)&&n%2==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)
                printf("*");
            printf("\n");
        }
        for(int i=n-1;i>0;i--){
            for(int j=1;j<=i;j++)
                printf("*");
            printf("\n");
        }
    }
    else
        printf("zly vstup");
}
int volitelny_pr8(){
    int n,m,g;
    printf("Zadajte neparne cislo od 1 do 15: ");
    scanf("%d",&n);
    if((n>0&&n<16)&&n%2==1){
      m=n;
      g=(int)n/2;
      for(int i=1;i<=m;i++)
      {
        for(int j=1;j<=m;j++)
        {
           if(i==j || j==(m-i+1)||j==g+1||i==g+1)
           {
             printf("*");
           }
           else
           {
             printf(" ");
           }
        }
        printf("\n");
      }
    }
    else
        printf("zly vstup");
}
int volitelny_pr9(){
    int n,m,g,q;
    printf("Zadajte neparne cislo od 1 do 15 a cislo od 1 do 5: ");
    scanf("%d %d",&n, &q);
    if(((n>0&&n<16)&&n%2==1)&&(q>0&&q<6)){
      m=n;
      g=(int)n/2;
      for(int h=0;h<q;h++){
          for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j || j==(m-i+1)||j==g+1||i==g+1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
          }
      }
    }
    else
        printf("zly vstup");
}
int volitelny_pr10(){
    int n,m,g,q;
    printf("Zadajte neparne cislo od 1 do 15 a cislo od 1 do 5: ");
    scanf("%d %d",&n, &q);
    if(((n>0&&n<16)&&n%2==1)&&(q>0&&q<6)){
        m=n;
        g=(int)n/2;
        for(int i=1;i<=m;i++){
            for(int h=0;h<q;h++){
                for(int j=1;j<=m;j++){
                    if(i==j || j==(m-i+1)||j==g+1||i==g+1)
                        printf("*");
                    else
                        printf(" ");
                }
            }
        printf("\n");
        }
    }
    else
        printf("zly vstup");
}
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
}
