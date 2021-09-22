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
	int num, i, j, ans = 0, a = 0, b, c;
	b = c = -1;
	cin >> num;
	vector<vector<int>> d(3, vector<int>(num));
	rep(i, 3) {
		rep(j, num)
			cin >> d[i][j];
		sort(d[i].begin(), d[i].end());
	}
	while (true) {
		while (++b < num and d[1][b] <= d[0][a]) {}
		while (b < num and ++c < num and d[2][c] <= d[1][b]) {}
		if (a++ < num and b < num and c < num)
			ans++;
		else
			break;
	}
	cout << ans << "\n";
	return 0;
}