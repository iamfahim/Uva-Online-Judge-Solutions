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
int pi[100005];
string p="";
string s="";/*
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}*/
int  main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int n;
    while(cin>>n>>s)
    {
       set<string>substring;
       int c=0;
       string ss="";
        int len=s.size();
        map<string,int>mp;
       for(int i=0;i<len-n+1;i++)
       {
           int k=i;

           while(c!=n && i<len)
           {

               ss+=s[i];
               c++;
               i++;
           }
           substring.insert(ss);
           mp[ss]++;
               ss="";
               c=0;
               i=k;
       }
       string ans="";
       int mx=-1;
       for(auto it:substring)
       {
         // vector<int>vs= rabin_karp(it,s);
          string aa=it;
          int ln=mp[aa];
          if(ln>mx)
          {
              mx=ln;
              ans="";
              ans+=it;
              //cout<<mx<<endl;

          }
       }
       cout<<ans<<endl;

    }
    return 0;
}
