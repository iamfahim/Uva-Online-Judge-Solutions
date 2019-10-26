#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll make;
int main()
{
 ll coin[]= {1,5,10,25,50};
    ll nways[30100]={0};
    nways[0]=1;
    for(ll i=0; i<5; i++)
    {
        //cout<<"i "<<i<<endl;
        for(ll j=coin[i],k=0; j<=30000; j++,k++)
        {
            //cout<<j<<" "<<k<<" "<<nways[j]<<" "<<nways[k]<<endl;
            nways[j]+=nways[k];

        }
    }

    while(cin>>make)
    {


        ll ans=nways[make];
        if(ans==1)
        {
            printf("There is only 1 way to produce %lld cents change.\n",make);
        }
        else
        {
            printf("There are %lld ways to produce %lld cents change.\n",ans,make);
        }
    }
    return 0;
}
