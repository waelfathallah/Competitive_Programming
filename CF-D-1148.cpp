
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
const int N = 5 * 1e5 + 5;
const double eps = 1e-5;

int n;
vector<pair<pair<int,int>,int>> asc,desc;

bool comp1(const pair<pair<int,int>,int>&i , const pair<pair<int,int>,int>&j){
    return i.F.S < j.F.S ;
}

bool comp2(const pair<pair<int,int>,int>&i , const pair<pair<int,int>,int>&j){
    return i.F.S > j.F.S ;
}

void aff(vector<int> v){
    cout << v.size() << endl;
    for(auto it : v)
        cout << it << " ";
}

int main() {_
    int a,b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b ;
        if(a > b)
            desc.PB({{a,b},i+1});
        else
            asc.PB({{a,b},i+1});
    }
    sort(desc.begin(),desc.end(),comp1);
    sort(asc.begin(),asc.end(),comp2);

    vector<int> ans1,ans2;

    if(asc.size()){
        ans1.PB(asc[0].S);
        for(int i=1;i<asc.size();i++){
            if(asc[i].F.F < asc[i-1].F.S)
                ans1.PB(asc[i].S);
            else
                break;
        }
    }

     if(desc.size()){
        ans2.PB(desc[0].S);
        for(int i=1;i<desc.size();i++){
            if(desc[i].F.F > desc[i-1].F.S)
                ans2.PB(desc[i].S);
            else
                break;
        }
    }

    if(ans1.size() > ans2.size())
        aff(ans1);
    else
        aff(ans2);

}
