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
    string s1,s2;
    while(  getline(cin,s1),getline(cin,s2))
    {

        int ar1[30]={0};
        int ar2[30]={0};
        int len1=s1.size();
        int len2=s2.size();
        //cout<<s1.size()<<endl;
        //cout<<s2.size()<<endl;
        for(int i=0;i<len1;i++)
        {
            ar1[s1[i]-'a']++;
        }
        for(int i=0;i<len2;i++)
        {
            ar2[s2[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<=26;i++)
        {
            if(ar1[i]!=0 && ar2[i]!=0)
            {
                int mn=min(ar1[i],ar2[i]);
                while(mn--)
                {
                    ans+=('a'+i);
                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
