#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define MOD 1000000007
typedef long long ll;
const ll oo = 1e9;
const int N = 2*1e5 + 5;
const double eps = 1e-5;

#define mp make_pair
#define pii pair<int,int>

int arr[N];
set<pii> s1;
set<pii> s2;
set<pii>::iterator it;


void solve(){
    int n,p,z,y,x;
    cin >> n ;
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    z=1;
    x=1;
    for(int i=2;i<=n;i++){
        if(arr[i]==arr[z]) x++;
        else{
            s1.insert(mp(z,x));
            s2.insert(mp(-x,z));
            x=1;
            z=i;
        }
    }
    s1.insert(mp(z,x));
    s2.insert(mp(-x,z));
    int ans=0;
    while(s2.size()){
        ans++;
        pii g=*(s2.begin());
        pii G=mp(g.S,-g.F);
        s2.erase(g);
        s1.erase(G);
        it=s1.lower_bound(G);
        if(it!=s1.begin() and it!=s1.end()){
            pii p=*it;
            it--;
            pii q=*it;
            if(arr[p.F]==arr[q.F]){
                s1.erase(p);
                s2.erase(mp(-p.S,p.F));
                s1.erase(q);
                s2.erase(mp(-q.S,q.F));
                q.S+=p.S;
                s1.insert(q);
                s2.insert(mp(-q.S,q.F));
            }
        }
    }

    cout << ans ;
}


int main() {_

    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
