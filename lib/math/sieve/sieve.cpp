#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e7 + 5; 

vector<int> primes; 
bool isp[maxN]; 

void sieve(int N) {
	for(int i = 2; i <= N; i++) isp[i] = true; 
	for(int i = 2; (ll) i * i <= N; i++)  { // benchmark: changing i -> i * i doesn't yield any significant advantage in terms of runtime for n = 1e6. 
		if(isp[i]) {
			for(int j = i * i; j <= N; j += i) { // be cautious: j = i * i can result in overflow.
				isp[j] = false; 
			}
		}
	}
	for(int i = 2; i <= N; i++) {
		if(isp[i]) {
			primes.push_back(i); 
		}
	}
}

signed main() {
	sieve(1e6); 
}
