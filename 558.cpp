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
#define mx 2500
int main ()
{
   IOS
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","wt",stdout);
   int t;
   cin>>t;
   while(t--){
   int n, e;
   int ua[mx], va[mx], wa[mx];
   cin >> n >> e;
   int d[mx];
      for(int i=0;i<n;i++)
      {
          d[i]=INT_MAX;
      }

   d[0] = 0;
   for (int i = 0; i < e; i++) {
      cin >> ua[i] >> va[i] >> wa[i];
   }
   int neg_cycle = false;
   for (int step = 0; step < n; step++) {
      int update = false;
      for (int i = 0; i < e; i++) {
         int u = ua[i]; int v = va[i];
         if (d[v] > d[u] + wa[i]) {
            d[v] = d[u] + wa[i];
            update = true;
            if (step == n-1) neg_cycle = true;
         }
      }
      if (update == false) break;
   }
   if (neg_cycle == false ) {
      cout<<"not possible"<<endl;
   }
   else cout <<"possible"<< endl;
   }
   return 0;
}
