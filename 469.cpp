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
int mark[102][102];
int cmark[102][102];
int Count=0;
int row,column;
int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1};
void floodfill(int i,int j)
{
    if(i<0 || j<0 || i>=row || j>=column)
    {
        return ;
    }
    if(mark[i][j]==1 && cmark[i][j]==0)
    {
        Count++;
        cmark[i][j]=1;
        for(int m=0; m<8; m++)
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
    int t;
    string abc="";
    cin>>t;
    cin.ignore();
    getline(cin,abc);
    while(t--)
    {

        vector<string>vs;
        string s;
        while(getline(cin,s))
        {
            if(s[0]!='L' && s[0]!='W')break;
            vs.push_back(s);
        }
        int r=vs.size();
        int c=vs[0].size();
        row=r,column=c;
       // cout<<r<<" "<<c<<endl;
        for(int i=0; i<102; i++)
        {
            for(int j=0; j<102; j++)
            {
                mark[i][j]=cmark[i][j]=0;
            }
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
               // cout<<vs[i][j];
                if(vs[i][j]=='W')
                {
                    mark[i][j]=1;
                }
                if(vs[i][j]=='L')
                {
                    mark[i][j]=0;
                }
            }
           // cout<<endl;
        }
        string tam="";
        int x=0,y=0;
        //cout<<s<<endl;
        istringstream cinn(s);
            cinn>>x;
            cinn>>y;
        Count=0;
       // cout<<x<<" "<<y<<endl;
        if(mark[x-1][y-1]==0)
        {
            cout<<0<<endl;
        }
        else
        {
            floodfill(x-1,y-1);
            cout<<Count<<endl;
        }
        //check
        Count=0;
        string ss;
        while(getline(cin,ss) && ss.size()>0)
        {
            istringstream cinn(ss);
            cinn>>x;
            cinn>>y;
                Count=0;
                for(int i=0; i<102; i++)
                {
                    for(int j=0; j<102; j++)
                    {
                        cmark[i][j]=0;
                    }
                }
                if(mark[x-1][y-1]==0)
                {
                    cout<<0<<endl;
                }
                else
                {
                    floodfill(x-1,y-1);
                    cout<<Count<<endl;
                }
            }
       if(t>0)cout<<endl;

    }
return 0;
}
