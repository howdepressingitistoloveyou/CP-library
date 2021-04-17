#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int maxN = 1e7 + 5; 
int lp[maxN], phi[maxN]; 

void sieve(int N) {
	for(int i = 1; i <= N; i++) {
		lp[i] = phi[i] = i; 
	}
	for(int i = 2; i <= N; i++) {
		if(lp[i] == i) {
			for(int j = i; j <= N; j += i) {
				lp[j] = min(lp[j], i); 
				phi[j] -= phi[j] / i; 
			}
		}
	}
}

bool isp[maxN]; 

vector<int> segmentedSieve(ll L, ll R) {
	assert((ll) (R - L + 1) <= (int) 1e7); 
	for(int i = 0; i < R - L + 1; i++) {
		isp[i] = true; 
	}
	int sqrtR = sqrt(R); 
	sieve(sqrtR); 
	for(int i = 2; i <= sqrtR; i++) {
		if(lp[i] == i) {
			for(ll j = (ll) max((ll) i, (L + i - 1) / i) * i; j <= R; j += i) {
				isp[j - L] = false; 
			}
		}
	}
	vector<int> ret; 
	for(int i = 0; i < R - L + 1; i++) {
		if(isp[i] and L + i != 1) ret.pb(L + i); 
	}
	return ret; 
}

vector<int> fac(int x) {
	vector<int> ret; 
	while(x > 1) {
		ret.pb(lp[x]); 
		x /= lp[x]; 
	}
	return ret; 
}

signed main() {
	sieve(1e6); 
	cout << "test lp, phi: \n"; 
	for(int i = 1; i <= 20; i++) {
		cout << lp[i] << ' ' << phi[i] << '\n'; 
	}
	cout << "fac: \n"; 
	int q; 
	cin >> q; 
	while(q--) {
		int x; 
		cin >> x; 
		vector<int> ans = fac(x); 
		for(auto p : ans) cout << p << ' '; cout << '\n'; 
	}
	cout << "segmented sieve: \n"; 
	ll L, R; 
	cin >> L >> R; 
	vector<int> res = segmentedSieve(L, R); 
	for(auto x : res) cout << x << ' ';
}
