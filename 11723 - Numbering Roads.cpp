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
    int n,r;
    int Case=0;
    while(cin>>n>>r)
    {
        if(n==0 && r==0)break;
        n--;
        int res=(n/r);
        if(res>26)
        {
            cout<<"Case "<<++Case<<": impossible"<<endl;
        }
        else    
        {
         cout<<"Case "<<++Case<<": "<<res<<endl;   
        }
    }
    return 0;
}