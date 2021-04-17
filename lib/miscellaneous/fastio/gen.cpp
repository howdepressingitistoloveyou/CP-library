#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); 

signed main() {
	freopen("input.txt", "w", stdout); 
	int n = 1e6; 
	cout << n << '\n'; 
	for(int i = 1; i <= n; i++) {
		ll num = rng(); 
		bool inv = !(rng() % 3);
		cout << num * (inv ? -1 : 1) << '\n';  
	}
}
