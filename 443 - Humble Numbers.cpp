//Bismiintahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
#define ll unsigned long long
#define mod 2e9+7
using namespace std;
const int MOD = (int)2e9+7;
map<ll,ll>mp;
int limit=5842;
vector<ll>st;
ll power(int b,int p)
{
    if(p==0)return 1;
    ll sum=1;
    while(p--)
    {
        sum*=b;
    }
    return sum;
}
void solve()
{
     for(int i=0;i<=40;i++)
        {

           for(int j=0;j<=40;j++)
           {

               for(int k=0;k<=40;k++)
               {

                 //  cout<<pow(5,k)<<endl;
                   for(int l=0;l<=40;l++)
                   {

                       ll data=1;
                       data*=power(7,i);
                       data*=power(5,j);
                       data*=power(3,k);
                       data*=power(2,l);
                       if(data>mod)break;
                      // cout<<i<<" "<<j<<" "<<" "<<k<<" "<<l<<" "<<data<<endl;
                      // cout<<data<<endl;
                       st.push_back(data);
                   }
               }
           }
        }

}
void mapping()
{
     int ind=1;
     int len=st.size();
     //cout<<len<<endl;
     sort(st.begin(),st.end());
     for(int i=0;i<len;i++)
     {
        mp[ind++]=st[i];
     }
}
int  main()
{
    IOS
    //store();
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    solve();
    mapping();
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int nn=n;
        int x=nn%10;
        nn/=10;
        int y=nn%10;

        if(n%10==1 && (y!=1))cout<<"The "<<n<<"st humble number is "<<mp[n]<<"."<<endl;
        else if(n%10==2 && y!=1)cout<<"The "<<n<<"nd humble number is "<<mp[n]<<"."<<endl;
        else if(n%10==3 && y!=1)cout<<"The "<<n<<"rd humble number is "<<mp[n]<<"."<<endl;
        else cout<<"The "<<n<<"th humble number is "<<mp[n]<<"."<<endl;
    }
    return 0;
}
