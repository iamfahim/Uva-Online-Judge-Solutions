//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
using namespace std;
#define mx 50005
vector<int>g[mx];
int visited[mx];
int ctn=0;
int MN=mx;
void dfs(int s)
{
    if(visited[s])return;
    visited[s]=1;
    ctn++;
    //cout<<s<<" ";
    for(int i=0;i<g[s].size();i++)
    {
        int u=g[s][i];
        if(!visited[u])
        {
            dfs(u);
        }
    }
}
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    int Case=0;
    while(t--)
    {
        int N;
        cin>>N;
        int a,b;
         for(int i=0;i<=N;i++)
        {
            visited[i]=0;
            g[i].clear();
        }
        for(int i=1;i<=N;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
        }
        vector<int>tam;
        for(int i=1;i<=N;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                tam.push_back(i);
            }
        }
        for(int i=1;i<=N;i++)
        {
            visited[i]=0;
        }
        //cout<<endl;
        vector<int>ans;
        int st=0;
        MN=mx;
        for(int i=tam.size()-1;i>=0;i--)
        {
            int u=tam[i];
            ctn=0;
            if(!visited[u])
            {
                dfs(u);
              //  cout<<endl;
             //   cout<<u<<" "<<ctn<<" "<<u<<endl;
                if(ctn>=st)
                {
                    st=ctn;
                    MN=min(u,MN);
                }
                ms(visited,0);
            }
        }
        cout<<"Case "<<++Case<<": "<<MN<<endl;
    }
    return 0;
}
