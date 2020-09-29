#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	ll ans = 0, s;
	cin >> num;
	vector<ll> a(num), b(num);
	for (i = 0; i < num; i++)
		scanf_s("%d%d", &a[i], &b[i]);
	for (i = num - 1; i >= 0; i--) {
		s = b[i] - a[i] - ans;
		s %= b[i];
		if (s < 0)
			s += b[i];
		ans += s;
	}
	cout << ans << "\n";
	return 0;
}