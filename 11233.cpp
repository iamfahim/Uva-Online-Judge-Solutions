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
    int L,N;
    while(cin>>L>>N)
    {
        map<string,string>mp;
        map<string,int>mpp;
        vector<string>vs;
        string s1,s2;
        for(int i=1; i<=L; i++)
        {
            cin>>s1>>s2;
            mp[s1]=s2;
            mpp[s1]=1;
        }
        string s3;
        for(int i=1; i<=N; i++)
        {
            cin>>s3;
            vs.push_back(s3);
        }
        vector<string>ans;
        for(int i=0; i<N; i++)
        {
            string tam="";
            tam+=vs[i];
            if(mpp[tam])
            {
                ans.push_back(mp[tam]);
            }
            else
            {
                int len=tam.size();
                if(tam[len-1]=='y' && tam[len-2]!='a'&& tam[len-2]!='e'&& tam[len-2]!='i'&& tam[len-2]!='o'&& tam[len-2]!='u' && len>=2)
                {
                    string tam1="";
                    for(int i=0; i<tam.size()-1; i++)
                    {
                        tam1+=tam[i];
                    }
                    tam1+="ies";
                    ans.push_back(tam1);
                }
                else if(tam[len-1]=='o' || tam[len-1]=='s' || tam[len-1]=='x' || (len>=2 && tam[len-2]=='c' && tam[len-1]=='h')||(len>=2 && tam[len-2]=='s' && tam[len-1]=='h'))
                {
                    string tam1="";
                    tam1+=tam;
                    tam1+="es";
                    ans.push_back(tam1);
                }
                else
                {
                    string tam1="";
                    tam1+=tam;
                    tam1+="s";
                    ans.push_back(tam1);
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
