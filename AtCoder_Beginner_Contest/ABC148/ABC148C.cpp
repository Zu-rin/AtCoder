#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	ll a, b, ans;
	cin >> a >> b;
	ans = a * b / gcd(a, b);
	cout << ans << "\n";
	return 0;
}