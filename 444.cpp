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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    string s;
    while(getline(cin,s))
    {
        string ans="";
        if((s[0]>='a' &&s[0]<='z') || (s[0]>='A' && s[0]<='Z') || (s[0]==' ') ||  (s[0]=='!') ||  (s[0]=='.') ||  (s[0]==',') ||  (s[0]==':') || (s[0]==';') || (s[0]=='?'))
        {
            for(int i=0;i<s.size();i++){
            int num=s[i];
            char ss[100];
            sprintf(ss,"%d",num);
            ans+=ss;
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
        else
        {
            reverse(s.begin(),s.end());
            for(int i=0;i<s.size();)
            {
                if(s[i]-'0'==1)
                {
                  int nn;
                  nn=s[i]-'0';
                  nn=nn*10+(s[i+1]-'0');
                  nn=nn*10+(s[i+2]-'0');
                  ans+=nn;
                  i+=3;
                }
                else {
                    int nn;
                  nn=s[i]-'0';
                  nn=nn*10+(s[i+1]-'0');
                  ans+=nn;
                  i+=2;
                }
            }
            cout<<ans<<endl;
        }


    }
    return 0;
}
