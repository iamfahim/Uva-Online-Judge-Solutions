#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define inf 1000000000
int d[mx][mx];
int par[mx];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int mark[mx][mx]={0};
int mat[mx][mx];
int n,e;
struct node
{
   int cityx,cityy,dist;
   node(int a,int b,int c)
   {
       cityx=a;
       cityy=b;
       dist=c;
   }
   bool operator< (const node& p) const
   {
       return p.dist<dist;
   }
};
void dijkstra(int srcx,int srcy,int desx,int desy)
{
    memset(d,127,sizeof d);
    priority_queue<node>q;
    d[srcx][srcy]=0;
    q.push(node(srcx,srcy,0));
    while(!q.empty())
    {
        node top=q.top();q.pop();
        int ux=top.cityx;
        int uy=top.cityy;
        mark[ux][uy]=1;
        if(ux==desx && uy==desy){
            d[ux][uy]+=mat[ux][uy];
                return  ;}
        for(int i=0;i<4;i++)
        {
            int f=ux+fx[i];
            int s=uy+fy[i];
            if(f>=1 && f<=n && s>=1 && s<=e && mark[f][s]==0)
            {
                if(d[ux][uy]+mat[ux][uy]<d[f][s])
                {
                   d[f][s]=d[ux][uy]+mat[ux][uy];
                   q.push(node(f,s,d[f][s]));
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d %d",&n,&e);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=e;j++)
        {
            mat[i][j]=mark[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=e;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    dijkstra(1,1,n,e);
    printf("%d\n",d[n][e]);
    }
    return 0;
}

