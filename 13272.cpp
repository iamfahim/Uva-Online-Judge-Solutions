//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
int ans[100005];
int mark[100005];
struct data
{
    char chr;
    int ind;
    data(char a,int b)
    {
        chr=a;
        ind=b;
    }
};
void solve(string s)
{
    int len=s.size();
    stack<data>stck;
    int cnt=0;
    bool ok1=false;
    bool ok2=false;
    bool ok3=false;

    for(int i=0; i<len; i++)
    {
        if(stck.empty() && (s[i]=='<' || s[i]=='(' || s[i]=='{' || s[i]=='['))
        {
            stck.push(data(s[i],i));
            continue;
        }
        if((s[i]=='>' || s[i]==')' || s[i]=='}' || s[i]==']') && (stck.empty()))
        {
            ok1=true;
            break;
        }
        else
        {
            data x=stck.top();
            char ch=x.chr;
            int index=x.ind;
            if(ch=='(' && s[i]==')')
            {
                mark[index]=1;
                stck.pop();
                ok3=true;
            }
            else if(ch=='{' && s[i]=='}')
            {
                mark[index]=1;
                stck.pop();
                ok3=true;
            }
            else if(ch=='[' && s[i]==']')
            {
                mark[index]=1;
                stck.pop();
            }
            else if(ch=='<' && s[i]=='>')
            {
                mark[index]=1;
                stck.pop();
                ok3=true;
            }
            else if((s[i]=='>' || s[i]==')' || s[i]=='}' || s[i]==']') && (!stck.empty()))
            {
                break;
            }
            else
            {
                stck.push(data(s[i],i));
            }
        }
    }
    if(ok1 && !ok3){}
    else{
    for(int i=len-1; i>=0; i--)
    {
        if(mark[i])
        {
            cnt++;
            ans[i]=cnt*2;
        }
    }
    }
}
int  main()
{
    IOS
   freopen("input.txt","r",stdin);
    freopen("output.txt","wt",stdout);
    int t;
    int Case=0;
    cin>>t;
    while(t--)
    {
        ms(ans,0);
        ms(mark,0);
        string s;
        cin>>s;
        solve(s);
        int ln=s.size();
        cout<<"Case "<<++Case<<":"<<endl;
        for(int i=0; i<s.size(); i++)
        {
            cout<<ans[i]<<endl;
        }
    }

    return 0;
}
