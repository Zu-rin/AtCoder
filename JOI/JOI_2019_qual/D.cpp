#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a, ans = 1, sum = 1, ok = true;
	cin >> num;
	vector<int> d(num + 2, true);
	priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> que;
	d[0] = d[num + 1] = false;
	for (i = 1; i <= num; i++) {
		cin >> a;
		if (a > 0)
			ok = false;
		que.push(make_pair(a, i));
	}
	if (ok) {
		printf("0\n");
		return 0;
	}
	while (!que.empty()) {
		a = que.top().first;
		while (!que.empty() && que.top().first == a) {
			i = que.top().second;
			que.pop();
			d[i] = false;
			if (d[i - 1] & d[i + 1])
				sum++;
			else if (!(d[i - 1] ^ d[i + 1]))
				sum--;
		}
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}