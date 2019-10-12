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
    ll n;
    while(scanf("%lld",&n)!=EOF){
        if(n==0)break;
    vector<ll>vs;
    vs.push_back(n);
    while(scanf("%lld",&n)!=EOF){
            if(n==0)break;
        vs.push_back(n);
    }
    sort(vs.begin(),vs.end());
    ll f=vs[0];
    for(int i=1;i<vs.size();i++)vs[i]-=f;
    ll gcd=__gcd(vs[1],vs[2]);
    if(vs.size()>3){
    for(int i=2;i<vs.size();i++)gcd=__gcd(gcd,vs[i]);
    }
    cout<<gcd<<endl;
    }
    return 0;
}
