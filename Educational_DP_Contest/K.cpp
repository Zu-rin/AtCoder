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
	int num, i, j, k;
	cin >> num >> k;
	vector<int> d(num);
	vector<char> dp(k + 1, 0);
	rep(i, num)
		cin >> d[i];
	rep(i, k) {
		if (!dp[i]) {
			rep(j, num) {
				if (i + d[j] <= k)
					dp[i + d[j]] = 1;
			}
		}
	}
	if (dp[k])
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}