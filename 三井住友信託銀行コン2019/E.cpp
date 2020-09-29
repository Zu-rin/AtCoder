#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a;
	ll ans = 1;
	cin >> num;
	vector<int> d(num, 0);
	for (i = 0; i < num; i++) {
		cin >> a;
		if (a > 0) {
			ans *= d[a - 1] - d[a];
			ans %= MOD;
		}
		d[a]++;
	}
	for (i = 0; i < d[0]; i++) {
		ans *= 3 - i;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}