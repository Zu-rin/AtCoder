#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i];
		ans += d[i];
	}
	cout << ans << "\n";
	sort(d.begin(), d.end());
	for (i = num - 2; i >= 0; i--)
		d[num - 1] -= d[i];
	cout << max(d[num - 1], 0) << "\n";
	return 0;
}