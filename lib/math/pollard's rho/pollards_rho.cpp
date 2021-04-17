#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
// what ?? changing mt19937 -> mt19937_64 results in very strange behaviors
// maybe it was the gcd function
// i think it's overflow, even for log mul. 

int mul(int a, int b, int mod) {
	int ret = 0; 
	while(b) {
		if(b & 1) ret = (ret + a) % mod; 
		a = a * 2 % mod; 
		b >>= 1; 
	}
	return ret; 
}

int bp(int a, int n, int mod) {
	int ret = 1; 
	while(n) {
		if(n & 1) ret = mul(ret, a, mod); 
		a = mul(a, a, mod); 
		n >>= 1; 
	}
	return ret; 
}

bool miller_rabin(int p) {
	if(p <= 5) {
		return p == 2 or p == 3 or p == 5;
	}
	int s = p - 1, k = 0; 
	while(!(s & 1)) {
		k++; 
		s >>= 1;
	}
	for(int iter = 1; iter <= 5; iter++) {
		int a = rng() % (p - 3) + 2; 
		a = bp(a, s, p); 
		bool bad = true; 
		if((a + p - 1) % p == 0) bad = false; 
		for(int i = 1; i <= k; i++) {
			if((a + 1) % p == 0) bad = false; 
			a = mul(a, a, p); 
		}
		if(bad) return false; 
	}
	return true; 
}

int f(int x, int b, int c, int mod) {
	return (mul(x, x, mod) + mul(b, x, mod) + c) % mod; 
}

int _rho(int x) {
	int b = rng(), c = rng(); 
	int tortoise = 2, hare = 2, g = 1; // easy to forget this part
	while(g == 1) {
		tortoise = f(tortoise, b, c, x); 
		hare = f(f(hare, b, c, x), b, c, x); 
		g = __gcd(abs(tortoise - hare), x); 
	}
	return g; 
}

int rho(int x) {
	int ret = _rho(x); 
	while(ret == x) ret = _rho(x); 
	return ret; 
}

vector<int> res; 

void fac(int n) {
	if(miller_rabin(n)) {
		res.pb(n); 
		return; 
	}
	int d = rho(n); 
	fac(d);
	fac(n / d); 
}

signed main() {
	while(1) {
		int x; 
		cin >> x; 
		res.clear(); 
		fac(x); 
		for(auto val : res) {
			cout << val << ' '; 
		}
		cout << '\n'; 
	}
}
