#include<bits/stdc++.h>
using namespace std;
#define mx 1005
struct node
{
    int u, v, w;
    node (int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator < (const node& p) const
    {
        return w < p.w;   //if present nodes cost is greater,
    }
};
vector<int>ans;                                                       //it means present nodes is greater..
vector <node > edge;
int par[mx];
int find(int u)
{
    if(u != par[u]) par[u] = find(par[u]);
    return par[u];
}
int mst (int n)
{
    sort (edge.begin(), edge.end());
    for (int i = 0; i <n; i++) par[i] = i; //Creating disjoint set as node numbers..
    int Count = 0, s = 0;
    for (int i = 0; i < (int ) edge.size(); i++)
    {
        int u = find (edge[i].u);
        int v = find (edge[i].v);
        if(u==v)
        {
            ans.push_back(edge[i].w);
        }
        else    //checking connection & cycle..
        {
            par[u] = v;
            Count++;
            s += edge[i].w; //adding minimum edges value..
           // if (Count == n-1) break; //node number of spanning tree is n-1..
        }
    }
    return s;
}
int main ()
{

    int n, e;
    while(scanf("%d %d",&n,&e)!=EOF)
    {
        if(n==0 && e==0)break;
        for (int i = 0; i < e; i++ )
        {
            int u, v, w;
            scanf("%d %d %d",&u,&v,&w);
            edge.push_back (node (u, v, w)); //Entering graph as Edge..
        }
        // cout << mst (n) << endl; //sum of edges of minimum spanning tree..
        mst(n);
        int len=ans.size();
        if(len==0)
        {
            cout<<"forest"<<endl;
        }
        else
        {
            for(int i=0; i<len; i++)
            {

                printf("%d",ans[i]);
                if(i<len-1)
                {
                    printf(" ");
                }
            }
          printf("\n");
        }
        edge.clear ();
        ans.clear();
    }
}
