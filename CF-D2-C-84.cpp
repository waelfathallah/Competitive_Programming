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
const int oo = 1e9;
int solve(ll a,ll b,ll r,ll x,ll y){
    ll calc=pow(x-a,2)+pow(y-b,2),R=r*r;
    if(calc==R){
        if(y==0){
            if(x==a+r)
                return 2;
            if(x==a-r)
                return -2;
        }
        return 1;
    }
    if(calc<R)
        return 1;

    if(calc>R)
        return 0;
}

int main() {_
ll n;cin >> n;
pair<pair<ll,ll>,ll> t[10001];
ll a,b;
for(int i=0;i<n;i++){
    cin >> a >> b;
    t[i]={{a,b},i};
}
ll m,x,y,ans[100001],res,k=0;;cin >> m;
sort(t,t+n);
mem(ans,-1);
for(int i=1;i<=m;i++){
    ll l=0,r=n,mid;
    cin >> x >> y;
    while(l<r){
        mid=(r+l)/2;

        if(t[mid].F.F+t[mid].F.S<x)
            l=mid+1;
        else if(t[mid].F.F-t[mid].F.S>x)
            r=mid;
        else{
            ll indx=t[mid].S;
            res=solve(t[mid].F.F,0,t[mid].F.S,x,y);
            if(res==1){
                if(ans[indx]==-1){
                    ans[indx]=i;
                    k++;
                }
            }
            else if(res==2){
                if(ans[indx]==-1){
                    ans[indx]=i;
                    k++;
                }
                if(solve(t[mid+1].F.F,0,t[mid+1].F.S,x,y)==-2 && ans[t[mid+1].S]==-1){
                    ans[t[mid+1].S]=i;
                    k++;
                }
            }
            else if(res==-2){
                if(ans[indx]==-1){
                    ans[indx]=i;
                    k++;
                }
                if(solve(t[mid-1].F.F,0,t[mid-1].F.S,x,y)==2 && ans[t[mid-1].S]==-1){
                        ans[t[mid-1].S]=i;
                        k++;
                }
            }
        break;
        }
    }
}
cout << k << endl ;
for(int i=0;i<n;i++)    cout << ans[i] << " " ;

}
