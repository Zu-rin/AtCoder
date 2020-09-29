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
	int num, k, i, a, sum = 0, ans;
	queue<int> que;
	cin >> num >> k;
	for (i = 0; i < k; i++) {
		cin >> a;
		sum += a;
		que.push(a);
	}
	ans = sum;
	for (; i < num; i++) {
		cin >> a;
		sum += a - que.front();
		que.push(a);
		que.pop();
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}