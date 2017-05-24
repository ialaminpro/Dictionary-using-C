#include<stdio.h>
	int main()
	{
             int  t,i,res,dn1,dn2,dn3,dn4,bn1,bn2,bn3,bn4,rem1,rem2,rem3,rem4,remb1,remb2,remb3,remb4,j;
	    scanf("%d",&t);
	    for(i=1;i<=t;i++)
	    {
	        scanf("%d.%d.%d.%d",&dn1,&dn2,&dn3,&dn4);
	        scanf("%d.%d.%d.%d",&bn1,&bn2,&bn3,&bn4);
	        for(j=0;j<=7;j++)
	        {
	            rem1=dn1%2;
	            rem2=dn2%2;
	            rem3=dn3%2;
	            rem4=dn4%2;

	            dn1=dn1/2;
	            dn2=dn2/2;
	            dn3=dn3/2;
	            dn4=dn4/2;

	            if((rem1==bn1)&&(rem2==bn2)&&(rem3==bn3)&&(rem4==bn4))
	            {
	                res=1;
	            }
	            else
	            {
	                res=0;
	                break;
	            }
	        }
	        if(res==1)
	        {
	            printf("Case %d: Yes\n",i);
	        }
	        else
	        {
	            printf("Case %d: No\n",i);
	        }
	    }
	    return 0;
	}
