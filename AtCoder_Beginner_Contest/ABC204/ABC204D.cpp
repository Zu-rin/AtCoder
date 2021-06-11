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
	int num, i, sum = 1, M = 100000;
	cin >> num;
	vector<int> d(num);
	vector<char> dp(M + 1, 0);
	dp[0] = 1;
	rep(i, num) {
		cin >> d[i];
		sum += d[i];
	}
	rep(i, num) {
		for (int j = M - d[i]; j >= 0; j--) {
			if (dp[j])
				dp[j + d[i]] = dp[j];
		}
	}
	for (i = sum / 2; i <= M; i++) {
		if (dp[i]) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}