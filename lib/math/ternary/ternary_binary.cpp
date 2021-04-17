#include <bits/stdc++.h>
#define ld long double 
#define ll long long 
using namespace std;

const ld INF = 1e18, eps = 1e-13; 

ll minimaInt(ll a, ll b, ll c) {
	int l = -1e6, r = 1e6; 
	while(l < r) {
		int mid = (l + r + 1) / 2; 
		if((ll) a * mid * mid + (ll) b * mid > (ll) a * (mid - 1) * (mid - 1) + (ll) b * (mid - 1)) r = mid - 1; 
		else l = mid; 
	}
	return l; 
}

ld minima(ld a, ld b, ld c) { // y = ax^2 + bx + c, concave
	ld l = -1e6, r = 1e6; 
	for(int iter = 1; iter <= 200; iter++) {
		iter++; 
		ld mid1 = (2 * l + r) / 3, mid2 = (l + 2 * r) / 3;  // this used to be int not ld smh 
		if(a * mid1 * mid1 + b * mid1 < a * mid2 * mid2 + b * mid2) {
			r = mid2; 
		}
		else l = mid1; 
	}
	return l; 
}

ld search(ld a, ld b, ld k) { // y = ax + b, monotonic
	ld l = -1e9, r = 1e9; 
	for(int iter = 1; iter <= 200; iter++) {
		ld mid = (l + r) / 2; 
		if((ld) a * mid + b < k) { 
			l = mid; 
		}
		else r = mid; 
	}
	return l; 
}

signed main() {
	while(true) {
		ld a, b, c;
		int type; cin >> type >> a >> b >> c; 
		if(type == 1) {
			cout << setprecision(13) << fixed << search(a, b, c) << '\n'; 
		}
		else if(type == 2) cout << setprecision(13) << fixed << minima(a, b, c) << '\n'; 
		else cout << setprecision(13) << fixed << minimaInt(a, b, c) << '\n'; 
	}
}
