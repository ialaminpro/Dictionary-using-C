#include <cstdio>
#include <iostream>
#include <string>

#define SZ(x) ((int)x.size())

using namespace std;

int main()
{
    int test,pos,cas=1;
    string s;
    cin>>test;
    while(test--)
    {
        cin>>pos>>s;
        pos--;
        cout<<cas++<<" ";
        for(int i=0;i<SZ(s);i++)
        {
            if(i!=pos) cout<<s[i];
        }
        puts("");
    }
    return 0;
}
