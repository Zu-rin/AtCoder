#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
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
	int num, i;
	ll x, ans = 0;
	string s;
	deque<int> que;
	cin >> num >> x >> s;
	while (x) {
		if (x & 1)
			que.push_front(1);
		else
			que.push_front(0);
		x >>= 1;
	}
	for (char c : s) {
		if (c == 'U')
			que.pop_back();
		else if (c == 'L')
			que.push_back(0);
		else
			que.push_back(1);
	}
	while (!que.empty()) {
		ans <<= 1;
		ans += que.front();
		que.pop_front();
	}
	cout << ans << "\n";
	return 0;
}