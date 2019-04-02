//if you you don't know about multisource_bfs go check some tutorials
//simple bfs get TLE
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define F first
#define S second
#define MP make_pair
#define PB push_back
typedef long long ll;
const ll oo = 1e13;
const ll N = 1e5;
int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1};
int n,m,t,g[200][200];
string ch;
int dist[200][200];
int vis[200][200];
set<pair<int,pair<int,int>>> s;
pair<pair<int,int>,int> u;
set<pair<int,pair<int,int>>>::iterator itr;

void MS_dfs(pair<int,int> start){
    int i=start.F,j=start.S;
    for(int cmp=0;cmp<4;cmp++){
        int x=i+dx[cmp],y=j+dy[cmp];
        if(dist[i][j]+1<dist[x][y]){
            itr=s.find({dist[x][y],{x,y}});
            s.erase(itr);
            dist[x][y]=dist[i][j]+1;
            s.insert({dist[x][y],{x,y}});
        }
    }

    if(s.size()==0)
        return;
    itr=s.begin();
    pair<int,int> nxt=itr->S;
    s.erase(itr);
    MS_dfs(nxt);
}

int main() {_
cin >> t;
while(t--){
 mem(dist,0);
 mem(vis,0);
 cin >> n >> m;
 for(int i=0;i<n;i++){
        cin >> ch;
        for(int j=0;j<ch.length();j++){
            g[i][j]=ch[j]-'0';
            if(g[i][j]==1)
                dist[i][j]=0,s.insert({0,{i,j}});
            else
                dist[i][j]=oo,s.insert({oo,{i,j}});
        }
 }
 itr=s.begin();
 pair<int,int> start=itr->S;
 MS_dfs(start);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout << dist[i][j] << " " ;
    }
    cout << endl ;
}
}

}
