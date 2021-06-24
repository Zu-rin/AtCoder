#include <iostream>
#include <vector>
#include <string>
#include <list>
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
	int num, i, j, h, w, ans = 0;
	cin >> h >> w;
	vector<vector<int>> d(h, vector<int>(w));
	rep(i, h) {
		rep(j, w)
			cin >> d[i][j];
	}
	for (int v = 1; v < (1 << h); v++) {
		map<int, int> mp;
		vector<int> s;
		rep(i, h) {
			if (v & (1 << i))
				s.push_back(i);
		}
		rep(j, w) {
			char ok = 1;
			int x = 0;
			for(int i : s){
				if (x and x != d[i][j]) {
					ok = 0;
					break;
				}
				else if (!x)
					x = d[i][j];
			}
			if (ok)
				mp[x]++;
		}
		for (auto& p : mp) {
			chmax(ans, p.second * (int)s.size());
		}
	}
	cout << ans << "\n";
	return 0;
}