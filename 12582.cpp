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
    int t;
    int Case=0;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        cin>>s;
        set<char>st;
        map<char,int>mp;
        stack<char>sckt;
        sckt.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
           // cout<<s[i]<<endl;
            char ch=s[i];
            char ch1=sckt.top();
            if(ch1==ch)
            {
                sckt.pop();
                if(sckt.empty())break;
                else{
                char ch3=sckt.top();
                st.insert(ch3);
                st.insert(ch);
                mp[ch3]++;
                mp[ch]++;
                }
            }
            else{
                sckt.push(ch);
            }
        }
        //cout<<"Faim"<<endl;
        cout<<"Case "<<++Case<<endl;
        for(auto it:st)
        {
            cout<<it<<" = "<<mp[it]<<endl;
        }

    }
    return 0;
}
