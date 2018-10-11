/*
Imagine that you have 3 circles puted in that way: 2 down , 1 up.
You have the distances between their centers equal to r. So you have an equilateral triangle.

Let's name the height of the triangle t. So we have : t^2 + (r/2)^2 = r^2. So t = sqrt(3)/2 * r.

Initially you put h/r*2 circles from bottom to top so you remain with h%r.
Up there you will have 3 cases: the 2 ones that are obvious ( 1 or 2 circles ) and the one presented below ( with the condition: t < h%r ).
*/

#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const ll oo = 1e19;
const ll N = 1e5;

int main() {_
ll r,h;
cin >> r >> h;
ll ans=h/r*2;
h%=r;
if(2*h>=r){
    ans+=2;
    if(h+r>=(double)r*sqrt(3)/2+r)
        ans++;
}
else
    ans++;
cout << ans;
}
