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
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int n;
    while(cin>>n){
    if(n==0)break;
    vector<int>ds;
    for(int i=1;i<=sqrt(n);i++)
    {
      if(n%i==0)
      {
          if((n/i)==i)ds.push_back(i);
          else {
            ds.push_back(i);
            ds.push_back(n/i);
          }
      }
    }
    int ans=0;
    ans+=ds.size();
    if(ds.size()>2)
    {
        for(int i=1;i<ds.size()-1;i++)
        {
            for(int j=i+1;j<ds.size();j++){
            int x=ds[i],y=ds[j];
            if((__gcd(x,y))==1)ans++;
            }
        }
        cout<<n<<" "<<ans<<endl;
    }
    else
    {
        cout<<n<<" "<<ans<<endl;
    }
    }
    return 0;
}
