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
const ll N = 1e6+1;
string s;
int n;
map<int,int> mp;
int det_type(auto c){
    if(islower(c)) return 0;
    else if(isupper(c)) return 1;
    else if(isdigit(c)) return 2;
}
char missing_char(){
    if(mp[0]==0) return 'a';
    else if(mp[1]==0) return 'A';
    else return '1';
}
int main() {_
cin >> n;
while(n--){
    mp.clear();
    cin >> s;
    for(int i=0;i<s.length();i++){
        auto c=s[i];
        mp[det_type(c)]++;
    }
    if(mp.size()==1){
        if(mp.begin()->F == 0) s[1]='A',s[2]='1';
        if(mp.begin()->F == 1) s[1]='a',s[2]='1';
        if(mp.begin()->F == 2) s[1]='A',s[2]='a';
    }
    else if(mp.size()==2){
        char missing=missing_char();
        for(int i=0;i<s.length();i++){
            auto c=s[i];
            int type=det_type(c);
            if(mp[type]>1){
                s[i]=missing;
                break;
            }
        }
    }
    cout << s << "\n";
}

}
