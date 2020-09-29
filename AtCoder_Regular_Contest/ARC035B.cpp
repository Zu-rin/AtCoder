#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

ll Perm(int n) {
	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= MOD;
	}
	return ans;
}

int main(void) {
	int num, i, a = 1;
	ll ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		cin >> d[i];
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++) {
		ans += d[i] * (num - i);
	}
	cout << ans << "\n";
	for (ans = 1, i = 0; i < num - 1; i++) {
		if (d[i] != d[i + 1]) {
			ans *= Perm(a);
			ans %= MOD;
			a = 1;
		}
		else
			a++;
	}
	if (a > 0) {
		ans *= Perm(a);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}