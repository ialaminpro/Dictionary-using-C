#include<stdio.h>
#include<string.h>
int main()
{
  char str[10005];
  int i, j, t;
  scanf("%d", &t);
  for(j=1;j<=t;j++)
    {

        scanf("%s", &str);
        for(i=0;i<=strlen(str);i++)
            {
            if(str[i]>=65&&str[i]<=90)
            {

                str[i]=str[i]+1;
                if(str[i]==91)
                    str[i]=65;

            }}


        printf("String #%d\n%s\n\n", j, str);
    }
  return 0;
}

