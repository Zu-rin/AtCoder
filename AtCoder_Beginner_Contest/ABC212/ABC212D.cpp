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
	int num, i, q, k;
	ll x, s = 0;
	priority_queue<ll, vector<ll>, greater<ll>> que;
	cin >> q;
	rep(i, q) {
		cin >> k;
		if (k == 3) {
			cout << que.top() + s << "\n";
			que.pop();
			continue;
		}
		cin >> x;
		if (k == 1)
			que.push(x - s);
		else
			s += x;
	}
	return 0;
}