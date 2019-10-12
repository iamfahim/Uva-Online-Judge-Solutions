//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
#define mx 310
#define INF 1234567
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;
const int MOD = (int)1e9+7;
vector<int>adj[305];
int v;
int color[305];
bool is_bipartite(int s)
{
for(int i=1;i<=v;i++)
{
    color[i]=-1;
}
queue<int>Q;
Q.push(s);
color[s]=1;//Set SRC as color 1
while(!Q.empty())
{
    int u=Q.front();
    //cout<<u<<endl;
    Q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(color[v]==-1)
        {
            color[v]=1-color[u];
            Q.push(v);
        }

        else if(color[v]==color[u])
           {
            return false;
           }
           //cout<<color[u]<<endl;
    }
}
return true;
}
void CLR()
{
    int s=305;
    for(int i=0;i<s;i++)
    {
        adj[i].clear();
    }
}
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    while(cin>>v)
    {
        if(v==0)break;
        int a,b;
        CLR();
        while(cin>>a>>b)
        {
            if(a==0 && b==0)break;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(is_bipartite(1))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
