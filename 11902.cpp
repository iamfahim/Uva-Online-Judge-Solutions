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
int mat[102][102];
int cmat[102][102];
int rmat[102][102];
int visited[102]= {0};
int cvisited[102]= {0};
int n;
void dfs(int s)
{
    if(visited[s])return;
    visited[s]=1;
    for(int i=0; i<n; i++)
    {
        if(mat[s][i]){
          dfs(i);
        }
    }
}
void cdfs(int s)
{
    if(cvisited[s])return;
    cvisited[s]=1;
    for(int i=0;i<n;i++)
    {
        if(cmat[s][i])
        {
            cdfs(i);
        }
    }
}
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);

   // freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    int Case=0;
    while(t--)
    {
        for(int i=0; i<102; i++)
        {
            for(int j=0; j<102; j++)
            {
                mat[i][j]=0;
                cmat[i][j]=0;
                rmat[i][j]=0;
            }
        }
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
                cmat[i][j]=mat[i][j];
            }
        }
        for(int i=0; i<102; i++)
        {
            visited[i]=0;
        }
        dfs(0);
        vector<int>node;
        for(int i=0; i<102; i++)
        {
            if(visited[i])
            {
                rmat[0][i]=1;
                rmat[i][i]=1;
                node.push_back(i);
            }
        }
        for(int i=1;i<node.size();i++)
        {
            int u=node[i];
            vector<int>tam;
            for(int j=0;j<n;j++){
                if(mat[u][j] && visited[j]){
                    tam.push_back(j);
                }
                cmat[u][j]=0;
            }
            if(tam.size()==0)
            {
                for(int j=0;j<n;j++){cmat[u][j]=mat[u][j];}
                continue;
            }
            else {
                for(int j=0;j<102;j++)
                {
                    cvisited[j]=0;
                }

                cdfs(0);
                for(int j=0;j<n;j++)
                {
                    if(!cvisited[j] && visited[j])
                    {
                        rmat[u][j]=1;
                    }
                }
                /*for(int j=0;j<tam.size();j++)
                {
                    if(!cvisited[tam[j]])
                    {
                        cout<<"u "<<u<<" "<<tam[j]<<endl;
                        rmat[u][tam[j]]=1;
                    }
                }*/
                for(int j=0;j<n;j++)
                {
                    cmat[u][j]=mat[u][j];
                }
            }

        }
        cout<<"Case "<<++Case<<":"<<endl;
       for(int i=0;i<(2*n)+1;i++)
       {
           if(i%2==0)
           {
               for(int j=0;j<(2*n)+1;j++)
               {
                   if(j==0 || j==((2*n)))cout<<"+";
                   else cout<<"-";
               }
               cout<<endl;
           }
           else{
             for(int j=0;j<(2*n)+1;j++)
             {
                 if(j%2==0)
                 {
                     cout<<"|";
                 }
                 else {
                    if(rmat[i/2][j/2])cout<<"Y";
                    else cout<<"N";
                 }
             }
             cout<<endl;
           }
       }
    }
        return 0;
    }
