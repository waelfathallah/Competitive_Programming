//simpl bfs starting from exit

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
int n,m;
char g[1001][1001];
pair<int ,int> start,fin;
queue<pair<pair<int,int>,int>> q;
int vis[1001][1001];
int cost[1001][1001];
bool verif(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && g[x][y]!='T' ;
}

void bfs(int x,int y){
    while(!q.empty()) q.pop();
    q.push({{x,y},0});
    while(!q.empty()){
        int c=q.front().S;
        x=q.front().F.F;
        y=q.front().F.S;
        q.pop();
        cost[x][y]=c;

        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(verif(nx,ny) && !vis[nx][ny]){
                q.push({{nx,ny},c+1});
                vis[nx][ny]=1;
            }
        }
    }
}

int main() {_
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
            if(g[i][j]=='S')
                start={i,j};
            if(g[i][j]=='E')
                fin={i,j};
        }
    }
    bfs(fin.F,fin.S);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cost[i][j]<=cost[start.F][start.S] && cost[i][j]!=0 && g[i][j]>'0' && g[i][j]<='9')
                ans+=g[i][j]-'0';
        }
    }
    cout << ans;
}
