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
	ll ans = 0;
	cin >> num;
	vector<int> d(num + 1, 0);
	for (i = 0; i < num; i++)
		cin >> d[i];
	for (i = num - 1; i >= 0; i--) {
		if (d[i] > i || d[i] + 1 < d[i + 1]) {
			ans = -1;
			break;
		}
		if (d[i] + 1 == d[i + 1])
			continue;
		ans += d[i];
	}
	cout << ans << "\n";
	return 0;
}