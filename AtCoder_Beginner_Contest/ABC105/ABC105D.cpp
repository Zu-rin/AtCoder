#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	ll m, a, ans = 0;
	cin >> num >> m;
	vector<ll> d(num + 1, 0);
	for (i = 0; i < num; i++) {
		cin >> a;
		d[i + 1] = (a + d[i]) % m;
	}
	sort(d.begin(), d.end());
	for (a = 0, i = 0; i < num; i++) {
		if (d[i] == d[i + 1])
			a++;
		else
			a = 0;
		ans += a;
	}
	cout << ans << "\n";
	return 0;
}