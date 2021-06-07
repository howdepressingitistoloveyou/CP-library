#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

int n; 
int a[200005]; 

signed main() {
	freopen("test.txt", "w", stdout); 
	cout << (n = 20000) << '\n'; 
	for(int i = 1; i <= n; i++) cout << rng() % 100 + 1 << ' '; cout << '\n'; 
	cout << 200 << '\n'; 
	for(int i = 1; i <= 200; i++) {
		int l = rng() % n + 1, r = rng() % n + 1; 
		if(l > r) swap(l, r); 
		int x = rng() % 100 + 1, y = rng() % 100 + 1; 
		cout << l << ' ' << r << ' ' << x << ' ' << y << '\n'; 
	} 
}
