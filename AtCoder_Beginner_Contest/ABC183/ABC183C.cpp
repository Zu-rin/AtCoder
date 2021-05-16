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

int Path(vector<int> & a, vector<vector<int>> & d) {
	int i, ans = d[0][a[0]] + d[*a.rbegin()][0];
	rep(i, a.size() - 1) {
		ans += d[a[i]][a[i + 1]];
	}
	return ans;
}

int main(void) {
	int num, i, j, k, ans = 0;
	cin >> num >> k;
	vector<int> a(num - 1);
	vector<vector<int>> d(num, vector<int>(num));
	rep(i, num - 1)
		a[i] = i + 1;
	rep(i, num) {
		rep(j, num) {
			cin >> d[i][j];
		}
	}
	do {
		if (Path(a, d) == k)
			ans++;
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << "\n";
	return 0;
}