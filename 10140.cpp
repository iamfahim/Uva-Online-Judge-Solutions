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
ll prime[1000000] ;
ll data[1000000] ;
ll pl ;
void isPrime()
{
    ll l,k ;

    prime[0] = prime[1] =1 ;
    for(l=2 ; l<=1000000 ; l++)
    {
        if(!prime[l])
        {
            data[pl++] = l ;
            for(k =l*2 ; k<=1000000 ; k+=l)
            {
                prime[k] =1 ;
            }
        }
    }
}

bool primeCheck(ll n)
{
    if(n<=1000000)
    {
        if(prime[n]==0)
            return true ;
        else
            return false ;
    }
    else
    {
        int k ;
        for(k=0 ; k<pl && data[k]<=sqrt(n) ; k++)
        {
            if(n%data[k]==0)
            {
                return false ;
            }
        }
        return true ;
    }
}

int  main()
{
    //IOS
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    isPrime();
    ll  L,U;
    while(scanf("%lld %lld",&L,&U)!=EOF)
    {
        bool ok1=false,ok2=false;
        ll f=0,s=0;
        ll cx=0,cy=0,lx=0,ly=0;
        ll mx=-1,mn=100000000000;
       // cout<<INT_MAX<<endl;
       // bool ok=false;
        //cout<<primes[primes.size()-1];

        for(ll i=L;i<=U;i++)
        {
           // printf("%lld\n",i);
           //if(primeCheck(i))cout<<i<<endl;
            if(ok1==false && primeCheck(i))
            {
                //cout<<"Fahim1"<<" "<<primes[i]<<endl;
                f=i;
                ok1=true;
            }
           else if(ok2==false && primeCheck(i))
            {
                //cout<<"Fahim2 "<<primes[i]<<endl;
                s=i;
                ok2=true;
            }
            if(ok1 && ok2)
            {
                ll dif=s-f;
               if(dif<mn)
               {
                   cx=f,cy=s;
                   mn=dif;
               }
               if(dif>mx)
               {
                   lx=f,ly=s;
                   mx=dif;
               }
                ok2=false;
                f=s;
            }

        }
        //cout<<cx<<" "<<cy<<" "<<lx<<" "<<ly<<endl;
        if(cx==0 && cy==0 && lx==0 && ly==0)
        {
            printf("There are no adjacent primes.\n");
            continue;
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",cx,cy,lx,ly);
    }
    return 0;
}
