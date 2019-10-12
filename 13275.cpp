//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
map<int,bool>mp;
bool isLeapYear(int year)
{
    if(year%400==0)return true;
    else if(year%100==0)return false;
    else if(year%4==0)return true;
    else return false;
}
int  main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    IOS
    for(int i=1850;i<=2016;i++)
    {
        if(isLeapYear(i))
        {
            mp[i]=true;
        }
        else
        {
            mp[i]=false;
        }
    }

    int T;
    int Case=0;
    scanf("%d",&T);
    while(T--){
    int d,m,y,qy;
   scanf("%d %d %d %d",&d,&m,&y,&qy);
    int ans=0;
   if(d==29 && m==2)
    {
       for(int i=y+1;i<=qy;i++)
       {
           if(mp[i])
           {
               ans++;
           }
       }
       printf("Case %d: %d\n",++Case,ans);
    }

    else
    {
        ans=(qy-y);
         printf("Case %d: %d\n",++Case,ans);
    }
    }
    return 0;
}
