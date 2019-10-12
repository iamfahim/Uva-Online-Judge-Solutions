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
#define max_size 100
int Count;
int row,column;
char ch1,ch2;
int flag[max_size][max_size]={0};
char grid[max_size][max_size];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void floodfill(int i,int j)
{
    if(j<0)j=column-1;
    if(j>=column)j=0;
    if(i<0 || i>=row )
    {
        return ;
    }
    if((grid[i][j]==ch1 && flag[i][j]==0))
    {
        Count++;
        flag[i][j]=1;
        for(int m=0;m<4;m++)
        {
            int x=i+fx[m];
            int y=j+fy[m];
            floodfill(x,y);
        }
    }
}
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    while(cin>>row>>column)
    {
        cin.ignore();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                grid[i][j]='\0';
                flag[i][j]=0;
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                cin>>grid[i][j];
            }
        }
         Count=0;
        int x,y;
        cin>>x>>y;
        ch1=grid[x][y];
        int ans=0;
        floodfill(x,y);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                    if(flag[i][j]==0 && grid[i][j]==ch1){

                        Count=0;
                        floodfill(i,j);
                        ans=max(ans,Count);
                    }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
