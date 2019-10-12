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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cntdg[10]={0};
        for(int i=1;i<=n;i++)
        {
            int tam=i;
            while(tam!=0)
            {
                int mod=tam%10;
                cntdg[mod]++;
                tam/=10;
            }
        }
        for(int i=0;i<9;i++)
        {
            cout<<cntdg[i]<<" ";
        }
        cout<<cntdg[9]<<endl;
    }
    return 0;
}