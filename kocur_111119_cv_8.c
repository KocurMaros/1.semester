#include<stdio.h>
int main(){
    int n,k=0;
    printf("Zadanie prve\n");
    int PISMENA=0,i=0;
    char c;
    FILE *fr;
    fr = fopen("vstup.txt","r");
    while((c=fgetc(fr))!=EOF){
        if(c>='A'&&c<='Z')
            PISMENA++;
    }
    fclose(fr);
    char *znaky = malloc(PISMENA * sizeof(char));
    fr = fopen("vstup.txt","r");
    if(fr!=NULL){
        while((c=fgetc(fr))!=EOF){
            if(c>='A'&&c<='Z'){
                znaky[i] = c;
                i++;
            }
        }
        fclose(fr);
        for(int j=i-1;j>=0;j--){
            if(k==20){
                printf("\n");
                k=0;}
            if(j%3==0){
                printf("%c",znaky[j]);
                k++;
            }
        }
        free(znaky);
        znaky = NULL;
    }
    /*printf("Zadanie druhe\n");
    scanf("%d",&n);
    int *a = malloc(n*sizeof(int));
    napln(a,n);
    vypis(a,n);
    free(a);
    a=NULL;*/
    return 0;
}
int napln(int a[],int i){
    for(int j=1;j<=i;j++)
        a[j-1]=j;
}
void vypis(int *a,int j){
    for(int i=0;i<j;i++)
        if(i%20==0)
            printf("%d",a[i]);
    printf("\n");
}
