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
   // freopen("output.txt","wt",stdout);
    map<char,char>mp;
    mp['=']='-';
    mp['-']='0';
    mp['0']='9';
    mp['9']='8';
    mp['8']='7';
    mp['7']='6';
    mp['6']='5';
    mp['5']='4';
    mp['4']='3';
    mp['3']='2';
    mp['2']='1';
    mp['1']='`';
    mp['\\']=']';
    mp[']']='[';
    mp['[']='P';
    mp['P']='O';
    mp['O']='I';
    mp['I']='U';
    mp['U']='Y';
    mp['Y']='T';
    mp['T']='R';
    mp['R']='E';
    mp['E']='W';
    mp['W']='Q';
    mp['\'']=';';
    mp[';']='L';
    mp['L']='K';
    mp['K']='J';
    mp['J']='H';
    mp['H']='G';
    mp['G']='F';
    mp['F']='D';
    mp['D']='S';
    mp['S']='A';
    mp['/']='.';
    mp['.']=',';
    mp[',']='M';
    mp['M']='N';
    mp['N']='B';
    mp['B']='V';
    mp['V']='C';
    mp['C']='X';
    mp['X']='Z';
    mp[' ']=' ';
    string s;
    while(
        getline(cin,s))
    {
        for(int i=0; i<s.size(); i++)
        {
            cout<<mp[s[i]];
        }
        cout<<endl;
    }


    return 0;
}
