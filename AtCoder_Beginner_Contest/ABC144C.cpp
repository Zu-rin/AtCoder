#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	ll i, n, ans;
	cin >> n;
	for (i = sqrt(n); i > 0; i--) {
		if (i * (n / i) == n) {
			ans = i + (n / i) - 2;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}