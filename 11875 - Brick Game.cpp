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
    cin>>t;
    int Case=0;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[50];
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        int mid=(n+1)/2;
        cout<<"Case "<<++Case<<": "<<arr[mid]<<endl;
    }
    return 0;
}