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
    int t;
    cin>>t;
    cin.ignore();
     vector<int>vs;
    while(t--)
    {
        string s;
        getline(cin,s);
        //cout<<s<<endl;
        string tam="";
        int ln=s.size();
        for(int i=0;i<ln;)
        {
                bool ok=false;
                while(s[i]>='0' && s[i]<='9' && i<ln)
                {
                    tam+=s[i];
                    i++;
                    ok=true;
                }
                if(ok){
                stringstream number(tam);
                int m=0;
                number>>m;
                //cout<<m<<endl;
                vs.push_back(m);
                tam="";
                continue;
                }
                i++;
        }
        sort(vs.begin(),vs.end());
        int gcdmx=1;

        //cout<<endl;
        for(int i=0;i<vs.size();i++)
            {
                for(int j=i+1;j<vs.size();j++)
                {
                    int tam=__gcd(vs[i],vs[j]);
                    //cout<<tam<<endl;
                    gcdmx=max(gcdmx,tam);
                }
            }
            cout<<gcdmx<<endl;
            vs.clear();
    }
    return 0;
}
