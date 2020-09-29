#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	ll ans = 0;
	cin >> num;
	vector<int> d(3 * num);
	for (i = 0; i < 3 * num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = 3 * num - 2; i >= num; i -= 2)
		ans += (ll)d[i];
	cout << ans << "\n";
	return 0;
}