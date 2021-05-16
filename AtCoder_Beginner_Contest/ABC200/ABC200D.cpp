#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
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

void print(set<int> &d) {
	cout << d.size();
	for (auto& x : d) {
		cout << " " << x + 1;
	}
	printf("\n");
}

int main(void) {
	int num, i;
	cin >> num;
	vector<int> d(num);
	vector<set<int>> dp(200);
	set<int> b, c;
	rep(i, num) {
		cin >> d[i];
		if (dp[d[i] % 200].size()) {
			b = dp[d[i] % 200];
			c.insert(i);
			printf("Yes\n");
			print(b);
			print(c);
			return 0;
		}
		dp[d[i] % 200].insert(i);
	}
	rep(i, 200) {
		if (dp[i].size()) {
			for (int j = 0; j < d.size(); j++) {
				if (dp[i].count(j))
					continue;
				int nx = (d[j] + i) % 200;
				if (dp[nx].size()) {
					b = dp[nx];
					c = dp[i];
					c.insert(j);
					if (b != c) {
						printf("Yes\n");
						print(b);
						print(c);
						return 0;
					}
				}
				dp[nx] = dp[i];
				dp[nx].insert(j);
			}
		}
	}
	printf("No\n");
	return 0;
}