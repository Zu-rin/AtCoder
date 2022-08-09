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
	int n, m, i;
	vector<int> d;
	vector<vector<int>> ans;
	cin >> n >> m;
	rep(i, m)
		d.push_back(i + 1);
	do {
		if (ans.size() > 0 and *ans.rbegin() == vector<int>{d.begin(), d.begin() + n})
			continue;
		ans.push_back(vector<int>{d.begin(), d.begin() + n});
		int ok = 1;
		rep(i, n - 1) {
			if (d[i] > d[i + 1]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			rep(i, n - 1)
				cout << d[i] << " ";
			cout << d[i] << "\n";
		}
	} while (next_permutation(d.begin(), d.end()));
	return 0;
}