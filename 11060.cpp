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
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int n,m;
    int Case=0;
    while(cin>>n)
    {
        cin.ignore();
        string s1,s2;
        map<string,int>mp;
        map<int,string>mp2;
        int indegree[102]= {0};
        vector<int>ans;
        vector<int>adj[102];
        for(int i=1; i<=n; i++)
        {
            cin>>s1;
            mp[s1]=i;
            mp2[i]=s1;
        }
        cin>>m;
        cin.ignore();
        for(int i=1; i<=m; i++)
        {
            cin>>s1>>s2;
            int u=mp[s1];
            int v=mp[s2];
            adj[u].push_back(v);
            indegree[v]++;
        }
     priority_queue<int, vector<int>, greater<int> > q;
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u=q.top();
            q.pop();
            ans.push_back(u);
            for(int i=0; i<adj[u].size(); i++)
            {
                int v=adj[u][i];
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        if(n==1){
             cout<<"Case #"<<++Case<<": Dilbert should drink beverages in this order: ";
       cout<<mp2[ans[0]]<<"."<<endl;
        }
        else{
        cout<<"Case #"<<++Case<<": Dilbert should drink beverages in this order: ";
       cout<<mp2[ans[0]]<<" ";
        for(int x=1; x<n; x++)
        {
            if(x==n-1)cout<<mp2[ans[x]];
            else cout<<mp2[ans[x]]<<" ";
        }
        cout<<"."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
