#include <bits/stdc++.h>
#define ii pair<int, int> 
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int maxN = 5e4 + 5, INF = INT_MAX / 2;
const int blocksize = 230;
int n, q; 
ii a[maxN]; 

bool byIndex(const ii &x, const ii &y) {
	return x.se < y.se; 
}

int minDiff[250][250][250], mx[250][250][250], mn[250][250][250]; 
int tmp[maxN]; 
int nearestL[maxN][250], nearestR[maxN][250]; 

int getminDiff(int b, int l, int r) {
	int bl = nearestR[l][b], br = nearestL[r][b];  
	if(bl > br) return INF; 
	return minDiff[b][bl][br]; 
}

int getMax(int b, int l, int r) {
	int bl = nearestR[l][b], br = nearestL[r][b];  
	if(bl > br) return INF; 
	return mx[b][bl][br]; 
}

int getMin(int b, int l, int r) {
	int bl = nearestR[l][b], br = nearestL[r][b];  
	if(bl > br) return INF; 
	return mn[b][bl][br]; 
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q; 	
	for(int i = 1; i <= n; i++) cin >> a[i].fi, a[i].se = i; 
	sort(a + 1, a + n + 1); 
	int blockcnt = (n + blocksize - 1) / blocksize; 
	for(int b = 1; b <= blockcnt; b++) {
		int L = (b - 1) * blocksize + 1, R = min(b * blocksize, n);
		vector<ii> v; 
		for(int i = L; i <= R; i++) {
			v.pb(a[i]); 
		}
		sort(all(v), byIndex);
		for(int i = 0; i < R - L + 1; i++) {
			for(int j = 0; j < R - L + 1; j++) {
				minDiff[b][i][j] = INF, mx[b][i][j] = 0, mn[b][i][j] = INF;
			}
		}
		for(int len = 1; len <= R - L + 1; len++) {
			for(int i = 0; i + len - 1 < R - L + 1; i++) {
				int j = i + len - 1; 
				if(i == j) {
					minDiff[b][i][j] = INF; 
					mx[b][i][j] = v[i].fi; 
					mn[b][i][j] = v[i].fi; 
				}
				else {
					minDiff[b][i][j] = min({minDiff[b][i][j - 1], minDiff[b][i + 1][j], abs(v[i].fi - v[j].fi)}); 
					mx[b][i][j] = max(mx[b][i][j - 1], v[j].fi); 
					mn[b][i][j] = min(mn[b][i][j - 1], v[j].fi); 
				}
			}
		}
		for(auto T : v) tmp[T.se]++; 
		int index = -1; 
		for(int i = 1; i <= n; i++) {
			if(tmp[i]) index++;  
			nearestL[i][b] = index; 
		}
		index = R - L + 1; 
		for(int i = n; i; i--) {
			if(tmp[i]) index--; 
			nearestR[i][b] = index; 
		}
		for(auto T : v) tmp[T.se]--; 
	}
	int last = 0; 
	for(int i = 1; i <= q; i++) {
		int qL, qR; cin >> qL >> qR; 
		qL = 1 + (qL + last) % n; 
		qR = 1 + (qR + last) % n; 
		if(qL > qR) swap(qL, qR); 
		int res = INF; 
		int lastgood = -1; 
		for(int b = 1; b <= blockcnt; b++) {
			res = min(res, getminDiff(b, qL, qR)); 
			if(lastgood != -1 and getMin(b, qL, qR) != INF) {
				res = min(res, getMin(b, qL, qR) - getMax(lastgood, qL, qR)); 
			}
			if(getMin(b, qL, qR) != INF) lastgood = b; 
		}
		cout << (last = res) << '\n'; 
	}
}
