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
int  main()
{
    //IOS
    //freopen("input.txt","r",stdin);
   //freopen("output.txt","wt",stdout);
    ll a,b,c;
    while(cin>>a>>b>>c)
    {
        ll para=a+b+c;
        double s=((para)*(1.0))/2;
       // cout<<para<<" "<<s<<endl;
        double area=sqrt(s*(s-a)*(s-b)*(s-c)*1.0);
        double r2=(2*area)/(para*1.0);
        double R=(a*b*c*1.0)/sqrt(para*(b+c-a)*(c+a-b)*(a+b-c));
        double cc=PI*(r2)*(r2);
        double bb=area-cc;
        double barea=PI*(R)*(R);
        //cout<<aa<<" "<<" "<<cc<<endl;
        printf("%.4f %.4f %.4f\n",(barea-area),bb,cc);
    }
    return 0;
}
