/*
Maros Kocur, 111119, cv.2
*/
#include <stdio.h>

int pr1(){
    int a,b;
    printf("Zadajte dve cele cisla oddelene medzerou: ");
    scanf("%d %d",&a,&b);
    printf("vacsie z cisel %d %d je %d\n",a,b,(a>b)?a:b);
    if(a>b)
    printf("mensie z cisel %d %d je %d\n",a,b,b);
    if(a<b)
    printf("mensie z cisel %d %d je %d\n",a,b,a);
}
int pr2(){
    char c;
    printf("Zadaj jeden znak:");
    c = getchar();
    if(c >=65 && c<=90){
        printf("na vstupe je: Velke pismeno\n");
    }
    else if(c >=97 && c<=122){
        printf("na vstupe je: Male pismeno\n");
    }
    else if(c >=48 && c<=57){
        printf("na vstupe je: Cislo\n");
    }
    else{
        printf("na vstupe je: ine pismeno\n");
    }
}
int pr3(){
    char c;
    printf("Zadaj jeden znak: ");
    c = getchar();
    printf("znak %c na vstupe ma ASCII hodnotu %d, alebo aj %x Hexa\n", c, c, c);
    if(c >=97 && c<=122){
        c = c - 32;
        printf("Male pismeno bolo zmenene na velke %c\n",c);
        printf("ktore ma ASCII hodnotu %d, alebo aj %x Hexa\n",c,c);
    }
}
int volitelny_pr4(){
    float f;
    printf("Zadaj teplotu F: ");
    scanf("%f",&f);
    printf("Teplota v stupnoch celzia: %.2f\n",(f-32)*5/9);
}
int volitelny_pr5(){
      int a,b,c;
      printf("Zadaj tri cele cisla: ");
      scanf("%d %d %d",&a, &b, &c);
      if(a<b && a<c){
        printf("Najmensie cislo z %d %d %d je %d\n",a, b, c, a);
      }
      else if(b<c && b<a){
          printf("Najmensie cislo z %d %d %d je %d\n",a, b, c, b);
        }
      else{
        printf("Najmensie cislo z %d %d %d je %d\n",a, b, c, c);
      }
}
int volitelny_pr6(){
    int a,b,c;
    printf("Zadaj tri cele cisla: ");
    scanf("%d %d %d",&a, &b, &c);
    if(a>b){
        if(a>c && b>c){
            printf("Usporiadany vysledok: %d %d %d\n",c,b,a);
        }
        else if(a>c && b<c){
            printf("Usporiadany vysledok: %d %d %d\n",b,c,a);
        }
    }
    if(b>c){
        if(b>a && a>c){
            printf("Usporiadany vysledok: %d %d %d\n",c,a,b);
        }
        else if(b>c && a<c){
            printf("Usporiadany vysledok: %d %d %d\n",a,c,b);
        }
    }
     if(c>a){
        if(c>b && a>b){
            printf("Usporiadany vysledok: %d %d %d\n",b,a,c);
        }
        else if(c>b && a<b){
            printf("Usporiadany vysledok: %d %d %d\n",a,b,c);
        }
    }
}
int volitelny_pr7(){
char a,b,c;
printf("Zadaj 3 pismena: ");
scanf("%c %c %c",&a, &b, &c);
if(a==b && a==c){
    printf("Vsetky pismena su rovnake\n");
}
else if(a!=b && a!=c){
    printf("Vsetky pismena su rozne\n");
}
else{
    printf("Dve pismena su rovnake\n");
}
}
int volitelny_pr8(){
float m, h, bmi;
    printf("Zadajte vysku v centimetroch a hmotnost v kilogramoch: ");
    scanf("%f %f", &h, &m);
    bmi = m/((h/100)*h/100);
    printf("BMI je %.3f\n", bmi);
    if(bmi<=18.5){
        printf("Podvaha\n");
    }
     else if(bmi>18.5 && bmi <=25){
        printf("Normalna hmotnost\n");
    }
    else if(bmi>25 && bmi <30){
        printf("Nadvaha\n");
    }
    else if(bmi>=30){
        printf("Obezita\n");
    }
}


int main() {
    pr1();
    //pr2();
    //pr3();
    //volitelny_pr4();
    //volitelny_pr5();
    //volitelny_pr6();
    //volitelny_pr7();
    //volitelny_pr8();
    return 0;
}
