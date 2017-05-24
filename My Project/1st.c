#include <stdio.h>
#include <conio.h>
void main ()
{
    int i,n,a[100];
    FILE *fp,*fo;
    fp=fopen("Frw01.in","r");
    fo=fopen("Frw01.out","w");
    printf("How many number: ");
    scanf("%d",&n);
    for (i=0; i<n ; i++)
        fscanf(fp,"%d",&a[i]);
    for (i=0;i<n;i++)
        fprintf(fo,"%4d",a[i]);
}
