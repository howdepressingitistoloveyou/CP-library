#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int mod = 1e9 + 7; 

int bp(int a, int n) { // non-recursive bp idea: n = 0101001010011 -> iterate through all the bits from low to high, if bit = 1, *= a^(2^k)
	int ret = 1; 
	while(n) {
		if(n & 1) ret = ret * a % mod; 
		a = a * a % mod; 
		n >>= 1;
	}
	return ret; 
}

signed main() {
	while(1) {
		int a, n; 
		cin >> a >> n; 
		cout << bp(a, n) << '\n'; 
	}
}
