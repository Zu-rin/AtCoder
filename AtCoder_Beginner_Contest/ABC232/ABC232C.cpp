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
	int num, m, i, j, a, b, ok = false;
	cin >> num >> m;
	vector<int> k(num);
	vector<vector<int>> d(num), x(num);
	rep(i, m) {
		cin >> a >> b;
		d[--a].push_back(--b);
	}
	rep(i, m) {
		cin >> a >> b;
		x[--a].push_back(--b);
	}
	rep(i, num) {
		k[i] = i;
		sort(d[i].begin(), d[i].end());
	}
	do {
		vector<vector<int>> buf(num);
		rep(i, num) {
			rep(j, x[i].size()) {
				a = min(k[i], k[x[i][j]]);
				b = max(k[i], k[x[i][j]]);
				buf[a].push_back(b);
			}
		}
		rep(i, num)
			sort(buf[i].begin(), buf[i].end());
		if (d == buf) {
			ok = true;
			break;
		}
	} while (next_permutation(k.begin(), k.end()));
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}