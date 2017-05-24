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

int main()
{
    int n, m;

    while(scanf("%d %d",&n,&m) == 2)
    {
        printf("%d\n",n*(m+1));
    }

    return 0;
}