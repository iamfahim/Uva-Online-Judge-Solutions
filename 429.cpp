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
#define Max_size 210
vector<int>Graph[Max_size];
int dest,distan;
void bfs(int source)
{
    queue<int>Q;
    Q.push(source);
    int visited[Max_size]={0},level[Max_size];
    int parent[Max_size];
    visited[source]=1;
    level[source]=0;
    bool ok=false;
    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0;i<Graph[u].size();i++)
        {
            int v=Graph[u][i];

            if(!visited[v])
            {
                level[v]=level[u]+1;
                parent[v]=u;
                visited[v]=1;
                if(v==dest)
            {
                ok=true;
                distan=level[dest];
                break;
            }
                Q.push(v);
            }
        }
        Q.pop();
        if(ok)break;
    }
}
int  main()
{
    IOS
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        vector<string>node;
        map<string,int>mp;
        int ctn=1;
        set<string>st;
        while(cin>>str)
        {
            if(str=="*")break;
            node.push_back(str);
            st.insert(str);
            mp[str]=ctn;
            ctn++;
        }
        for(auto it:st)
        {
            string ss=it;
            for(int i=0;i<node.size();i++)
            {
                if(ss!=node[i])
                {
                    int chk=0;
                    int k=0;
                    for(int j=0;j<node[i].size();j++){
                       if(node[i][j]!=ss[k++])
                       {
                           chk++;
                       }
                    }
                    if(chk==1)
                    {
                        Graph[mp[ss]].push_back(mp[node[i]]);
                        Graph[mp[node[i]]].push_back(mp[ss]);
                    }
                }
            }
        }
        string S;
        cin.ignore();
        string a,b;
        while(getline(cin,S))
        {
           // cout<<S<<endl;
            if(S.size()==0)break;
            vector<string>yn;
            for(int i=0;i<S.size();)
            {
                bool ok2=false;
                string sss="";
                while(((S[i]>='A' && S[i]<='Z')||(S[i]>='a' && S[i]<='z') || (S[i]>='0' && S[i]<='9')) && i<S.size()){

                    sss+=S[i];
                    i++;
                    ok2=true;
                }
                if(ok2)
                {
                  yn.push_back(sss);
                }
                else
                {
                    i++;
                }
            }
          //  cout<<yn[0]<<" "<<yn[1]<<endl;

            int u=mp[yn[0]];
            int v=mp[yn[1]];
            dest=v;
            distan=0;
            bfs(u);
            //cout<<a<<" "<<b<<" "<<distan<<endl;
            cout<<yn[0]<<" "<<yn[1]<<" "<<distan<<endl;
        }
        if(t>=1){
        cout<<endl;
        }
       // cout<<"Fahim"<<endl;
        for(int i=0;i<Max_size;i++)
        {
            Graph[i].clear();
        }
    }
    return 0;
}
