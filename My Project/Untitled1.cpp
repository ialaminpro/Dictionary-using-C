#include<stdio.h>
int main()
{
int n,i,j,f=0,k,h,l,a,b[50];
scanf("%d",&a);
{
for(j=1;j<=a;j++)
{
 h=0;
 l=0;
 scanf("%d",&n);
 for(i=0;i<n;i++){
 scanf("%d",&b);
 if(b>f)
  h=h+1;
  if(b<f)
  l=l+1;}
   printf("Case %d: %d %d\n",j,h,l);
 }
}
return 0;
}
