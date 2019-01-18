//i've just sorted the adj lists of all nodes in the order they appear in the input BFS sequence 
//then run BFS and check if it's same as the input seq 
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define mod 998244353
typedef long long ll;
const ll oo = 1e9;
const int N = 2*1e5 + 1, MOD = 1e9 + 7;
const double eps = 1e-5;

vector<vector<int>> g;
bool vis[N];
queue<int> q;
int t[N],pos[N];

bool cmp(int a,int b){
    return pos[a]<pos[b];
}

void bfs(int u){
    q.push(u);
    vis[u]=1;
    int ind=1;
    while(!q.empty()){
        int v=q.front();
        if(v!=t[ind]){
            cout << "No";
            exit(0);
        }
        ind++;
        q.pop();
        for(int i=0;i<g[v].size();i++){
            if(!vis[g[v][i]]){
                vis[g[v][i]]=1;
                q.push(g[v][i]);
            }
        }
    }
    cout << "Yes";
}

int main() {_
    int n;
    cin >> n;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    for(int i=1;i<=n;i++){
        cin >> t[i];
        pos[t[i]]=i;
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end(),cmp);
    }
    memset(vis,0,sizeof vis);
    bfs(1);
}
