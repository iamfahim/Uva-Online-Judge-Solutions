//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1
vector<vii> AdjList;
vi dfs_num;
vector<pair<int,int>>ans;
int numCC;
vi dfs_low;
vi dfs_parent;
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
void articulationPointAndBridge(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
        {
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v.first);

            if (dfs_low[v.first] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[v.first] > dfs_num[u])
                ans.push_back(make_pair(min(u,v.first),max(u,v.first)));
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
        else if (v.first != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
}
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","wt",stdout);
    int V;
    while(cin>>V)
    {
        int cnt=0;
        if(V==0)
        {
            break;
        }
        else
        {
            AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
            string s;
            cin.ignore();
            while(getline(cin,s))
            {
                if(s[0]=='0')break;
                vector<int>tam;
                int len=s.size();
                for(int i=0; i<len;)
                {
                    int tt=0;
                    bool ok=false;
                    while(s[i]>='0' && s[i]<='9' && i<len)
                    {
                        int ttt=s[i]-'0';
                        tt=(tt*10)+ttt;
                        i++;
                        ok=true;
                    }
                    if(ok)
                    {
                        tam.push_back(tt);
                    }
                    else
                    {
                        i++;
                    }
                }
                int u=tam[0];
                for(int j=1; j<tam.size(); j++)
                {
                    AdjList[u-1].push_back(ii(tam[j]-1, 0));
                    AdjList[tam[j]-1].push_back(ii(u-1, 0));
                }
            }
            dfsNumberCounter = 0;
            dfs_num.assign(V, DFS_WHITE);
            dfs_low.assign(V, 0);
            dfs_parent.assign(V, -1);
            articulation_vertex.assign(V, 0);
            for (int i = 0; i < V; i++)
            {
                if (dfs_num[i] == DFS_WHITE)
                {
                    dfsRoot = i;
                    rootChildren = 0;
                    articulationPointAndBridge(i);
                    articulation_vertex[dfsRoot] = (rootChildren > 1);
                }
            }
            for (int i = 0; i < V; i++)
            {
                if (articulation_vertex[i])cnt++;
            }
        }
        cout<<cnt<<endl;
        ans.clear();
    }
    return 0;
}

