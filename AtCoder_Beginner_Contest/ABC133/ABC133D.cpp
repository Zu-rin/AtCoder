#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	ll a = 0;
	cin >> num;
	vector<ll> d(num), ans(num);
	for (i = 0; i < num; i++) {
		cin >> d[i];
		a += d[i];
	}
	a -= 2 * d[num - 1];
	for (i = 1; i < num - 3; i += 2)
		a -= d[i] << 1;
	ans[num - 2] = a;
	ans[num - 1] = 2 * d[num - 2] - ans[num - 2];
	for (i = num - 3; i >= 0; i--)
		ans[i] = (d[i] << 1) - ans[i + 1];
	for (i = 0; i < num; i++)
		cout << ans[i] << " ";
	printf("\n");
	return 0;
}