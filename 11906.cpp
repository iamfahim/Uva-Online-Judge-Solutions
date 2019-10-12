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
#define pii pair<int,int>
const int MOD = (int)1e9+7;
#define max_size 105
int Count;
int row,column,m,n;
int flag[max_size][max_size]= {0};
int grid[max_size][max_size]= {0};
int mat[max_size][max_size]= {0};
int fx[]= {-1,+1,-1,+1,-1,+1,-1,+1};
int fy[]= {+1,+1,-1,-1,+1,+1,-1,-1};
void bfs(int i,int j)
{
    queue<pii>q;
    q.push(pii(i,j));
    grid[i][j]=1;
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        i=top.first;
        j=top.second;
         set<pii>st;
        if(m==n)
        {

            for(int p=0; p<4; p++)
            {

                int x=i+((fx[p])*m);
                int y=j+((fy[p])*n);

                //   printf("%d %d\n",x,y);
                if(x>=0 && x<row && y>=0 && y<column && flag[x][y]==0 && grid[x][y]==0)
                {
                    grid[x][y]=1;
                   // mat[i][j]++;
                   st.insert(pii(x,y));
                    q.push(pii(x,y));
                }
                else if(x>=0 && x<row && y>=0 && y<column && flag[x][y]==0)
                {
                    //mat[i][j]++;
                    st.insert(pii(x,y));
                }
            }
        }
        else
        {

            for(int p=0; p<8; p++)
            {

                if(p<4)
                {
                    int x=i+((fx[p])*m);
                    int y=j+((fy[p])*n);
                    //   printf("%d %d\n",x,y);
                    if(x>=0 && x<row && y>=0 && y<column && flag[x][y]==0 && grid[x][y]==0)
                    {
                        grid[x][y]=1;
                        //mat[i][j]++;
                        st.insert(pii(x,y));
                        q.push(pii(x,y));
                    }
                    else if(x>=0 && x<row && y>=0 && y<column && flag[x][y]==0)
                    {
                        st.insert(pii(x,y));
                        //mat[i][j]++;
                    }
                }
                else
                {
                    int x=i+((fx[p])*n);
                    int y=j+((fy[p])*m);
                    // printf("%d %d \n",x,y);
                    if(x>=0 && x<row && y>=0 && y<column && flag[x][y]==0 && grid[x][y]==0)
                    {
                         st.insert(pii(x,y));
                        grid[x][y]=1;
                        //mat[i][j]++;
                        q.push(pii(x,y));
                    }
                    else if(x>=0 && x<row && y>=0 && y<column && flag[x][y]==0)
                    {
                         st.insert(pii(x,y));
                        //mat[i][j]++;
                    }
                }
            }
        }

        mat[i][j]+=st.size();
        }
    }
int  main()
{
    IOS
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    int Case=0;
    while(t--)
    {
        int w,x,y;
        cin>>row>>column>>m>>n;
        cin>>w;
        ms(flag,0);
        for(int i=1; i<=w; i++)
        {
            cin>>x>>y;
            flag[x][y]=1;
        }
        ms(mat,0);
        ms(grid,0);
        bfs(0,0);
        int even=0,odd=0;
        for(int j=0; j<row; j++)
        {
            for(int k=0; k<column; k++)
            {
                //cout<<mat[j][k]<<" ";
                if( flag[j][k]==0 && mat[j][k]!=0)
                {

                    if(mat[j][k]%2==0)even++;
                    else odd++;
                }
            }
            //cout<<endl;
        }
        if(even ==0 && odd==0)
        {
         cout<<"Case "<<++Case<<": "<<1<<" "<<0<<endl;
         continue;
        }
        cout<<"Case "<<++Case<<": "<<even<<" "<<odd<<endl;

    }
    return 0;
}
