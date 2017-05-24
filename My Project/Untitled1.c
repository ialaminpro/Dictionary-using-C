#include<stdio.h>
int main()
{
int i,Cases,j,Wall_Number,Wall_Length,Second_Wall,First_Wall,Hight_Jumps,Low_Jumps;
scanf("%d",&Cases);
for(i=1;i<=Cases;i++)
{
 scanf("%d",&Wall_Number);
 for(j=1;j<=Wall_Number;j++)
 {
  scanf("%d",&Wall_Length);
  First_Wall=Wall_Length;
   if(j>1)
    {
      if(First_Wall>Second_Wall)
        {
          Hight_Jumps++;
        }
      if(First_Wall<Second_Wall)
        {
          Low_Jumps++;
        }
        Second_Wall=First_Wall;
     }
 else
      {
        Hight_Jumps=0;
        Low_Jumps=0;
        Second_Wall=Wall_Length;
      }
   }
   printf("Case %d: %d %d\n",i,Hight_Jumps,Low_Jumps);

 }
  return 0;
}
