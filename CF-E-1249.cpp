//dynamic programming approche
#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PI;
int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };
const int oo = 2e9;
const int N = 2*1e5;

int a[N+1],b[N+1];
int dp[N+1][2];

int main() {

    int n,c;
    cin >> n >> c ;
    for(int i=1;i<n;i++){
        cin >> a[i] ;
    }

    for(int i=1;i<n;i++){
        cin >> b[i] ;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=oo;
        }
    }
    dp[0][0]=0,dp[0][1]=c;
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i][0],dp[i-1][0]+a[i]); //stair to stair
        dp[i][0]=min(dp[i][0],dp[i-1][1]+a[i]); //elev to stair
        dp[i][1]=min(dp[i][1],dp[i-1][0]+b[i]+c); //stair to elev
        dp[i][1]=min(dp[i][1],dp[i-1][1]+b[i]); //elev to elev
    }

    for(int i=0;i<n;i++){
        cout << min(dp[i][1],dp[i][0]) << " " ;
    }
    return 0;
}
