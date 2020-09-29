#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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
	int num, i, j, n, a, b, k;
	cin >> num;
	vector<vector<int>> d(num);
	vector<int> n0(num, 1), n1(num, 2);
	priority_queue<pp> que[2];
	map<int, int> sp, item[2];
	rep(i, num) {
		cin >> n;
		d[i].resize(n);
		rep(j, n) {
			cin >> a;
			d[i][j] = a;
		}
		item[0][d[i][0]] = i;
		item[1][d[i][0]] = i;
		if(n > 1)
			item[1][d[i][1]] = i;
	}
	cin >> n;
	rep(i, n) {
		cin >> k;
		if (k == 1) {
			auto x = item[0].rbegin();
			while (sp.count((*x).first)) {
				item[0].erase((*x).first);
				x = item[0].rbegin();
			}
			int ans = (*x).first, pos = (*x).second;
			cout << ans << "\n";
			item[0].erase(ans);
			sp[ans];
			while (n0[pos] < d[pos].size() && sp.count(d[pos][n0[pos]]))
				n0[pos]++;
			if (n0[pos] < d[pos].size()) {
				item[0][d[pos][n0[pos]]] = pos;
				n0[pos]++;
			}
			if (n1[pos] < d[pos].size()) {
				item[1][d[pos][n1[pos]]] = pos;
				n1[pos]++;
			}
		}
		else {
			auto x = item[1].rbegin();
			while (sp.count((*x).first)) {
				item[1].erase((*x).first);
				x = item[1].rbegin();
			}
			int ans = (*x).first, pos = (*x).second;
			cout << ans << "\n";
			item[1].erase(ans);
			sp[ans];
			while (n1[pos] < d[pos].size() && sp.count(d[pos][n1[pos]]))
				n1[pos]++;
			if (n1[pos] < d[pos].size()) {
				item[1][d[pos][n1[pos]]] = pos;
				n1[pos]++;
			}
			if (item[0].count(ans)) {
				item[0].erase(ans);
				while (n0[pos] < d[pos].size() && sp.count(d[pos][n0[pos]]))
					n0[pos]++;
				if (n0[pos] < d[pos].size()) {
					item[0][d[pos][n0[pos]]] = pos;
					n0[pos]++;
				}
			}
		}
	}
	return 0;
}