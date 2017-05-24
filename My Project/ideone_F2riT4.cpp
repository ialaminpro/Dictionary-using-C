
#include<iostream>
#include<cstdio>

using namespace std;


int main()
{
	int t,n,k1,k2,gun,ans,k3,r;
	cin>>t;
	while(t--)
	{
        cin>>n;
        k3=k2=k1=n;
        r=1;
        ans=n;
        while(k1>=10)
        {
            gun=ans/r;
            gun%=10;
            r*=10;
            ans/=r;
            if(gun>=5)
            {
                ans++;
                ans*=r;
            }
            else
            {
            ans*=r;
            }
            k1/=10;
        }
        cout<<ans;

        cout<<endl;
	}
}

