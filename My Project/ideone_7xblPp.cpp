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

    int n, i, cnt;

    string s;

    while(scanf("%d",&n) == 1)
    {
        cnt = 0;
        while(n--)
        {
            cin >> s;
            if(s[1] == '+')
                cnt++;
            else
                cnt--;
        }
        cout << cnt << "\n";
    }


    return 0;
}