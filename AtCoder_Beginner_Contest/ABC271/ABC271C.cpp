#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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
	int num, i, a, ans = 0;
	cin >> num;
	map<int, int> mp;
	deque<int> que;
	rep(i, num) {
		cin >> a;
		mp[a]++;
	}
	for (auto it = mp.rbegin(); it != mp.rend(); it++) {
		que.push_front((*it).first);
		rep(i, (*it).second - 1)
			que.push_back((*it).first);
	}
	while (!que.empty()) {
		if (que.front() == ans + 1) {
			que.pop_front();
		}
		else {
			if (que.size() <= 1)
				break;
			que.pop_back();
			que.pop_back();
		}
		ans++;
	}
	cout << ans << "\n";
	return 0;
}