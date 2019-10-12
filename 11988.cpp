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
    string s;
    while(getline(cin,s))
    {
        list<char>ls;
        ll sz=s.size();
        for(int i=0;i<sz;)
        {
            bool ok=false;
            if(s[i]=='[')
            {
               i++;
               string tam="";
               while(s[i]!=']' && s[i]!='[' && i<sz)
               {
                   tam+=s[i];
                   i++;
                   ok=true;
               }
               if(ok)
               {
                   int ln=tam.size();
                   for(int i=ln-1;i>=0;i--)
                   {
                       ls.push_front(tam[i]);
                   }
                   continue;
               }
            }
            else if(s[i]==']')
            {
                i++;
                while(s[i]!='[' && s[i]!=']' && i<sz)
                {
                    ls.push_back(s[i]);
                    i++;
                    ok=true;
                }
                if(ok)continue;
            }
            else
            {
                if(s[i]!='[' && s[i]!=']')
                {
                    ls.push_back(s[i]);
                }
                i++;
            }
        }
        for(auto it:ls)
        {
            cout<<it;
        }
        cout<<endl;
    }
    return 0;
}
