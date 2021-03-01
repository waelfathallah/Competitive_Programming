#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define MP make_pair
#define pii pair<int,int>
#define PB push_back
#define MOD 1000000007

typedef long long ll;
const ll oo = 1e9;
const int N = 2*1e5 + 5;
const double eps = 1e-5;


int n,m;
int a[101],b[101],s[101][101];
int main(){_

	cin >> n >> m;
	int ret=0,qq=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i!=n){
			s[i][1]=a[i];
			for(int j=2;j<=m;j++) s[i][j]=0;
			qq^=a[i];
		}
		else{
			ret^=a[i];
		}
	}

	for(int i=1;i<=m;i++){
		cin >> b[i];
		if(i!=1){
			ret^=b[i];
			s[n][i]=b[i];
		}
	}
	if((ret^qq)!=b[1]){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	s[n][1]=ret;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << s[i][j] << " ";
		}
		cout << endl;
	}

}
 
