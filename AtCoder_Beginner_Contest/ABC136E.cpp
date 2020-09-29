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

int Judge(int x, int k, vector<int> d) {
	int i, sum = 0, a = 0;
	rep(i, d.size()) {
		d[i] %= x;
		sum += d[i];
	}
	sort(d.begin(), d.end(), greater<int>());
	rep(i, sum / x) {
		a += x - d[i];
	}
	return a <= k;
}

int main(void) {
	int num, i, k, sum = 0, ans;
	priority_queue<int> que;
	cin >> num >> k;
	vector<int> d(num);
	rep(i, num) {
		cin >> d[i];
		sum += d[i];
	}
	for (i = 1; i * i <= sum; i++) {
		if (sum % i == 0) {
			que.push(i);
			que.push(sum / i);
		}
	}
	while (!que.empty()) {
		ans = que.top();
		que.pop();
		if (Judge(ans, k, d))
			break;
	}
	cout << ans << "\n";
	return 0;
}