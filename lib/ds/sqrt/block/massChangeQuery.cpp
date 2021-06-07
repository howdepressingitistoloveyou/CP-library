#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxN = 2e5 + 5; 
const int blocksize = 480; // forgot to fix blocksize -> 1 sub
int n, q; 
int a[maxN]; 

struct Block {
	int L, R; 
	int p[5005], rootOf[105], sz[5005]; // NOTE: making a constant for 105 -> doesnt look good for me. 
	int Find(int u) { return u == p[u] ? u : p[u] = Find(p[u]); }
	void Merge(int u, int v) {  
		u = Find(u), v = Find(v); 
		if(u != v) {
			if(sz[u] < sz[v]) swap(u, v);  // bug in dsu: initially there was no "rootOf" -> didn't think precisely about how and what to implement. 
			sz[u] += sz[v]; 
			p[v] = u; 
		}
	}
	void Change(int x, int y) { // bug 2
		if(x == y) return; 
		if(!rootOf[x]) return; 
		if(!rootOf[y]) {
			rootOf[y] = rootOf[x]; 
			rootOf[x] = 0; 
			return; 
		}
		Merge(rootOf[x], rootOf[y]); 
		rootOf[x] = 0, rootOf[y] = Find(rootOf[y]); 
 	}
	void Assign() { 
		for(int color = 1; color <= 100; color++) if(rootOf[color]) a[rootOf[color] + L - 1] = color;  // lotta bugs here. Main issue is CHANGED L -> R TO 1 -> R - L + 1, BUT DIDNT CHANGE COMPLETELY. 
		for(int i = L; i <= R; i++) if(p[i - L + 1] != i - L + 1) a[i] = a[Find(i - L + 1) + L - 1]; 
	}
	void Reset() {
		for(int color = 1; color <= 100; color++) rootOf[color] = 0; 
		for(int i = L; i <= R; i++) {
			p[i - L + 1] = i - L + 1, sz[i - L + 1] = 1; 
			if(!rootOf[a[i]]) rootOf[a[i]] = i - L + 1; 
			else Merge(i - L + 1, rootOf[a[i]]), rootOf[a[i]] = Find(rootOf[a[i]]);
		}
	}
} B[5005];

signed main() {
//	freopen("test.txt", "r", stdin); 
//	freopen("out.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> q; 
	int blockcnt = (n + blocksize - 1) / blocksize; 
	for(int i = 1; i <= blockcnt; i++) {
		B[i].L = (i - 1) * blocksize + 1; 
		B[i].R = min(i * blocksize, n);  
		B[i].Reset(); 
	}
//	cout << "init: \n"; 
//	for(int i = 1; i <= blockcnt; i++) {
//		cout << "block: " << i << '\n'; 
//		B[i].Print(); 
//	}
	for(int query = 1; query <= q; query++) {
		int l, r, x, y; 
		cin >> l >> r >> x >> y; 
		int blockL = (l - 1) / blocksize + 1, blockR = (r - 1) / blocksize + 1; 
//		cout << "block L, R: " << blockL << ' ' << blockR << '\n'; 
		if(blockL == blockR) {
			B[blockL].Assign(); 
			for(int i = l; i <= r; i++) {
				if(a[i] == x) a[i] = y;  
			}
			B[blockL].Reset(); 
		}
		else {
			B[blockL].Assign(); 
			for(int i = l; i <= B[blockL].R; i++) if(a[i] == x) a[i] = y; 
			B[blockL].Reset(); 
			
			B[blockR].Assign(); 
			for(int i = B[blockR].L; i <= r; i++) if(a[i] == x) a[i] = y; 
			B[blockR].Reset(); 			
			
//			cout << "middle blocks: \n"; 
			for(int block = blockL + 1; block < blockR; block++) {
				B[block].Change(x, y); 
//				cout << "block: " << block << '\n'; 
//				B[block].Print(); 
			}
//			cout << "blockl: \n"; B[blockL].Print(); 
//			cout << "blockr: \n"; B[blockR].Print(); 
//			cout << '\n'; 
		}
	} 
	for(int block = 1; block <= blockcnt; block++) B[block].Assign(); 
	for(int i = 1; i <= n; i++) cout << a[i] << ' '; 
}

