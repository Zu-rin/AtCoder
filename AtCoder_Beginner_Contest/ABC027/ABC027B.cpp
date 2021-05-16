#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, sum = 0, ans = 0, ave, l = 0, r = 1;
	cin >> num;
	vector<int> d(num + 1, 0);
	rep(i, num) {
		cin >> d[i + 1];
		d[i + 1] += d[i];
	}
	if (d[num] % num > 0)
		ans = -1;
	else {
		ave = d[num] / num;
		for (r = 1; r < num; r++) {
			if (d[r] - d[l] == (r - l) * ave) {
				ans += r - l - 1;
				l = r;
			}
		}
	}
	ans += r - l - 1;
	cout << ans << "\n";
	return 0;
}