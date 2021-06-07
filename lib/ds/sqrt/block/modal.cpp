#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5; 

int n, q; 
int a[maxN]; 

signed main() {
	freopen("test.txt", "r", stdin); 
	freopen("modalout.txt", "w", stdout); 
	cin >> n; 
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	cin >> q; 
	for(int i = 1; i <= q; i++) {
		int l, r, x, y;
		cin >> l >> r >> x >> y; 
		for(int j = l; j <= r; j++) if(a[j] == x) a[j] = y; 
	}	
	for(int i = 1; i <= n; i++) cout << a[i] << ' '; 
}
