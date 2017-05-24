#include <stdio.h>
int main()
{
    int mark[]={40,50,60,6,96,58,25,12,31,84};
    int sum,average;
    sum=mark[0]+mark[1]+mark[2]+mark[3]+mark[4]+mark[5]+mark[6]+mark[7]+mark[8]+mark[9];
    average=sum/10;
    int i;
    for(i=0;i<10;i++)
    {
        if (mark[i]%2==0)
        {
            printf("even=");
            printf("%d\n",mark[i]);
        }
        else
        {
            printf("odd=");
            printf("%d\n",mark[i]);
        }
    }
    printf ("Addition=%d\n",sum);
    printf ("Average Marks=%d\n",average);
    return 0;
}
