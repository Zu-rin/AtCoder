#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	ll num, i, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = 0; i < num - 1; i++)
		ans += (ll)(d[i + 1] - d[i]) * (i + 1) * (num - 1 - i);
	cout << ans << "\n";
	return 0;
}