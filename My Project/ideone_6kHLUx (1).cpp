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

#define SZ 1010

char arr[SZ][SZ];
char s[SZ];

int main()
{
    int i, j, k, col, row, len, mark;

    while(scanf("%d",&col) == 1 && col)
    {
        scanf("%s",s);
        len = strlen(s);
        row = len/col;

        mark = 1;
        k = 0;

        for(i=0; i<row; i++)
        {
            if(mark == 1)
            {
                mark = !mark;

                for(j=0; j<col; j++)
                    arr[i][j] = s[k++];
            }
            else
            {
                mark = !mark;
                for(j=col-1; j>=0; j--)
                    arr[i][j] = s[k++];
            }
        }


        k = 0;

        for(i=0; i<col; i++)
        {
            for(j=0; j<row; j++)
            {
                printf("%c",arr[j][i]);
            }
        }


        printf("\n");
    }


    return 0;
}
