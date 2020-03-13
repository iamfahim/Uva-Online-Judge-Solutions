//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ms(a,b)         memset(a, b, sizeof(a))
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout<<"Hello, i am in here."<<endl;
#define bit_cnt(mask) __builtin_popcountll(mask)
#define ll long long int
#define dst(u,v,x,y) sqrt((x*1.0-u*1.0)*(x*1.0-u*1.0)+(y*1.0-v*1.0)*(y*1.0-v*1.0))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}
using namespace std;
const int MOD = (int)1e9+7;
bool isPalindrom(ll number)
{
    string str= to_string(number);
    string str2=str;
    reverse(str2.begin(),str2.end());
    if(str==str2)return true;
    else return false;
}
void solve()
{
    ll n;
    ll Counter=0;
    cin>>n;
    ll temp=n;
    string rn= to_string(temp);
    while(!isPalindrom(temp)){
    reverse(rn.begin(),rn.end());
    stringstream fahim(rn);
    ll RN=0;
    fahim>>RN;
    temp=temp+RN;
    rn=to_string(temp);
    Counter++;
    }
    cout<<Counter<<" "<<rn<<endl;
}
int  main()
{
    IOS
    ll t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}

