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
int  main()
{
    IOS
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t,Case=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int B=0,W=0,T=0,A=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')B++;
            else if(s[i]=='W')W++;
            else if(s[i]=='T')T++;
            else if(s[i]=='A')A++;
        }
        if(W==0 && T==0 && B!=0){
            printf("Case %d: BANGLAWASH\n",++Case);
        }
        else if(B==0 && T==0 && W!=0){
            printf("Case %d: WHITEWASH\n",++Case);
        }
        else if(n==A)
        {
           printf("Case %d: ABANDONED\n",++Case);
        }
        else if(B==W)
        {
            printf("Case %d: DRAW %d %d\n",++Case,B,T);
        }
        else if(B>W)
        {
            printf("Case %d: BANGLADESH %d - %d\n",++Case,B,W);
        }
        else if(W>B)
        {
          printf("Case %d: WWW %d - %d\n",++Case,W,B);
        }
    }
    return 0;
}
