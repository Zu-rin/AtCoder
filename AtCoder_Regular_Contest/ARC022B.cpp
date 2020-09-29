#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, l = 0, r, ans = 1;
	cin >> num;
	vector<int> d(num), a(100001, false);
	for (i = 0; i < num; i++) {
		cin >> d[i];
	}
	for (r = 0; r < num; r++) {
		while (a[d[r]]) {
			a[d[l]] = false;
			l++;
		}
		a[d[r]] = true;
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return 0;
}