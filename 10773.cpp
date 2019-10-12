//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;
const int MOD = (int)1e9+7;
int  main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    int Case=0;
    scanf("%d",&t);
    while(t--)
    {
      int d,v,u;
      scanf("%d %d %d",&d,&v,&u);
      if(v>=u || v==0 || u==0 || d==0)
      {
          printf("Case %d: can't determine\n",++Case);
      }
      else
      {
          double t1=((d*1.0)/(sqrt(u*u-v*v)));
          double t2=((d*1.0)/(u));
          double dif=abs(t1-t2);
          printf("Case %d: %.3f\n",++Case,dif);
      }
    }
    return 0;
}
