#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int num;

ll Search(int s, const vector<int> &d, vector<ll> &dp) {
	if (s == 0)
		return 1;
	if (dp[s] != 0)
		return dp[s];
	ll ans = 0;
	for (int i = 0; i < num; i++) {
		if (s & (1 << i)) {
			if ((s & d[i]) == 0)
				ans += Search(s - (1 << i), d, dp);
		}
	}
	dp[s] = ans;
	return ans;
}

int main(void) {
	int m, i, a, b;
	ll ans;
	cin >> num >> m;
	vector<int> d(num, 0);
	vector<ll> dp(1 << num, 0);
	for (i = 0; i < m; i++) {
		scanf_s("%d%d", &a, &b);
		d[a - 1] += 1 << (b - 1);
	}
	ans = Search((1 << num) - 1, d, dp);
	cout << ans << "\n";
	return 0;
}