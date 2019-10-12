//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming
const int MOD = (int)1e9+7;
#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1
vi S, visited;                                    // additional global variables
int numSCC;
vector<vii> AdjList;
vi dfs_num;
vi dfs_low;
int dfsNumberCounter;
map<string,int>mp1;
map<int,string>mp2;
void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
    S.push_back(u);           // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            tarjanSCC(v.first);
        if (visited[v.first])                                // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }

    if (dfs_low[u] == dfs_num[u])           // if this is a root (start) of an SCC
    {
      //  printf("SCC %d:", ++numSCC);            // this part is done after recursion
        while (1)
        {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            //printf(" %d", v);
            cout<<mp2[v+1];
            if (u == v) break;
            else{
                cout<<", ";
            }
        }
       cout<<endl;
    }
}
int  main()
{
    IOS
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int V,M;
    int Case=0;
    while(cin>>V>>M){
    if(V==0 && M==0)break;
    cin.ignore();
    AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
    dfs_num.assign(V, DFS_WHITE);
    dfs_low.assign(V, 0);
    visited.assign(V, 0);
    mp1.clear();
    mp2.clear();
    int nd=1;
    for(int i=0; i<M; i++)
    {
        string  u,v;
        cin>>u>>v;
        if(mp1[u]==false)
        {
            mp1[u]=nd;
            mp2[nd]=u;
            nd++;
        }
        if(mp1[v]==false)
        {
            mp1[v]=nd;
            mp2[nd]=v;
            nd++;
        }
        AdjList[mp1[u]-1].push_back(ii(mp1[v]-1,0));
    }
    dfsNumberCounter = numSCC = 0;
    cout<<"Calling circles for data set "<<++Case<<":"<<endl;
    for (int i = 0; i < V; i++)
    {
        if (dfs_num[i] == DFS_WHITE)
        {
            tarjanSCC(i);
        }
    }
    }
    return 0;
}

