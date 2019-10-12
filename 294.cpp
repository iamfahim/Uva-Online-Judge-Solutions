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
ll _sieve_size;
bitset<10000010> bs;
vi primes;
void sieve(ll upperbound)            // create list of primes in [0..upperbound]
{
    _sieve_size = upperbound + 1;                   // add 1 to include upperbound
    bs.set();                                                 // set all bits to 1
    bs[0] = bs[1] = 0;                                     // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);  // also add this vector containing list of primes
        }
}
ll numDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;                                             // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);                              // according to the formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;             // (last factor has pow = 1, we add 1 to it)
  return ans;
}
int  main()
{
    IOS
    sieve(10000000);
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll d,p,H,L;
        scanf("%lld %lld",&L,&H);
        ll mx=0;
        for(ll i=L;i<=H;i++)
        {
          ll tam=numDiv(i);
          if(tam>mx){
            p=i;
            mx=tam;
          }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,H,p,mx);
    }
    return 0;
}
