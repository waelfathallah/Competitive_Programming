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
const int N = 1e5 + 5;
const double eps = 1e-8;

vector<vector<pii>> g;
bool vis[N];
int max_cost;

ll furthest(int u,int prev){
    ll ans=0;

    for(int i=0;i<g[u].size();i++){
        int nxt=g[u][i].F;
        int cost=g[u][i].S;
        if(nxt!=prev){
            ans=max(ans,cost+furthest(nxt,u));
        }
    }

    return ans;
}

int main(){_
    int n;
    cin >> n ;
    g.clear();
    g.resize(n+1);

    ll res=0;
    for(int i=0;i<n-1;i++){
        int x,y,z;
        cin >> x >> y >> z ;
        g[x].PB({y,z});
        g[y].PB({x,z});
        res+=2*z;
    }

    cout << res-furthest(1,-1);
}
