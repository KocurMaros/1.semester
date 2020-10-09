
/*
Maros Kocur,ID: 111119 , CV. 1
*/

#include <stdio.h>


int cv1pr1() {
   printf("\t\\*/\"Toto\" je na '100%%' zarucene\\*/\n");
}
int cv1pr2() {
   int a, b, c;
    printf("Zadaj 3 cele cisla:");
    scanf("%d %d %d",&a, &b, &c);
    printf("\nVysledok %d x %d x %d je %d\n",a,b,c,a*b*c);
}
int cv1pr3() {
    float r, o, s;
    printf("Zadaj polomer (realne cislo):");
    scanf("%f",&r);
    o= 2*r*3.14;
    s= r*r*3.14;
    printf("\nKruh s polomerom %.2f: obvod = %.2f, obsah= %.2f\n",r ,o ,s);
}
int cv1pr4() {
    float x,y,z;
    printf("Zadaj 3 realne cisla:");
    scanf("%f %f %f",&x, &y, &z);
    printf("\nPriemer cisel %.3f %.3f %.3f je: %.3f\n",x,y,z, (x+y+z)/3);
}
int cv1pr5() {
    float c, o;
    printf("Zadaj cislo: ");
    scanf("%f", &c);
    printf("Cena bez dane: %.2f",c);
    printf("\nPredajna cena s danou 20%%: %.2f\n", c*1.2);
}
int cv1pr6() {
    float m, h;
    printf("Zadajte vysku v centimetroch: ");
    scanf("%f", &h);
    printf("Zadajte hmotnost v kilogramoch: ");
    scanf("%f", &m);
    printf("\nBMI %.3f\n", m/((h/100)*h/100));
}
int main() {
    cv1pr1();
    //cv1pr2();
    //cv1pr3();
    //cv1pr4();
    //cv1pr5();
    //cv1pr6();
}

