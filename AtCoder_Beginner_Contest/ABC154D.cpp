#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
	int num, i, k;
	double d, sum = 0.0, ans = 0.0;
	queue<double> que;
	cin >> num >> k;
	rep(i, num) {
		cin >> d;
		d = (d + 1.0) / 2.0;
		sum += d;
		que.push(d);
		chmax(ans, sum);
		if (que.size() == k) {
			sum -= que.front();
			que.pop();
		}
	}
	printf("%.9lf\n", ans);
	return 0;
}