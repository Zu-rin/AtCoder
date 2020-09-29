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
	int num, m, q, i, a, b, k;
	cin >> num >> m >> q;
	vector<list<int>> ps(num + 1);
	vector<int> d(num + 1);
	rep(i, m) {
		cin >> a >> b;
		ps[a].push_back(b);
		ps[b].push_back(a);
	}
	for(i = 1; i <= num; i++)
		cin >> d[i];
	rep(i, q) {
		cin >> k >> a;
		cout << d[a] << "\n";
		if (k == 1) {
			for (auto it = ps[a].begin(); it != ps[a].end(); it++)
				d[*it] = d[a];
		}
		else {
			cin >> b;
			d[a] = b;
		}
	}
	return 0;
}