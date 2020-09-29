#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
 
int main(void) {
	int num, i;
	ll a, k, ans = 0;
	cin >> num;
	queue<int> que;
	rep(i, num) {
		cin >> a >> k;
		while (k > 0) {
			if (k & 1)
				que.push(a);
			k >>= 1;
			ans += k;
			a <<= 1;
			if (a >= 10) {
				ans += k;
				a = a % 10 + 1;
			}
		}
	}
	a = que.front();
	que.pop();
	ans += que.size();
	while (!que.empty()) {
		a += que.front();
		que.pop();
		if (a >= 10) {
			ans++;
			a = a % 10 + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}