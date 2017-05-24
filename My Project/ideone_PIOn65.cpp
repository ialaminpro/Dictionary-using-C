#include <sstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

#define SZ(x) ((int)x.size())

using namespace std;

int main()
{
    string s,pre,next;
    int n,pr,nx;
    stringstream ss;
    cin>>s;
    ss<<s;
    ss>>n;
    pr=n-1;
    if(pr>=0)
    {
        ss.clear();
        ss<<pr;
        ss>>pre;
        ss.clear();
        pre=string((6-SZ(pre)),'0')+pre;
        int l=0,r=0;
        for(int i=0; i<3; i++) l+=pre[i]-'0';
        for(int i=3; i<6; i++) r+=pre[i]-'0';
        if(r==l)
        {
            puts("Yes");
            return 0;
        }
    }
    nx=n+1;
    if(nx<=999999)
    {
        ss.clear();
        ss<<nx;
        ss>>next;
        ss.clear();
        next=string((6-SZ(next)),'0')+next;
        int l=0,r=0;
        for(int i=0; i<3; i++) l+=next[i]-'0';
        for(int i=3; i<6; i++) r+=next[i]-'0';
        if(r==l)
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
/*
715068
445219
012200
*/
