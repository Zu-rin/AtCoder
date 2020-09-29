#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, a, b;
	ll ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		ans -= b;
		d[i] = a + b;
	}
	sort(d.begin(), d.end(), greater<int>());
	for (i = 0; i < num; i += 2) {
		ans += d[i];
	}
	cout << ans << "\n";
	return 0;
}