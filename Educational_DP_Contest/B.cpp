#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, k;
	cin >> num >> k;
	vector<int> d(num + k, INF), dp(num + k, INF);
	rep(i, num)
		cin >> d[i];
	dp[0] = 0;
	rep(i, num - 1) {
		for(int j = 1; j <= k; j++)
			chmin(dp[i + j], dp[i] + abs(d[i] - d[i + j]));
	}
	cout << dp[num - 1] << "\n";
	return 0;
}