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
    while(cin>>s)
    {
        if(s==".")break;
        //cout<<s<<endl;
        int len=s.size();
        set<int>subsize;
        for(int i=1;i<=sqrt(len);i++)
        {
           if(len%i==0)
           {
               if((len/i)==i)
               {
                   subsize.insert(i);
               }
               else
               {
                   subsize.insert(len/i);
                   subsize.insert(i);
               }
           }
        }
        int ans=0;
        for(auto it:subsize)
        {
            int sz=it;
            string str=s.substr(0,sz);
            int Count=0;
            //cout<<str<<endl;
            for(int i=0;i<len-sz+1;i++)
            {
                bool ok=false;
                int j=0;
                Count=0;
                while(str[j]==s[i] && i<len)
                {
                    if(j==sz-1){
                        Count++;
                        j=0;
                        i++;
                        continue;
                    }
                    i++;
                    j++;
                }
                break;
            }
          //  cout<<str<<" "<<Count<<endl;
            if((sz*Count)==len)
            {
                ans=Count;
                break;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
