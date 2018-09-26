// bfs
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
const ll oo = 1e9;
const ll N = 1e5+1;
map<pair<int,int>,int> cost;
queue<pair<int,int>> q;
set<pair<int,int>> pts;
int xi,xf,yi,yf,r,a,b,n;
int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int main() {_
cin >> xi >> yi >> xf >> yf >> n;
for(int i=0;i<n;i++){
    cin >> r >> a >> b;
    for(int i=a;i<=b;i++){
        pts.insert({r,i});
    }
}
q.push({xi,yi});
cost[{xi,yi}]=0;
while(!q.empty()){
    int r=q.front().F;
    int c=q.front().S;
    q.pop();
    for(int i=0;i<8;i++){
        int nx=r+dx[i];
        int ny=c+dy[i];
        if(pts.find({nx,ny})!=pts.end() && cost[{nx,ny}]==0){
            q.push({nx,ny});
            cost[{nx,ny}]=cost[{r,c}]+1;
        }
        if(nx==xf && ny==yf){
            cout << cost[{nx,ny}] ;
            return 0;
        }
    }
}
cout << -1 ;
}
