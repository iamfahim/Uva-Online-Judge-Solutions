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
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","wt",stdout);
    int sr,sc,dr,dc;
    int ans=0;

    while(cin>>sr>>sc>>dr>>dc)
    {
        if(sr==0 && sc==0 && dr==0 && dc==0)break;
        vector<pair<int,int> >pr;
        pr.push_back(make_pair(sr,sc));
        pr.push_back(make_pair(dr,dc));
        sort(pr.begin(),pr.end());
        ans=0;
        sr=pr[0].first;
        sc=pr[0].second;
        dr=pr[1].first;
        dc=pr[1].second;
        if((dr==sr)&& (dc==sc))
        {
            ans=0;
        }
        else if(dr==sr)
        {
            ans=abs(dc-sc);
        }
        else if(dc==sc)
        {
            if(((sr+sc)%2==0 && (dr+dc)%2!=0))ans=abs(dr-sr)*2-1;
            else if((sr+sc)%2!=0 && (dr+dc)%2==0)ans=abs(dr-sr)*2+1;
            else ans=abs(dr-sr)*2;
        }
        else if(pr[0].second>pr[1].second)
        {
            bool ok=false;
            if(((sr+sc)%2)!=0)
            {
                ans++;
                int nextr=dr;
                sc--;
                int nextc=sc+1-abs(dr-sr);
                if(nextc<=0)sc+=2;
                nextc=sc+1-abs(dr-sr);
                //cout<<nextr<<" "<<nextc<<endl;
                ans+=abs(nextr-sr)+abs(sc-nextc);
                if(nextc>dc)
                {
                    ans+=(nextc-dc);
                    ok=true;
                }
                if(((dr+dc)%2)!=0) {}
                else if(!ok) ans++;
                //check
                //cout<<ans<<endl;
            }
            else
            {
                int nextr=dr;
                int nextc=sc+1-abs(dr-sr);
                //cout<<nextr<<" "<<nextc<<endl;
                ans=abs(nextr-sr)+abs(sc-nextc);
                if(nextc>dc)
                {
                    ans+=(nextc-dc);
                    ok=true;
                }
                if(((dr+dc)%2!=0)) {}
                else if(!ok) ans++;
            }
        }
        else
        {
            // cout<<"Fahim42"<<endl;
            bool ok=false;
            if(((sr+sc)%2)!=0)
            {
                ans++;
                int nextr=dr;
                sc++;
                int nextc=abs(dr-sr)+sc-1;
                //cout<<nextr<<" "<<nextc<<endl;
                ans+=abs(nextr-sr)+abs(nextc-sc);
                if(nextc<dc)
                {
                    ans+=(dc-nextc);
                    ok=true;
                }
                if(((dr+dc)%2!=0)) {}
                else if(!ok) ans++;
                //check
                //cout<<ans<<endl;
            }
            else
            {
                int nextr=dr;
                int nextc=abs(dr-sr)+sc-1;
                //cout<<nextr<<" "<<nextc<<endl;
                ans=abs(nextr-sr)+abs(nextc-sc);
                if(nextc<dc)
                {
                    ans+=(dc-nextc);
                    ok=true;
                }
                if(((dr+dc)%2!=0)) {}
                else if(!ok) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
