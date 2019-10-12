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
#define MAXC 102
string  A,B;
int lenA,lenB;
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];
int calcLCS(int i,int j)
{
	if(A[i]=='\0' || B[j]=='\0') return 0;
	if(visited[i][j])return dp[i][j];

	int ans=0;
	if(A[i]==B[j]) ans=1+calcLCS(i+1,j+1);
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		ans=max(val1,val2);
	}
	visited[i][j]=1;
	dp[i][j]=ans;
	return dp[i][j];
}
int  main()
{
    IOS
    int Case=0;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    while(getline(cin,A))
    {
       if(A=="#")break;
       getline(cin,B);
       int ans=calcLCS(0,0);
       cout<<"Case #"<<++Case<<": you can visit at most "<<ans<<" cities."<<endl;
       for(int i=0;i<MAXC;i++)
       {
           for(int j=0;j<MAXC;j++)
           {
               visited[i][j]=dp[i][j]=0;
           }
       }
    }
    return 0;
}
