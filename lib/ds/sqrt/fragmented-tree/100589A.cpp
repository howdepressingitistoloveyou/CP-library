#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll; 

const int maxN = 1e5 + 5, maxFT = 1e5 + 2005; 
const int blocksize = 3; 

int n, q; 
vector<int> adj[maxN]; 

struct fragment {
	vector<int> cnt; 
	fragment() {} 
	fragment(int root) {

	}
}

int sz[maxFT]; 

int FTsize; 
void buildFT(int u, int p) {
	sz[u] = 1; 
	for(auto v : adj[u]) {
		buildFT(v, u); 
		sz[u] += sz[v]; 
	}
	vector<int> vert, child; 
	int cur = 0; 
	for(auto v : adj[u]) {
		cur += sz[v]; 
		vert.pb(v); 
		if(cur > blocksize) {
			sz[u] -= cur; 
			cur = 0; 
			++FTsize; 
			child.pb(FTsize); 

		}
	}
}

signed main() {
	cin >> n >> q; 
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v; 
		adj[u].pb(v); 
		adj[v].pb(u); 
	}
	FTsize = n; 
	buildFT(1); 
}