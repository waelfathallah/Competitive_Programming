//using cumulative sum
#include <bits/stdc++.h>
#include <sstream>
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
const int N = 3*1e5+1;
ll n,m,a[N],b[N];
int main() {_
    cin >> n;
    cin >> a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    cin >> m;
    cin >> b[0];
    for(int i=1;i<m;i++){
        cin >> b[i];
        b[i]+=b[i-1];
    }
    int i=0,j=0,ans=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            ans++;
            i++;j++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else if(b[j]>a[i]){
            i++;
        }
    }
    if(i==n && j==m) cout << ans ;
    else cout << -1;

}
