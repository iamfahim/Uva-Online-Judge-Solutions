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
string s="";
int ans=0;
int len(int l,int r)
{
    if(l==r)return 1;
    if(l+1==r)
    {
        if(s[l]==s[r]){
        return 2;
        }
        else
        {
            return 1;
        }
    }
    if(s[l]==s[r])
    {
        return 2+len(l+1,r-1);
    }
    else
    {
        return max(len(l,r-1),len(l+1,r));
    }
}
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        s="";
        cin>>s;
        int ln=s.size();

        ans=len(0,ln-1);
        cout<<ans<<endl;
    }
    return 0;
}
