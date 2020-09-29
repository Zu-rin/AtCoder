#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, m, i, a;
	ll ans = 0;
	priority_queue<int> que;
	cin >> num >> m;
	for (i = 0; i < num; i++) {
		cin >> a;
		que.push(a);
	}
	for (i = 0; i < m; i++) {
		a = que.top();
		que.pop();
		a >>= 1;
		que.push(a);
	}
	while (!que.empty()) {
		ans += que.top();
		que.pop();
	}
	cout << ans << "\n";
	return 0;
}