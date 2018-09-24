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

int main() {_
int n,sum=0,mx=-oo;
cin >> n;
string s;
cin >> s;
for(int i=0;i<n;i++){
    sum+=s[i]-'0';
    mx=max(mx,s[i]-'0');
}
//i calculate max_element because i can't split to a part with sum_part<mx
if(sum==0 && n>=2){cout << "YES"; return 0;} // case with all zeros
vector<int> div;
for(int i=2;sum/i>=mx;i++){
    if(sum%i==0){
        div.PB(i); //i put in vector all possible dividing numbers (num of parts)
    }
}
int curr,parts,p;
for(int i=0;i<div.size();i++){
    curr=0;parts=0,p=sum/div[i]; // p is parts to try
    for(int j=0;j<n;j++){
        curr+=s[j]-'0';
        parts+=(curr%p==0 && s[j]!='0'); // form a part when i reach the possible sum only the first time not with zeros ;
    }
    if(parts==div[i]){
        cout << "YES" ;
        return 0;
    }
}
cout << "NO" ;
}
