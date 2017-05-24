#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

int cum[1100];

int f(int n)
{
    if(n % 7 == 0) return true;
    while(n)
    {
        if(n%10 == 7) return true;
        n /= 10;
    }
    return false;
}

int main()
{
    int i, j, k, t;

    for(i=1; i<=1000; i++)
        if(f(i))
            cum[i] = 1;

    for(i=1000; i>=0; i--)
        if(cum[i])
            cum[i] += cum[i+1];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&k);

        for(i=0; i<=1000; i++)
            if(cum[i] >= k)
            {
                printf("%d\n",i);
                break;
            }
    }

    return 0;
}
