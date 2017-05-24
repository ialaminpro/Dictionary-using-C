#include <stdio.h>
int main()
{
    int sum=0;
    int i;
    int marks[5]={2};
    for(i=0;i<5;i++){
        sum=sum+marks[i];

    }

    printf("%d\n",sum);
    return 0;
}
