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
	int num, i, j, k, c = 1;
	cin >> num >> k;
	vector<vector<int>> d(1, vector<int>(num + 1));
	rep(i, num)
		cin >> d[0][i];
	rep(i, k) {
		if (!c)
			break;
		c = false;
		d.push_back(vector<int>(num + 1, 0));
		rep(j, num) {
			d[i + 1][max(0, j - d[i][j])]++;
			d[i + 1][min(num, j + d[i][j] + 1)]--;
		}
		rep(j, num) {
			d[i + 1][j + 1] += d[i + 1][j];
			if (d[i][j] != d[i + 1][j])
				c = true;
		}
	}
	rep(j, num - 1)
		cout << d[i][j] << " ";
	cout << d[i][j] << "\n";
	return 0;
}