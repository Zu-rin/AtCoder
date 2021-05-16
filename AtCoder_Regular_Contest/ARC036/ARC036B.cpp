#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a = 0, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i];
	}
	for (i = 1; i < num - 1; i++) {
		if (d[i - 1] > d[i] && d[i] < d[i + 1]) {
			ans = max(ans, i - a + 1);
			a = i;
		}
	}
	ans = max(ans, num - a);
	cout << ans << "\n";
	return 0;
}