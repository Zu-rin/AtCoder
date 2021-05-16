#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	ll a, b, ans = 0;
	cin >> num >> a >> b;
	vector<ll> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	for (i = 0; i < num - 1; i++)
		ans += min(a * (d[i + 1] - d[i]), b);
	cout << ans << "\n";
	return 0;
}