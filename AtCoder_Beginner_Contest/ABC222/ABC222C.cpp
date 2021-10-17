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

int Judge(char a, char b) {
	string gcp = "GCP";
	int x = gcp.find(a) - gcp.find(b);
	if (!x)
		return 0;
	if (x == -1 || x == 2)
		return 1;
	return -1;
}

struct Player {
	int num, win = 0;
	string s;

	bool operator<(const Player& r) {
		if (win == r.win)
			return num < r.num;
		return win > r.win;
	}
};

int main(void) {
	int num, m, i, j;
	cin >> num >> m;
	vector<Player> ans(2 * num);
	rep(i, ans.size()) {
		cin >> ans[i].s;
		ans[i].num = i + 1;
	}
	rep(j, m) {
		rep(i, num) {
			int r = Judge(ans[2 * i].s[j], ans[2 * i + 1].s[j]);
			if (r > 0)
				ans[2 * i].win++;
			else if (r < 0)
				ans[2 * i + 1].win++;
		}
		sort(ans.begin(), ans.end());
	}
	rep(i, ans.size()) {
		cout << ans[i].num << "\n";
	}
	return 0;
}