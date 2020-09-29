#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	ll n, k, g;
	cin >> n >> k;
	g = gcd(n, k);
	cout << k - g << "\n";
	return 0;
}