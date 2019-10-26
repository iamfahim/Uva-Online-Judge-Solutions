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
int n, A[101][101], maxSubRect, subRect;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
            if (j > 0) A[i][j] += A[i][j - 1];
        }
    maxSubRect = -127*100*100;
    for (int l = 0; l < n; l++) for (int r = l; r < n; r++)
        {
            subRect = 0;
            for (int row = 0; row < n; row++)
            {

                if (l > 0) subRect += A[row][r] - A[row][l - 1];
                else       subRect += A[row][r];


                if (subRect < 0) subRect = 0;
                maxSubRect = max(maxSubRect, subRect);
            }
        }

    printf("%d\n", maxSubRect);
    return 0;
}
