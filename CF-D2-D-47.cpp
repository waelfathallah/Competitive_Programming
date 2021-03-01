#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define MP make_pair
#define pii pair<int,int>
#define PB push_back
#define MOD 1000000007

typedef long long ll;
const ll oo = 1e9;
const int N = 2*1e5 + 5;
const double eps = 1e-5;


int n,k,a[101],b[101];
int dp[101][2*100001];


int solve(int i ,int balance){
    if(i==n)
        return ( balance==0 ? 0 : -oo);
    int &ret=dp[i][balance];
    if(dp[i][balance]) return dp[i][balance];
    ret=-oo;

    ret=max(ret,max(solve(i+1,balance),a[i]+solve(i+1,balance+a[i]-k*b[i])));

    return ret;

}

int main() {_
    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }

    for(int i=0;i<n;i++){
        cin >> b[i] ;
    }

    int ans=solve(0,0);

    cout << (ans <= 0 ? -1 : ans );
}
