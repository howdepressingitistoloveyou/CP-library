#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
	int a[5]; 
	ll longInt; 
	bool ok; 
	cout << "sizeof(whole array a): " << sizeof(a) << '\n'; 
	cout << "sizeof(pointer -> a): " << sizeof(*a) << '\n'; 
	cout << "sizeof(int): " << sizeof(a[0]) << '\n'; 
	cout << "sizeof(ll): " << sizeof(longInt) << '\n'; 
	cout << "sizeof(bool): " << sizeof(ok) << '\n'; 
	cout << "Note: 1 byte = 8 bits" << '\n'; 
}
