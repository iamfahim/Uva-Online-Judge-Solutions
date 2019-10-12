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
#define mx 100005
int visited[mx];
vector<int>g[mx];
int indgree[mx]= {0};
void dfs(int s)
{
    if(visited[s])return;
    visited[s]=1;
    for(int i=0; i<g[s].size(); i++)
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
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<=n; i++)
        {
            g[i].clear();
            visited[i]=0;
            indgree[i]=0;
        }
        int a,b;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
        }
       vector<int>tam;
        int ans=0;
        int aa=0;
        for(int i=1;i<=n;i++){
            if(!visited[i])
            {
                dfs(i);
                tam.push_back(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
           visited[i]=0;
        }
        for(int i=tam.size()-1;i>=0;i--){
            int u=tam[i];
            if(!visited[u])
            {
                dfs(u);
            aa++;
            }
        }
        cout<<aa<<endl;
    }
    return 0;
}
