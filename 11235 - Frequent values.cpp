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
#define mx 100001
struct data{
   int left, right, mxx, left_value, right_value, maxx_value;

};
data tree[mx * 3];
int arr[mx];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].mxx = 1;
        tree[node].maxx_value=arr[b];
        tree[node].left=1;
        tree[node].right=1;
        tree[node].left_value=arr[b];
        tree[node].right_value=arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    if(tree[Left].left_value == tree[Right].left_value  ){
            tree[node].left=tree[Left].left+tree[Right].left;
            tree[node].left_value=tree[Left].left_value;
    }
    else{
        tree[node].left=tree[Left].left;
        tree[node].left_value=tree[Left].left_value;

    }
    if(tree[Left].right_value == tree[Right].right_value  ){
            tree[node].right=tree[Left].right+tree[Right].right;
            tree[node].right_value=tree[Left].right_value;
    }
    else{
        tree[node].right=tree[Right].right;
        tree[node].right_value=tree[Right].right_value;
    }
    if(tree[Left].mxx>tree[Right].mxx){
        tree[node].mxx=tree[Left].mxx;
        tree[node].maxx_value=tree[Left].maxx_value;
    }
    else{
        tree[node].mxx=tree[Right].mxx;
        tree[node].maxx_value=tree[Right].maxx_value;
    }
    int t_max=-1;
    if(tree[Left].right_value == tree[Right].left_value ){
        t_max=tree[Left].right+tree[Right].left;
        if(t_max > tree[node].mxx ){
            tree[node].mxx=t_max;
            tree[node].maxx_value=tree[Left].right_value;
        }
    }
}
data query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b){
        data tp;
        tp.mxx=-5;
        return tp;
    }
    if (b >= i && e <= j){
        return tree[node];
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    data p_left = query(Left, b, mid, i, j);
    data p_right = query(Right, mid + 1, e, i, j);
    if(p_left.mxx==-5 && p_right.mxx!= -5)return p_right;
    if(p_right.mxx==-5 && p_left.mxx != -5)return p_left;
    data tam;
    if(p_left.left_value == p_right.left_value  ){
            tam.left=p_left.left+p_right.left;
            tam.left_value=p_left.left_value;
    }
    else{
        tam.left=p_left.left;
        tam.left_value=p_left.left_value;
    }
    if(p_left.right_value == p_right.right_value  ){
            tam.right=p_left.right+p_right.right;
            tam.right_value=p_left.right_value;
    }
    else{
        tam.right=p_right.right;
        tam.right_value=p_right.right_value;
    }
    if(p_left.mxx>p_right.mxx){
        tam.mxx=p_left.mxx;
        tam.maxx_value=p_left.maxx_value;
    }
    else{
        tam.mxx=p_right.mxx;
        tam.maxx_value=p_right.maxx_value;
    }
    int t_max=-1;
    if(p_left.right_value == p_right.left_value ){
        t_max=p_left.right+p_right.left;
        if(t_max > tam.mxx ){
            tam.mxx=t_max;
            tam.maxx_value=p_left.right_value;
        }
    }
    return tam;
}
int  main()
{
    int n,q;
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        if(n==0)break;
         for(int i=1;i<=n;i++){
             scanf("%d",&arr[i]);
    }
        init(1,1,n);
         for(int i=1;i<=q;i++)
         {
             int x,y;
             scanf("%d %d",&x,&y);
             data ANS=query(1, 1, n, x, y);
             printf("%d\n",ANS.mxx);
         }
    }
    return 0;
}
