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
   // IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
       ll n;
    scanf("%lld",&n);
    ll aa,bb,cc,dd;
    vector<ll>st,st2;
    vector<ll>a,b,c,d;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld %lld %lld %lld",&aa,&bb,&cc,&dd);
        a.push_back(aa);
        b.push_back(bb);
        c.push_back(cc);
        d.push_back(dd);
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            st.push_back(a[i]+b[j]);
        }
    }
    sort(st.begin(),st.end());
    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            ll val=(-1)*(c[i]+d[j]);
            ans+= upper_bound(st.begin(),st.end(),val)-lower_bound(st.begin(),st.end(),val);
        }
    }
    printf("%lld\n",ans);
    if(t)
    {
        printf("\n");
    }
    }
    return 0;
}
