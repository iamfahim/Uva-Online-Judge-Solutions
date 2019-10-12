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
string  A,B;
set<string>vs;
void solve1()
{
   int len1=A.size();
   int len2=B.size();
   for(int i=0;i<len1;i++)
   {
       for(int j=0;j<len2;)
       {
           bool ok=false;
           if(A[i]==B[j])
           {
               int point=i;
               string tm="";
               bool ok2=false;
               int point2=j;
               while(A[point]==B[j] && point<len1 && j<len2)
               {
                   tm+=A[point];
                   point++;
                   j++;
                   ok=true;
                   ok2=true;
               }
              // cout<<tm<<endl;
               if(ok2)
               {
                   vs.insert(tm);
                    point2++;
            j=point2;}
           }
           if(!ok)
           {
           j++;
           }
       }

   }
}
int  main()
{
    IOS
    int Case=0;
    string s;
    int ck=0;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    while(getline(cin,A))
    {
        if(ck!=0){
           getline(cin,A);
        }
       getline(cin,B);
       if(ck!=0)
       {
           cout<<endl;
       }
       ck++;
       solve1();
     // solve2();
       int mx_sz=-1;
       for(auto it:vs)
       {
          string ss=it;
          int ln=ss.size();
          mx_sz=max(mx_sz,ln);
       }
       for(auto it:vs)
       {
           string ss=it;
           if(mx_sz==ss.size())
           {
               cout<<ss<<endl;
           }
       }
       if(vs.size()==0)
       {
           cout<<"No common sequence."<<endl;
       }
       vs.clear();
      // cin>>s;
    }
    return 0;
}
